cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/lagrange.c -o lagrange -lm
[ "$(./lagrange < ../test/lagrange/example1.in)" = "$(cat ../test/lagrange/example1.out)" ] && echo True || echo False
[ "$(./lagrange < ../test/lagrange/example2.in)" = "$(cat ../test/lagrange/example2.out)" ] && echo True || echo False
[ "$(./lagrange < ../test/lagrange/example3.in)" = "$(cat ../test/lagrange/example3.out)" ] && echo True || echo False
rm lagrange
