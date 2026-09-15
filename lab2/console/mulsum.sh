cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/mulsum.c -o mulsum -lm
[ "$(./mulsum < ../test/mulsum1.txt)" = "$(sed -n '1p' ../test/mulsum_answerkey.txt)" ] && echo True || echo False
[ "$(./mulsum < ../test/mulsum2.txt)" = "$(sed -n '2p' ../test/mulsum_answerkey.txt)" ] && echo True || echo False
[ "$(./mulsum < ../test/mulsum3.txt)" = "$(sed -n '3p' ../test/mulsum_answerkey.txt)" ] && echo True || echo False
rm mulsum
