cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/primegaps.c -o primegaps -lm
[ "$(./primegaps < ../test/primegaps1.txt)" = "$(sed -n '1p' ../test/primegaps_answerkey.txt)" ] && echo True || echo False
[ "$(./primegaps < ../test/primegaps2.txt)" = "$(sed -n '2p' ../test/primegaps_answerkey.txt)" ] && echo True || echo False
[ "$(./primegaps < ../test/primegaps3.txt)" = "$(sed -n '3p' ../test/primegaps_answerkey.txt)" ] && echo True || echo False
rm primegaps
