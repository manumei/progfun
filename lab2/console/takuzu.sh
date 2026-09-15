cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/takuzu.c -o takuzu -lm
[ "$(./takuzu < ../test/takuzu1.txt)" = "$(sed -n '1p' ../test/takuzu_answerkey.txt)" ] && echo True || echo False
[ "$(./takuzu < ../test/takuzu2.txt)" = "$(sed -n '2p' ../test/takuzu_answerkey.txt)" ] && echo True || echo False
[ "$(./takuzu < ../test/takuzu3.txt)" = "$(sed -n '3p' ../test/takuzu_answerkey.txt)" ] && echo True || echo False
rm takuzu
