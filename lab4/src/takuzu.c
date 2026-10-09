/* file : takuzu.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 09-10-2026 */
/* compile: gcc -std=c99 -Wall -pedantic takuzu.c -o takuzu */

/* Description:
    Conway's takuzu
    - if two consecutive are equal, surround with opposites
    - if two equal with one empty in between, fill with opposite
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

char **makeCharArray2D(int width, int height) {
  char **arr = safeMalloc(height * sizeof(char *));
  arr[0] = safeMalloc(width * height * sizeof(char));
  for (int row = 1; row < height; row++) {
    arr[row] = arr[row - 1] + width;
  }
  return arr;
}

/* free a 2D dynamic array */
void destroyIntArray2D(char **arr) {
  free(arr[0]);
  free(arr);
}

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d %d", &n, &m);
  char **board = makeCharArray2D(m, n);
  char **next = makeCharArray2D(m, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &board[i][j]);
    }
  }

  int iters = 0;
  bool changed = true;

  while (changed) {
    changed = false;

    // Copy board to next
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        next[i][j] = board[i][j];
      }
    }

    // Check horizontal groups of 3
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m - 2; j++) {
        char a = board[i][j];
        char b = board[i][j + 1];
        char c = board[i][j + 2];

        // N-N-empty
        if (a != '.' && a == b && c == '.') {
          next[i][j + 2] = (a == '1') ? '0' : '1';
          changed = true;
        }

        // empty-N-N
        if (a == '.' && b != '.' && b == c) {
          next[i][j] = (b == '1') ? '0' : '1';
          changed = true;
        }

        // N-empty-N
        if (a != '.' && a == c && b == '.') {
          next[i][j + 1] = (a == '1') ? '0' : '1';
          changed = true;
        }
      }
    }

    // Check vertical groups of 3
    for (int i = 0; i < n - 2; i++) {
      for (int j = 0; j < m; j++) {
        char a = board[i][j];
        char b = board[i + 1][j];
        char c = board[i + 2][j];

        // N-N-empty
        if (a != '.' && a == b && c == '.') {
          next[i + 2][j] = (a == '1') ? '0' : '1';
          changed = true;
        }

        // empty-N-N
        if (a == '.' && b != '.' && b == c) {
          next[i][j] = (b == '1') ? '0' : '1';
          changed = true;
        }

        // N-empty-N
        if (a != '.' && a == c && b == '.') {
          next[i + 1][j] = (a == '1') ? '0' : '1';
          changed = true;
        }
      }
    }

    if (changed) {
      iters++;
    }

    // update board
    char **temp = board;
    board = next;
    next = temp;
  }

  printf("%d", iters);

  return 0;
}