/* file : paper.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 11-09-2026 */
/* version: 1.0 */
/* compile: gcc -std=c99 -Wall -pedantic paper.c -o paper */

/* Description:
    Calculates number of packs needed for exam papers
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // declare
  int exams_num;
  int sheets_per_exam;
  int pages_per_pack;

  // read input
  scanf("%d %d %d", &exams_num, &sheets_per_exam, &pages_per_pack);

  // variables
  int pages_total = exams_num * sheets_per_exam;
  int packs_needed = 0;

  // calculate packs needed
  if (pages_per_pack > 0) { // packages need to actually have pages
    packs_needed = (pages_total + pages_per_pack - 1) /
                   pages_per_pack; // Ceiling [a, b] is [a + b - 1] // b
  }

  // end
  printf("%d\n", packs_needed);
  return 0;
}