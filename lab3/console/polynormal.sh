cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/polynormal.c -o polynormal -lm
[ "$(./polynormal < ../test/polynormal1.txt)" = "$(sed -n '1p' ../test/polynormal_answerkey.txt)" ] && echo True || echo False
[ "$(./polynormal < ../test/polynormal2.txt)" = "$(sed -n '2p' ../test/polynormal_answerkey.txt)" ] && echo True || echo False
[ "$(./polynormal < ../test/polynormal3.txt)" = "$(sed -n '3p' ../test/polynormal_answerkey.txt)" ] && echo True || echo False
rm polynormal
