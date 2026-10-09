/* file : othello.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 09-10-2026 */
/* compile: gcc -std=c99 -Wall -pedantic othello.c -o othello */

/* Description:
    TODO:
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool withinBounds(int r, int c) { return (r >= 0 && r < 8 && c >= 0 && c < 8); }

int main(int argc, char *argv[]) {
  char row;
  int col;

  // starting board: 0 = empty, B = black, W = white
  char board[8][8] = {0};

  board[3][3] = 'W';
  board[4][4] = 'W';
  board[3][4] = 'B';
  board[4][3] = 'B';

  // manage turns
  int turnNum = 0;
  char turn;

  while (scanf(" %c%d", &row, &col) == 2) {
    // indices for board
    int r = col - 1;
    int c = row - 'a';

    // play
    turn = (turnNum % 2 == 0) ? 'B' : 'W';
    board[r][c] = turn;

    for (int i = r - 1; i <= r + 1; i++) {
      for (int j = c - 1; j <= c + 1; j++) {

        // skip itself
        if (i == r && j == c) {
          continue;
        }

        // bounds
        if (!withinBounds(i, j)) {
          continue;
        }

        // dir to follow on the neighbor to enclose
        int dir[2];
        dir[0] = i - r;
        dir[1] = j - c;

        int newr = i;
        int newc = j;
        int link = 0;
        bool flips = false;

        // walk through consecutive opponent stones
        while (withinBounds(newr, newc) && board[newr][newc] != 0 &&
               board[newr][newc] != turn) {
          link++;
          newr += dir[0];
          newc += dir[1];
        }

        // check if it closed with a same-color
        if (link > 0 && withinBounds(newr, newc) && board[newr][newc] == turn) {
          flips = true;
        }

        if (flips) {
          for (int f = 1; f <= link; f++) {
            board[r + (f * dir[0])][c + (f * dir[1])] = turn;
          }
        }
      }
    }
    turnNum++;
  }

  // Print the final board.
  for (int i = 0; i < 8; i++) {
    printf("%d", i + 1);
    for (int j = 0; j < 8; j++) {
      printf("%c", board[i][j] ? board[i][j] : '.');
    }
    printf("\n");
  }
  printf(" abcdefgh\n");
  return 0;
}