/* Name:  your name here
 * Student number: your student number here
 * Table: your table number here
 * gcc -std=c99 -Wall -pedantic palin.c -o palin
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(char s[], int len) {
  // check if is palindrome
  for (int j = 0; j < len / 2; j++) {
    if (s[j] != s[len - 1 - j]) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  char s[21];
  scanf("%20s", s);
  int len = strlen(s);

  for (int k = 0; k < len; k++) {
    char first = s[0];
    for (int i = 0; i < len - 1; i++) {
      s[i] = s[i + 1];
    }
    s[len - 1] = first;

    if (isPalindrome(s, len)) {
      printf("%s\n", s);
      return 0;
    }
  }
  printf("###\n");
  return 0;
}