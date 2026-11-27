#include <stdio.h>
#include <string.h>

int main() {
  char string1[20] = "Hello";
  char string2[20] = "Hiiii";
  strcat(string2, string1);
  printf("string 1: %s, concat version: %s\n", string1, string2);
  return 0;
}
