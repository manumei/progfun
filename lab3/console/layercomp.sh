cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/layercomp.c -o layercomp -lm
[ "$(./layercomp < ../test/layercomp1.txt)" = "$(sed -n '1p' ../test/layercomp_answerkey.txt)" ] && echo True || echo False
[ "$(./layercomp < ../test/layercomp2.txt)" = "$(sed -n '2p' ../test/layercomp_answerkey.txt)" ] && echo True || echo False
[ "$(./layercomp < ../test/layercomp3.txt)" = "$(sed -n '3p' ../test/layercomp_answerkey.txt)" ] && echo True || echo False
rm layercomp
