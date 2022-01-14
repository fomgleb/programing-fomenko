/**
 * @file test.c
 * @brief Файл з тестом на реалізацію функції отримання інформації про
 * числа які повторюються в масиві та допоміжних функцій
 *
 * @author fomgleb
 * @date 11.01.2022
 * @version 1.0
*/

#include "lib.h"
#include <check.h>
#include <limits.h>
#include <stdio.h>

/**
 * @brief Верифікація роботи функції {@link get_random_numbers}
 * на основі вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_get_random_numbers)
{
	int input_min_value = -10;
	int input_max_value = 10;

	int expected_min_value = -10;
	int expected_max_value = 9;

	size_t array_length = 50;
	int *array = get_random_numbers(array_length, input_min_value, input_max_value);

	int actual_min_value = INT_MAX;
	int actual_max_value = INT_MIN;

	for (size_t i = 0; i < array_length; i++) {
		int current_value = *(array + i);
		actual_max_value = current_value > actual_max_value ? current_value : actual_max_value;
		actual_min_value = current_value < actual_min_value ? current_value : actual_min_value;
	}

	ck_assert_int_eq(expected_min_value, actual_min_value);
	ck_assert_int_eq(expected_max_value, actual_max_value);
}
END_TEST

/**
 * @brief Верифікація роботи функції {@link get_count_of_number_repetitions}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_get_count_of_number_repetitions)
{
	const size_t data_size = 4;

	size_t input_lengths[] = { 7, 20, 10, 1 };
	int input_arrays[][20] = {
		{ 8, -3, 9, 1, 5, 4, 2 }, { 2, 8, 5, 3, 7, 8, 9, 7, 5, 3, 7, 9, 0, 8, 7, 6, 5, 4, 3, 2 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 5 }
	};
	int input_numbers_to_check[] = { 3, 7, 1, 5 };

	size_t expected_values[] = { 0, 4, 10, 1 };

	size_t actual_values[data_size];

	for (size_t i = 0; i < data_size; i++) {
		actual_values[i] = get_count_of_number_repetitions(input_arrays[i], input_lengths[i], input_numbers_to_check[i]);
	}

	for (size_t i = 0; i < data_size; i++) {
		ck_assert_int_eq(expected_values[i], actual_values[i]);
	}
}
END_TEST

/**
 * @brief Верифікація роботи функції {@link get_copied_array}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_get_copied_array)
{
	const size_t data_size = 4;

	size_t input_lengths[] = { 6, 22, 1, 1 };
	int input_and_expected_arrays[][22] = { { -3, 12, 5, 6, 2, 457 },
						{ 2, 8, 4, 3, 2, 4, 7, 7, 5, 3, 2, 456765, 434567, 876, 543, 456, 78, 7654, 32, 35678, 7654, 32 },
						{ 1 },
						{ 0 } };

	int *actual_values[data_size];

	for (size_t i = 0; i < data_size; i++) {
		for (size_t j = 0; j < input_lengths[i]; j++) {
			actual_values[i] = get_copied_array(input_and_expected_arrays[i], input_lengths[i]);
		}
	}

	for (size_t i = 0; i < data_size; i++) {
		for (size_t j = 0; j < input_lengths[i]; j++) {
			ck_assert_int_eq(input_and_expected_arrays[i][j], actual_values[i][j]);
		}
	}
}
END_TEST

/**
 * @brief Верифікація роботи функції {@link get_information_about_repeating_numbers}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_get_information_about_repeating_numbers)
{
	const int data_size = 5;

	size_t input_lengths[] = { 11, 7, 9, 2, 1 };
	int input_numbers[][11] = {
		{ 5, 7, 4, 3, 7, 8, 5, 3, 3, 4, 6 }, { 50, -40, 30, 12, 49, 38, 28 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 0, 0 }, { 0 }
	};

	size_t lengths_for_expected_information[] = { 8, 2, 2, 2, 2 };
	int expected_information[][8] = { { 5, 2, 7, 2, 4, 2, 3, 3 }, { 0, 0 }, { 1, 9 }, { 0, 2 }, { 0, 0 } };

	int *actual_information[data_size];

	for (size_t i = 0; i < data_size; i++) {
		actual_information[i] = get_information_about_repeating_numbers(input_numbers[i], input_lengths[i]);
	}

	for (size_t i = 0; i < data_size; i++) {
		for (size_t j = 0; j < lengths_for_expected_information[i]; j++) {
			ck_assert_int_eq(expected_information[i][j], actual_information[i][j]);
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
	TCase *tc_core = tcase_create("lab10");
	tcase_add_test(tc_core, test_get_random_numbers);
	tcase_add_test(tc_core, test_get_count_of_number_repetitions);
	tcase_add_test(tc_core, test_get_copied_array);
	tcase_add_test(tc_core, test_get_information_about_repeating_numbers);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}