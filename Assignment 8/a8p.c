#include <stdio.h>

void swap_pointers(int *pointer_1, int *pointer_2) {

  int temp = *pointer_1;

  *pointer_1 = *pointer_2;
  *pointer_2 = temp;
}

int main() {

  int value_1, value_2;

  printf("Enter the first number: ");
  scanf("%d", &value_1);

  printf("Enter the second number: ");
  scanf("%d", &value_2);

  int *value_1_pointer = &value_1;
  int *value_2_pointer = &value_2;

  printf("\nBefore swapping:\n");
  printf("Value 1 = %d, Value 2 = %d\n", *value_1_pointer, *value_2_pointer);

  swap_pointers(value_1_pointer, value_2_pointer);

  printf("\nAfter swapping:\n");
  printf("Value 1 = %d, Value 2 = %d\n", *value_1_pointer, *value_2_pointer);

  return 0;
}
