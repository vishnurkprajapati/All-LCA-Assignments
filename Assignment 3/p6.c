#include <stdio.h>
#include <stdlib.h>

int main() {

  int choice;
  do {
    printf("\nEnter a choice:\n");
    printf("1. Print 'Hii mom!!'\n");
    printf("2. Exit\n");
    printf("Enter a choice (1, 2): ");
    scanf("%d", &choice);
    if (choice == 1) {
      printf("Hii mom!!\n");
    }
  } while (choice != 2);
  return EXIT_SUCCESS;
}
