#include <stdio.h>

void clean_stdin() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
    // here getchar() keeps consuming until either \n or EOF, loop body does
    // nothing
  };
}

int main() {
  char string_1[50], string_2[50];
  printf("Enter one word: ");
  scanf("%s", string_1); // Array names automatically decay into pointers so we
                         // don't need to
  // explicitly pass the address of said variables. Infact, doing so will throw
  // compiler warnings :D
  clean_stdin();

  printf("%s \n", string_1);

  printf("Enter a sentence: ");
  fgets(string_2, sizeof(string_2), stdin);

  printf("%s \n", string_2);

  return 0;
}

// Dead code follows

// void clean_stdin() { // Works on unix only --
//                      //
//                      https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux/23885008#23885008
//   int stdin_copy =
//       dup(STDIN_FILENO); // This duplicates fd 0, so stdin_copy is just a
//       second
//                          // handle pointing at the same open tty
//   /* remove garbage from stdin */
//   // tcdrain(stdin_copy);       // blocks until all pending output written to
//   // the terminal has been transmitted., useless in our case because we read
//   // using scanf
//
//   tcflush(stdin_copy, TCIFLUSH); // a command to the terminal driver to
//   discard
//                                  // data. With TCIFLUSH it
//   // discards input that the kernel has received but that no read() has
//   consumed
//   // yet. Because stdin_copy refers to the same tty as fd 0, purging via the
//   // duplicate clears stdin's pending input queue.
//
//   close(stdin_copy); // Closes the duplicate fd
// }
