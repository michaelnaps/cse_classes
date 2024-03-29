/* File: lab1_napoli38.c      */
/* Created by: Michael Napoli */
/* Created on: 10/23/2021     */
/* Due Date: 11/1/2021        */

#include <stdio.h>

/* FUNCTION DECLARATIONS */
void print_data(const float *data, const int n);
void get_data(float *data, const int n);

void enter_loop(const float *data, const int n);
int prompt_user();

float maximum(const float *data, const int n);
float minimum(const float *data, const int n);
float sum_data(const float *data, const int n);
float average_data(const float *data, const int n);



int main() {
  float dataSet[8];
  const int dataSetSize = 8;

  get_data(dataSet, dataSetSize);
  enter_loop(dataSet, dataSetSize);

  return 0;
}


/* FUNCTION DEFINITIONS */
/*
  For all function inputs:
    'data' - array with the data entered by the user
    'n' - number of values in the given array
*/

/* Prompt the user for data that will be used in loop. */
void get_data(float *data, const int n) {
  int i = 0;

  printf("Enter data for calculation:\n");

  /* get data from user */
  for (i = 0; i < n; ++i) {
    scanf("%f", &data[i]);
  }

  return;  /* return nothing */
}

/* Main loop function which contains user decision tree. */
void enter_loop(const float *data, const int n) {
  int user_input = -1;

  while (user_input != 6) {
    user_input = prompt_user();

    if (user_input == 1)
      printf("The minimum for the data is: %.2f.\n\n", minimum(data, n));
    else if (user_input == 2)
      printf("The maximum for the data is: %.2f.\n\n", maximum(data, n));
    else if (user_input == 3)
      printf("The sum for the data is: %.2f.\n\n", sum_data(data, n));
    else if (user_input == 4)
      printf("The average for the data is: %.2f.\n\n", average_data(data, n));
    else if (user_input == 5) {
      printf("The data entered by the user was...\n");
      print_data(data, n);
    }
    else if (user_input == 6) {
      printf("Ending program...\n\n");
    }
    else {
      printf("Please enter a valid option from the list given...");
    }
  }

  return;  /* return nothing */
}

/* Prompt for user calculation choice. */
int prompt_user() {
  int user_input = -1;

  printf("1). Find minimum value.\n");
  printf("2). Find maximum value.\n");
  printf("3). Calculate the sum of all values.\n");
  printf("4). Calculate the average of all the values.\n");
  printf("5). Print the values in the data set.\n");
  printf("6). Exit the program.\n");
  printf("Choose computation to perform from list above: ");

  scanf("%i", &user_input);
  return user_input;
}

/* Option 1 */
/* Find the minimum value in the given array. */
float minimum(const float *data, const int n) {
  int i = 1;
  float min = data[0];

  for (i; i < n; ++i) {
    if (min > data[i]) {
      min = data[i];
    }
  }

  return min;
}

/* Option 2 */
/* Find the maximum value in the given array. */
float maximum(const float *data, const int n) {
  int i = 1;
  float max = data[0];

  for (i; i < n; ++i) {
    if (data[i] > max) {
      max = data[i];
    }
  }

  return max;
}

/* Option 3 */
/* Calculate the sum of the array given. */
float sum_data(const float *data, const int n) {
  int i = 0;
  float sum = 0;

  for (i; i < n; ++i) {
    sum += data[i];
  }

  return sum;
}

/* Option 4 */
/* Calculate the average for the array given. */
float average_data(const float *data, const int n) {
  float sum = sum_data(data, n);
  return sum / n;
}

/* Option 5 */
/* Print the array given in comma seperated format. */
void print_data(const float *data, const int n) {
  int i = 0;

  printf("Data Set:\n");
  for (i = 0; i < n; ++i) {
    printf("%.2f\n", data[i]);

    if (i != (n - 1)) {
    }
  }

  printf("\n");

  return;  /* return nothing */
}
