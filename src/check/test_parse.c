#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на некорректные данные
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

START_TEST(test_parser_fail1) {
  char *obj_path = "_objfiles/";
  s21_obj_data data;
  s21_parser_result code_check = S21_PARSER_ERROR_FILE;
  test_parser_fail(obj_path, &data, code_check);
}

START_TEST(test_parser_fail2) {
  char *obj_path = "_objfiles/lkjhygtfrds.obj";
  s21_obj_data data;
  s21_parser_result code_check = S21_PARSER_ERROR_FILE;
  test_parser_fail(obj_path, &data, code_check);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на корректные данные
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

START_TEST(test_parser_ok1) {
  char *obj_path = "_objfiles/_cube.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  ck_assert_uint_eq(data.num_of_v, 24);
  ck_assert_uint_eq(data.num_of_f, 72);
  ck_assert_float_eq_tol(data.max_coord, 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[0], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], -1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[3], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[6], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[9], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], -1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[12], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], -1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[15], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[16], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[17], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[18], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[19], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[20], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[21], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[22], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[23], -1, TEST_PRECISION);

  ck_assert_uint_eq(data.array_of_f[0], 1);
  ck_assert_uint_eq(data.array_of_f[1], 2);
  ck_assert_uint_eq(data.array_of_f[2], 2);
  ck_assert_uint_eq(data.array_of_f[3], 3);
  ck_assert_uint_eq(data.array_of_f[4], 3);
  ck_assert_uint_eq(data.array_of_f[5], 1);
  ck_assert_uint_eq(data.array_of_f[6], 7);
  ck_assert_uint_eq(data.array_of_f[7], 6);
  ck_assert_uint_eq(data.array_of_f[8], 6);
  ck_assert_uint_eq(data.array_of_f[9], 5);
  ck_assert_uint_eq(data.array_of_f[10], 5);
  ck_assert_uint_eq(data.array_of_f[11], 7);
  ck_assert_uint_eq(data.array_of_f[12], 4);
  ck_assert_uint_eq(data.array_of_f[13], 5);
  ck_assert_uint_eq(data.array_of_f[14], 5);
  ck_assert_uint_eq(data.array_of_f[15], 1);
  ck_assert_uint_eq(data.array_of_f[16], 1);
  ck_assert_uint_eq(data.array_of_f[17], 4);
  ck_assert_uint_eq(data.array_of_f[18], 5);
  ck_assert_uint_eq(data.array_of_f[19], 6);
  ck_assert_uint_eq(data.array_of_f[20], 6);
  ck_assert_uint_eq(data.array_of_f[21], 2);
  ck_assert_uint_eq(data.array_of_f[22], 2);
  ck_assert_uint_eq(data.array_of_f[23], 5);
  ck_assert_uint_eq(data.array_of_f[24], 2);
  ck_assert_uint_eq(data.array_of_f[25], 6);
  ck_assert_uint_eq(data.array_of_f[26], 6);
  ck_assert_uint_eq(data.array_of_f[27], 7);
  ck_assert_uint_eq(data.array_of_f[28], 7);
  ck_assert_uint_eq(data.array_of_f[29], 2);
  ck_assert_uint_eq(data.array_of_f[30], 0);
  ck_assert_uint_eq(data.array_of_f[31], 3);
  ck_assert_uint_eq(data.array_of_f[32], 3);
  ck_assert_uint_eq(data.array_of_f[33], 7);
  ck_assert_uint_eq(data.array_of_f[34], 7);
  ck_assert_uint_eq(data.array_of_f[35], 0);
  ck_assert_uint_eq(data.array_of_f[36], 0);
  ck_assert_uint_eq(data.array_of_f[37], 1);
  ck_assert_uint_eq(data.array_of_f[38], 1);
  ck_assert_uint_eq(data.array_of_f[39], 3);
  ck_assert_uint_eq(data.array_of_f[40], 3);
  ck_assert_uint_eq(data.array_of_f[41], 0);
  ck_assert_uint_eq(data.array_of_f[42], 4);
  ck_assert_uint_eq(data.array_of_f[43], 7);
  ck_assert_uint_eq(data.array_of_f[44], 7);
  ck_assert_uint_eq(data.array_of_f[45], 5);
  ck_assert_uint_eq(data.array_of_f[46], 5);
  ck_assert_uint_eq(data.array_of_f[47], 4);
  ck_assert_uint_eq(data.array_of_f[48], 0);
  ck_assert_uint_eq(data.array_of_f[49], 4);
  ck_assert_uint_eq(data.array_of_f[50], 4);
  ck_assert_uint_eq(data.array_of_f[51], 1);
  ck_assert_uint_eq(data.array_of_f[52], 1);
  ck_assert_uint_eq(data.array_of_f[53], 0);
  ck_assert_uint_eq(data.array_of_f[54], 1);
  ck_assert_uint_eq(data.array_of_f[55], 5);
  ck_assert_uint_eq(data.array_of_f[56], 5);
  ck_assert_uint_eq(data.array_of_f[57], 2);
  ck_assert_uint_eq(data.array_of_f[58], 2);
  ck_assert_uint_eq(data.array_of_f[59], 1);
  ck_assert_uint_eq(data.array_of_f[60], 3);
  ck_assert_uint_eq(data.array_of_f[61], 2);
  ck_assert_uint_eq(data.array_of_f[62], 2);
  ck_assert_uint_eq(data.array_of_f[63], 7);
  ck_assert_uint_eq(data.array_of_f[64], 7);
  ck_assert_uint_eq(data.array_of_f[65], 3);
  ck_assert_uint_eq(data.array_of_f[66], 4);
  ck_assert_uint_eq(data.array_of_f[67], 0);
  ck_assert_uint_eq(data.array_of_f[68], 0);
  ck_assert_uint_eq(data.array_of_f[69], 7);
  ck_assert_uint_eq(data.array_of_f[70], 7);
  ck_assert_uint_eq(data.array_of_f[71], 4);

  s21_print_obj_data(&data);
  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok2) {
  char *obj_path = "_objfiles/_cube.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_TRUE);

  ck_assert_uint_eq(data.num_of_v, 24);
  ck_assert_uint_eq(data.num_of_f, 72);
  ck_assert_float_eq_tol(data.max_coord, 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[0], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], -1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[3], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[6], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[9], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], -1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[12], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], -1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[15], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[16], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[17], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[18], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[19], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[20], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[21], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[22], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[23], -1, TEST_PRECISION);

  ck_assert_uint_eq(data.array_of_f[0], 1);
  ck_assert_uint_eq(data.array_of_f[1], 2);
  ck_assert_uint_eq(data.array_of_f[2], 2);
  ck_assert_uint_eq(data.array_of_f[3], 3);
  ck_assert_uint_eq(data.array_of_f[4], 3);
  ck_assert_uint_eq(data.array_of_f[5], 1);
  ck_assert_uint_eq(data.array_of_f[6], 7);
  ck_assert_uint_eq(data.array_of_f[7], 6);
  ck_assert_uint_eq(data.array_of_f[8], 6);
  ck_assert_uint_eq(data.array_of_f[9], 5);
  ck_assert_uint_eq(data.array_of_f[10], 5);
  ck_assert_uint_eq(data.array_of_f[11], 7);
  ck_assert_uint_eq(data.array_of_f[12], 4);
  ck_assert_uint_eq(data.array_of_f[13], 5);
  ck_assert_uint_eq(data.array_of_f[14], 5);
  ck_assert_uint_eq(data.array_of_f[15], 1);
  ck_assert_uint_eq(data.array_of_f[16], 1);
  ck_assert_uint_eq(data.array_of_f[17], 4);
  ck_assert_uint_eq(data.array_of_f[18], 5);
  ck_assert_uint_eq(data.array_of_f[19], 6);
  ck_assert_uint_eq(data.array_of_f[20], 6);
  ck_assert_uint_eq(data.array_of_f[21], 2);
  ck_assert_uint_eq(data.array_of_f[22], 2);
  ck_assert_uint_eq(data.array_of_f[23], 5);
  ck_assert_uint_eq(data.array_of_f[24], 2);
  ck_assert_uint_eq(data.array_of_f[25], 6);
  ck_assert_uint_eq(data.array_of_f[26], 6);
  ck_assert_uint_eq(data.array_of_f[27], 7);
  ck_assert_uint_eq(data.array_of_f[28], 7);
  ck_assert_uint_eq(data.array_of_f[29], 2);
  ck_assert_uint_eq(data.array_of_f[30], 0);
  ck_assert_uint_eq(data.array_of_f[31], 3);
  ck_assert_uint_eq(data.array_of_f[32], 3);
  ck_assert_uint_eq(data.array_of_f[33], 7);
  ck_assert_uint_eq(data.array_of_f[34], 7);
  ck_assert_uint_eq(data.array_of_f[35], 0);
  ck_assert_uint_eq(data.array_of_f[36], 0);
  ck_assert_uint_eq(data.array_of_f[37], 1);
  ck_assert_uint_eq(data.array_of_f[38], 1);
  ck_assert_uint_eq(data.array_of_f[39], 3);
  ck_assert_uint_eq(data.array_of_f[40], 3);
  ck_assert_uint_eq(data.array_of_f[41], 0);
  ck_assert_uint_eq(data.array_of_f[42], 4);
  ck_assert_uint_eq(data.array_of_f[43], 7);
  ck_assert_uint_eq(data.array_of_f[44], 7);
  ck_assert_uint_eq(data.array_of_f[45], 5);
  ck_assert_uint_eq(data.array_of_f[46], 5);
  ck_assert_uint_eq(data.array_of_f[47], 4);
  ck_assert_uint_eq(data.array_of_f[48], 0);
  ck_assert_uint_eq(data.array_of_f[49], 4);
  ck_assert_uint_eq(data.array_of_f[50], 4);
  ck_assert_uint_eq(data.array_of_f[51], 1);
  ck_assert_uint_eq(data.array_of_f[52], 1);
  ck_assert_uint_eq(data.array_of_f[53], 0);
  ck_assert_uint_eq(data.array_of_f[54], 1);
  ck_assert_uint_eq(data.array_of_f[55], 5);
  ck_assert_uint_eq(data.array_of_f[56], 5);
  ck_assert_uint_eq(data.array_of_f[57], 2);
  ck_assert_uint_eq(data.array_of_f[58], 2);
  ck_assert_uint_eq(data.array_of_f[59], 1);
  ck_assert_uint_eq(data.array_of_f[60], 3);
  ck_assert_uint_eq(data.array_of_f[61], 2);
  ck_assert_uint_eq(data.array_of_f[62], 2);
  ck_assert_uint_eq(data.array_of_f[63], 7);
  ck_assert_uint_eq(data.array_of_f[64], 7);
  ck_assert_uint_eq(data.array_of_f[65], 3);
  ck_assert_uint_eq(data.array_of_f[66], 4);
  ck_assert_uint_eq(data.array_of_f[67], 0);
  ck_assert_uint_eq(data.array_of_f[68], 0);
  ck_assert_uint_eq(data.array_of_f[69], 7);
  ck_assert_uint_eq(data.array_of_f[70], 7);
  ck_assert_uint_eq(data.array_of_f[71], 4);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok3) {
  char *obj_path = "_objfiles/_cube 2.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  ck_assert_uint_eq(data.num_of_v, 24);
  ck_assert_uint_eq(data.num_of_f, 60);
  ck_assert_float_eq_tol(data.max_coord, 2, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[0], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[3], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], 2, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[6], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[9], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], 2, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[12], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[15], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[16], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[17], 2, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[18], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[19], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[20], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[21], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[22], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[23], 2, TEST_PRECISION);

  ck_assert_uint_eq(data.array_of_f[0], 0);
  ck_assert_uint_eq(data.array_of_f[1], 6);
  ck_assert_uint_eq(data.array_of_f[2], 6);
  ck_assert_uint_eq(data.array_of_f[3], 4);
  ck_assert_uint_eq(data.array_of_f[4], 4);
  ck_assert_uint_eq(data.array_of_f[5], 0);
  ck_assert_uint_eq(data.array_of_f[6], 0);
  ck_assert_uint_eq(data.array_of_f[7], 2);
  ck_assert_uint_eq(data.array_of_f[8], 2);
  ck_assert_uint_eq(data.array_of_f[9], 6);
  ck_assert_uint_eq(data.array_of_f[10], 6);
  ck_assert_uint_eq(data.array_of_f[11], 0);
  ck_assert_uint_eq(data.array_of_f[12], 0);
  ck_assert_uint_eq(data.array_of_f[13], 3);
  ck_assert_uint_eq(data.array_of_f[14], 3);
  ck_assert_uint_eq(data.array_of_f[15], 2);
  ck_assert_uint_eq(data.array_of_f[16], 2);
  ck_assert_uint_eq(data.array_of_f[17], 0);
  ck_assert_uint_eq(data.array_of_f[18], 0);
  ck_assert_uint_eq(data.array_of_f[19], 1);
  ck_assert_uint_eq(data.array_of_f[20], 1);
  ck_assert_uint_eq(data.array_of_f[21], 3);
  ck_assert_uint_eq(data.array_of_f[22], 3);
  ck_assert_uint_eq(data.array_of_f[23], 0);
  ck_assert_uint_eq(data.array_of_f[24], 2);
  ck_assert_uint_eq(data.array_of_f[25], 7);
  ck_assert_uint_eq(data.array_of_f[26], 7);
  ck_assert_uint_eq(data.array_of_f[27], 6);
  ck_assert_uint_eq(data.array_of_f[28], 6);
  ck_assert_uint_eq(data.array_of_f[29], 2);
  ck_assert_uint_eq(data.array_of_f[30], 2);
  ck_assert_uint_eq(data.array_of_f[31], 3);
  ck_assert_uint_eq(data.array_of_f[32], 3);
  ck_assert_uint_eq(data.array_of_f[33], 7);
  ck_assert_uint_eq(data.array_of_f[34], 7);
  ck_assert_uint_eq(data.array_of_f[35], 2);
  ck_assert_uint_eq(data.array_of_f[36], 4);
  ck_assert_uint_eq(data.array_of_f[37], 6);
  ck_assert_uint_eq(data.array_of_f[38], 6);
  ck_assert_uint_eq(data.array_of_f[39], 7);
  ck_assert_uint_eq(data.array_of_f[40], 7);
  ck_assert_uint_eq(data.array_of_f[41], 4);
  ck_assert_uint_eq(data.array_of_f[42], 4);
  ck_assert_uint_eq(data.array_of_f[43], 7);
  ck_assert_uint_eq(data.array_of_f[44], 7);
  ck_assert_uint_eq(data.array_of_f[45], 5);
  ck_assert_uint_eq(data.array_of_f[46], 5);
  ck_assert_uint_eq(data.array_of_f[47], 4);
  ck_assert_uint_eq(data.array_of_f[48], 0);
  ck_assert_uint_eq(data.array_of_f[49], 4);
  ck_assert_uint_eq(data.array_of_f[50], 4);
  ck_assert_uint_eq(data.array_of_f[51], 5);
  ck_assert_uint_eq(data.array_of_f[52], 5);
  ck_assert_uint_eq(data.array_of_f[53], 0);
  ck_assert_uint_eq(data.array_of_f[54], 0);
  ck_assert_uint_eq(data.array_of_f[55], 5);
  ck_assert_uint_eq(data.array_of_f[56], 5);
  ck_assert_uint_eq(data.array_of_f[57], 1);
  ck_assert_uint_eq(data.array_of_f[58], 1);
  ck_assert_uint_eq(data.array_of_f[59], 0);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok4) {
  char *obj_path = "_objfiles/_cube 2.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_TRUE);

  ck_assert_uint_eq(data.num_of_v, 24);
  ck_assert_uint_eq(data.num_of_f, 60);
  ck_assert_float_eq_tol(data.max_coord, 2, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[0], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[3], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[6], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[9], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[12], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[15], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[16], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[17], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[18], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[19], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[20], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[21], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[22], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[23], 1, TEST_PRECISION);

  ck_assert_uint_eq(data.array_of_f[0], 0);
  ck_assert_uint_eq(data.array_of_f[1], 6);
  ck_assert_uint_eq(data.array_of_f[2], 6);
  ck_assert_uint_eq(data.array_of_f[3], 4);
  ck_assert_uint_eq(data.array_of_f[4], 4);
  ck_assert_uint_eq(data.array_of_f[5], 0);
  ck_assert_uint_eq(data.array_of_f[6], 0);
  ck_assert_uint_eq(data.array_of_f[7], 2);
  ck_assert_uint_eq(data.array_of_f[8], 2);
  ck_assert_uint_eq(data.array_of_f[9], 6);
  ck_assert_uint_eq(data.array_of_f[10], 6);
  ck_assert_uint_eq(data.array_of_f[11], 0);
  ck_assert_uint_eq(data.array_of_f[12], 0);
  ck_assert_uint_eq(data.array_of_f[13], 3);
  ck_assert_uint_eq(data.array_of_f[14], 3);
  ck_assert_uint_eq(data.array_of_f[15], 2);
  ck_assert_uint_eq(data.array_of_f[16], 2);
  ck_assert_uint_eq(data.array_of_f[17], 0);
  ck_assert_uint_eq(data.array_of_f[18], 0);
  ck_assert_uint_eq(data.array_of_f[19], 1);
  ck_assert_uint_eq(data.array_of_f[20], 1);
  ck_assert_uint_eq(data.array_of_f[21], 3);
  ck_assert_uint_eq(data.array_of_f[22], 3);
  ck_assert_uint_eq(data.array_of_f[23], 0);
  ck_assert_uint_eq(data.array_of_f[24], 2);
  ck_assert_uint_eq(data.array_of_f[25], 7);
  ck_assert_uint_eq(data.array_of_f[26], 7);
  ck_assert_uint_eq(data.array_of_f[27], 6);
  ck_assert_uint_eq(data.array_of_f[28], 6);
  ck_assert_uint_eq(data.array_of_f[29], 2);
  ck_assert_uint_eq(data.array_of_f[30], 2);
  ck_assert_uint_eq(data.array_of_f[31], 3);
  ck_assert_uint_eq(data.array_of_f[32], 3);
  ck_assert_uint_eq(data.array_of_f[33], 7);
  ck_assert_uint_eq(data.array_of_f[34], 7);
  ck_assert_uint_eq(data.array_of_f[35], 2);
  ck_assert_uint_eq(data.array_of_f[36], 4);
  ck_assert_uint_eq(data.array_of_f[37], 6);
  ck_assert_uint_eq(data.array_of_f[38], 6);
  ck_assert_uint_eq(data.array_of_f[39], 7);
  ck_assert_uint_eq(data.array_of_f[40], 7);
  ck_assert_uint_eq(data.array_of_f[41], 4);
  ck_assert_uint_eq(data.array_of_f[42], 4);
  ck_assert_uint_eq(data.array_of_f[43], 7);
  ck_assert_uint_eq(data.array_of_f[44], 7);
  ck_assert_uint_eq(data.array_of_f[45], 5);
  ck_assert_uint_eq(data.array_of_f[46], 5);
  ck_assert_uint_eq(data.array_of_f[47], 4);
  ck_assert_uint_eq(data.array_of_f[48], 0);
  ck_assert_uint_eq(data.array_of_f[49], 4);
  ck_assert_uint_eq(data.array_of_f[50], 4);
  ck_assert_uint_eq(data.array_of_f[51], 5);
  ck_assert_uint_eq(data.array_of_f[52], 5);
  ck_assert_uint_eq(data.array_of_f[53], 0);
  ck_assert_uint_eq(data.array_of_f[54], 0);
  ck_assert_uint_eq(data.array_of_f[55], 5);
  ck_assert_uint_eq(data.array_of_f[56], 5);
  ck_assert_uint_eq(data.array_of_f[57], 1);
  ck_assert_uint_eq(data.array_of_f[58], 1);
  ck_assert_uint_eq(data.array_of_f[59], 0);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok5) {
  char *obj_path = "_objfiles/in cube 2.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  ck_assert_uint_eq(data.num_of_v, 24);
  ck_assert_uint_eq(data.num_of_f, 60);
  ck_assert_float_eq_tol(data.max_coord, 2, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[0], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[3], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], 2, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[6], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[9], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], 2, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[12], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[15], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[16], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[17], 2, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[18], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[19], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[20], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[21], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[22], 2, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[23], 2, TEST_PRECISION);

  ck_assert_uint_eq(data.array_of_f[0], 0);
  ck_assert_uint_eq(data.array_of_f[1], 6);
  ck_assert_uint_eq(data.array_of_f[2], 6);
  ck_assert_uint_eq(data.array_of_f[3], 4);
  ck_assert_uint_eq(data.array_of_f[4], 4);
  ck_assert_uint_eq(data.array_of_f[5], 0);
  ck_assert_uint_eq(data.array_of_f[6], 0);
  ck_assert_uint_eq(data.array_of_f[7], 2);
  ck_assert_uint_eq(data.array_of_f[8], 2);
  ck_assert_uint_eq(data.array_of_f[9], 6);
  ck_assert_uint_eq(data.array_of_f[10], 6);
  ck_assert_uint_eq(data.array_of_f[11], 0);
  ck_assert_uint_eq(data.array_of_f[12], 0);
  ck_assert_uint_eq(data.array_of_f[13], 3);
  ck_assert_uint_eq(data.array_of_f[14], 3);
  ck_assert_uint_eq(data.array_of_f[15], 2);
  ck_assert_uint_eq(data.array_of_f[16], 2);
  ck_assert_uint_eq(data.array_of_f[17], 0);
  ck_assert_uint_eq(data.array_of_f[18], 0);
  ck_assert_uint_eq(data.array_of_f[19], 1);
  ck_assert_uint_eq(data.array_of_f[20], 1);
  ck_assert_uint_eq(data.array_of_f[21], 3);
  ck_assert_uint_eq(data.array_of_f[22], 3);
  ck_assert_uint_eq(data.array_of_f[23], 0);
  ck_assert_uint_eq(data.array_of_f[24], 2);
  ck_assert_uint_eq(data.array_of_f[25], 7);
  ck_assert_uint_eq(data.array_of_f[26], 7);
  ck_assert_uint_eq(data.array_of_f[27], 6);
  ck_assert_uint_eq(data.array_of_f[28], 6);
  ck_assert_uint_eq(data.array_of_f[29], 2);
  ck_assert_uint_eq(data.array_of_f[30], 2);
  ck_assert_uint_eq(data.array_of_f[31], 3);
  ck_assert_uint_eq(data.array_of_f[32], 3);
  ck_assert_uint_eq(data.array_of_f[33], 7);
  ck_assert_uint_eq(data.array_of_f[34], 7);
  ck_assert_uint_eq(data.array_of_f[35], 2);
  ck_assert_uint_eq(data.array_of_f[36], 4);
  ck_assert_uint_eq(data.array_of_f[37], 6);
  ck_assert_uint_eq(data.array_of_f[38], 6);
  ck_assert_uint_eq(data.array_of_f[39], 7);
  ck_assert_uint_eq(data.array_of_f[40], 7);
  ck_assert_uint_eq(data.array_of_f[41], 4);
  ck_assert_uint_eq(data.array_of_f[42], 4);
  ck_assert_uint_eq(data.array_of_f[43], 7);
  ck_assert_uint_eq(data.array_of_f[44], 7);
  ck_assert_uint_eq(data.array_of_f[45], 5);
  ck_assert_uint_eq(data.array_of_f[46], 5);
  ck_assert_uint_eq(data.array_of_f[47], 4);
  ck_assert_uint_eq(data.array_of_f[48], 0);
  ck_assert_uint_eq(data.array_of_f[49], 4);
  ck_assert_uint_eq(data.array_of_f[50], 4);
  ck_assert_uint_eq(data.array_of_f[51], 5);
  ck_assert_uint_eq(data.array_of_f[52], 5);
  ck_assert_uint_eq(data.array_of_f[53], 0);
  ck_assert_uint_eq(data.array_of_f[54], 0);
  ck_assert_uint_eq(data.array_of_f[55], 5);
  ck_assert_uint_eq(data.array_of_f[56], 5);
  ck_assert_uint_eq(data.array_of_f[57], 1);
  ck_assert_uint_eq(data.array_of_f[58], 1);
  ck_assert_uint_eq(data.array_of_f[59], 0);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok6) {
  char *obj_path = "_objfiles/in cube.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  ck_assert_uint_eq(data.num_of_v, 24);
  ck_assert_uint_eq(data.num_of_f, 72);
  ck_assert_float_eq_tol(data.max_coord, 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[0], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], -1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[3], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[6], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[9], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], -1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[12], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], -1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[15], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[16], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[17], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[18], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[19], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[20], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[21], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[22], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[23], -1, TEST_PRECISION);

  ck_assert_uint_eq(data.array_of_f[0], 1);
  ck_assert_uint_eq(data.array_of_f[1], 2);
  ck_assert_uint_eq(data.array_of_f[2], 2);
  ck_assert_uint_eq(data.array_of_f[3], 3);
  ck_assert_uint_eq(data.array_of_f[4], 3);
  ck_assert_uint_eq(data.array_of_f[5], 1);
  ck_assert_uint_eq(data.array_of_f[6], 7);
  ck_assert_uint_eq(data.array_of_f[7], 6);
  ck_assert_uint_eq(data.array_of_f[8], 6);
  ck_assert_uint_eq(data.array_of_f[9], 5);
  ck_assert_uint_eq(data.array_of_f[10], 5);
  ck_assert_uint_eq(data.array_of_f[11], 7);
  ck_assert_uint_eq(data.array_of_f[12], 4);
  ck_assert_uint_eq(data.array_of_f[13], 5);
  ck_assert_uint_eq(data.array_of_f[14], 5);
  ck_assert_uint_eq(data.array_of_f[15], 1);
  ck_assert_uint_eq(data.array_of_f[16], 1);
  ck_assert_uint_eq(data.array_of_f[17], 4);
  ck_assert_uint_eq(data.array_of_f[18], 5);
  ck_assert_uint_eq(data.array_of_f[19], 6);
  ck_assert_uint_eq(data.array_of_f[20], 6);
  ck_assert_uint_eq(data.array_of_f[21], 2);
  ck_assert_uint_eq(data.array_of_f[22], 2);
  ck_assert_uint_eq(data.array_of_f[23], 5);
  ck_assert_uint_eq(data.array_of_f[24], 2);
  ck_assert_uint_eq(data.array_of_f[25], 6);
  ck_assert_uint_eq(data.array_of_f[26], 6);
  ck_assert_uint_eq(data.array_of_f[27], 7);
  ck_assert_uint_eq(data.array_of_f[28], 7);
  ck_assert_uint_eq(data.array_of_f[29], 2);
  ck_assert_uint_eq(data.array_of_f[30], 0);
  ck_assert_uint_eq(data.array_of_f[31], 3);
  ck_assert_uint_eq(data.array_of_f[32], 3);
  ck_assert_uint_eq(data.array_of_f[33], 7);
  ck_assert_uint_eq(data.array_of_f[34], 7);
  ck_assert_uint_eq(data.array_of_f[35], 0);
  ck_assert_uint_eq(data.array_of_f[36], 0);
  ck_assert_uint_eq(data.array_of_f[37], 1);
  ck_assert_uint_eq(data.array_of_f[38], 1);
  ck_assert_uint_eq(data.array_of_f[39], 3);
  ck_assert_uint_eq(data.array_of_f[40], 3);
  ck_assert_uint_eq(data.array_of_f[41], 0);
  ck_assert_uint_eq(data.array_of_f[42], 4);
  ck_assert_uint_eq(data.array_of_f[43], 7);
  ck_assert_uint_eq(data.array_of_f[44], 7);
  ck_assert_uint_eq(data.array_of_f[45], 5);
  ck_assert_uint_eq(data.array_of_f[46], 5);
  ck_assert_uint_eq(data.array_of_f[47], 4);
  ck_assert_uint_eq(data.array_of_f[48], 0);
  ck_assert_uint_eq(data.array_of_f[49], 4);
  ck_assert_uint_eq(data.array_of_f[50], 4);
  ck_assert_uint_eq(data.array_of_f[51], 1);
  ck_assert_uint_eq(data.array_of_f[52], 1);
  ck_assert_uint_eq(data.array_of_f[53], 0);
  ck_assert_uint_eq(data.array_of_f[54], 1);
  ck_assert_uint_eq(data.array_of_f[55], 5);
  ck_assert_uint_eq(data.array_of_f[56], 5);
  ck_assert_uint_eq(data.array_of_f[57], 2);
  ck_assert_uint_eq(data.array_of_f[58], 2);
  ck_assert_uint_eq(data.array_of_f[59], 1);
  ck_assert_uint_eq(data.array_of_f[60], 3);
  ck_assert_uint_eq(data.array_of_f[61], 2);
  ck_assert_uint_eq(data.array_of_f[62], 2);
  ck_assert_uint_eq(data.array_of_f[63], 7);
  ck_assert_uint_eq(data.array_of_f[64], 7);
  ck_assert_uint_eq(data.array_of_f[65], 3);
  ck_assert_uint_eq(data.array_of_f[66], 4);
  ck_assert_uint_eq(data.array_of_f[67], 0);
  ck_assert_uint_eq(data.array_of_f[68], 0);
  ck_assert_uint_eq(data.array_of_f[69], 7);
  ck_assert_uint_eq(data.array_of_f[70], 7);
  ck_assert_uint_eq(data.array_of_f[71], 4);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok7) {
  char *obj_path = "_objfiles/_pyramid.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  ck_assert_uint_eq(data.num_of_v, 15);
  ck_assert_uint_eq(data.num_of_f, 36);
  ck_assert_float_eq_tol(data.max_coord, 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[0], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[3], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], -1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[6], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], -1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[9], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[12], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], 1, TEST_PRECISION);

  ck_assert_uint_eq(data.array_of_f[0], 0);
  ck_assert_uint_eq(data.array_of_f[1], 1);
  ck_assert_uint_eq(data.array_of_f[2], 1);
  ck_assert_uint_eq(data.array_of_f[3], 2);
  ck_assert_uint_eq(data.array_of_f[4], 2);
  ck_assert_uint_eq(data.array_of_f[5], 0);
  ck_assert_uint_eq(data.array_of_f[6], 0);
  ck_assert_uint_eq(data.array_of_f[7], 2);
  ck_assert_uint_eq(data.array_of_f[8], 2);
  ck_assert_uint_eq(data.array_of_f[9], 3);
  ck_assert_uint_eq(data.array_of_f[10], 3);
  ck_assert_uint_eq(data.array_of_f[11], 0);
  ck_assert_uint_eq(data.array_of_f[12], 0);
  ck_assert_uint_eq(data.array_of_f[13], 3);
  ck_assert_uint_eq(data.array_of_f[14], 3);
  ck_assert_uint_eq(data.array_of_f[15], 4);
  ck_assert_uint_eq(data.array_of_f[16], 4);
  ck_assert_uint_eq(data.array_of_f[17], 0);
  ck_assert_uint_eq(data.array_of_f[18], 0);
  ck_assert_uint_eq(data.array_of_f[19], 4);
  ck_assert_uint_eq(data.array_of_f[20], 4);
  ck_assert_uint_eq(data.array_of_f[21], 1);
  ck_assert_uint_eq(data.array_of_f[22], 1);
  ck_assert_uint_eq(data.array_of_f[23], 0);
  ck_assert_uint_eq(data.array_of_f[24], 2);
  ck_assert_uint_eq(data.array_of_f[25], 1);
  ck_assert_uint_eq(data.array_of_f[26], 1);
  ck_assert_uint_eq(data.array_of_f[27], 3);
  ck_assert_uint_eq(data.array_of_f[28], 3);
  ck_assert_uint_eq(data.array_of_f[29], 2);
  ck_assert_uint_eq(data.array_of_f[30], 1);
  ck_assert_uint_eq(data.array_of_f[31], 4);
  ck_assert_uint_eq(data.array_of_f[32], 4);
  ck_assert_uint_eq(data.array_of_f[33], 3);
  ck_assert_uint_eq(data.array_of_f[34], 3);
  ck_assert_uint_eq(data.array_of_f[35], 1);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok8) {
  char *obj_path = "_objfiles/in pyramid.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  ck_assert_uint_eq(data.num_of_v, 15);
  ck_assert_uint_eq(data.num_of_f, 36);
  ck_assert_float_eq_tol(data.max_coord, 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[0], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[3], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], -1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[6], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], -1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[9], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[12], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], 1, TEST_PRECISION);

  ck_assert_uint_eq(data.array_of_f[0], 0);
  ck_assert_uint_eq(data.array_of_f[1], 1);
  ck_assert_uint_eq(data.array_of_f[2], 1);
  ck_assert_uint_eq(data.array_of_f[3], 2);
  ck_assert_uint_eq(data.array_of_f[4], 2);
  ck_assert_uint_eq(data.array_of_f[5], 0);
  ck_assert_uint_eq(data.array_of_f[6], 0);
  ck_assert_uint_eq(data.array_of_f[7], 2);
  ck_assert_uint_eq(data.array_of_f[8], 2);
  ck_assert_uint_eq(data.array_of_f[9], 3);
  ck_assert_uint_eq(data.array_of_f[10], 3);
  ck_assert_uint_eq(data.array_of_f[11], 0);
  ck_assert_uint_eq(data.array_of_f[12], 0);
  ck_assert_uint_eq(data.array_of_f[13], 3);
  ck_assert_uint_eq(data.array_of_f[14], 3);
  ck_assert_uint_eq(data.array_of_f[15], 4);
  ck_assert_uint_eq(data.array_of_f[16], 4);
  ck_assert_uint_eq(data.array_of_f[17], 0);
  ck_assert_uint_eq(data.array_of_f[18], 0);
  ck_assert_uint_eq(data.array_of_f[19], 4);
  ck_assert_uint_eq(data.array_of_f[20], 4);
  ck_assert_uint_eq(data.array_of_f[21], 1);
  ck_assert_uint_eq(data.array_of_f[22], 1);
  ck_assert_uint_eq(data.array_of_f[23], 0);
  ck_assert_uint_eq(data.array_of_f[24], 2);
  ck_assert_uint_eq(data.array_of_f[25], 1);
  ck_assert_uint_eq(data.array_of_f[26], 1);
  ck_assert_uint_eq(data.array_of_f[27], 3);
  ck_assert_uint_eq(data.array_of_f[28], 3);
  ck_assert_uint_eq(data.array_of_f[29], 2);
  ck_assert_uint_eq(data.array_of_f[30], 1);
  ck_assert_uint_eq(data.array_of_f[31], 4);
  ck_assert_uint_eq(data.array_of_f[32], 4);
  ck_assert_uint_eq(data.array_of_f[33], 3);
  ck_assert_uint_eq(data.array_of_f[34], 3);
  ck_assert_uint_eq(data.array_of_f[35], 1);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok9) {
  char *obj_path = "_objfiles/_octahedron.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  ck_assert_uint_eq(data.num_of_v, 18);
  ck_assert_uint_eq(data.num_of_f, 48);
  ck_assert_float_eq_tol(data.max_coord, 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[0], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[1], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[2], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[3], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[4], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[5], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[6], -1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[7], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[8], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[9], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[10], 1, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[11], 0, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[12], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[13], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[14], 1, TEST_PRECISION);

  ck_assert_float_eq_tol(data.array_of_v[15], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[16], 0, TEST_PRECISION);
  ck_assert_float_eq_tol(data.array_of_v[17], -1, TEST_PRECISION);

  ck_assert_uint_eq(data.array_of_f[0], 1);
  ck_assert_uint_eq(data.array_of_f[1], 0);
  ck_assert_uint_eq(data.array_of_f[2], 0);
  ck_assert_uint_eq(data.array_of_f[3], 4);
  ck_assert_uint_eq(data.array_of_f[4], 4);
  ck_assert_uint_eq(data.array_of_f[5], 1);
  ck_assert_uint_eq(data.array_of_f[6], 2);
  ck_assert_uint_eq(data.array_of_f[7], 1);
  ck_assert_uint_eq(data.array_of_f[8], 1);
  ck_assert_uint_eq(data.array_of_f[9], 4);
  ck_assert_uint_eq(data.array_of_f[10], 4);
  ck_assert_uint_eq(data.array_of_f[11], 2);
  ck_assert_uint_eq(data.array_of_f[12], 3);
  ck_assert_uint_eq(data.array_of_f[13], 2);
  ck_assert_uint_eq(data.array_of_f[14], 2);
  ck_assert_uint_eq(data.array_of_f[15], 4);
  ck_assert_uint_eq(data.array_of_f[16], 4);
  ck_assert_uint_eq(data.array_of_f[17], 3);
  ck_assert_uint_eq(data.array_of_f[18], 0);
  ck_assert_uint_eq(data.array_of_f[19], 3);
  ck_assert_uint_eq(data.array_of_f[20], 3);
  ck_assert_uint_eq(data.array_of_f[21], 4);
  ck_assert_uint_eq(data.array_of_f[22], 4);
  ck_assert_uint_eq(data.array_of_f[23], 0);
  ck_assert_uint_eq(data.array_of_f[24], 0);
  ck_assert_uint_eq(data.array_of_f[25], 1);
  ck_assert_uint_eq(data.array_of_f[26], 1);
  ck_assert_uint_eq(data.array_of_f[27], 5);
  ck_assert_uint_eq(data.array_of_f[28], 5);
  ck_assert_uint_eq(data.array_of_f[29], 0);
  ck_assert_uint_eq(data.array_of_f[30], 1);
  ck_assert_uint_eq(data.array_of_f[31], 2);
  ck_assert_uint_eq(data.array_of_f[32], 2);
  ck_assert_uint_eq(data.array_of_f[33], 5);
  ck_assert_uint_eq(data.array_of_f[34], 5);
  ck_assert_uint_eq(data.array_of_f[35], 1);
  ck_assert_uint_eq(data.array_of_f[36], 2);
  ck_assert_uint_eq(data.array_of_f[37], 3);
  ck_assert_uint_eq(data.array_of_f[38], 3);
  ck_assert_uint_eq(data.array_of_f[39], 5);
  ck_assert_uint_eq(data.array_of_f[40], 5);
  ck_assert_uint_eq(data.array_of_f[41], 2);
  ck_assert_uint_eq(data.array_of_f[42], 3);
  ck_assert_uint_eq(data.array_of_f[43], 0);
  ck_assert_uint_eq(data.array_of_f[44], 0);
  ck_assert_uint_eq(data.array_of_f[45], 5);
  ck_assert_uint_eq(data.array_of_f[46], 5);
  ck_assert_uint_eq(data.array_of_f[47], 3);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok10) {
  char *obj_path = "_objfiles/100 cottage_obj.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  ck_assert_uint_eq(data.num_of_v, 1059);
  ck_assert_uint_eq(data.num_of_f, 2008);
  ck_assert_float_eq_tol(data.max_coord, 167.101471, TEST_PRECISION);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok11) {
  char *obj_path = "_objfiles/1000 Glass.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  ck_assert_uint_eq(data.num_of_v, 2688);
  ck_assert_uint_eq(data.num_of_f, 7040);
  ck_assert_float_eq_tol(data.max_coord, 5.073612, TEST_PRECISION);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok12) {
  char *obj_path = "_objfiles/10000 Gun.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  ck_assert_uint_eq(data.num_of_v, 39492);
  ck_assert_uint_eq(data.num_of_f, 87324);
  ck_assert_float_eq_tol(data.max_coord, 7.334266, TEST_PRECISION);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok13) {
  char *obj_path = "_objfiles/100000 sirus city.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  ck_assert_uint_eq(data.num_of_v, 392790);
  ck_assert_uint_eq(data.num_of_f, 801824);
  ck_assert_float_eq_tol(data.max_coord, 1276.29, TEST_PRECISION);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok14) {
  char *obj_path = "_objfiles/1000000 tree.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  ck_assert_uint_eq(data.num_of_v, 3000000);
  ck_assert_uint_eq(data.num_of_f, 6677268);
  ck_assert_float_eq_tol(data.max_coord, 21.699883, TEST_PRECISION);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok15) {
  char *obj_path = "_objfiles/empty.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  ck_assert_uint_eq(data.num_of_v, 3);
  ck_assert_uint_eq(data.num_of_f, 6);
  ck_assert_float_eq_tol(data.max_coord, 1, TEST_PRECISION);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok16) {
  char *obj_path = "_objfiles/empty abs.obj";
  s21_obj_data data;
  test_parser(obj_path, &data, S21_FALSE);

  ck_assert_uint_eq(data.num_of_v, 0);
  ck_assert_uint_eq(data.num_of_f, 0);
  ck_assert_float_eq_tol(data.max_coord, 0, TEST_PRECISION);

  s21_destroy_obj_data(&data);
}

