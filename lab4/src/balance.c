/* file : balance.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 09-10-2026 */
/* compile: gcc -std=c99 -Wall -pedantic balance.c -o balance */

/* Description:
    Find balance points in matrix
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  int m, n;
  scanf("%d %d", &n, &m);
  int **board = makeIntArray2D(m, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  int balances[n][2];
  bool unbalanced = true;
  int count = 0;

  // m+1 and n+1 to add padding of zeros (avoid edge cases i,j=0)
  int **presum = makeIntArray2D(m + 1, n + 1);
  memset(presum[0], 0, (size_t)(n + 1) * (m + 1) * sizeof(int));

  // do all the sums in O(n*m)
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      presum[i][j] = board[i - 1][j - 1] + presum[i][j - 1] + presum[i - 1][j] -
                     presum[i - 1][j - 1];
    }
  }

  // fetch
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {

      int a = presum[i + 1][j + 1];     // top left
      int b = presum[i + 1][m] - a;     // top right
      int c = presum[n][j + 1] - a;     // bottom left
      int d = presum[n][m] - a - b - c; // bottom right

      if (a == b && b == c && c == d) {
        balances[count][0] = i;
        balances[count][1] = j;
        count++;
        unbalanced = false;
      }
    }
  }

  if (unbalanced) {
    printf("UNBALANCED\n");
  } else {
    for (int h = 0; h < count; h++) {
      printf("%d %d\n", balances[h][0], balances[h][1]);
    }
  }
  destroyIntArray2D(presum);
  destroyIntArray2D(board);

  return 0;
}