cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/othello.c -o othello -lm
[ "$(./othello < ../test/othello1.txt)" = "$(cat ../test/othello1_ans.txt)" ] && echo True || echo False
[ "$(./othello < ../test/othello2.txt)" = "$(cat ../test/othello2_ans.txt)" ] && echo True || echo False
[ "$(./othello < ../test/othello3.txt)" = "$(cat ../test/othello3_ans.txt)" ] && echo True || echo False
rm othello
