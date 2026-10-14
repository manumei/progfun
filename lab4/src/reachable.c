/* file : reachable.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 14-10-2026 */
/* compile: gcc -std=c99 -Wall -pedantic reachable.c -o reachable */

/* Description:
    Gotta reach end without blocked by #s

    go from right to left cause column needs to know if the cells on the RIGHT
    are free (if I go left to right, gotta spend more searches or recursion)
    it's like cheating in those maze games by tracing from the exit instead of
    the entrance xd
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

char **makeCharArray2D(int width, int height) {
  char **arr = safeMalloc(height * sizeof(char *));
  arr[0] = safeMalloc(width * height * sizeof(char));
  for (int row = 1; row < height; row++) {
    arr[row] = arr[row - 1] + width;
  }
  return arr;
}

/* free a 2D dynamic array */
void destroyCharArray2D(char **arr) {
  free(arr[0]);
  free(arr);
}

bool withinBounds(int r, int n) { return (r >= 0 && r < n); }

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

  // next is a boolean matrix (1=reachable, 0=not-reachable)
  for (int r = 0; r < n; r++) {
    next[r][m - 1] = (board[r][m - 1] == '.');
  }

  // as explained before, right to left
  for (int c = m - 2; c >= 0; c--) {
    for (int r = 0; r < n; r++) {

      // # is blocked
      if (board[r][c] == '#') {
        next[r][c] = false;
        continue;
      }

      // Check the three positions
      bool reachable = false;
      for (int d = -1; d <= 1; d++) {
        int newr = r + d;
        if (withinBounds(newr, n) && next[newr][c + 1]) {
          reachable = true;
          break;
        }
      }
      next[r][c] = reachable;
    }
  }

  // print all rows with a viable path
  bool path = false;
  for (int r = 0; r < n; r++) {
    if (next[r][0]) {

      if (path) { // space betwewn prints for the other rows
        printf(" ");
      }

      printf("%d", r);
      path = true;
    }
  }
  if (!path) {
    printf("IMPOSSIBLE");
  }
  printf("\n");

  // free
  destroyCharArray2D(board);
  destroyCharArray2D(next);
  return 0;
}