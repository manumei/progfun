cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/polydiv.c -o polydiv -lm
[ "$(./polydiv < ../test/polydiv1.txt)" = "$(sed -n '1p' ../test/polydiv_answerkey.txt)" ] && echo True || echo False
[ "$(./polydiv < ../test/polydiv2.txt)" = "$(sed -n '2p' ../test/polydiv_answerkey.txt)" ] && echo True || echo False
[ "$(./polydiv < ../test/polydiv3.txt)" = "$(sed -n '3p' ../test/polydiv_answerkey.txt)" ] && echo True || echo False
rm polydiv
