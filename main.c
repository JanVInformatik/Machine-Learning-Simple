#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float training_data[][2] = {{0, 0}, {1, 5}, {2, 10}, {3, 15}, {4, 20}};

float random_number(void) {
  srand(time(0));
  return (float)rand() / (float)RAND_MAX;
}

#define training_data_size (sizeof(training_data) / sizeof(training_data[0]))

float cost(float param) {
  float acc = 0;

  for (size_t i = 0; i < training_data_size; ++i) {
    float input = training_data[i][0];
    float expected_output = training_data[i][1];
    float actual_output = input * param;
    float d = expected_output - actual_output;
    acc += d * d;
  }
  acc /= (float)training_data_size;
  return acc;
}

int main() {
  float w = random_number() * 10.0f;
  float h = 1e-3;
  float learning_rate = 1e-1;

  printf("Initial parameter: %f\n", w);

  for (size_t i = 0; i < 10; ++i) {
    float derivative_cost = (cost(w + h) - cost(w)) / h;
    w -= derivative_cost * learning_rate;
    printf("Adjusted parameter to %f, achieved at cost of: %f\n", w, cost(w));
  }
}
