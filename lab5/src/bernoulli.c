/* file : bernoulli.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 21-10-2026 */
/* compile: gcc -std=c99 -Wall -pedantic bernoulli.c -o bernoulli */

/* Description:
    bernoulli pyramid (modulus)
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
  int a, b, m;
  scanf("%d %d %d", &a, &b, &m);
  int *row = safeMalloc(b * sizeof(int)); // keep one row and update it
  row[0] = 1;

  // width = digits of (m-1)
  int width = 0;
  for (int value = m - 1; value > 0; value /= 10) {
    width++;
  }

  for (int n = 1; n <= b; n++) {
    if (n > 1) {
      row[n - 1] = (2 * row[n - 2]) % m; // right most doubles in each row

      // get new row values
      for (int j = n - 2; j >= 1; j--) {
        row[j] = (row[j - 1] + row[j]) % m;
      }
    }
    if (n < a) {
      continue;
    }

    // print in place (so no need to store all rows)
    for (int j = 0; j < n; j++) {
      if (j > 0) {
        printf(" ");
      }
      // # padding
      int digits = 1;
      for (int value = row[j]; value >= 10; value /= 10) {
        digits++;
      }
      for (int padding = digits; padding < width; padding++) {
        printf("#");
      }

      printf("%d", row[j]);
    }
    printf("\n");
  }

  free(row);
  return 0;
}
