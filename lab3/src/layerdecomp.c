/* file : layerdecomp.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 01-10-2026 */
/* compile: gcc -std=c99 -Wall -pedantic layerdecomp.c -o layerdecomp */

/* Description:
  Decompose array into layers

  n                = array length (first input line)
  arr[n]           = the input values
  stackH[n + 1]    = heights of open layers (idx 0 is ground) // to open
  stackS[n + 1]    = start index of each open layer
  top              = index of top of stack
  current          = height at pos (0 when pos == n) // to close
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  // build array
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("%d\n", n);

  int stackH[n + 1], stackS[n + 1];
  for (int i = 0; i <= n; i++) {
    stackH[i] = 0;
    stackS[i] = 0;
  }
  int current, first, last, delta;
  int top = 0;

  for (int pos = 0; pos <= n; pos++) {
    current = (pos < n) ? arr[pos] : 0;

    // if current is a dip, gotta break
    while (stackH[top] > current) {
      // layer ends (get the values)
      first = stackS[top];
      last = pos - 1;

      int below = stackH[top - 1]; // trace back to see if current can go on top
      if (below >= current) {      // layer below also ends
        delta = stackH[top] - below;
        printf("%d %d %d\n", first, last, delta);
        top--;
      } else { // current lands inside top layer
        delta = stackH[top] - current;
        printf("%d %d %d\n", first, last, delta);
        stackH[top] = current; // lower part stays open, same start
      }
    }

    // if theyre equal, do nothing, pos++ and continue

    // if current is a step up, mark it on the stack
    if (current > stackH[top]) {
      top++;
      stackH[top] = current;
      stackS[top] = pos;
    }
  }

  //
  return 0;
}