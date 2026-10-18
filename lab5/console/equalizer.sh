cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/equalizer.c -o equalizer -lm
[ "$(./equalizer < ../test/equalizer/example1.in)" = "$(cat ../test/equalizer/example1.out)" ] && echo True || echo False
[ "$(./equalizer < ../test/equalizer/example2.in)" = "$(cat ../test/equalizer/example2.out)" ] && echo True || echo False
[ "$(./equalizer < ../test/equalizer/example3.in)" = "$(cat ../test/equalizer/example3.out)" ] && echo True || echo False
rm equalizer
