#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include "backend.h"

void s21_parse_file(char *file_path, s21_obj_data *data) {
  setlocale(LC_NUMERIC, "C");
  FILE *file;
  char buff[1024];
  file = fopen(file_path, "r");
  // TODO(hubertfu): file open error
  if (file != NULL) {
    s21_init_obj_data(data);

    while (!feof(file)) {
      char *res = fgets(buff, 1024, file);
      if (res != NULL) {
        if (buff[0] == 'v' && buff[1] == ' ') {
          s21_parse_line_v(buff, data);
        } else if (buff[0] == 'f' && buff[1] == ' ') {
          s21_parse_line_f(buff, data);
        }
      }
      // if (data->num_of_v % 1000 == 0) {
      //   printf("{%u}\n", data->num_of_v);
      // }
    }

    fclose(file);
    // s21_print_obj_data(data);
    // exit(1);
  }
}

void s21_init_obj_data(s21_obj_data *data) {
  data->num_of_f = 0;
  data->num_of_v = 0;
  data->array_of_v = NULL;
  data->array_of_f = NULL;
}

void s21_allocate_memory_block_f(s21_obj_data *data) {
  if (data->num_of_f == 0) {
    // TODO(hubertfu): memory allocation by blocks
    // TODO(hubertfu): handle memory errors
    data->array_of_f = malloc(S21_MEMORY_BLOCK_SIZE_F * sizeof(unsigned int));
  } else {
    if (data->num_of_f % S21_MEMORY_BLOCK_SIZE_F == 0) {
      data->array_of_f = realloc(
          data->array_of_f, (((data->num_of_f / S21_MEMORY_BLOCK_SIZE_F) + 1) *
                             S21_MEMORY_BLOCK_SIZE_F * sizeof(unsigned int)));
      //  printf("\n\n[allocate %u (%u)]\n\n", ((data->num_of_f /
      //  (S21_MEMORY_BLOCK_SIZE * 2)) + 1), data->num_of_f);
    }
  }
}

void s21_parse_float(char *line, float *number, int *shift) {
  char *ptr = line;
  float tmp = 0.0;
  int pow = 1;
  int is_tochka = 0;
  float sign = 1;
  while (*ptr != ' ' && *ptr != '\n' && *ptr != '\0') {
    // printf("{%f}",tmp);
    if (*ptr == '.') {
      is_tochka = 1;
      ++ptr;
      continue;
    }

    if (*ptr == '-') {
      sign = -1;
      ++ptr;
      continue;
    }

    if (is_tochka == 1) {
      pow *= 10;
    }

    tmp *= 10;
    tmp += *ptr - 48;
    ++ptr;
  }

  *number = sign * tmp / pow;
  *shift = ptr - line;
}

void s21_parse_line_v(char *line, s21_obj_data *data) {
  // TODO(hubertfu): handle incoorect lines
  if (data->num_of_v == 0) {
    // TODO(hubertfu): memory allocation by blocks
    data->array_of_v = malloc(S21_MEMORY_BLOCK_SIZE * 3 * sizeof(float));
  } else {
    if (data->num_of_v % (S21_MEMORY_BLOCK_SIZE * 3) == 0) {
      data->array_of_v =
          realloc(data->array_of_v,
                  ((data->num_of_v / (S21_MEMORY_BLOCK_SIZE * 3)) + 1) *
                      S21_MEMORY_BLOCK_SIZE * 3 * sizeof(float));
    }
  }

  if (data->array_of_v == NULL) {
    // TODO(hubertfu): handle memory errors
  }

  // TODO(hubertfu): scanf memory errors
  sscanf(line, "v %f %f %f", &data->array_of_v[data->num_of_v],
         &data->array_of_v[data->num_of_v + 1],
         &data->array_of_v[data->num_of_v + 2]);

  // char *ptr = line;
  // int shift = 0;
  // ptr += 2;
  // printf("%s", ptr);
  // s21_parse_float(ptr, &data->array_of_v[data->num_of_v], &shift);

  // ptr += shift + 1;
  // printf("%s", ptr);
  // s21_parse_float(ptr, &data->array_of_v[data->num_of_v + 1], &shift);

  // ptr += shift + 1;
  // printf("%s", ptr);
  // s21_parse_float(ptr, &data->array_of_v[data->num_of_v + 2], &shift);
  data->num_of_v += 3;
}

