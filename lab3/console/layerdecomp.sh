cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/layerdecomp.c -o layerdecomp -lm
[ "$(./layerdecomp < ../test/layerdecomp1.txt)" = "$(cat ../test/layerdecomp1_ans.txt)" ] && echo True || echo False
[ "$(./layerdecomp < ../test/layerdecomp2.txt)" = "$(cat ../test/layerdecomp2_ans.txt)" ] && echo True || echo False
[ "$(./layerdecomp < ../test/layerdecomp3.txt)" = "$(cat ../test/layerdecomp3_ans.txt)" ] && echo True || echo False
rm layerdecomp
