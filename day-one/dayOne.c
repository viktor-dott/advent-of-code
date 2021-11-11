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
      for(int k = (i + 2); k < lines; k++) {
        if (numberArray[i] + numberArray[j] + numberArray[k] == TARGET) {
          printf("Pair with a given sum %d is %d, %d, %d\n", TARGET, numberArray[i], numberArray[j], numberArray[k]);
          printf("Final answer is: %d\n", numberArray[i]*numberArray[j]*numberArray[k]);
          return 1;
        }
      }
    }
  }

  fclose(puzzleInputPointer);
  return 0;
}