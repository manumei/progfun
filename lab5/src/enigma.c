/* file : enigma.c */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 20-10-2026 */
/* compile: gcc -std=c99 -Wall -pedantic enigma.c -o enigma */

/* Description:
    TODO:
*/

#include <stdio.h>
#include <stdlib.h>

void *safeMalloc(int n) {
  void *p = malloc(n);
  if (p == NULL) {
    printf("Error: malloc(%d) failed. Out of memory?\n", n);
    exit(EXIT_FAILURE);
  }
  return p;
}

int main(int argc, char *argv[]) {
  int capacity = 128; // base size (can make it longer if I need)
  int length = 0;
  char *text = safeMalloc(capacity);
  int ch;

  while ((ch = getchar()) != '\n' && ch != EOF) {
    // idk how long the array will be, so make longer
    if (length == capacity - 1) {
      capacity *= 2;
      char *larger = safeMalloc(capacity);

      for (int i = 0; i < length; i++) {
        larger[i] = text[i];
      }

      free(text);
      text = larger;
    }

    text[length++] = (char)ch;
  }

  // make the text a printable string
  text[length] = '\0';

  int k, r;
  scanf("%d %d", &k, &r);

  int plugboard[26]; // 26 alphabet letters, at start each maps to itself
  for (int i = 0; i < 26; i++) {
    plugboard[i] = i;
  }

  // k <= 13 pairs (26/2 letters)
  char pairs[13][2];
  for (int i = 0; i < k; i++) {
    scanf(" %c%c", &pairs[i][0], &pairs[i][1]);

    // chars to ints to change them around
    int first = pairs[i][0] - 'A';
    int second = pairs[i][1] - 'A';

    plugboard[first] = second;
    plugboard[second] = first;
  }

  int *initial = safeMalloc(r * sizeof(int)); // to print
  int *rotors = safeMalloc(r * sizeof(int));  // to check if I need to carry

  // rotors
  int shift = 0;
  for (int i = 0; i < r; i++) {
    scanf("%d", &initial[i]);
    rotors[i] = initial[i];
    shift = (shift + rotors[i]) % 26; // combined shift of all
  }

  // pass through the rotos
  for (int i = 0; i < length; i++) {
    int letter = text[i] - 'A';

    letter = plugboard[letter];          // plug
    letter = (letter + shift) % 26;      // forward r
    letter = 25 - letter;                // reflect
    letter = (letter - shift + 26) % 26; // return r (+26 for positive wrapping)
    letter = plugboard[letter];          // plug
    text[i] = (char)(letter + 'A');

    // advance rotors
    for (int j = 0; j < r; j++) {
      rotors[j] = (rotors[j] + 1) % 26;
      shift = (shift + 1) % 26;
      if (rotors[j] != 0) {
        break; // no wrap, no increase to next rotor
      }
    }
  }

  // Output line 1: the encoded text.
  printf("%s\n", text);

  // Output line 2: the unchanged pair and rotor counts.
  printf("%d %d\n", k, r);

  // Output line 3: the original pairs, separated by single spaces.
  for (int i = 0; i < k; i++) {
    if (i > 0) {
      printf(" ");
    }

    // Each row contains two characters, not a null-terminated string.
    printf("%c%c", pairs[i][0], pairs[i][1]);
  }
  printf("\n"); // Also produces an empty line when k == 0.

  // Output line 4: the INITIAL rotor settings, not the final settings.
  for (int i = 0; i < r; i++) {
    if (i > 0) {
      printf(" ");
    }
    printf("%d", initial[i]);
  }
  printf("\n");

  // Release all dynamically allocated memory.
  free(text);
  free(initial);
  free(rotors);

  return 0;
}