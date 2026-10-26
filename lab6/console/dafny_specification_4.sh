#!/usr/bin/env bash
set -uo pipefail

slug="dafny_specification_4"
script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
lab_dir="$(cd -- "$script_dir/.." && pwd)"
source_file="$lab_dir/src/$slug.dfy"
test_dir="$lab_dir/test/$slug"
build_dir="$lab_dir/build/$slug"

mkdir -p "$build_dir"
if ! command -v dafny >/dev/null 2>&1; then
  echo "FAIL: Dafny is not installed or not on PATH." >&2
  exit 1
fi
if ! dafny build --no-verify --output:"$build_dir/$slug" "$source_file"; then
  echo "FAIL: Dafny build failed for $slug." >&2
  exit 1
fi

if [[ -x "$build_dir/$slug" ]]; then
  executable=("$build_dir/$slug")
elif [[ -f "$build_dir/$slug.dll" ]] && command -v dotnet >/dev/null 2>&1; then
  executable=(dotnet "$build_dir/$slug.dll")
else
  echo "FAIL: Compiled executable not found in $build_dir." >&2
  exit 1
fi

shopt -s nullglob
inputs=("$test_dir"/*.in)
if ((${#inputs[@]} == 0)); then
  echo "No example tests provided for $slug."
  exit 0
fi

failed=0
for input_file in "${inputs[@]}"; do
  output_file="${input_file%.in}.out"
  test_name="$(basename "${input_file%.in}")"
  if [[ ! -f "$output_file" ]]; then
    printf 'FAIL %s: expected output file is missing: %s\n' "$test_name" "$output_file"
    failed=1
    continue
  fi

  actual_file="$(mktemp "$build_dir/${slug}.actual.XXXXXX")"
  if ! "${executable[@]}" < "$input_file" > "$actual_file"; then
    printf 'FAIL %s: program exited unsuccessfully\n' "$test_name"
    failed=1
  elif diff -u "$output_file" "$actual_file"; then
    printf 'PASS %s\n' "$test_name"
  else
    printf 'FAIL %s: output differs\n' "$test_name"
    failed=1
  fi
  rm -f -- "$actual_file"
done

exit "$failed"
