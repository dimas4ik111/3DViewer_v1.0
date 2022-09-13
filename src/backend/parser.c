#include <stdio.h>

void parse_file(char *file_path) {
  FILE *file;
  char buff[1024];
  file = fopen(file_path, "r");
  if (file != NULL) {
    printf("[%s]\n\n", file_path);
    while (!feof(file)) {
      fgets(buff, 1024, file);
      if (buff[0] == 'v' && buff[1] == ' ') {
        printf("%s", buff);
      } else if (buff[0] == 'f' && buff[1] == ' ') {
        printf("%s", buff);
      }
      
    }

    fclose(file);
  }
}
