cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/laser.c -o laser -lm
[ "$(./laser < ../test/laser1.txt)" = "$(cat ../test/laser1_ans.txt)" ] && echo True || echo False
[ "$(./laser < ../test/laser2.txt)" = "$(cat ../test/laser2_ans.txt)" ] && echo True || echo False
[ "$(./laser < ../test/laser3.txt)" = "$(cat ../test/laser3_ans.txt)" ] && echo True || echo False
rm laser
