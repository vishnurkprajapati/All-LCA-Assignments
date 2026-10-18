#include <stdio.h>
#include <stdlib.h>

int main() {
  int number, factorial = 1, i = 1;
  printf("Enter the number whose factorial you want to calculate: ");
  scanf("%d", &number);
  while (i <= number) {
    factorial *= i;
    i++;
  }
  printf("Factorial of %d = %d\n", number, factorial);
  return EXIT_SUCCESS;
}
