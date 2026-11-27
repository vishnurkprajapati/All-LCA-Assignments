#include <stdio.h>

int main() {
  char string_1[10] = "Hello"; //
  char string_2[] = "Hello2";
  char string_3[] = {'H', 'e', 'l',
                     'l', 'o', '\0'}; // does not need an explicit size
  printf("string 1: %s \n string 2: %s \n string 3: %s \n", string_1, string_2,
         string_3);
  return 0;
}
