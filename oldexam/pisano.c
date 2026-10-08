/* Name:  your name here
 * Student number: your student number here
 * Table: your table number here
 * gcc -std=c99 -Wall -pedantic pisano.c -o pisano
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int fib(int n, int m) {
  if (n <= 1) {
    return n;
  } else {
    return (fib(n - 1, m) + fib(n - 2, m)) % m;
  }
}

int main(int argc, char *argv[]) {
  // you get the modulus
  int m;
  scanf("%d", &m);

  // how many fibonnaccis do you need to run? that's the key
  // m squared because a & b can have m values each
  // projects as much as m**2 pairs

  int prev = 0;
  int curr = 1;

  bool zero = false; // save if a 0 shows up
  for (int i = 1; i <= m * m; i++) {
    int next = (prev + curr) % m;
    prev = curr;
    curr = next;

    if (prev == 0 && curr == 1) {
      printf("%d\n", i);
      break;
    }
  }

  return 0;
}