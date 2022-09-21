#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./test.h"

START_TEST(test_other_ok1) {
  char *obj_path = "check/objfiles/cube.obj";
  s21_obj_data data;
  s21_obj_data data_copy;
  test_other(obj_path, &data, S21_FALSE);

  s21_copy_obj_data(&data_copy, &data);

  ck_assert_uint_eq(data_copy.num_of_v, data.num_of_v);
  ck_assert_uint_eq(data_copy.num_of_f, data.num_of_f);
  ck_assert_float_eq_tol(data_copy.max_coord, data.max_coord, TEST_PRECISION);

  ck_assert_float_eq_tol(data_copy.array_of_v[0], data.array_of_v[0],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[1], data.array_of_v[1],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[2], data.array_of_v[2],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[3], data.array_of_v[3],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[4], data.array_of_v[4],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[5], data.array_of_v[5],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[6], data.array_of_v[6],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[7], data.array_of_v[7],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[8], data.array_of_v[8],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[9], data.array_of_v[9],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[10], data.array_of_v[10],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[11], data.array_of_v[11],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[12], data.array_of_v[12],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[13], data.array_of_v[13],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[14], data.array_of_v[14],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[15], data.array_of_v[15],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[16], data.array_of_v[16],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[17], data.array_of_v[17],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[18], data.array_of_v[18],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[19], data.array_of_v[19],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[20], data.array_of_v[20],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[21], data.array_of_v[21],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[22], data.array_of_v[22],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_v[23], data.array_of_v[23],
                         TEST_PRECISION);

  ck_assert_float_eq_tol(data_copy.array_of_f[0], data.array_of_f[0],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[1], data.array_of_f[1],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[2], data.array_of_f[2],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[3], data.array_of_f[3],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[4], data.array_of_f[4],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[5], data.array_of_f[5],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[6], data.array_of_f[6],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[7], data.array_of_f[7],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[8], data.array_of_f[8],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[9], data.array_of_f[9],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[10], data.array_of_f[10],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[11], data.array_of_f[11],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[12], data.array_of_f[12],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[13], data.array_of_f[13],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[14], data.array_of_f[14],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[15], data.array_of_f[15],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[16], data.array_of_f[16],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[17], data.array_of_f[17],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[18], data.array_of_f[18],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[19], data.array_of_f[19],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[20], data.array_of_f[20],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[21], data.array_of_f[21],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[22], data.array_of_f[22],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[23], data.array_of_f[23],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[24], data.array_of_f[24],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[25], data.array_of_f[25],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[26], data.array_of_f[26],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[27], data.array_of_f[27],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[28], data.array_of_f[28],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[29], data.array_of_f[29],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[30], data.array_of_f[30],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[31], data.array_of_f[31],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[32], data.array_of_f[32],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[33], data.array_of_f[33],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[34], data.array_of_f[34],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[35], data.array_of_f[35],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[36], data.array_of_f[36],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[37], data.array_of_f[37],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[38], data.array_of_f[38],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[39], data.array_of_f[39],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[40], data.array_of_f[40],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[41], data.array_of_f[41],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[42], data.array_of_f[42],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[43], data.array_of_f[43],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[44], data.array_of_f[44],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[45], data.array_of_f[45],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[46], data.array_of_f[46],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[47], data.array_of_f[47],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[48], data.array_of_f[48],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[49], data.array_of_f[49],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[50], data.array_of_f[50],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[51], data.array_of_f[51],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[52], data.array_of_f[52],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[53], data.array_of_f[53],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[54], data.array_of_f[54],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[55], data.array_of_f[55],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[56], data.array_of_f[56],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[57], data.array_of_f[57],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[58], data.array_of_f[58],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[59], data.array_of_f[59],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[60], data.array_of_f[60],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[61], data.array_of_f[61],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[62], data.array_of_f[62],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[63], data.array_of_f[63],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[64], data.array_of_f[64],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[65], data.array_of_f[65],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[66], data.array_of_f[66],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[67], data.array_of_f[67],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[68], data.array_of_f[68],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[69], data.array_of_f[69],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[70], data.array_of_f[70],
                         TEST_PRECISION);
  ck_assert_float_eq_tol(data_copy.array_of_f[71], data.array_of_f[71],
                         TEST_PRECISION);

  s21_destroy_obj_data(&data);
  s21_destroy_obj_data(&data_copy);
}

Suite *other_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("parse_file");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_other_ok1);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_other(char *obj_path, s21_obj_data *data,
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
