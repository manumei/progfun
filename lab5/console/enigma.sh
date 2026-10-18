cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/enigma.c -o enigma -lm
[ "$(./enigma < ../test/enigma/example1.in)" = "$(cat ../test/enigma/example1.out)" ] && echo True || echo False
[ "$(./enigma < ../test/enigma/example2.in)" = "$(cat ../test/enigma/example2.out)" ] && echo True || echo False
[ "$(./enigma < ../test/enigma/example3.in)" = "$(cat ../test/enigma/example3.out)" ] && echo True || echo False
rm enigma
