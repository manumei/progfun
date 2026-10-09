/* file : othello.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 09-10-2026 */
/* compile: gcc -std=c99 -Wall -pedantic othello.c -o othello */

/* Description:
    TODO:
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char row;
  int col;

  // starting board
  bool board[8][8];
  board[3][3] = true;  // W
  board[4][4] = true;  // W
  board[3][4] = false; // B
  board[4][3] = false; // B

  // manage turns
  int turnNum = 0;
  bool turn;

  while (scanf(" %c%d", &row, &col) == 2) {
    // indices for board
    int r = row - 'a';
    int c = col - 1;
    turn = (turnNum % 2); // Black (false) or White (true)

    // move
    board[r][c] = turn;

    // check neighbors, link=0, then for each neighbor
    // neighbors are
    // board[r-1][c-1]
    // board[r-1][c]
    // board[r-1][c+1]
    // board[r][c-1]
    // board[r][c+1]
    // board[r+1][c-1]
    // board[r+1][c]
    // board[r+1][c+1]

    bool diff, curr, neig;
    int dir[2];
    for (int i = r - 1; i == r + 1; i++) {
      for (int j = c - 1; j == c + 1; j++)
        if ((i == r && c == j) || (r == 0) || (r == 7) || (c == 0) ||
            (c == 7)) {
          curr = board[i][j];
          neig = board[r][c];
          // if i > r, dir is row++, if i < r, dir is row--, same for j & col
          dir[0] = i - r;
          dir[1] = j - c;

          while (curr != neig) {
          }
        }
    }

    // if neighbor!=current -> link++ and check its same-dir neighbor
    // if neighbor==current -> if link>0, then go back the link and flip em
    // can do this with a while(neighbor!=current)
    turn++;
  }

  return 0;
}