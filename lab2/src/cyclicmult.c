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
  printf("Hallo Welt!\n");
  return 0;
}