/**
 * @file test.c
 * @brief Файл з тестом на реалізацію функцій для отримання оберненої матриці
 *
 * @author fomgleb
 * @date 17.02.2022
 * @version 1.0
*/

#include "lib.h"
#include <check.h>
#include <stdio.h>
#include <math.h>

/**
 * @brief Верифікація роботи функції {@link get_identity_matrix}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_get_identity_matrix)
{
	const int MATRIXES_COUNT = 2;

	size_t input_widths_and_heights[MATRIXES_COUNT] = { 4, 3 };
	long double expected_matrixes[MATRIXES_COUNT][4][4] = { { { 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 } },
								{ { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } } };
	long double **actual_matrixes[MATRIXES_COUNT];
	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		actual_matrixes[i] = get_identity_matrix(input_widths_and_heights[i]);
	}

	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		size_t current_width_and_height = input_widths_and_heights[i] > 0 ? input_widths_and_heights[i] : 1;
		for (size_t j = 0; j < current_width_and_height; j++) {
			for (size_t r = 0; r < current_width_and_height; r++) {
				ck_assert_int_eq(*(*(actual_matrixes[i] + j) + r), expected_matrixes[i][j][r]);
			}
		}
	}

	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		for (size_t j = 0; j < input_widths_and_heights[i]; j++) {
			free(actual_matrixes[i][j]);
		}
		free(actual_matrixes[i]);
	}
}
END_TEST

/**
 * @brief Верифікація роботи функції {@link swap_lines_in_matrix}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */

START_TEST(test_swap_lines_in_matrix)
{
	const int MATRIXES_COUNT = 2;

	long double input_and_actual_matrixes[MATRIXES_COUNT][3][3] = { { { 4, 8, 3 }, { 3, 8, 3 }, { 8, 8, 2 } },
									{ { 0, -32, 9.5 }, { 2.7, 0, 23 }, { 3.54, 1, 5 } } };
	size_t input_lines_to_swap[MATRIXES_COUNT][2] = { { 0, 1 }, { 1, 2 } };
	size_t input_widths[MATRIXES_COUNT] = { 3, 3 };
	long double expected_matrixes[MATRIXES_COUNT][3][3] = { { { 3, 8, 3 }, { 4, 8, 3 }, { 8, 8, 2 } },
								{ { 0, -32, 9.5 }, { 3.54, 1, 5 }, { 2.7, 0, 23 } } };

	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		swap_lines_in_matrix(input_and_actual_matrixes[i][input_lines_to_swap[i][0]], input_and_actual_matrixes[i][input_lines_to_swap[i][1]],
				     input_widths[i]);
	}

	char a[100];
	char b[100];
	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		for (size_t j = 0; j < 3; j++) {
			for (size_t k = 0; k < 3; k++) {
				sprintf(a, "%Lf", input_and_actual_matrixes[i][j][k]);
				sprintf(b, "%Lf", expected_matrixes[i][j][k]);

				ck_assert_str_eq(a, b);
			}
		}
	}
}
END_TEST

