/* file : polynormal.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 30-09-2026 */
/* compile: gcc -std=c99 -Wall -pedantic polynormal.c -o polynormal */

/* Description:
    Writes polynomials in normal form, given a list of coefficients and
   exponents.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void coefPrintFirst(int a, int i);
void coefPrintNonFirst(int a, int i);

int main(int argc, char *argv[]) {
  int coeff[101] = {0}; // up to 100 degrees

  int base, exp;
  char c;

  while (scanf("%d", &base) == 1) {
    if (scanf("%c", &c) != 1) { // end
      coeff[0] += base;         // no power, just a*x⁰ = a
      break;
    }

    if (c == 'x') {
    char next;
    scanf("%c", &next);

    if (next == '^') { // power
        scanf("%d", &exp);
    } else { // it's just a lone x, meaning power of 1
        exp = 1;
        ungetc(next, stdin); // accidentally grabbed the operator
    }
    coeff[exp] += base;
    } else { // no x, means it's just a coefficient a
      coeff[0] += base;

      if (c !=
          '\n') { // if it's not the end, and the %c saw no x, that means it
        // grabbed the next number's operator, so gotta drop it
        ungetc(c, stdin);
      }
    }
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