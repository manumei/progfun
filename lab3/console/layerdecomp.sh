cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/layerdecomp.c -o layerdecomp -lm
[ "$(./layerdecomp < ../test/layerdecomp1.txt)" = "$(sed -n '1p' ../test/layerdecomp_answerkey.txt)" ] && echo True || echo False
[ "$(./layerdecomp < ../test/layerdecomp2.txt)" = "$(sed -n '2p' ../test/layerdecomp_answerkey.txt)" ] && echo True || echo False
[ "$(./layerdecomp < ../test/layerdecomp3.txt)" = "$(sed -n '3p' ../test/layerdecomp_answerkey.txt)" ] && echo True || echo False
rm layerdecomp
