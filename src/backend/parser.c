#define _GNU_SOURCE
#include <dirent.h>
#include <errno.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "./backend.h"

s21_parser_result s21_parse_file(char *file_path, s21_obj_data *data,
                                 s21_boolean need_normalize) {
  s21_parser_result code = S21_PARSER_OK;
  s21_init_obj_data(data);

  DIR *dir = opendir(file_path);
  if (dir) {
    code = S21_PARSER_ERROR_FILE;
    closedir(dir);
  } else {
    FILE *file;
    file = fopen(file_path, "r");

    if (file != NULL) {
      setlocale(LC_NUMERIC, "C");
      char *line = NULL;
      size_t len = 0;
      errno = 0;
      while ((getline(&line, &len, file)) != -1) {
        if (code != S21_PARSER_OK) {
          break;
        }
        char *res = line;
        while (*res == ' ') {
          res++;
        }
        if (*res == 'v') {
          ++res;
          if (*res == ' ' || *res == '\n') {
            ++res;
            code = s21_parse_line_v(res, data);
          }
        } else if (*res == 'f') {
          ++res;
          if (*res == ' ') {
            code = s21_parse_line_f(res, data);
          }
        }
      }

      if (code == S21_PARSER_OK && errno == ENOMEM) {
        code = S21_PARSER_ERROR_MEMORY;
      }
      free(line);
      fclose(file);
    } else {
      code = S21_PARSER_ERROR_FILE;
    }

    if (code == S21_PARSER_OK) {
      if (need_normalize == S21_TRUE) {
        if (data->max_coord > 1.0f) {
          for (unsigned int i = 0; i < data->num_of_v; i++) {
            data->array_of_v[i] = data->array_of_v[i] / data->max_coord;
          }
        }
      }
    }
  }

  return code;
}

s21_parser_result s21_parse_line_v(char *line, s21_obj_data *data) {
  s21_parser_result code = S21_PARSER_OK;

  code = s21_allocate_memory_block_v(data);

  if (code == S21_PARSER_OK) {
    char *ptr = line;
    int num_of_v = 0, no_float = 0;
    while (*ptr != '\0') {
      if (num_of_v == 3 || no_float == 1) {
        break;
      }
      if (*ptr == ' ' || *ptr == 'v') {
        ++ptr;
        continue;
      } else {
        char *end;
        float tmp = strtof(ptr, &end);

        if (end - ptr == 0) {
          no_float = 1;
        } else {
          data->array_of_v[data->num_of_v] = tmp;
          ++num_of_v;
          ++data->num_of_v;
          if (fabsf(tmp) > data->max_coord) {
            data->max_coord = fabsf(tmp);
          }
        }
        ptr += end - ptr;
        continue;
      }
      ++ptr;
    }

    while (num_of_v < 3) {
      data->array_of_v[data->num_of_v] = 0.0f;
      ++num_of_v;
      ++data->num_of_v;
    }
  }

  return code;
}

s21_parser_result s21_parse_line_f(char *line, s21_obj_data *data) {
  s21_parser_result code = S21_PARSER_OK;
  char *ptr = line;
  int flag = 0;
  int new_num = 0;
  int num_points = 0;
  int first_index = data->num_of_f;

  while (*ptr != '\0') {
    if (code != S21_PARSER_OK) {
      break;
    }
    unsigned int tmp = 0;
    if (flag == 0) {
      char *end;
      tmp = strtol(ptr, &end, 10);
      ptr += end - ptr;
      flag = 1;
      new_num = 1;
    }

    if (*ptr == ' ') {
      flag = 0;
    }

    if (new_num == 1 && tmp > 0) {
      if (num_points > 1) {
        code = s21_allocate_memory_block_f(data);
        if (code == S21_PARSER_OK) {
          data->array_of_f[data->num_of_f] =
              data->array_of_f[data->num_of_f - 1];
          ++(data->num_of_f);
        }
      }
      if (code == S21_PARSER_OK) {
        code = s21_allocate_memory_block_f(data);
        if (code == S21_PARSER_OK) {
          data->array_of_f[data->num_of_f] = tmp - 1;
          ++(data->num_of_f);
        }

        new_num = 0;
        ++num_points;
      }
    }

    ++ptr;
  }

  if (code == S21_PARSER_OK) {
    if (num_points > 1) {
      code = s21_allocate_memory_block_f(data);
      if (code == S21_PARSER_OK) {
        data->array_of_f[data->num_of_f] = data->array_of_f[data->num_of_f - 1];
        ++(data->num_of_f);

        code = s21_allocate_memory_block_f(data);
        if (code == S21_PARSER_OK) {
          data->array_of_f[data->num_of_f] = data->array_of_f[first_index];
          ++(data->num_of_f);
        }
      }
    } else {
      --(data->num_of_f);
    }
  }

  return code;
}

