#include <stdio.h>
#include <string.h>

int main() {
  char string1[30] = "Hello";
  char string2[] = "World";
  char concat_string[30];
  strncat(string1, string2, 10);
  printf("%s", string1);
  return 0;
}
