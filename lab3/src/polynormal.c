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

void coefPrintFirst(int a, int i);
void coefPrintNonFirst(int a, int i);

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

  bool emptyInput = true;
  bool firstPrint = true;

  for (int i = 100; i > 1; i--) {
    int a = coeff[i];
    if (a != 0) {
      // dont print + for first number
      if (firstPrint) {
        coefPrintFirst(a, i);
        firstPrint = false;
        emptyInput = false;
      } else {
        coefPrintNonFirst(a, i);
        emptyInput = false;
      }
    }
  }

  // special case: for coef 1, print just x, no exponent
  // special case: for coef 0, print just the number, no x
  int oneCoef = coeff[1];
  int absOneCoef = abs(oneCoef);
  if (oneCoef) {
    if (firstPrint) {
      if (absOneCoef == 1) {
        printf("%sx", (oneCoef < 0) ? "-" : "");
      } else {
        printf("%dx", oneCoef);
      }
      emptyInput = false;
    } else {
      char op = (oneCoef > 0) ? '+' : '-';
      if (absOneCoef == 1) {
        printf("%cx", op);
      } else {
        printf("%c%dx", op, absOneCoef);
      }
      emptyInput = false;
    }
  }

  // special case: for coef 0, print just the number, no x
  int zeroCoef = coeff[0];
  if (zeroCoef) {
    if (firstPrint) {
      printf("%d", zeroCoef);
      emptyInput = false;
    } else {
      char op = (zeroCoef > 0) ? '+' : '-';
      printf("%c%d", op, abs(zeroCoef));
      emptyInput = false;
    }
  }

  if (emptyInput) {
    printf("0");
  }
  printf("\n");
}

void coefPrintFirst(int a, int i) {
  // first gets no +
  int absA = abs(a);
  bool neg = (a < 0);
  // if 1, dont print the coef 1
  if (absA == 1) {
    if (neg) {
      printf("-x^%d", i);
    } else {
      printf("x^%d", i);
    }
  } else { // otherwise print coefficient a, but not the +
    if (neg) {
      printf("-%dx^%d", absA, i);
    } else {
      printf("%dx^%d", absA, i);
    }
  }
  return;
}

void coefPrintNonFirst(int a, int i) {
  int absA = abs(a);
  char op = (a > 0) ? '+' : '-';

  // if 1, dont print the coef 1
  if (absA == 1) {
    printf("%cx^%d", op, i);
  } else { // otherwise print coefficient a
    printf("%c%dx^%d", op, absA, i);
  }
  return;
}