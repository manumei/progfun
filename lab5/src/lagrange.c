/* file : lagrange.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 19-10-2026 */
/* compile: gcc -std=c99 -Wall -pedantic lagrange.c -o lagrange */

/* Description:
    Find lagrange squares

    Search space for a:
      {a, b, c, d <= a} so {n =< 4a^2} so {a >= sqrt(n)/2}
      a^2 <= n, so a <= sqrt(n)
      find sqrt of n, a must be smaller or equal than the sqrt rounded down, and
      a must be bigger or equal than [sqrt(n/4)] rounded up
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  double sqrtN = sqrt(n);            // store for faster
  int maxA = (int)sqrtN;             // round down (a^2 cant be bigger than n)
  int minA = (int)ceil(sqrtN / 2.0); // round up (4a^2 cant be smaller than n)
  // int minA = (int)ceil(sqrt(n / 4.0));

  for (int a = minA; a <= maxA; a++) {
    for (int b = 0; b <= a; b++) {
      for (int c = 0; c <= b; c++) {
        int sqA = a * a;
        int sqB = b * b;
        int sqC = c * c;
        int dSquared = n - sqA - sqB - sqC;
        int d = (int)sqrt(dSquared);

        if (d <= c && (n == sqA + sqB + sqC + d * d)) {
          printf("%d^2+%d^2+%d^2+%d^2\n", a, b, c, d);
          return 0;
        }
      }
    }
  }
  return 0;
}