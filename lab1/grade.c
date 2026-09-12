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

  float grade = (g1 * w1 + g2 * w2 + g3 * w3) / 100;

  grade = 2 * grade;
  float rounded = roundf(grade) / 2.0f;
  return rounded;

  return 0;
}