/* file : laser.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : TODO: */
/* compile: gcc -std=c99 -Wall -pedantic laser.c -o laser */

/* Description:
    TODO:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char newDirection(char dir, int mirror) {
  if (dir == '^') { // laser comes from below
    return (mirror == 1) ? '>' : '<';
  } else if (dir == 'v') { // laser comes from above
    return (mirror == 1) ? '<' : '>';
  } else if (dir == '<') { // llaser comes from right
    return (mirror == 1) ? 'v' : '^';
  } else if (dir == '>') { // laser comes from left
    return (mirror == 1) ? '^' : 'v';
  }
  return 0;
}

int laserMove(int laser[3], int n, int m, char board[n][m]) {
  char dir = laser[0];
  int row = laser[1];
  int col = laser[2];

  // move
  board[row][col] =
      ((board[row][col] != '\\' && board[row][col] != '/') ? dir
                                                           : board[row][col]);

  if (dir == '^') {
    row--;
  } else if (dir == 'v') {
    row++;
  } else if (dir == '<') {
    col--;
  } else if (dir == '>') {
    col++;
  }

  // went outside
  if ((row >= n) || (col >= m) || (row < 0) || (col < 0)) {
    return 0;
  }

  // if mirror then change dirs; else continue
  if (board[row][col] == '\\') {
    dir = newDirection(dir, -1);
  } else if (board[row][col] == '/') {
    dir = newDirection(dir, 1);
  }

  laser[0] = dir;
  laser[1] = row;
  laser[2] = col;
  return 1;
}

int main(int argc, char *argv[]) {

  // input
  int n, m;
  scanf("%d %d", &n, &m);
  char board[n][m];
  int laser[3]; // [0] stores direction, [1] & [2] store position

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // every char is appended to the board
      char c;
      scanf(" %c", &c);
      if (c == 'v' || c == '>' || c == '<' || c == '^') {
        laser[0] = c;
        laser[1] = i;
        laser[2] = j;
      }
      board[i][j] = c;
    }
  }

  int inside = 1;
  // laser travel
  while (inside) {
    inside = laserMove(laser, n, m, board);
  }

  // print board
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
  return 0;
}