cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/reachable.c -o reachable -lm
[ "$(./reachable < ../test/reachable1.txt)" = "$(cat ../test/reachable1_ans.txt)" ] && echo True || echo False
[ "$(./reachable < ../test/reachable2.txt)" = "$(cat ../test/reachable2_ans.txt)" ] && echo True || echo False
[ "$(./reachable < ../test/reachable3.txt)" = "$(cat ../test/reachable3_ans.txt)" ] && echo True || echo False
rm reachable
