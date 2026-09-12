gcc -std=c99 -Wall -pedantic grade.c -o grade -lm
[ "$(./grade < tests/grade1.txt)" = "8.5" ] && echo True || echo False
[ "$(./grade < tests/grade2.txt)" = "6.5" ]   && echo True || echo False
[ "$(./grade < tests/grade3.txt)" = "6" ]   && echo True || echo False
rm grade