#ifndef SRC_BACKEND_BACKEND_H_
#define SRC_BACKEND_BACKEND_H_

typedef struct s21_vertex {
  float x;
  float y;
  float z;
} s21_vertex;

typedef struct s21_polygon {
  unsigned int *points;
  unsigned int num_of_points;
} s21_polygon;

typedef struct s21_obj_data {
  unsigned int num_of_v;
  unsigned int num_of_f;
  s21_vertex *array_of_v;
  s21_polygon *array_of_f;
} s21_obj_data;

typedef enum s21_boolean {
  S21_FALSE = 0,
  S21_TRUE = 1,
} s21_boolean;

void s21_parse_file(char *file_path, s21_obj_data *data);
void s21_parse_line_v(char *line, s21_obj_data *data);
void s21_parse_line_f(char *line, s21_obj_data *data);
void s21_destroy_obj_data(s21_obj_data *data);
void s21_print_obj_data(s21_obj_data *data);
s21_boolean s21_is_number(char symbol);

#endif  // SRC_BACKEND_BACKEND_H_
