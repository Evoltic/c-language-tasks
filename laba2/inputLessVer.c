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


float getResult() {
  float numbers[100];

  numbers[0] = 0.3;
  numbers[1] = -0.3;

  float number;
  float closestToOne = 1;
  float closestToZero = 0;

  for (int i = 2; i < 100; i++) {
    number = sin(numbers[i - 2]);
    // fabs - absolute value
    if (1 - fabs(number) < fabs(closestToOne))
      closestToOne = number;
    if (1 - fabs(number) > fabs(closestToZero))
      closestToZero = number;

    numbers[i] = number;
  }

  if (fabs(closestToOne) > fabs(closestToZero))
    return closestToZero;
  else
    return closestToOne;
}


int main(void) {
  int continueAnswer = 1;
  // console - 1, file - 0
  int outputMethodAnswer;
  // 1 or 2
  int taskNumber;

  while (1) {
    if (continueAnswer == 1) {
      printf("\nChoose output option: 1 - console, 0 - file: ");
      scanf("%d", &outputMethodAnswer);

      float result = getResult();

      outputMethodAnswer ? outputConsole(result) : outputFile(result);

      printf("\nSuccess!");
      printf("\nDo you want to continue? 1 / 0: ");
      scanf("%d", &continueAnswer);

    } else if (continueAnswer == 0) {
      break;
    }
  }

  return 0;
}
