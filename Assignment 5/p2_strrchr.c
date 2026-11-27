#include <stdio.h>
#include <string.h>

int main() {
  char string[] = "banana";
  char *ptr = strchr(string, 'a');
  if (ptr) {
    printf("%s\n", ptr);
  } else {
    printf("not found :(\n");
    printf("%s", string);
  }
  return 0;
}
