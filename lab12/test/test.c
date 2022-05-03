/**
 * @file test.c
 * @brief Файл з тестом на реалізацію функцій для отримання отримання частотної таблиці символів у тексті
 *
 * @author fomgleb
 * @date 30.04.2022
 * @version 1.0
*/

#include "lib.h"
#include <check.h>
#include <math.h>

/**
 * @brief Верифікація роботи функції {@link get_percentage}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_get_percentage)
{
	const int DECIMAL_PLACES_ROUND_TO = 1;
	const size_t ARRAYS_COUNT = 4;
	const size_t MAX_ARRAYS_LENGTH = 4;
	size_t input_numbers_array[ARRAYS_COUNT][MAX_ARRAYS_LENGTH] = { { 1, 1, 1 }, { 2, 1 }, { 2, 2, 2, 2 }, { 1 } };
	size_t input_numbers_lengths_array[ARRAYS_COUNT] = { 3, 2, 4, 1 };
	float expected_data[ARRAYS_COUNT][MAX_ARRAYS_LENGTH] = { { 33.3f, 33.3f, 33.3f }, { 66.7f, 33.3f }, { 25.0f, 25.0f, 25.0f }, { 100.0f } };
	float *actual_data[ARRAYS_COUNT];

	for (size_t i = 0; i < ARRAYS_COUNT; i++) {
		actual_data[i] = get_percentage(input_numbers_array[i], input_numbers_lengths_array[i]);
	}

	for (size_t i = 0; i < ARRAYS_COUNT - 1; i++) {
		for (size_t y = 0; y < input_numbers_lengths_array[i]; y++) {
			short sign = 1;
			if (actual_data[i][y] < 0) {
				sign = -1;
				actual_data[i][y] *= -1;
			}

			int a = (int)(actual_data[i][y] * pow(10, DECIMAL_PLACES_ROUND_TO) + 0.5);
			actual_data[i][y] = (float)a / (float)pow(10, DECIMAL_PLACES_ROUND_TO);
			actual_data[i][y] *= sign;
		}
	}

	char actual[100];
	char expected[100];
	for (size_t i = 0; i < ARRAYS_COUNT; i++) {
		for (size_t j = 0; j < 3; j++) {
			sprintf(actual, "%f", actual_data[i][j]);
			sprintf(expected, "%f", expected_data[i][j]);

			ck_assert_str_eq(actual, expected);
		}
	}
}
END_TEST

/**
 * @brief Верифікація роботи функції {@link get_repeating_chars_counts}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_get_repeating_chars_counts)
{
	const size_t ARRAYS_COUNT = 3;

	char input_texts[ARRAYS_COUNT][20] = { "I'm glad to see you\0", "444 888 2\0", "marin kitagawa\0" };
	size_t input_texts_lengths[ARRAYS_COUNT] = { 20, 10, 15 };
	char expected_output_repeating_chars_array[ARRAYS_COUNT][19] = { "I'm gladtoseyu", "4 82", "marin ktgw" };
	size_t expected_repeating_chars_counts_array[ARRAYS_COUNT][19] = { { 1, 1, 1, 4, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1 },
									   { 3, 2, 3, 1 },
									   { 1, 4, 1, 2, 1, 1, 1, 1, 1, 1 } };
	char *actual_output_repeating_chars_array[ARRAYS_COUNT];
	size_t *actual_repeating_chars_counts_array[ARRAYS_COUNT];

	for (size_t i = 0; i < ARRAYS_COUNT; i++) {
		actual_output_repeating_chars_array[i] = malloc(input_texts_lengths[i] * sizeof(char));
	}
	for (size_t i = 0; i < ARRAYS_COUNT; i++) {
		actual_repeating_chars_counts_array[i] =
			get_repeating_chars_counts(input_texts[i], input_texts_lengths[i], actual_output_repeating_chars_array[i]);
	}

	for (size_t i = 0; i < ARRAYS_COUNT; i++) {
		for (size_t j = 0; actual_output_repeating_chars_array[i][j] != '\0'; j++) {
			ck_assert_str_eq(actual_output_repeating_chars_array[i], expected_output_repeating_chars_array[i]);
			ck_assert_int_eq(actual_repeating_chars_counts_array[i][j], expected_repeating_chars_counts_array[i][j]);
		}
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
	TCase *tc_core = tcase_create("lab12");
	tcase_add_test(tc_core, test_get_percentage);
	tcase_add_test(tc_core, test_get_repeating_chars_counts);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}