cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/takuzu.c -o takuzu -lm
[ "$(./takuzu < ../test/takuzu1.txt)" = "$(cat ../test/takuzu1_ans.txt)" ] && echo True || echo False
[ "$(./takuzu < ../test/takuzu2.txt)" = "$(cat ../test/takuzu2_ans.txt)" ] && echo True || echo False
[ "$(./takuzu < ../test/takuzu3.txt)" = "$(cat ../test/takuzu3_ans.txt)" ] && echo True || echo False
rm takuzu
