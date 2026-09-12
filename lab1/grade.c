/* file : grade.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 12-09-2026 */
/* compile: gcc -std=c99 -Wall -pedantic grade.c -o grade */

/* Description:
    Calculates final course grade as weighted average
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int g1, g2, g3;
  int w1, w2, w3;

  scanf("%d %d %d", &g1, &g2, &g3);
  scanf("%d %d %d", &w1, &w2, &w3);

  // weighted average
  double grade = (g1 * w1 + g2 * w2 + g3 * w3) / 100.0;

  // round to nearest 0.5 --> multiply by 2, round to nearest int, divide by 2
  grade = 2 * grade;
  double rounded = round(grade) / 2.0;

  if (rounded == 5.5) {
    rounded = 6.0;
  }

  // print with %g to print float but remove trailing zeros (error if "6.0" when
  // answer is "6")
  printf("%g\n", rounded);

  return 0;
}