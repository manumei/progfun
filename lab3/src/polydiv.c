/* file : polydiv.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 1-10-2026 */
/* compile: gcc -std=c99 -Wall -pedantic polydiv.c -o polydiv */

/* Description:
    Divide two polynomials
*/

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int updateCoefs(double cfsP[], int *c) {
  // polynomials close with )
  while (*c != ')') {
    // get the sign
    int sign = 1; // default cause skipped in first if +
    if (*c == '+' || *c == '-') {
      if (*c == '-') {
        sign = -1;
      }
      *c = getchar();
    }
    // get the coefficient
    bool hasDigits = false;
    int coef = 0;
    while (isdigit(*c)) {
      coef = coef * 10 + (*c - '0'); // build char by char
      *c = getchar();
      hasDigits = true;
    }
    if (!hasDigits) // 1x is skipped as just x
      coef = 1;

    int exp = 0; // default no exponential
    if (*c == 'x') {
      exp = 1;
      *c = getchar();
      if (*c == '^') { // got a power
        exp = 0;
        *c = getchar();
        while (isdigit(*c)) { // build char by char
          exp = exp * 10 + (*c - '0');
          *c = getchar();
        }
      }
    }

    // record final value
    cfsP[exp] += sign * coef;
  }
  for (int i = 100; i >= 0; i--) {
    if (cfsP[i] != 0) {
      return i;
    }
  }
  return -1;
}

void printPoly(double coeff[], int size) {
  bool first = true;
  for (int i = size; i >= 0; i--) {
    double a = coeff[i];
    if (a == 0)
      continue;

    if (a < 0) {
      printf("-");
    } else if (!first) {
      printf("+");
    }

    if (fabs(a) != 1.0 || i == 0) // quotient might have fractions
      printf("%g", fabs(a));

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

int main(int argc, char *argv[]) {
  double cfsP1[101] = {0};
  double cfsP2[101] = {0};
  double coeffsQuot[101] = {0};
  int c = getchar(); // '('
  c = getchar();     // skip first '(' for pol1

  // coeffs pol1
  int highExpPol1 = updateCoefs(cfsP1, &c);

  c = getchar();
  if (c != '/') {
    printf("something broke, no slash");
    return -1;
  } else {
    c = getchar();
    if (c != '(') {
      printf("something broke, no ( for pol2");
    } else {
      c = getchar();
    }
  }

  // coeffs pol2
  int highExpPol2 = updateCoefs(cfsP2, &c);

  // divide:
  // get leading term of F(X), divide by leading of G(X), get qu0(x) from it
  // append qu0(x) to the quotient Q(x)
  // do f1(x) = F(X) - qu0(x)*G(X)
  // then f1(x)[lead] / G(X)[lead] -> qu1(x)
  // append qu1(x) to the quotient Q(x)
  // then f2(x) = f1(x) - qu1(x)*G(X)
  // continue until F(X)[lead][exp] < G(X)[lead][exp]

  // division
  bool divisible = true;

  if (highExpPol2 == -1) { // polnyomial 2 is just zero, cant divide by 0
    printf("INDIVISIBLE\n");
    return 0;
  }

  if (highExpPol1 == -1) { // polynomial 1 is just zero, then quotient is 0
    printf("%d\n", 0);
    return 0;
  }

  while (highExpPol1 >= highExpPol2) {
    // get qu(x)
    double quotermCoef = (double)cfsP1[highExpPol1] / cfsP2[highExpPol2];
    int quotermExp = highExpPol1 - highExpPol2;
    coeffsQuot[quotermExp] += quotermCoef; // append term

    // new f
    // multiplying Pol 2 by qu(x) to subtract from Pol 1
    // is moving to the lower side the exp index of Pol 2
    // so for example if quExp=2, the x^63 term becomes x^65, so to subtract
    // from Pol1[65], we take the exp power 2 places higher to match
    for (int i = 0; i + quotermExp <= 100; i++) {
      int newExp = i + quotermExp;
      cfsP1[newExp] -= quotermCoef * (cfsP2[i]);
    }
    // find new highest exp
    for (highExpPol1 = 100; highExpPol1 >= 0; highExpPol1--) {
      if (cfsP1[highExpPol1] != 0) {
        break;
      }
    }
  }

  // check if non-zero remainder
  // now that cfsP1 has been updated to hold what is left post-division
  for (int i = 0; i <= 100; i++) {
    if (cfsP1[i] != 0) {
      divisible = false;
      break;
    }
  }

  if (divisible) {
    printPoly(coeffsQuot, 100);
  } else {
    printf("INDIVISIBLE\n");
  }

  return 0;
}