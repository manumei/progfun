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

void coef_print_first(int a, int i);
void coef_print_nonfirst(int a, int i);

int main(int argc, char *argv[]) {
  int coeff[101] = {0}; // up to 100 degrees

  int base, exp;
  char c;

  while (scanf("%d", &base) == 1) {
    if (scanf("%c", &c) != 1) { // end
      coeff[0] += base;         // no power, just a*x⁰ = a
      break;
    }

    if (c == 'x') { // x shows up, means prev %d is coefficient and next %d
                    // after ^ is the exponential
      scanf("^%d", &exp);
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

  bool first_print = true;

  for (int i = 100; i > 0; i--) {
    int a = coeff[i];
    if (a != 0) {
      // dont print + for first number
      if (first_print) {
        coef_print_first(a, i);
        first_print = false;
      } else {
        coef_print_nonfirst(a, i);
      }
    }
  }

  int zero_coef = coeff[0];
  if (zero_coef) {
    if (first_print) {
      printf("%d", zero_coef);
    } else {
      char op = (zero_coef > 0) ? '+' : '-';
      printf("%c%d", op, abs(zero_coef));
    }
  }

  printf("\n");
}

void coef_print_first(int a, int i) {
  // first gets no +
  int abs_a = abs(a);
  bool neg = (a < 0);
  // if 1, dont print the coef 1
  if (abs_a == 1) {
    if (neg) {
      printf("-x^%d", i);
    } else {
      printf("x^%d", i);
    }
  } else { // otherwise print coefficient a, but not the +
    if (neg) {
      printf("-%dx^%d", abs_a, i);
    } else {
      printf("%dx^%d", abs_a, i);
    }
  }
  return;
}

void coef_print_nonfirst(int a, int i) {
  int abs_a = abs(a);
  char op = (a > 0) ? '+' : '-';

  // if 1, dont print the coef 1
  if (abs_a == 1) {
    printf("%cx^%d", op, i);
  } else { // otherwise print coefficient a
    printf("%c%dx^%d", op, abs_a, i);
  }
  return;
}