void s21_parse_line_f(char *line, s21_obj_data *data) {
  // TODO(hubertfu): handle incoorect lines
  char *ptr = line;
  int flag = 0;
  int new_num = 0;
  int num_points = 0;
  int first_index = data->num_of_f;
  // printf("[%s]\n", line);
  // data->array_of_f[data->num_of_f].num_of_points = 0;

  while (*ptr != '\0') {
    unsigned int tmp;
    if (flag == 0 && s21_is_number(*ptr)) {
      // sscanf(ptr, "%u", &tmp);
      tmp = 0;
      while (s21_is_number(*ptr)) {
        tmp *= 10;
        tmp += *ptr - 48;
        ++ptr;
      }
      flag = 1;
      new_num = 1;
      // printf("%u(%u) ", tmp, data->num_of_f);
    }

    if (*ptr == ' ') {
      flag = 0;
    }
    // printf("{%d}\n", data->num_of_f % (S21_MEMORY_BLOCK_SIZE * 2));

    if (new_num == 1) {
      s21_allocate_memory_block_f(data);
      if (num_points < 2) {
        data->array_of_f[data->num_of_f] = tmp - 1;
        ++(data->num_of_f);
      } else {
        data->array_of_f[data->num_of_f] = data->array_of_f[data->num_of_f - 1];
        ++(data->num_of_f);
        s21_allocate_memory_block_f(data);
        data->array_of_f[data->num_of_f] = tmp - 1;
        ++(data->num_of_f);
      }

      new_num = 0;
      ++num_points;
    }

    ++ptr;
  }
  // 1,2,2,3,3,1,7,6,6,5,5,7,4,5,5,1,1,4,5,6,6,2,2,5,2,6,6,7,7,2,0,3,3,7,7,0,0,1,1,3,3,0,4,7,7,5,5,4,0,4,4,1,1,0,1,5,5,2,2,1,3,2,2,7,7,3,4,0,0,7,7,4
  // 1,2,2,3,3,1,7,6,6,5,5,7,4,5,5,1,1,4,5,6,6,2,2,5,2,6,6,7,7,2,0,3,3,7,7,0,0,1,1,3,3,0,4,7,7,5,5,4,0,4,4,1,1,0,1,5,5,2,2,1,3,2,2,7,7,3,4,0,0,7,7,4
  s21_allocate_memory_block_f(data);

  data->array_of_f[data->num_of_f] = data->array_of_f[data->num_of_f - 1];
  ++(data->num_of_f);

  s21_allocate_memory_block_f(data);

  data->array_of_f[data->num_of_f] = data->array_of_f[first_index];
  ++(data->num_of_f);

  // printf("\n");

  // while (*ptr != '\0') {
  //   if (s21_is_number(*ptr) && flag == 0) {
  //     unsigned int tmp;
  //     sscanf(ptr, "%u", &tmp);

  //     flag = 1;
  //     if (data->array_of_f[data->num_of_f].num_of_points == 0) {
  //       // TODO(hubertfu): memory allocation by blocks
  //       // TODO(hubertfu): handle memory errors
  //       data->array_of_f[data->num_of_f].points =
  //           malloc(1 * sizeof(unsigned int));
  //     } else {
  //       data->array_of_f[data->num_of_f].points =
  //           realloc(data->array_of_f[data->num_of_f].points,
  //                   (data->array_of_f[data->num_of_f].num_of_points + 1) *
  //                       sizeof(unsigned int));
  //     }
  //     data->array_of_f[data->num_of_f]
  //         .points[data->array_of_f[data->num_of_f].num_of_points] = tmp;
  //     ++(data->array_of_f[data->num_of_f].num_of_points);
  //   }
  //   if (*ptr == ' ') {
  //     flag = 0;
  //   }
  //   ++ptr;
  // }

  // data->num_of_f += 2;
}

s21_boolean s21_is_number(char symbol) {
  return ((int)symbol >= 48 && (int)symbol <= 57);
}

void s21_destroy_obj_data(s21_obj_data *data) {
  free(data->array_of_v);
  // for (unsigned int i = 0; i < data->num_of_f; i++) {
  //   free(data->array_of_f[i].points);
  // }
  free(data->array_of_f);
}

void s21_print_obj_data(s21_obj_data *data) {
  printf("\n\n");
  for (unsigned int i = 0; i < data->num_of_v / 3; i++) {
    printf("x:%10f y:%10f z:%10f\n", data->array_of_v[i * 3],
           data->array_of_v[i * 3 + 1], data->array_of_v[i * 3 + 2]);
  }

  for (unsigned int i = 0; i < data->num_of_f; i++) {
    printf("%u,", data->array_of_f[i]);
  }

  // for (unsigned int i = 0; i < data->num_of_f; i++) {
  //   printf("f: ");
  //   for (unsigned int j = 0; j < data->array_of_f[i].num_of_points; j++) {
  //     printf("%u ", data->array_of_f[i].points[j]);
  //   }
  //   printf("\n");
  // }
}
