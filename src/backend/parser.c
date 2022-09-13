#include <stdio.h>

void parse_file(char *file_path) {
  FILE *file = fopen(file_path, "r");
  printf("[%s]\n", file_path);
  fclose(file);
}
