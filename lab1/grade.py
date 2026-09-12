import subprocess
import math

tests = [
    ("tests/grade1.txt", 8.5),
    ("tests/grade2.txt", 6.5),
    ("tests/grade3.txt", 6.0),
]

for filename, expected in tests:
    with open(filename) as f:
        result = subprocess.run(
            ["./grade"],
            stdin=f,
            capture_output=True,
            text=True
        )

    actual = float(result.stdout.strip())
    passed = math.isclose(actual, expected)

    print(f"{filename}: {passed}")

    if not passed:
        print(f"  expected: {expected}")
        print(f"  actual:   {actual}")