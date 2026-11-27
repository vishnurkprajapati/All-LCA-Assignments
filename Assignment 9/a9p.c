
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int copy_file_contents(FILE *source_file_pointer,
                       FILE *destination_file_pointer) {
  char file_data_buffer[BUFFER_SIZE];
  size_t bytes_read;

  while ((bytes_read = fread(file_data_buffer, 1, BUFFER_SIZE,
                             source_file_pointer)) > 0) {
    size_t bytes_written =
        fwrite(file_data_buffer, 1, bytes_read, destination_file_pointer);

    if (bytes_written != bytes_read) {
      printf("Error: Unable to write data to the destination file.\n");
      return 1;
    }
  }

  if (ferror(source_file_pointer)) {
    printf("Error: Unable to read data from the source file.\n");
    return 1;
  }

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
    return 1;
  }

  FILE *source_file_pointer = fopen(argv[1], "rb");

  if (source_file_pointer == NULL) {
    printf("Error: Unable to open the source file.\n");
    return 1;
  }

  FILE *destination_file_pointer = fopen(argv[2], "wb");

  if (destination_file_pointer == NULL) {
    printf("Error: Unable to create the destination file.\n");
    fclose(source_file_pointer);
    return 1;
  }

  int copy_status =
      copy_file_contents(source_file_pointer, destination_file_pointer);

  fclose(source_file_pointer);

  if (fclose(destination_file_pointer) != 0) {
    printf("Error: Unable to close the destination file properly.\n");
    copy_status = 1;
  }

  if (copy_status == 0) {
    printf("File contents copied successfully.\n");
  }

  return copy_status;
}
