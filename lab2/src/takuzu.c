/* file : takuzu.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 17-09-2026 */
/* compile: gcc -std=c99 -Wall -pedantic takuzu.c -o takuzu */

/* Description:
    Prints whether a number is takuzu (no 3 consecutive equal bits in binary
   representation)
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned int n;
  scanf("%u", &n);

  // aux counters
  int cons_zeros = 0;
  int cons_ones = 0;

  // count digits
  while ((n > 0) && (cons_zeros < 3) && (cons_ones < 3)) {
    unsigned int digit = n % 2; // they are in reverse but doesn't matter
    n /= 2;                     // keep going down binary bases until 0

    // if it's a zero, reset consecutive 1s and add one to the 0s
    if (digit == 0) {
      cons_zeros++;
      cons_ones = 0;
    } else { // viceversa if it's a 1
      cons_zeros = 0;
      cons_ones++;
    }
  }

  // takuzu if it doesnt have 3 consecutives
  if ((cons_zeros == 3) || (cons_ones == 3)) {
    printf("%s\n", "NO");
  } else {
    printf("%s\n", "YES");
  }

  return 0;
}