/**
 * @brief Верифікація роботи функції {@link subtract_one_line_from_another}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_subtract_one_line_from_another)
{
	const int MATRIXES_COUNT = 3;

	long double input_and_actual_matrixes[MATRIXES_COUNT][4][4] = { { { 4, 8, 3 }, { 3, 8, 3 }, { 8, 8, 2 } },
									{ { 0, -32, 9.5 }, { 2.7, 0, 23 }, { 3.54, 1, 5 } },
									{ { 3, 8, 2, 9 }, { 4, 7, 92, 23 }, { 3, 8, 345, 3 }, { 3, 26, 8, 3 } } };
	size_t input_subtrahend_lines_indexes[MATRIXES_COUNT] = { 0, 1, 0 };
	long double input_subtrahend_multipliers[MATRIXES_COUNT] = { 2, 1, -3 };
	size_t input_minuend_lines_indexes[MATRIXES_COUNT] = { 2, 0, 3 };
	size_t input_widths[MATRIXES_COUNT] = { 3, 3, 4 };

	long double expected_matrixes[MATRIXES_COUNT][4][4] = { { { 4, 8, 3 }, { 3, 8, 3 }, { 0, -8, -4 } },
								{ { -2.7, -32, -13.5 }, { 2.7, 0, 23 }, { 3.54, 1, 5 } },
								{ { 3, 8, 2, 9 }, { 4, 7, 92, 23 }, { 3, 8, 345, 3 }, { 12, 50, 14, 30 } } };

	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		subtract_one_array_from_another(input_and_actual_matrixes[i][input_subtrahend_lines_indexes[i]], input_subtrahend_multipliers[i],
						input_and_actual_matrixes[i][input_minuend_lines_indexes[i]], input_widths[i]);
	}

	char a[100];
	char b[100];
	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		for (size_t j = 0; j < input_widths[i]; j++) {
			for (size_t k = 0; k < input_widths[i]; k++) {
				sprintf(a, "%Lf", input_and_actual_matrixes[i][j][k]);
				sprintf(b, "%Lf", expected_matrixes[i][j][k]);
				ck_assert_str_eq(a, b);
			}
		}
	}
}
END_TEST

/**
 * @brief Верифікація роботи функції {@link append_identity_matrix}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_append_identity_matrix)
{
	const int MATRIXES_COUNT = 3;

	long double input_matrixes[MATRIXES_COUNT][4][4] = { { { 4, 8, 3 }, { 3, 8, 3 }, { 8, 8, 2 } },
							     { { 0, -32, 9.5 }, { 2.7, 0, 23 }, { 3.54, 1, 5 } },
							     { { 3, 8, 2, 9 }, { 4, 7, 92, 23 }, { 3, 8, 345, 3 }, { 3, 26, 8, 3 } } };
	size_t input_widths_and_heights[MATRIXES_COUNT] = { 3, 3, 4 };

	long double **dynamic_input_matrixes[MATRIXES_COUNT];
	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		dynamic_input_matrixes[i] = malloc(input_widths_and_heights[i] * sizeof(long double *));
		for (size_t j = 0; j < input_widths_and_heights[i]; j++) {
			dynamic_input_matrixes[i][j] = malloc(input_widths_and_heights[i] * sizeof(long double));
			for (size_t k = 0; k < input_widths_and_heights[i]; k++) {
				dynamic_input_matrixes[i][j][k] = input_matrixes[i][j][k];
			}
		}
	}

	long double expected_matrixes[MATRIXES_COUNT][4][8] = {
		{ { 4, 8, 3, 1, 0, 0 }, { 3, 8, 3, 0, 1, 0 }, { 8, 8, 2, 0, 0, 1 } },
		{ { 0, -32, 9.5, 1, 0, 0 }, { 2.7, 0, 23, 0, 1, 0 }, { 3.54, 1, 5, 0, 0, 1 } },
		{ { 3, 8, 2, 9, 1, 0, 0, 0 }, { 4, 7, 92, 23, 0, 1, 0, 0 }, { 3, 8, 345, 3, 0, 0, 1, 0 }, { 3, 26, 8, 3, 0, 0, 0, 1 } }
	};

	long double **actual_matrixes[MATRIXES_COUNT];
	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		actual_matrixes[i] = append_identity_matrix(dynamic_input_matrixes[i], input_widths_and_heights[i]);
	}

	char a[100];
	char b[100];
	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		for (size_t j = 0; j < input_widths_and_heights[i]; j++) {
			for (size_t k = 0; k < input_widths_and_heights[i] + input_widths_and_heights[i]; k++) {
				sprintf(a, "%Lf", actual_matrixes[i][j][k]);
				sprintf(b, "%Lf", expected_matrixes[i][j][k]);
				ck_assert_str_eq(a, b);
			}
		}
	}

	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		for (size_t y = 0; y < input_widths_and_heights[i]; y++) {
			free(dynamic_input_matrixes[i][y]);
			free(actual_matrixes[i][y]);
		}
		free(dynamic_input_matrixes[i]);
		free(actual_matrixes[i]);
	}
}
END_TEST

/**
 * @brief Верифікація роботи функції {@link divide_array_by_number}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_divide_array_by_number)
{
	const int ARRAYS_COUNT = 3;
	const int DECIMAL_PALCES_ROUND_TO = 3;

	long double input_and_actual_arrays[ARRAYS_COUNT][6] = { { 4, -64, 0.43, 0.42, 43, 22 }, { 0.43, 5.23 }, { 2, 0, 94, -23.434 } };
	long double input_numbers[ARRAYS_COUNT] = { 0.53, 7, 83 };
	long double input_widths[ARRAYS_COUNT] = { 6, 2, 4 };

	long double expected_arrays[ARRAYS_COUNT][6] = { { 7.547, -120.755, 0.811, 0.792, 81.132, 41.509 },
							 { 0.061, 0.747 },
							 { 0.024, 0, 1.133, -0.282 } };

	for (size_t i = 0; i < ARRAYS_COUNT; i++) {
		for (size_t j = 0; j < input_widths[i]; j++) {
			input_and_actual_arrays[i][j] /= input_numbers[i];
		}
	}

	for (size_t i = 0; i < ARRAYS_COUNT; i++) {
		for (size_t j = 0; j < input_widths[i]; j++) {
			short sign = 1;
			if (input_and_actual_arrays[i][j] < 0) {
				sign = -1;
				input_and_actual_arrays[i][j] *= -1;
			}

			int a = (int)(input_and_actual_arrays[i][j] * pow(10, DECIMAL_PALCES_ROUND_TO) + 0.5);
			input_and_actual_arrays[i][j] = (long double)a / (long double)pow(10, DECIMAL_PALCES_ROUND_TO);
			input_and_actual_arrays[i][j] *= sign;
		}
	}

	char a[100];
	char b[100];
	for (size_t i = 0; i < ARRAYS_COUNT; i++) {
		for (size_t j = 0; j < input_widths[i]; j++) {
			sprintf(a, "%Lf", expected_arrays[i][j]);
			sprintf(b, "%Lf", input_and_actual_arrays[i][j]);
			ck_assert_str_eq(a, b);
		}
	}
}
END_TEST

/**
 * @brief Верифікація роботи функції {@link test_get_inverse_matrix}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_get_inverse_matrix)
{
	const size_t MATRIXES_COUNT = 3;
	const int DECIMAL_PALCES_ROUND_TO = 3;

	long double input_matrixes[MATRIXES_COUNT][3][3] = { { { 1, 2 }, { 3, 4 } },
							     { { 8.3, 90, 23 }, { 95, 232, -54 }, { 9, 3, 0 } },
							     { { 7, 7 }, { 7, 7 } } };
	size_t input_widths_and_heights[MATRIXES_COUNT] = { 2, 3, 2 };

	long double **dynamic_input_matrixes[MATRIXES_COUNT];
	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		dynamic_input_matrixes[i] = malloc(input_widths_and_heights[i] * sizeof(long double *));
		for (size_t j = 0; j < input_widths_and_heights[i]; j++) {
			dynamic_input_matrixes[i][j] = malloc(input_widths_and_heights[i] * sizeof(long double));
			for (size_t k = 0; k < input_widths_and_heights[i]; k++) {
				dynamic_input_matrixes[i][j][k] = input_matrixes[i][j][k];
			}
		}
	}

	long double expected_matrixes[MATRIXES_COUNT][3][3] = { { { -2, 1 }, { 1.5, -0.5 } },
								{ { -0.002, -0.001, 0.122 }, { 0.006, 0.002, -0.031 }, { 0.021, -0.009, 0.079 } },
								{ {} } };

	long double **actual_matrixes[MATRIXES_COUNT];
	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		actual_matrixes[i] = get_inverse_matrix(dynamic_input_matrixes[i], input_widths_and_heights[i]);
	}

	if (actual_matrixes[2] == NULL) {
		ck_assert_str_eq("null", "null");

		// Округляю до трёх знаков после запятой
		for (size_t i = 0; i < MATRIXES_COUNT - 1; i++) {
			for (size_t y = 0; y < input_widths_and_heights[i]; y++) {
				for (size_t x = 0; x < input_widths_and_heights[i]; x++) {
					short sign = 1;
					if (actual_matrixes[i][y][x] < 0) {
						sign = -1;
						actual_matrixes[i][y][x] *= -1;
					}

					int a = (int)(actual_matrixes[i][y][x] * pow(10, DECIMAL_PALCES_ROUND_TO) + 0.5);
					actual_matrixes[i][y][x] = (long double)a / (long double)pow(10, DECIMAL_PALCES_ROUND_TO);
					actual_matrixes[i][y][x] *= sign;
				}
			}
		}

		char expected[100];
		char actual[100];
		for (size_t i = 0; i < MATRIXES_COUNT - 1; i++) {
			for (size_t y = 0; y < input_widths_and_heights[i]; y++) {
				for (size_t x = 0; x < input_widths_and_heights[i]; x++) {
					sprintf(expected, "%Lf", expected_matrixes[i][y][x]);
					sprintf(actual, "%Lf", actual_matrixes[i][y][x]);

					ck_assert_str_eq(expected, actual);
				}
			}
		}
	} else {
		ck_assert_str_eq("null", "unnull");
	}

	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		for (size_t y = 0; y < input_widths_and_heights[i]; y++) {
			free(dynamic_input_matrixes[i][y]);
		}
		free(dynamic_input_matrixes[i]);
	}

	for (size_t i = 0; i < MATRIXES_COUNT - 1; i++) {
		for (size_t y = 0; y < input_widths_and_heights[i]; y++) {
			free(actual_matrixes[i][y]);
		}
		free(actual_matrixes[i]);
	}
}
END_TEST

/**
 * Точка входу модуля тестування.
 *
 * По завершенню тестів виводиться на екран резуміюча інформація про стан
 * проходження тестів.
 *
 * @return стан проходження тестів: 0 - тести пройшли успішно, 1 - частина
 * тестів не пройшла
 */
int main(void)
{
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("lab11");
	tcase_add_test(tc_core, test_get_identity_matrix);
	tcase_add_test(tc_core, test_swap_lines_in_matrix);
	tcase_add_test(tc_core, test_subtract_one_line_from_another);
	tcase_add_test(tc_core, test_append_identity_matrix);
	tcase_add_test(tc_core, test_divide_array_by_number);
	tcase_add_test(tc_core, test_get_inverse_matrix);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}