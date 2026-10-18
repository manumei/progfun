cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/powerful.c -o powerful -lm
[ "$(./powerful < ../test/powerful/example1.in)" = "$(cat ../test/powerful/example1.out)" ] && echo True || echo False
[ "$(./powerful < ../test/powerful/example2.in)" = "$(cat ../test/powerful/example2.out)" ] && echo True || echo False
[ "$(./powerful < ../test/powerful/example3.in)" = "$(cat ../test/powerful/example3.out)" ] && echo True || echo False
rm powerful
