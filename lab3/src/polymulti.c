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

void update_coefs(int coeffs_pol[], int *c) {
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
    coeffs_pol[exp] += sign * coef;
    *c = getchar();
  }
  return;
}

int main(int argc, char *argv[]) {
  int coeffs_prod[201] = {0}; // up to 200 degrees (100+100)
  int coeffs_pol1[101] = {0}; // up to 100
  int coeffs_pol2[101] = {0};
  int c = getchar(); // the first '('

  // 1st polynomial

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

  // pol 2, repeat process
  while (c != ')') {
    // update pol1 coeffs
    c = getchar();
  }

  return 0;
}