cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/collision.c -o collision -lm
[ "$(./collision < ../test/collision1.txt)" = "$(sed -n '1p' ../test/collision_answerkey.txt)" ] && echo True || echo False
[ "$(./collision < ../test/collision2.txt)" = "$(sed -n '2p' ../test/collision_answerkey.txt)" ] && echo True || echo False
[ "$(./collision < ../test/collision3.txt)" = "$(sed -n '3p' ../test/collision_answerkey.txt)" ] && echo True || echo False
rm collision
