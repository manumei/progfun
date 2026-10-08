cd "$(dirname "$0")"
gcc -std=c99 -Wall -pedantic ../src/balance.c -o balance -lm
[ "$(./balance < ../test/balance1.txt)" = "$(cat ../test/balance1_ans.txt)" ] && echo True || echo False
[ "$(./balance < ../test/balance2.txt)" = "$(cat ../test/balance2_ans.txt)" ] && echo True || echo False
[ "$(./balance < ../test/balance3.txt)" = "$(cat ../test/balance3_ans.txt)" ] && echo True || echo False
rm balance
