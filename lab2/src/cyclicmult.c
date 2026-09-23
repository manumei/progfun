/* file : cyclicmult.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 19-09-2026 */
/* compile: gcc -std=c99 -Wall -pedantic cyclicmult.c -o cyclicmult */

/* Description:
    Find if an integer is a cyclic multiple (all cyclic arrangements of its
   digits share a GCD bigger than 1)
*/

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main(int argc, char *argv[]) {
  // input
  int num;
  scanf("%d", &num);
  int numGcd = num; // starrting out, gcd(a) = a

  int scale = 1; // up to what power of 10
  int digits = 1;

  // get how many digits it has
  while (num / scale >= 10) {
    scale *= 10;
    digits++;
  }

  // iterate through the digits to cycle
  for (int i = 0; i < digits; i++) {
    int firstDigit = num / scale;
    // num % scale removes the first digit
    // multiply by 10 moves the other digits one place to the left
    // adding first_digit moves that to the right side
    // abcd becomes -> bcd*10+a = bcda
    num = (num % scale) * 10 + firstDigit;

    // each round I want gcd(new_num, aux_cpy) where num_gcd gets updated to be
    // the gcd of the previous round, since gcd(a, b, c) = gcd(gcd(a,b), c)
    numGcd = gcd(numGcd, num);
  }

  if (numGcd > 1) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}