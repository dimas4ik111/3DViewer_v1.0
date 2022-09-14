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
  test_parser(obj_path);
}

START_TEST(test_parser_ok2) {
  char *obj_path = "check/objfiles/Gun.obj";
  test_parser(obj_path);
}

START_TEST(test_parser_ok3) {
  // char *obj_path = "check/objfiles/Kalashnikov.obj";
  // test_parser(obj_path);
}

START_TEST(test_parser_ok4) {
  // char *obj_path = "check/objfiles/Bugatti.obj";
  // test_parser(obj_path);
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

  suite_add_tcase(s, tc_core);
  return s;
}

void test_parser(char *obj_path) {
  s21_obj_data data;
  clock_t start, end;
  start = clock();
  s21_parse_file(obj_path, &data);
  s21_destroy_obj_data(&data);
  end = clock();
  printf("v: %u\n", data.num_of_v);
  printf("f: %u\n", data.num_of_f);
  printf("Parsing time: %.7f\n", (double)(end - start) / (CLOCKS_PER_SEC));
}
