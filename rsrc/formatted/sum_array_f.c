#include <stdio.h>

// -a option
// Number of assignments: 8

int add(int a, int b) { return a + b; }

int sum_array(int* a, int size) {
  int total = 0;
  for (int i = 0; i < size; ++i) {
    total += a[i];
  }
  return total;
}

int main() {
  int first_nums[5] = {1, 2, 3, 4, 5};
  int second_nums[3] = {3, 4, 5};

  int first_sum = sum_array(first_nums, 5);
  int second_sum = sum_array(second_nums, 3);

  printf("first sum is % d.\n", first_sum);
  printf("second sum is % d.\n", second_sum);

  if (first_sum == second_sum) {
    printf("The sums are equal.\n");
  } else {
    printf("The sums are different.\n");
  }
  return 0;
}