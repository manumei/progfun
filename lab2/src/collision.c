/* file : collision.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 18-09-2026 */
/* compile: gcc -std=c99 -Wall -pedantic collision.c -o collision */

/* Description:
    TODO:
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // variables
  int M, p, q;
  int step = 0;
  scanf("%d %d %d", &M, &p, &q);
  int max_steps = M * 6; // because there are at max (M * LCM(2,3)) outcomes
  // since p changes by factor of 2 and q changes by factor of 3

  while ((p != q) && (step < max_steps)) {
    // Take Step
    p = (2 * p + 1) % M;
    q = (3 * q + 1) % M;
    step++;
  }

  if (p == q) {
    printf("%d: p=q=%d\n", step, p);
  } else {
    printf("No collision\n");
  }

  return 0;
}