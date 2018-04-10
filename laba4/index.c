// 267
#include <stdio.h>
#include <math.h>
#include <malloc.h>


void outputFile(char string[]) {
  char path[100];
  printf("\nEnter output file path (or use default path by passing 'def'): ");
  scanf("%s", path);

  FILE *outputFile;

  if ( (path[0] == 'd') && (path[1] == 'e') && (path[2] == 'f') ) {
    // if passed path is "def" then change path to "output.txt"
    outputFile = fopen("output.txt", "w");

  } else {
    // if not then just use that was passed
    outputFile = fopen(path, "w");
  }

  fprintf(outputFile, "%s", string);

  fclose(outputFile);
}


void outputConsole(char string[]) {
  printf("Result: %s", string);
}


void getResult(char string[], int length) {
  for (int i = 0; i < length; i++) {

    if ( i < (length / 2) ) {
      if (string[i] == ':') {
        // replace symbol ':' for ',' every even number include one
        string[i] = ',';
      }
    }

    if ( i > (length / 2) ) {
      if (string[i] == '!') {
        // replace symbol '!' for '.' every odd number
        string[i] = '.';
      }
    }
  }
}


void inputFile(char string[]) {
  char path[100];
  printf("\nEnter input file path: ");
  scanf("%s", path);

  FILE *inputFile;
  inputFile = fopen(path, "r");

  if (inputFile == NULL) {
    inputFile = fopen("input.txt", "r");
  }

  fscanf(inputFile, "%s", string);

  fclose(inputFile);
}


void inputConsole(char string[]) {
  printf("\nEnter string: ");
  scanf("%s", string);
}


int main(void) {
  int continueAnswer = 1;

  // console - 1, file - 0
  int inputMethodAnswer;
  int outputMethodAnswer;

  while (continueAnswer) {
    printf("\nChoose input option: 1 - console, 0 - file: ");
    scanf("%d", &inputMethodAnswer);

    printf("\nChoose output option: 1 - console, 0 - file: ");
    scanf("%d", &outputMethodAnswer);

    char *string;
    int length;

    printf("\nEnter length of string: ");
    scanf("%d", &length);

    string = (char*)malloc(length * sizeof(char));


    inputMethodAnswer ? inputConsole(string) : inputFile(string);

    getResult(string, length);

    outputMethodAnswer ? outputConsole(string) : outputFile(string);

    printf("\nSuccess!\n");
    free(string);

    if (inputMethodAnswer == 1) {
      printf("\nDo you want to continue? 1 / 0: ");
      scanf("%d", &continueAnswer);
    } else {
      break;
    }
  }

  return 0;
}
