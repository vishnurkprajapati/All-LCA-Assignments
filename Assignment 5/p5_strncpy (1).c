#include <stdio.h>
#include <string.h>

int main() {

  char source[] = "Za warudo!";
  char destination[20];
  strncpy(destination, source, 5);
  printf("%s", destination);
  return 0;
}
