// File: lab1_napoli38.c
// Created by: Michael Napoli
// Created on: 10/23/2021
// Due Date: 11/1/2021

#include <stdio.h>

// FUNCTION DECLARATIONS
void print_data(const float* data, const int n);
void prompt_user(float* data, const int n);

int main()
{
  float dataSet[8];
  const int dataSetSize = 8;

  prompt_user(dataSet, dataSetSize);

  print_data(dataSet, dataSetSize);

  return 0;
}

void print_data(const float* data, const int n) {
  int i(0);

  for (i = 0; i < n; ++i)
  { printf("%.3f, ", (float)data[i]); }

  printf("/n");

  return;  // return nothing
}

void prompt_user(float* data, const int n) {
  int i(0);

  printf("Enter data for calculation:\n");

  // get data from user
  for (i = 0; i < n; ++i) {
    scanf("%f", data[i]);
  }

  return;  // return nothing
}