s21_parser_result s21_allocate_memory_block_v(s21_obj_data *data) {
  s21_parser_result code = S21_PARSER_OK;
  if (data->num_of_v == 0) {
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
    code = S21_PARSER_ERROR_MEMORY;
  }

  return code;
}

s21_parser_result s21_allocate_memory_block_f(s21_obj_data *data) {
  s21_parser_result code = S21_PARSER_OK;
  if (data->num_of_f == 0) {
    data->array_of_f = malloc(S21_MEMORY_BLOCK_SIZE_F * sizeof(unsigned int));
  } else {
    if (data->num_of_f % S21_MEMORY_BLOCK_SIZE_F == 0) {
      data->array_of_f = realloc(
          data->array_of_f, (((data->num_of_f / S21_MEMORY_BLOCK_SIZE_F) + 1) *
                             S21_MEMORY_BLOCK_SIZE_F * sizeof(unsigned int)));
    }
  }

  if (data->array_of_f == NULL) {
    code = S21_PARSER_ERROR_MEMORY;
  }

  return code;
}

void s21_init_obj_data(s21_obj_data *data) {
  data->num_of_f = 0;
  data->num_of_v = 0;
  data->max_coord = 0.0f;
  data->array_of_v = NULL;
  data->array_of_f = NULL;
}

s21_parser_result s21_copy_obj_data(s21_obj_data *dst, s21_obj_data *src) {
  s21_parser_result code = S21_PARSER_OK;
  s21_init_obj_data(dst);
  dst->num_of_f = src->num_of_f;
  dst->num_of_v = src->num_of_v;
  dst->max_coord = src->max_coord;
  dst->array_of_v = malloc(dst->num_of_v * sizeof(float));
  if (dst->array_of_v == NULL) {
    code = S21_PARSER_ERROR_MEMORY;
  } else {
    dst->array_of_f = malloc(dst->num_of_f * sizeof(unsigned int));
    if (dst->array_of_f == NULL) {
      code = S21_PARSER_ERROR_MEMORY;
    }
  }
  s21_copy_obj_to_obj(dst, src);

  return code;
}

void s21_copy_obj_to_obj(s21_obj_data *dst, s21_obj_data *src) {
  if (dst->num_of_f == src->num_of_f && dst->num_of_v == src->num_of_v) {
    for (unsigned int i = 0; i < dst->num_of_v; i++) {
      dst->array_of_v[i] = src->array_of_v[i];
    }
    for (unsigned int i = 0; i < dst->num_of_f; i++) {
      dst->array_of_f[i] = src->array_of_f[i];
    }
  }
}

void s21_destroy_obj_data(s21_obj_data *data) {
  data->num_of_f = 0;
  data->num_of_v = 0;
  data->max_coord = 0.0f;
  free(data->array_of_v);
  free(data->array_of_f);
}

void s21_print_obj_data(s21_obj_data *data) {
  printf("\n\n");
  for (unsigned int i = 0; i < data->num_of_v / 3; i++) {
    printf("x:%10f y:%10f z:%10f\n", data->array_of_v[i * 3],
           data->array_of_v[i * 3 + 1], data->array_of_v[i * 3 + 2]);
  }
  printf("\n");
  for (unsigned int i = 0; i < data->num_of_f; i++) {
    printf("%u,", data->array_of_f[i]);
  }
  printf("\n\n");
  printf("v: %u (%u)\n", data->num_of_v / 3, data->num_of_v);
  printf("f: %u (%u)\n", data->num_of_f / 2, data->num_of_f);
  printf("max: %f\n", data->max_coord);
  printf("\n\n");
}
