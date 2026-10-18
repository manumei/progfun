cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/bernoulli.c -o bernoulli -lm
[ "$(./bernoulli < ../test/bernoulli/example1.in)" = "$(cat ../test/bernoulli/example1.out)" ] && echo True || echo False
[ "$(./bernoulli < ../test/bernoulli/example2.in)" = "$(cat ../test/bernoulli/example2.out)" ] && echo True || echo False
[ "$(./bernoulli < ../test/bernoulli/example3.in)" = "$(cat ../test/bernoulli/example3.out)" ] && echo True || echo False
rm bernoulli
