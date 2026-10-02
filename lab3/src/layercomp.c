/* file : layercomp.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 01-10-2026 */
/* compile: gcc -std=c99 -Wall -pedantic layercomp.c -o layercomp */

/* Description:
    Compose array based on layers
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int len;
  scanf("%d", &len);

  int arr[len];
  for (int i = 0; i < len; i++) {
    arr[i] = 0;
  }

  // add (delta) blocks on every layer (order irrelevant)
  int first, last, delta;
  while (scanf("%d %d %d", &first, &last, &delta) == 3) {
    for (int j = first; j <= last; j++) {
      arr[j] += delta;
    }
  }

  printf("%d\n", len);
  for (int i = 0; i < len; i++) {
    // no whitespace at the end (or breaks)
    if (i > 0) {
      printf(" ");
    }
    printf("%d", arr[i]);
  }
  printf("\n");

  return 0;
}