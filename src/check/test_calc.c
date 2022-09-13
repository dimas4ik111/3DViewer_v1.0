#include <stdio.h>
#include <stdlib.h>

#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на некорректные данные
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

START_TEST(test_calc_fail1) {}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на корректные данные
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

START_TEST(test_calc_ok1) {
  char *obj_path = "./objfiles/cube.obj";
  parse_file(obj_path);
}

Suite *parse_file_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("parse_file");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_calc_fail1);

  tcase_add_test(tc_core, test_calc_ok1);

  suite_add_tcase(s, tc_core);
  return s;
}
