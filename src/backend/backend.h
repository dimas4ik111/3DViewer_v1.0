#ifndef SRC_BACKEND_BACKEND_H_
#define SRC_BACKEND_BACKEND_H_

#define S21_MEMORY_BLOCK_SIZE 128U
#define S21_MEMORY_BLOCK_SIZE_F 256U

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct s21_obj_data {
  unsigned int num_of_v;
  unsigned int num_of_f;
  float max_coord;
  float *array_of_v;
  unsigned int *array_of_f;
} s21_obj_data;

typedef enum s21_boolean {
  S21_FALSE = 0,
  S21_TRUE = 1,
} s21_boolean;

typedef enum s21_parser_result {
  S21_PARSER_OK = 0,
  S21_PARSER_ERROR_FILE = 1,
  S21_PARSER_ERROR_MEMORY = 2,
} s21_parser_result;

s21_parser_result s21_parse_file(char *file_path, s21_obj_data *data,
                                 s21_boolean need_normalize);
s21_parser_result s21_parse_line_v(char *line, s21_obj_data *data);
s21_parser_result s21_parse_line_f(char *line, s21_obj_data *data);
s21_parser_result s21_allocate_memory_block_f(s21_obj_data *data);
s21_parser_result s21_allocate_memory_block_v(s21_obj_data *data);
void s21_init_obj_data(s21_obj_data *data);
void s21_destroy_obj_data(s21_obj_data *data);
void s21_print_obj_data(s21_obj_data *data);
void s21_copy_obj_data(s21_obj_data *dst, s21_obj_data *src);

void s21_move_x(s21_obj_data *data, float shift);
void s21_move_y(s21_obj_data *data, float shift);
void s21_move_z(s21_obj_data *data, float shift);
void s21_scale(s21_obj_data *data, float scale);
void s21_rotate_x(s21_obj_data *data, float angle);
void s21_rotate_y(s21_obj_data *data, float angle);
void s21_rotate_z(s21_obj_data *data, float angle);
float s21_degres_to_radians(float angle);

#endif  // SRC_BACKEND_BACKEND_H_
