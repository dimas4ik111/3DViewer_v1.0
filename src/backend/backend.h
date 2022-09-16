#ifndef SRC_BACKEND_BACKEND_H_
#define SRC_BACKEND_BACKEND_H_

#define S21_MEMORY_BLOCK_SIZE 128U
#define S21_MEMORY_BLOCK_SIZE_F 256U

typedef struct s21_obj_data {
  unsigned int num_of_v;
  unsigned int num_of_f;
  float *array_of_v;
  unsigned int *array_of_f;
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
