// 389
#include <stdio.h>
#include <malloc.h>


void outputFile(int index[]) {
  char path[100];
  printf("\nEnter output file path: ");
  scanf("%s", path);

  FILE *outputFile;
  outputFile = fopen(path, "w");

  fprintf(outputFile, "Row index: %d", index[0]);
  fprintf(outputFile, "\nColumn index: %d", index[1]);

  fclose(outputFile);
}


void outputConsole(int index[]) {
  printf("\nResult: ");
  printf("\nRow index: %d", index[0]);
  printf("\nColumn index: %d", index[1]);
}


int* getResult(float array[], int rows, int columns) {
  float number, lowestInRow;

  // highest of  all lowest in row
  float highestOfLowest;

  // index of lowest number in row
  int lowestNumberRowIndex;
  int lowestNumberColumnIndex;

  // index of highest number of lowest
  static int index[2];

  for (int i = 0; i < rows; i++) {
    // gives default value
    lowestInRow = *(array + i*columns + 0);

    for (int j = 0; j < columns; j++) {
      number = *(array + i*columns + j);

      if (number <= lowestInRow) {
        lowestInRow = number;
        lowestNumberRowIndex = i;
        lowestNumberColumnIndex = j;
      }
    }

    if (i == 0) {
      // gives default value
      highestOfLowest = lowestInRow;
      index[0] = lowestNumberRowIndex;
      index[1] = lowestNumberColumnIndex;
    }

    if (lowestInRow > highestOfLowest) {
      index[0] = lowestNumberRowIndex;
      index[1] = lowestNumberColumnIndex;
      highestOfLowest = lowestInRow;
    }
    // printf("\nLowest in Row %f highest of lowest %f\n", lowestInRow, highestOfLowest);
    // printf("\nIndex lowest is %d %d Index highest is %d %d\n", lowestNumberRowIndex, lowestNumberColumnIndex, index[0], index[1]);
  }

  return index;
}


void inputFile(float array[], int rows, int columns) {
  char path[100];
  printf("\nAttention! In file you have to separate numbers with a space\n");
  printf("\nEnter input file path: ");
  scanf("%s", path);

  FILE *inputFile;
  inputFile = fopen(path, "r");

  if (inputFile == NULL) {
    printf("\nSuch file doesnt exist. Data will be grabed from input.txt\n");
    inputFile = fopen("input.txt", "r");
  }

  float number;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      fscanf(inputFile, "%f", &number);
      *(array + i*columns + j) = number;
    }
  }

  fclose(inputFile);
}


void inputConsole(float array[], int rows, int columns) {
  printf("\n");

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("array[%d][%d] = ", i, j);
      scanf("%f", (array + i*columns + j));
    }
  }
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

    float *array;
    int rows, columns;

    printf("\nEnter rows number: ");
    scanf("%d", &rows);
    printf("\nEnter columns number: ");
    scanf("%d", &columns);

    array = (float*)malloc(columns * rows * sizeof(float));

    inputMethodAnswer
      ? inputConsole(array, rows, columns)
        : inputFile(array, rows, columns);

     printf("\n");
     // prints array in matrix form
     for (int i = 0; i < rows; i++) {
       for (int j = 0; j < columns; j++) {
         printf("%20f ", *(array + i*columns + j));
       }
       printf("\n");
     }

    int *result;

    result = getResult(array, rows, columns);

    outputMethodAnswer ? outputConsole(result) : outputFile(result);

    printf("\nSuccess!\n");

    free(array);

    if (inputMethodAnswer == 1) {
      printf("\nDo you want to continue? 1 / 0: ");
      scanf("%d", &continueAnswer);

    } else {
      break;
    }
  }

  return 0;
}
