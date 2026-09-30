/* file : polynormal.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 30-09-2026 */
/* compile: gcc -std=c99 -Wall -pedantic polynormal.c -o polynormal */

/* Description:
    Writes polynomials in normal form, given a list of coefficients and
   exponents.
*/

#include <ctype.h> // for isdigit
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printPoly(int coeff[]);

int main(int argc, char *argv[]) {
  int coeff[101] = {0}; // up to 100 degrees

  int c = getchar(); // cant use scanf cause x might or might not come with a
                     // coef (so at beginning or after operator I cant know if
                     // next is %c or %d)
  while (c != EOF && c != '\n') {
    int sign = 1; // default cause skipped in first
    if (c == '+' || c == '-') {
      if (c == '-') {
        sign = -1;
      }
      c = getchar();
    }

    int coef = 0;
    bool hasDigits = false;
    while (isdigit(c)) {
      // since cant use scanf, have to manually check for digits
      coef = coef * 10 + (c - '0'); // units, tens, hundreds, etc,
                                    // (c - '0') converts digit char to int
                                    // cause theyre consecutive in ascii
      hasDigits = true;
      c = getchar();
    }
    if (!hasDigits)
      coef = 1; // implicit coefficient: "x^5", "-x"

    int exp = 0; // no x: constant term
    if (c == 'x') {
      exp = 1; // lone x
      c = getchar();
      if (c == '^') {
        exp = 0;
        c = getchar();
        while (isdigit(c)) {
          exp = exp * 10 + (c - '0');
          c = getchar();
        }
      }
    }
    coeff[exp] += sign * coef;
  }
  printPoly(coeff);
  return 0;
}

void printPoly(int coeff[]) {
  bool first = true;
  for (int i = 100; i >= 0; i--) {
    int a = coeff[i];
    if (a == 0)
      continue;

    if (a < 0) {
      printf("-");
    } else if (!first) {
      printf("+");
    }

    if (abs(a) != 1 || i == 0)
      printf("%d", abs(a)); // hide 1, except for constants
    if (i >= 1)
      printf("x");
    if (i >= 2)
      printf("^%d", i);

    first = false;
  }
  if (first)
    printf("0"); // nothing was printed
  printf("\n");
}
