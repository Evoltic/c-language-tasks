// 211
#include <stdio.h>
#include <math.h>


void outputFile(float result) {
  char path[100];
  printf("\nEnter output file path: ");
  scanf("%s", path);

  FILE *outputFile;
  outputFile = fopen(path, "w");

  fprintf(outputFile, "%f\n", result);

  fclose(outputFile);
}


void outputConsole(float result) {
  printf("\nResult: %f", result);
}


float getResult(float x1, float x2) {
  float numbers[100];

  numbers[0] = x1;
  numbers[1] = x2;

  float number;
  float closestToOne = 0;
  float closestToZero = 1;

  for (int i = 2; i < 100; i++) {
    number = sin(numbers[i - 2]);
    // fabs - absolute value
    if (fabs(number) > fabs(closestToOne))
      closestToOne = number;
    if (fabs(number) < fabs(closestToZero))
      closestToZero = number;

    numbers[i] = number;
  }

  for (int i = 0; i < 2; i++) {
    if (fabs(numbers[i]) > closestToOne)
      closestToOne = numbers[i];
    if (fabs(numbers[i]) < closestToZero)
      closestToZero = numbers[i];
  }

  // list of numbers for checking result
  for (int i = 0; i < 100; i++) {
    printf("%f\n", numbers[i]);
  }

  if (1 - fabs(closestToOne) > fabs(closestToZero))
    return closestToZero;
  else
    return closestToOne;
}


int inputFile(float *x1, float *x2) {
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

  float value;
  float firstValue, secondValue;
  int i = 1;

  while (fscanf(inputFile, "%f", &value) != EOF) {
    i == 1 ? (firstValue = value) : (secondValue = value);
    i++;
  }

  *x1 = firstValue;
  *x2 = secondValue;
  fclose(inputFile);
}


int inputConsole(float *x1, float *x2) {
  float firstValue, secondValue;
  printf("\nEnter x1: ");
  scanf("%f", &firstValue);
  printf("\nEnter x2: ");
  scanf("%f", &secondValue);
  *x1 = firstValue;
  *x2 = secondValue;
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

    printf("\n0 <= x <= 1\n");

    float x1, x2;

    inputMethodAnswer ? inputConsole(&x1, &x2) : inputFile(&x1, &x2);

    float result = getResult(x1, x2);

    outputMethodAnswer ? outputConsole(result) : outputFile(result);

    printf("\nSuccess!\n");

    if (inputMethodAnswer == 1) {
      printf("\nDo you want to continue? 1 / 0: ");
      scanf("%d", &continueAnswer);

    } else {
      break;
    }
  }

  return 0;
}
