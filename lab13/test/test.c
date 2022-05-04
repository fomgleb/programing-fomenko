/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій для отримання максимального елементу матриці
 *
 * @author fomgleb
 * @date 02.05.2022
 * @version 1.0
*/

#include "lib.h"
#include <check.h>

/**
 * @brief Верифікація роботи функції {@link get_max_matrix_element}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_get_max_matrix_element)
{
	const size_t MATRIXES_COUNT = 3;
	const size_t MAX_MATRIX_HEIGHT = 3;
	const size_t MAX_MATRIX_WIDTH = 3;

	size_t input_matrixes_heights[MATRIXES_COUNT] = { 3, 3, 1 };
	size_t input_matrixes_widths[MATRIXES_COUNT] = { 3, 2, 1 };
	double input_static_matrixes[MATRIXES_COUNT][MAX_MATRIX_HEIGHT][MAX_MATRIX_WIDTH] = { { { 9.32, 8.33, 21 }, { 3, 98, 23 }, { 32, 9, 21.2 } },
											      { { 321, 21.32 }, { 9.3, 21 }, { 9, 2 } },
											      { { 777 } } };
	double expected_max_elements[MATRIXES_COUNT] = { 98, 321, 777 };
	double actual_max_elements[MATRIXES_COUNT];
	double **input_dynamic_matrixes[MATRIXES_COUNT];
	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		input_dynamic_matrixes[i] = malloc(input_matrixes_heights[i] * sizeof(double *));
		for (size_t y = 0; y < input_matrixes_heights[i]; y++) {
			input_dynamic_matrixes[i][y] = malloc(input_matrixes_widths[i] * sizeof(double));
			for (size_t x = 0; x < input_matrixes_widths[i]; x++) {
				input_dynamic_matrixes[i][y][x] = input_static_matrixes[i][y][x];
			}
		}
	}

	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		actual_max_elements[i] = get_max_matrix_element(input_dynamic_matrixes[i], input_matrixes_heights[i], input_matrixes_widths[i]);
	}

	for (size_t i = 0; i < MATRIXES_COUNT; i++) {
		ck_assert_int_eq(expected_max_elements[i], actual_max_elements[i]);
	}
}
END_TEST

/**
 * @brief Верифікація роботи функції {@link write_to_file} та {@link read_from_file}
 * на основі вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_write_to_file_and_read_from_file)
{
	const char PATH_TO_FILE[] = "test/test.txt";
	char writing_data[] = "It's a good idea to put 5 points.";
	char expected_data[] = "It's a good idea to put 5 points.";
	char *actual_data = NULL;

	write_to_file(PATH_TO_FILE, writing_data);
	actual_data = read_from_file(PATH_TO_FILE, 10, 1000);

	ck_assert_str_eq(expected_data, actual_data);
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
	TCase *tc_core = tcase_create("lab13");
	tcase_add_test(tc_core, test_get_max_matrix_element);
	tcase_add_test(tc_core, test_write_to_file_and_read_from_file);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}