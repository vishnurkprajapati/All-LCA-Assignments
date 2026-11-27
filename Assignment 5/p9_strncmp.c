#include <stdio.h>
#include <string.h>

int main() {
  char string1[] = "Hello";
  char string2[] = "Byee";
  int result = strncmp(string1, string2, 4);
  printf("For the first 4 chars; string 1 and string2 are:");
  if (result == 0) {
    printf("Equal");
  } else if (result > 0) {
    printf("String2 > string1");
  } else {
    printf("string1 > string2");
  }

  return 0;
}
