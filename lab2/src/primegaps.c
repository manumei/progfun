/* file : primegaps.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 18-09-2026 */
/* compile: gcc -std=c99 -Wall -pedantic primegaps.c -o primegaps */

/* Description:
  Finds pair of consecutive primes (p,q) with the smallest p such that (q - p)
  >= n, where n is a positive integer given as input.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPrime(int n) {
  bool prime;
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

  // case where p is 2, q would be 3 and thus n should be 1
  // to avoid checking even values for p in in the while loop
  if (n == 1) {
    p = 2;
    q = 3;
    printf("%d: %d %d\n", q - p, p, q);
    return 0;
  }

  // set starting prime (odd)
  p = 3;

  // case where p is odd
  while (true) {
    for (q = p + 2; !isPrime(q); q += 2) {
      // keep running until not(isPrime(q)) becomes false,
      // meaning keep running until q is prime, so it's the consecutive prime
      ;
    }

    if (q - p >= n) {
      break;
    }

    // move p to the next prime (which I already found at q)
    p = q;
  }

  printf("%d: %d %d\n", q - p, p, q);
  return 0;
}