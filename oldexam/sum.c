/* Name:  your name here
 * Student number: your student number here
 * Table: your table number here
 * gcc -std=c99 -Wall -pedantic sum.c -o sum
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int prev = getchar() - '0';
  int curr;
  int pairSum = 0;
  int moreDigits = 0;

  while ((curr = getchar()) != EOF && curr != '\n') {
    curr -= '0';
    pairSum += prev * curr;
    prev = curr;
    moreDigits++;
  }

  if (!moreDigits) {
    printf("%d %d\n", prev, 0);
    return 0;
  }

  int newNum = pairSum;
  int steps = 1;

  while (newNum > 9) {
    int n = newNum;
    int prev = n % 10;
    n /= 10;
    newNum = 0;

    while (n > 0) {
      int curr = n % 10;
      newNum += prev * curr;

      prev = curr;
      n /= 10;
    }
    steps++;
  }

  printf("%d %d\n", newNum, steps);
  return 0;
}
