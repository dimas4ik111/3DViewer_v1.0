#ifndef SRC_CHECK_TEST_H_
#define SRC_CHECK_TEST_H_

#include <check.h>

#include "./../backend/backend.h"

// Отображение отладочной информации в тестах
// #define __DEBUG 1

Suite *parse_file_suite(void);

void test_parser(char *obj_path);

#endif  // SRC_CHECK_TEST_H_
