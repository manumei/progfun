/* file : primegaps.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 18-09-2026 */
/* compile: gcc -std=c99 -Wall -pedantic primegaps.c -o primegaps */

/* Description:

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int isPrime(n) {
  int n;
  bool prime;
  scanf("%d", &n);
  int a = 3, sq = 9;
  while (sq <= n) {
    if (n % a == 0) {
      break; // n is not a prime
    }
    sq += 4 * a + 4;
    a += 2;
  }
  prime = ((n == 2) || ((n >= 2) && (n % 2) && (sq > n)) ? true : false);
  return prime;
}

int main(int argc, char *argv[]) {

  int q, p, n;
  scanf("%d", &n);
  p = 2;

  while ((p < q) && (q - p >= n)) {
  }

  return 0;
}