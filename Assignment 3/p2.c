#include <stdio.h>
#include <stdlib.h>

int main() {

  int n, sum=0;
  printf(
      "Enter n for which this program will print the sum of first n numbers: ");
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    sum += i;
  }
  printf("%d\n", sum);

  return EXIT_SUCCESS;
}
