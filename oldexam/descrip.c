/* Name:  your name here
 * Student number: your student number here
 * Table: your table number here
 * gcc -std=c99 -Wall -pedantic descrip.c -o descrip
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n, s;
  scanf("%d %d", &n, &s);

  // max digits is 964, max pairs is 482
  int pairs[482][2];
  int iter = 0;

  if (s == 0) {
    printf("%d", n);
    return 0;
  }

  int len, ;

  // how to represent final output -> for loop print the pairs
  while (i < len) {
    char digit = current[i];
    int count = 0;

    while (i < len && current[i] == digit) {
      count++;
      i++;
    }

    // append count
    // append digit
  }
}
return 0;
}
