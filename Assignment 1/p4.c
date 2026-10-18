#include <stdio.h>

int main() {

int a, b, choice;
printf("Please enter the first number: ");
scanf("%d", &a);
printf("Please enter the Second number: ");
scanf("%d", &b);
printf(
"Select a choice: \n 1 : addition\n 2 : subtraction\n 3 : multiplication\n 4 : division\n 5: Modulus\n");
printf("Choice: ");
scanf("%d", &choice);
// switchcae
switch (choice) {
case 1: printf("%d\n", a + b); break;
case 2: printf("%d\n", a - b); break;
case 3: printf("%d\n", a*b); break;
case 4: printf("%d\n", a/b); break;
case 5: printf("%d\n", a%b); break;
default: printf("Please enter a valid choice\n");
}

return 0;
}
