cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/cyclicmult.c -o cyclicmult -lm
[ "$(./cyclicmult < ../test/cyclicmult1.txt)" = "$(sed -n '1p' ../test/cyclicmult_answerkey.txt)" ] && echo True || echo False
[ "$(./cyclicmult < ../test/cyclicmult2.txt)" = "$(sed -n '2p' ../test/cyclicmult_answerkey.txt)" ] && echo True || echo False
[ "$(./cyclicmult < ../test/cyclicmult3.txt)" = "$(sed -n '3p' ../test/cyclicmult_answerkey.txt)" ] && echo True || echo False
rm cyclicmult
