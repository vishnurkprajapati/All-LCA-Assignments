#include <stdio.h>
#include <string.h>

int main() {
  char string[] = "Hello World";
  char *pointer = strstr(string, "World");
  if (pointer)
    printf("%s", pointer);
  else
    printf("Not found");
  return 0;
}
