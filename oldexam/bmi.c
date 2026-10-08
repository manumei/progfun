/* Name:  your name here
 * Student number: your student number here
 * Table: your table number here
 * compile: gcc -std=c99 -Wall -pedantic bmi.c -o bmi
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  // bmi = weightKg / heightMeters**2

  int weightKg, heightCm;
  scanf("%d %d", &weightKg, &heightCm);

  double heightMeters = heightCm / 100.0;
  double bmi = weightKg / (heightMeters * heightMeters);

  if (bmi < 18.5) {
    printf("UNDERWEIGHT\n");
  } else if (bmi < 25.0) {
    printf("HEALTHY\n");
  } else if (bmi < 30) {
    printf("OVERWEIGHT\n");
  } else {
    printf("OBESE\n");
  }

  return 0;
}