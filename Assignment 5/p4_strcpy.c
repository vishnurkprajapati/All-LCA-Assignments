#include <stdio.h>
#include <string.h>

int main() {
  char source[] = "Helllo!!";
  char destination[20];
  strcpy(destination, source);
  printf("%s", destination);
  return 0;
}
