/* File: lab1_napoli38.c      */
/* Created by: Michael Napoli */
/* Created on: 10/23/2021     */
/* Due Date: 11/1/2021        */

#include <stdio.h>

/* FUNCTION DECLARATIONS */
void print_data(const float* data, const int n);
void prompt_user(float* data, const int n);
void enter_loop(const float* data, const int n);

float maximum(const float* data, const int n);
float minimum(const float* data, const int n);
float sum(const float* data, const int n);
float average(const float* data, const int n);



int main() {
  float dataSet[8];
  const int dataSetSize = 8;

  prompt_user(dataSet, dataSetSize);

  enter_loop(dataSet, dataSetSize);

  print_data(dataSet, dataSetSize);

  return 0;
}


/* FUNCTION DEFINITIONS */
void print_data(const float* data, const int n) {
  int i = 0;

  for (i = 0; i < n; ++i) {
    printf("%.3f", data[i]);

    if (i != (n - 1)) {
      printf(", ");
    }
  }

  printf("\n");

  return;  /* return nothing */
}

void prompt_user(float* data, const int n) {
  int i = 0;

  printf("Enter data for calculation:\n");

  /* get data from user */
  for (i = 0; i < n; ++i) {
    scanf("%f", &data[i]);
  }

  return;  /* return nothing */
}

void enter_loop(const float* data, const int n) {
  int user_input = 6;

  while (user_input != 6) {
    printf("1). Find minimum value.\n");
    printf("2). Find maximum value.\n");
    printf("3). Calculate the sum of all values.\n");
    printf("4). Calculate the average of all the values.\n");
    printf("5). Print the values in the data set.\n");
    printf("6). Exit the program.\n\n");
    printf("Choose computation to perform from list above: ");

    scanf("%i", &user_input);

    if (user_input == 1)
      minimum(data, n);
    else if (user_input == 2)
      maximum(data, n);
    else if (user_input == 3)
      sum(data, n);
    else if (user_input == 4)
      average(data, n);
    else if (user_input == 5)
      print_data(data, n);
    else
      user_input = 6;
  }

  return;  /* return nothing */
}

float maximum(const float* data, const int n) {
  int i = 1;
  float max = data[0];

  for (i; i < n; ++i) {
    if (data[i] > max) {
      max = data[i];
    }
  }

  return max;
}

float minimum(const float* data, const int n) {
  return 1.0;
}

float sum(const float* data, const int n) {
  return 1.0;
}

float average(const float* data, const int n) {
  return 1.0;
}
