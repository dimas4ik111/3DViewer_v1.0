#ifndef SRC_CHECK_TEST_H_
#define SRC_CHECK_TEST_H_

#include <check.h>

#include "./../backend/backend.h"

// Отображение отладочной информации в тестах
// #define __DEBUG 1
#define TEST_PRECISION 1e-6

Suite *parse_file_suite(void);
Suite *other_suite(void);
Suite *transform_suite(void);

void test_parser(char *obj_path, s21_obj_data *data,
                 s21_boolean need_normalize);
void test_parser_fail(char *obj_path, s21_obj_data *data,
                      s21_parser_result code_check);
void test_other(char *obj_path, s21_obj_data *data, s21_boolean need_normalize);

#endif  // SRC_CHECK_TEST_H_
