/* file : balance.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 09-10-2026 */
/* compile: gcc -std=c99 -Wall -pedantic balance.c -o balance */

/* Description:
    TODO:
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int sumQuad(int n, int m, int board[n][m], int rs, int re, int cs, int ce) {
  int sum = 0;
  for (int i = rs; i <= re; i++) {
    for (int j = cs; j <= ce; j++) {
      sum += board[i][j];
    }
  }
  return sum;
}

int main(int argc, char *argv[]) {
  int m, n;
  scanf("%d %d", &n, &m);
  int board[n][m];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  int balances[n][2];
  bool unbalanced = true;
  int count = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      // proba sumar top quadrant
      int a = sumQuad(n, m, board, 0, i, 0, j);
      int b = sumQuad(n, m, board, 0, i, j + 1, m - 1);
      int c = sumQuad(n, m, board, i + 1, n - 1, 0, j);
      int d = sumQuad(n, m, board, i + 1, n - 1, j + 1, m - 1);

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

  return 0;
}