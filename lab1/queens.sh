gcc -std=c99 -Wall -pedantic queens.c -o queens -lm
[ "$(./queens < tests/queens1.txt)" = "YES" ] && echo True || echo False
[ "$(./queens < tests/queens2.txt)" = "YES" ]   && echo True || echo False
[ "$(./queens < tests/queens3.txt)" = "NO" ]   && echo True || echo False
rm queens