Suite *parse_file_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("parse_file");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_parser_fail1);
  tcase_add_test(tc_core, test_parser_fail2);

  tcase_add_test(tc_core, test_parser_ok1);
  tcase_add_test(tc_core, test_parser_ok2);
  tcase_add_test(tc_core, test_parser_ok3);
  tcase_add_test(tc_core, test_parser_ok4);
  tcase_add_test(tc_core, test_parser_ok5);
  tcase_add_test(tc_core, test_parser_ok6);
  tcase_add_test(tc_core, test_parser_ok7);
  tcase_add_test(tc_core, test_parser_ok8);
  tcase_add_test(tc_core, test_parser_ok9);
  tcase_add_test(tc_core, test_parser_ok10);
  tcase_add_test(tc_core, test_parser_ok11);
  tcase_add_test(tc_core, test_parser_ok12);
  tcase_add_test(tc_core, test_parser_ok13);
  tcase_add_test(tc_core, test_parser_ok14);
  tcase_add_test(tc_core, test_parser_ok15);
  tcase_add_test(tc_core, test_parser_ok16);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_parser(char *obj_path, s21_obj_data *data,
                 s21_boolean need_normalize) {
  clock_t start, end;
  start = clock();
  s21_parser_result code = s21_parse_file(obj_path, data, need_normalize);
  end = clock();
  printf("v: %u (%u)\n", data->num_of_v / 3, data->num_of_v);
  printf("f: %u (%u)\n", data->num_of_f / 2, data->num_of_f);
  printf("max: %f\n", data->max_coord);
  printf("Parsing time: %.7f\n", (double)(end - start) / (CLOCKS_PER_SEC));
  ck_assert_int_eq(code, S21_PARSER_OK);
}

void test_parser_fail(char *obj_path, s21_obj_data *data,
                      s21_parser_result code_check) {
  clock_t start, end;
  start = clock();
  s21_parser_result code = s21_parse_file(obj_path, data, S21_TRUE);
  end = clock();
  printf("v: %u (%u)\n", data->num_of_v / 3, data->num_of_v);
  printf("f: %u (%u)\n", data->num_of_f / 2, data->num_of_f);
  printf("max: %f\n", data->max_coord);
  printf("Parsing time: %.7f\n", (double)(end - start) / (CLOCKS_PER_SEC));
  ck_assert_int_eq(code, code_check);
  ck_assert_uint_eq(data->num_of_v, 0);
  ck_assert_uint_eq(data->num_of_f, 0);
  ck_assert_uint_eq(data->max_coord, 0);
}
