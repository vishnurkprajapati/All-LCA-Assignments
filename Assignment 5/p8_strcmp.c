#include <stdio.h>
#include <string.h>

int main() {
  char string1[] = "Hello";
  char string2[] = "Byee";
  int result = strcmp(string1, string2);
  if (result == 0) {
    printf("Equal");
  } else if (result > 0) {
    printf("String2 > string1");
  } else {
    printf("string1 > string2");
  }

  return 0;
}
