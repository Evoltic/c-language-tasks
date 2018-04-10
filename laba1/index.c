// 139 и) е)
#include <stdio.h>


void outputFile(float result[], int size) {
  char path[100];
  printf("\nEnter output file path: ");
  scanf("%s", path);

  FILE *outputFile;
  outputFile = fopen(path, "w");

  for (int i = 0; i < size; i++) {
    fprintf(outputFile, "%f\n", result[i]);
  }

  fclose(outputFile);
}


void outputConsole(float result[], int size) {
  printf("\nResult:\n");

  for (int i = 0; i < size; i++) {
    printf("%f\n", result[i]);
  }
}


float* getResultSecondTask(int inputValue) {
  static float result[100];

  float numerator;
  float denominator = 1;

  for (int i = 1; i <= inputValue; i++) {
    i == 1 ? (numerator = 2) : (numerator *= 2);
    denominator *=  i;
    result[i - 1] = numerator / denominator;
  }

  return result;
}


float* getResultFirstTask(int inputValue) {
  static float result[100];

  float factorial = 1;

  // sum of factorials
  float sum = 0;

  for (int i = 1; i <= inputValue; i++) {
    factorial *=  i;
    sum += (1 / factorial);
    result[i - 1] = i * sum;
  }

  return result;
}


int inputFile() {
  char path[100];
  printf("\nEnter input file path: ");
  scanf("%s", path);

  FILE *inputFile;
  inputFile = fopen(path, "r");

  if (inputFile == NULL) {
    printf("\nSuch file doesnt exist. Data will be grabed from input.txt\n");
    inputFile = fopen("input.txt", "r");
  }

  int number;

  while (fscanf(inputFile, "%d", &number) != EOF) {
    return number;
  }

  fclose(inputFile);
}


int inputConsole() {
  int n;

  printf("\nInput natural number: ");
  scanf("%d", &n);

  return n;
}


int main(void) {
  int continueAnswer = 1;

  // console - 1, file - 0
  int inputMethodAnswer;
  int outputMethodAnswer;

  // 1 or 2
  int taskNumber;

  while (continueAnswer) {
    printf("\n What task number do you want to see ? 1 - 2: ");
    scanf("%d", &taskNumber);

    printf("\nChoose input option: 1 - console, 0 - file: ");
    scanf("%d", &inputMethodAnswer);

    printf("\nChoose output option: 1 - console, 0 - file: ");
    scanf("%d", &outputMethodAnswer);

    int inputValue = inputMethodAnswer ? inputConsole() : inputFile();

    float *result;

    result = taskNumber == 1
      ? getResultFirstTask(inputValue)
        : getResultSecondTask(inputValue);

    outputMethodAnswer
      ? outputConsole(result, inputValue)
        : outputFile(result, inputValue);

    printf("\nSuccess!");

    if (inputMethodAnswer == 1) {
      printf("\nDo you want to continue? 1 / 0: ");
      scanf("%d", &continueAnswer);

    } else {
      break;
    }
  }

  return 0;
}
