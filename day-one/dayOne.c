#include <stdio.h>

int main (void) {

  int TARGET = 2020;
  FILE *puzzleInputPointer = fopen("puzzle_input.txt", "r");
  int ch=0;
  int lines=0;
  int numberArray[200];

  while(!feof(puzzleInputPointer)) {
    ch = fgetc(puzzleInputPointer);
    if(ch == '\n') {
      fscanf(puzzleInputPointer, "%d", &numberArray[lines]);
      lines++;
    }
  }

  for (int i = 0; i < (lines - 1); i++) {
    for (int j = (i + 1); j < lines; j++) {
      if (numberArray[i] + numberArray[j] == TARGET) {
        printf("Pair with a given sum %d is %d, %d", TARGET, numberArray[i], numberArray[j]);
        return 1;
      }
    }
  }

  fclose(puzzleInputPointer);
  return 0;
}