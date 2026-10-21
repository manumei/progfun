/* file : powerful.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 21-10-2026 */
/* compile: gcc -std=c99 -Wall -pedantic powerful.c -o powerful */

/* Description:
    2^n in scientific notation
*/

#include <stdio.h>
#include <stdlib.h>

void *safeMalloc(int n) {
  void *p = malloc(n);
  if (p == NULL) {
    printf("Error: malloc(%d) failed. Out of memory?\n", n);
    exit(EXIT_FAILURE);
  }
  return p;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int steps = abs(n);
  int multiplier =
      (n < 0) ? 5 : 2; // divide by 2 (meaning mult by 5/10 for negatives)

  int *digits = safeMalloc(
      (steps) * sizeof(int)); // more than enough allocation since 5^n, has at
                              // most n*log10(5)+1 digits, ~6990 for n=10000
  digits[0] = 1;
  int length = 1;

  // calculate 2^n if positive, 5^(-n) if negative
  for (int step = 0; step < steps; step++) {
    int carry = 0;

    for (int i = 0; i < length; i++) {
      int value = digits[i] * multiplier + carry;
      // transform to scientific
      digits[i] = value % 10;
      carry = value / 10;
    }
    if (carry) {
      digits[length] = carry;
      length++;
    }
  }

  int exponent = length - 1;

  if (n < 0) {
    exponent += n; // {(10^a / 10^(-b)) = 10^(a+b)}
  }

  printf("%d", digits[length - 1]);
  if (length > 1) {
    printf(".");
    for (int i = length - 2; i >= 0; i--) {
      printf("%d", digits[i]);
    }
  }
  printf("*10^%d\n", exponent);

  free(digits);
  return 0;
}
