/* file : palindrome.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 11-09-2026 */
/* version: 1.0 */
/* compile: gcc -std=c99 -Wall -pedantic palindrome.c -o palindrome */

/* Description:
    Checks if a given number is a palindrome
*/

#include <stdio.h>
#include <stdlib.h>

int is_palindromable(int num);

int main(int argc, char *argv[]) {

  // input
  int num;
  scanf("%d", &num);

  int palindrome_approved = is_palindromable(num);
  printf("%s\n", palindrome_approved ? "YES" : "NO");

  return 0;
}

int is_palindromable(int num) {
  // reverse the number
  int d1 = (num / 100) % 10;
  int d2 = (num / 10) % 10;
  int d3 = num % 10;

  if ((d3 != 0) && (d1 == d3 || d1 == d2 || d2 == d3)) {
    return 1;
  } else {
    return 0;
  }
}