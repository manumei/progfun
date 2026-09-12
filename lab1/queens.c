/* file : queens.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 12-09-2026 */
/* compile: gcc -std=c99 -Wall -pedantic queens.c -o queens */

/* Description:
    Finds if two queens can attack each other
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char q1c, q2c; // columns
  int q1r, q2r;  // rows
  scanf("%c%d %c%d", &q1c, &q1r, &q2c, &q2r);

  char *attackable; // string for answer

  // convert columns to 1-8 range (with ascii, since theyre consecutive in the
  // ascii table)
  q1c = q1c - 'a' + 1; // +1 so a is 1
  q2c = q2c - 'a' + 1;

  // can attack? same col OR same row OR same diagonal
  if (q1c == q2c) {
    attackable = "YES";
  } else if (q1r == q2r) {
    attackable = "YES";
  } // they're in the same diagonal when the absolute distance between cols is
    // the same as the absolute distance between rows
  else if (abs(q1c - q2c) == abs(q1r - q2r)) {
    attackable = "YES";
  } else {
    attackable = "NO";
  }
  printf("%s\n", attackable);

  return 0;
}