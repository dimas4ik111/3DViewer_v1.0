#include <math.h>

#include "./backend.h"

void s21_move_x(s21_obj_data *data, float shift) {
  for (unsigned int i = 0; i < data->num_of_v; i += 3) {
    data->array_of_v[i] += shift;
  }
}

void s21_move_y(s21_obj_data *data, float shift) {
  for (unsigned int i = 1; i < data->num_of_v; i += 3) {
    data->array_of_v[i] += shift;
  }
}

void s21_move_z(s21_obj_data *data, float shift) {
  for (unsigned int i = 2; i < data->num_of_v; i += 3) {
    data->array_of_v[i] += shift;
  }
}

void s21_scale(s21_obj_data *data, float scale) {
  for (unsigned int i = 0; i < data->num_of_v; i++) {
    data->array_of_v[i] *= scale;
  }
}

void s21_rotate_x(s21_obj_data *data, float angle) {
  angle = s21_degres_to_radians(angle);
  for (unsigned int i = 0; i < data->num_of_v; i += 3) {
    float y = data->array_of_v[i + 1];
    float z = data->array_of_v[i + 2];

    data->array_of_v[i + 1] = y * cos(angle) - z * sin(angle);
    data->array_of_v[i + 2] = y * sin(angle) + z * cos(angle);
  }
}

void s21_rotate_y(s21_obj_data *data, float angle) {
  angle = s21_degres_to_radians(angle);
  for (unsigned int i = 0; i < data->num_of_v; i += 3) {
    float x = data->array_of_v[i];
    float z = data->array_of_v[i + 2];

    data->array_of_v[i] = x * cos(angle) - z * sin(angle);
    data->array_of_v[i + 2] = x * sin(angle) + z * cos(angle);
  }
}

void s21_rotate_z(s21_obj_data *data, float angle) {
  angle = s21_degres_to_radians(angle);
  for (unsigned int i = 0; i < data->num_of_v; i += 3) {
    float x = data->array_of_v[i];
    float y = data->array_of_v[i + 1];

    data->array_of_v[i] = x * cos(angle) - y * sin(angle);
    data->array_of_v[i + 1] = x * sin(angle) + y * cos(angle);
  }
}

float s21_degres_to_radians(float angle) { return angle * M_PI / 180; }
