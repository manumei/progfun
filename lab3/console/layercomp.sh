cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/layercomp.c -o layercomp -lm
[ "$(./layercomp < ../test/layercomp1.txt)" = "$(cat ../test/layercomp1_answer.txt)" ] && echo True || echo False
[ "$(./layercomp < ../test/layercomp2.txt)" = "$(cat ../test/layercomp2_answer.txt)" ] && echo True || echo False
[ "$(./layercomp < ../test/layercomp3.txt)" = "$(cat ../test/layercomp3_answer.txt)" ] && echo True || echo False
rm layercomp
