#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на корректные данные
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

START_TEST(test_transform_ok1) {
  char *obj_path = "_objfiles/_cube.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  s21_move_x(&data, 0.5f);

  ck_assert_float_eq_tol(data.array_of_v[0], 1.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[3], 1.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[6], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[9], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[12], 1.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[15], 1.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[16], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[17], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[18], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[19], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[20], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[21], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[22], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[23], -1.000000, TEST_PRECISION);

  s21_destroy_obj_data(&data);
}

START_TEST(test_transform_ok2) {
  char *obj_path = "_objfiles/_cube.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  s21_move_y(&data, 0.5f);

  ck_assert_float_eq_tol(data.array_of_v[0], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[3], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[6], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[9], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[12], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 1.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[15], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[16], 1.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[17], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[18], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[19], 1.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[20], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[21], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[22], 1.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[23], -1.000000, TEST_PRECISION);

  s21_destroy_obj_data(&data);
}

START_TEST(test_transform_ok3) {
  char *obj_path = "_objfiles/_cube.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  s21_move_z(&data, 0.5f);

  ck_assert_float_eq_tol(data.array_of_v[0], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[3], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], 1.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[6], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], 1.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[9], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[12], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[15], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[16], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[17], 1.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[18], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[19], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[20], 1.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[21], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[22], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[23], -0.500000, TEST_PRECISION);

  s21_destroy_obj_data(&data);
}

START_TEST(test_transform_ok4) {
  char *obj_path = "_objfiles/_cube.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  s21_scale(&data, 0.5f);

  ck_assert_float_eq_tol(data.array_of_v[0], 0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[3], 0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], 0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[6], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], 0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[9], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[12], 0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[15], 0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[16], 0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[17], 0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[18], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[19], 0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[20], 0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[21], -0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[22], 0.500000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[23], -0.500000, TEST_PRECISION);

  s21_destroy_obj_data(&data);
}

START_TEST(test_transform_ok5) {
  char *obj_path = "_objfiles/_cube.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  s21_rotate_x(&data, 20.0f);

  ck_assert_float_eq_tol(data.array_of_v[0], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], -0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], -1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[3], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], -1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], 0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[6], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], -1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], 0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[9], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], -0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], -1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[12], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], -0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[15], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[16], 0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[17], 1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[18], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[19], 0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[20], 1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[21], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[22], 1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[23], -0.597672, TEST_PRECISION);

  s21_destroy_obj_data(&data);
}

START_TEST(test_transform_ok6) {
  char *obj_path = "_objfiles/_cube.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  s21_rotate_y(&data, 20.0f);

  ck_assert_float_eq_tol(data.array_of_v[0], 0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], -1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[3], 1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], 0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[6], -0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], 1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[9], -1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], -0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[12], 0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], -1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[15], 1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[16], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[17], 0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[18], -0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[19], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[20], 1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[21], -1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[22], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[23], -0.597672, TEST_PRECISION);

  s21_destroy_obj_data(&data);
}

START_TEST(test_transform_ok7) {
  char *obj_path = "_objfiles/_cube.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  s21_rotate_z(&data, 20.0f);

  ck_assert_float_eq_tol(data.array_of_v[0], 1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], -0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[3], 1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], -0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[6], -0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], -1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[9], -0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], -1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[12], 0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], -1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[15], 0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[16], 1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[17], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[18], -1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[19], 0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[20], 1.000000, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[21], -1.281713, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[22], 0.597672, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[23], -1.000000, TEST_PRECISION);

  s21_destroy_obj_data(&data);
}

Suite *transform_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("transform");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_transform_ok1);
  tcase_add_test(tc_core, test_transform_ok2);
  tcase_add_test(tc_core, test_transform_ok3);
  tcase_add_test(tc_core, test_transform_ok4);
  tcase_add_test(tc_core, test_transform_ok5);
  tcase_add_test(tc_core, test_transform_ok6);
  tcase_add_test(tc_core, test_transform_ok7);

  suite_add_tcase(s, tc_core);
  return s;
}
