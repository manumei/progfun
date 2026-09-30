/* file : polymulti.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : TODO: */
/* compile: gcc -std=c99 -Wall -pedantic polymulti.c -o polymulti */

/* Description:
    TODO:
*/

#include <ctype.h> // for isdigit
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void updateCoefs(int coeffsPol[], int *c) {
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
    coeffsPol[exp] += sign * coef;
  }
  return;
}

void printPoly(int coeff[], int size) {
  bool first = true;
  for (int i = size; i >= 0; i--) {
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

int main(int argc, char *argv[]) {
  int coeffsProd[201] = {0}; // up to 200 degrees (100+100)
  int coeffsPol1[101] = {0}; // up to 100
  int coeffsPol2[101] = {0};
  int c = getchar();
  c = getchar(); // skip first '('

  // 1st polynomial
  updateCoefs(coeffsPol1, &c); // fill in the first polynomial's coefficients

  // get through the multiplication
  c = getchar();
  if (c != '*') {
    printf("something broke, no asterisc");
    return -1;
  } else {
    c = getchar();
    if (c != '(') {
      printf("something broke, no ( for pol2");
    } else {
      c = getchar();
    }
  }

  // 2nd polynomial
  updateCoefs(coeffsPol2, &c); // fill in the first polynomial's coefficients

  // multiplication
  for (int i = 100; i >= 0; i--) {
    int coef1 = coeffsPol1[i];
    if (coef1) { // if not zero
      for (int j = 100; j >= 0; j--) {
        int coef2 = coeffsPol2[j];
        if (coef2) { // if not zero
          int newExp = i + j;
          int newCoef = coef1 * coef2;
          coeffsProd[newExp] += newCoef;
        }
      }
    }
  }

  printPoly(coeffsProd, 200);
  return 0;
}