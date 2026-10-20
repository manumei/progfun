/* file : equalizer.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 19-10-2026 */
/* compile: gcc -std=c99 -Wall -pedantic equalizer.c -o equalizer */

/* Description:
    Equalize array
*/

#include <stdbool.h>
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

int **makeIntArray2D(int width, int height) {
  int **arr = safeMalloc(height * sizeof(int *));
  arr[0] = safeMalloc(width * height * sizeof(int));
  for (int row = 1; row < height; row++) {
    arr[row] = arr[row - 1] + width;
  }
  return arr;
}

void destroyIntArray2D(int **arr) {
  free(arr[0]);
  free(arr);
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int *arr = safeMalloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int i = 0; // index(not iter whole thing every time, only from relevant point)
  while (i < n) {
    if ((i > 0 && arr[i] - arr[i - 1] >= 2) ||
        (i < n - 1 && arr[i] - arr[i + 1] >= 2)) {

      // find smallest neighbor, either edge element or left if tie
      int neighbor;
      if (i == 0) {
        neighbor = 1;
      } else if (i == n - 1) {
        neighbor = n - 2;
      } else if (arr[i - 1] <= arr[i + 1]) {
        neighbor = i - 1;
      } else {
        neighbor = i + 1;
      }

      // decrease & add
      arr[i]--;
      arr[neighbor]++;

      // gotta check if can be equalized again after new values
      if (i > 0) {
        i--;
      }
    } else { // no equalizing here NOR earlier, move forward
      i++;
    }
  }

  // array printing
  printf("[");
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      printf(",");
    }
    printf("%d", arr[i]);
  }
  printf("]\n");

  free(arr);
  return 0;
}