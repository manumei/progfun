/* file : mulsum.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 17-09-2026 */
/* compile: gcc -std=c99 -Wall -pedantic mulsum.c -o mulsum */

/* Description:
    Prints whether a number is mulsum (sum of digits equals product of digits)
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int num;
  scanf("%d", &num);

  // first gotta check n==0, otherwise rest of my stuff breaks cause I gotta
  // check n>0 to get the digits, so n=0 doesnt go into my loop, doesnt do the
  // addition and multiplication, and the final if will check that 0=1 which is
  // false, but 0 is indeed a mulsum number (0=0)
  if (num == 0) {
    printf("%s\n", "YES");
    return 0;
  }

  int digit_suma = 0; // adding 0 changes nothing
  int digit_prod = 1; // multiplying by 1 changes nothing

  // extract digits
  for (; num > 0; num /= 10) {
    int digit = num % 10;
    digit_suma += digit; // add each digit in the loop
    digit_prod *= digit; // multiply by each digit in the loop
  }

  // check if sum of digits and product of digits are equal
  char *result = (digit_suma == digit_prod) ? "YES" : "NO";
  printf("%s\n", result);

  return 0;
}