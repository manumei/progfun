/* Name:  your name here
 * Student number: your student number here
 * Table: your table number here
 * gcc -std=c99 -Wall -pedantic descrip.c -o descrip
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n, s;
  scanf("%d %d", &n, &s);

  char current[965];
  char next[965];

  // turn starting number into a string
  sprintf(current, "%d", n);

  int len = strlen(current);

  // apply transformation s times
  for (int step = 0; step < s; step++) {
    int i = 0;
    int newLen = 0;

    while (i < len) {
      char digit = current[i];
      int count = 0;

      // count how many identical digits in a row
      while (i < len && current[i] == digit) {
        count++;
        i++;
      }

      // write the count into next[]
      char countStr[10];
      sprintf(countStr, "%d", count);

      for (int j = 0; countStr[j] != '\0'; j++) {
        next[newLen] = countStr[j];
        newLen++;
      }

      // write the digit itself
      next[newLen] = digit;
      newLen++;
    }

    // terminate next as a proper string
    next[newLen] = '\0';

    // copy next back into current
    strcpy(current, next);

    len = newLen;
  }

  printf("%s\n", current);

  return 0;
}