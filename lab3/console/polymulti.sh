cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/polymulti.c -o polymulti -lm
[ "$(./polymulti < ../test/polymulti1.txt)" = "$(sed -n '1p' ../test/polymulti_answerkey.txt)" ] && echo True || echo False
[ "$(./polymulti < ../test/polymulti2.txt)" = "$(sed -n '2p' ../test/polymulti_answerkey.txt)" ] && echo True || echo False
[ "$(./polymulti < ../test/polymulti3.txt)" = "$(sed -n '3p' ../test/polymulti_answerkey.txt)" ] && echo True || echo False
rm polymulti
