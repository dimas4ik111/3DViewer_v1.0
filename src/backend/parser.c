#include <stdio.h>
#include <stdlib.h>

#include "backend.h"

void s21_parse_file(char *file_path, s21_obj_data *data) {
  FILE *file;
  char buff[1024];
  file = fopen(file_path, "r");
  // TODO(hubertfu): file open error
  if (file != NULL) {
    data->num_of_f = 0;
    data->num_of_v = 0;

    while (!feof(file)) {
      fgets(buff, 1024, file);
      if (buff[0] == 'v' && buff[1] == ' ') {
        s21_parse_line_v(buff, data);
      } else if (buff[0] == 'f' && buff[1] == ' ') {
        s21_parse_line_f(buff, data);
      }
      // if (data->num_of_v % 1000 == 0) {
      //   printf("{%u}\n", data->num_of_v);
      // }
    }

    fclose(file);
    // s21_print_obj_data(data);
  }
}

void s21_parse_line_v(char *line, s21_obj_data *data) {
  // TODO(hubertfu): handle incoorect lines
  if (data->num_of_v == 0) {
    // TODO(hubertfu): memory allocation by blocks
    data->array_of_v = malloc(1 * sizeof(s21_vertex));
  } else {
    data->array_of_v =
        realloc(data->array_of_v, (data->num_of_v + 1) * sizeof(s21_vertex));
  }

  if (data->array_of_v == NULL) {
    // TODO(hubertfu): handle memory errors
  }

  // TODO(hubertfu): scanf memory errors
  s21_vertex tmp = {0, 0, 0};
  sscanf(line, "v %f %f %f", &tmp.x, &tmp.y, &tmp.z);
  data->array_of_v[data->num_of_v] = tmp;
  ++(data->num_of_v);
}

void s21_parse_line_f(char *line, s21_obj_data *data) {
  // TODO(hubertfu): handle incoorect lines
  char *ptr = line;
  int flag = 0;

  if (data->num_of_f == 0) {
    // TODO(hubertfu): memory allocation by blocks
    // TODO(hubertfu): handle memory errors
    data->array_of_f = malloc(1 * sizeof(s21_vertex));
  } else {
    data->array_of_f =
        realloc(data->array_of_f, (data->num_of_f + 1) * sizeof(s21_polygon));
  }

  data->array_of_f[data->num_of_f].num_of_points = 0;

  while (*ptr != '\0') {
    if (s21_is_number(*ptr) && flag == 0) {
      unsigned int tmp;
      sscanf(ptr, "%u", &tmp);

      flag = 1;
      if (data->array_of_f[data->num_of_f].num_of_points == 0) {
        // TODO(hubertfu): memory allocation by blocks
        // TODO(hubertfu): handle memory errors
        data->array_of_f[data->num_of_f].points =
            malloc(1 * sizeof(unsigned int));
      } else {
        data->array_of_f[data->num_of_f].points =
            realloc(data->array_of_f[data->num_of_f].points,
                    (data->array_of_f[data->num_of_f].num_of_points + 1) *
                        sizeof(unsigned int));
      }
      data->array_of_f[data->num_of_f]
          .points[data->array_of_f[data->num_of_f].num_of_points] = tmp;
      ++(data->array_of_f[data->num_of_f].num_of_points);
    }
    if (*ptr == ' ') {
      flag = 0;
    }
    ++ptr;
  }

  ++(data->num_of_f);
}

s21_boolean s21_is_number(char symbol) {
  return ((int)symbol >= 48 && (int)symbol <= 57);
}

void s21_destroy_obj_data(s21_obj_data *data) {
  free(data->array_of_v);
  for (unsigned int i = 0; i < data->num_of_f; i++) {
    free(data->array_of_f[i].points);
  }
  free(data->array_of_f);
}

void s21_print_obj_data(s21_obj_data *data) {
  printf("\n\n");
  for (unsigned int i = 0; i < data->num_of_v; i++) {
    printf("x:%10f y:%10f z:%10f\n", data->array_of_v[i].x,
           data->array_of_v[i].y, data->array_of_v[i].z);
  }

  for (unsigned int i = 0; i < data->num_of_f; i++) {
    printf("f: ");
    for (unsigned int j = 0; j < data->array_of_f[i].num_of_points; j++) {
      printf("%u ", data->array_of_f[i].points[j]);
    }
    printf("\n");
  }
}
