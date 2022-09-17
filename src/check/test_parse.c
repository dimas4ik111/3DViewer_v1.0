#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на некорректные данные
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

START_TEST(test_parser_fail1) {}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на корректные данные
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

START_TEST(test_parser_ok1) {
  char *obj_path = "check/objfiles/cube.obj";
  s21_obj_data data;
  test_parser(obj_path, &data);
  ck_assert_uint_eq(data.num_of_v, 24);
  ck_assert_uint_eq(data.num_of_f, 72);
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

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok2) {
  char *obj_path = "check/objfiles/Gun.obj";
  s21_obj_data data;
  test_parser(obj_path, &data);

  ck_assert_uint_eq(data.num_of_v, 39492);
  ck_assert_uint_eq(data.num_of_f, 87324);

  s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok3) {
  // char *obj_path = "check/objfiles/Kalashnikov.obj";
  // s21_obj_data data;
  // test_parser(obj_path, &data);

  // ck_assert_uint_eq(data.num_of_v, 590535);
  // ck_assert_uint_eq(data.num_of_f, 1571608);

  // s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok4) {
  // char *obj_path = "check/objfiles/Bugatti.obj";
  // s21_obj_data data;
  // test_parser(obj_path, &data);

  // ck_assert_uint_eq(data.num_of_v, 2232639);
  // ck_assert_uint_eq(data.num_of_f, 5981036);

  // s21_destroy_obj_data(&data);
}

START_TEST(test_parser_ok5) {
  // char *obj_path = "check/objfiles/one_million.obj";
  // s21_obj_data data;
  // test_parser(obj_path, &data);

  // ck_assert_uint_eq(data.num_of_v, 3000000);
  // ck_assert_uint_eq(data.num_of_f, 6677268);

  // s21_destroy_obj_data(&data);
}

Suite *parse_file_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("parse_file");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_parser_fail1);

  tcase_add_test(tc_core, test_parser_ok1);
  tcase_add_test(tc_core, test_parser_ok2);
  tcase_add_test(tc_core, test_parser_ok3);
  tcase_add_test(tc_core, test_parser_ok4);
  tcase_add_test(tc_core, test_parser_ok5);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_parser(char *obj_path, s21_obj_data *data) {
  clock_t start, end;
  start = clock();
  s21_parse_file(obj_path, data);
  end = clock();
  printf("v: %u (%u)\n", data->num_of_v / 3, data->num_of_v);
  printf("f: %u (%u)\n", data->num_of_f / 2, data->num_of_f);
  printf("Parsing time: %.7f\n", (double)(end - start) / (CLOCKS_PER_SEC));
}
