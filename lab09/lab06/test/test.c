/**
 * @file test.c
 * @brief Файл з тестом на реалізацію функції знаходження найбільшого спільного
 * дільника
 *
 * @author fomgleb
 * @date 31-apr-2021
 * @version 1.0
 */

#include "lib.h"
#include <check.h>
#include <stdbool.h>

/**
 * @brief Верифікація роботи функції {@link get_greatest_common_divisor}
 * на основі набору масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_get_greatest_common_divisor)
{
#define DATA_SIZE_GET_GREATEST_COMMON_DIVISOR 14
#define STRING_SIZE_GET_GREATEST_COMMON_DIVISOR 100
	int input_data[] = { 9999, 9990, 9111, 9010, 9001, 9000, 999, 900, 99, 11, 10, 9, 0, -666 };
	char expected_values[][STRING_SIZE_GET_GREATEST_COMMON_DIVISOR] = { "nine thousand nine hundred and ninety-nine\0",
									    "nine thousand nine hundred and ninety\0",
									    "nine thousand one hundred and eleven\0",
									    "nine thousand and ten\0",
									    "nine thousand and one\0",
									    "nine thousand\0",
									    "nine hundred and ninety-nine\0",
									    "nine hundred\0",
									    "ninety-nine\0",
									    "eleven\0",
									    "ten\0",
									    "nine\0",
									    "zero\0",
									    "minus six hundred and sixty-six\0" };

	for (int i = 0; i < DATA_SIZE_GET_GREATEST_COMMON_DIVISOR; i++) {
		char actual_value[STRING_SIZE_GET_GREATEST_COMMON_DIVISOR];
		make_string_from_number(input_data[i], actual_value);

		ck_assert_str_eq(expected_values[i], actual_value);
	}
}
END_TEST

/**
 * @brief Верифікація роботи функції {@link get_real_word_size}
 * на основі набору масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_get_real_word_size)
{
#define DATA_SIZE_GET_REAL_WORD_SIZE 2
#define STRING_SIZE_GET_REAL_WORD_SIZE 15
	char input_data[][STRING_SIZE_GET_REAL_WORD_SIZE] = { "some_word\0", "BoyNextDoor\0" };
	int expected_values[] = { 9, 11 };

	for (int i = 0; i < DATA_SIZE_GET_REAL_WORD_SIZE; i++) {
		int actual_value = get_real_word_size(input_data[i], STRING_SIZE_GET_REAL_WORD_SIZE);

		ck_assert_int_eq(expected_values[i], actual_value);
	}
}
END_TEST

/**
 * @brief Верифікація роботи функції {@insert_word_in_the_end}
 * на основі набору масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_insert_word_in_the_end)
{
#define DATA_SIZE_INSERT_WORD_IN_THE_END 3
#define STRING_SIZE_INSERT_WORD_IN_THE_END 50

	char input_text[][STRING_SIZE_INSERT_WORD_IN_THE_END] = { "some kind of ", "", "Put 100 points for semester " };
	char input_word[][STRING_SIZE_INSERT_WORD_IN_THE_END] = { "word", "...", "thanks" };
	int input_insetring_index[] = { 13, 0, 28 };
	bool input_put_space_in_the_end_bool[] = { false, false, true };

	char expected_values1[][STRING_SIZE_INSERT_WORD_IN_THE_END] = { "some kind of word", "...", "Put 100 points for semester thanks " };
	int expected_values2[] = { 4, 3, 7 };

	for (int i = 0; i < DATA_SIZE_INSERT_WORD_IN_THE_END; i++) {
		char actual_value[STRING_SIZE_INSERT_WORD_IN_THE_END];

		for (int j = 0; j < STRING_SIZE_INSERT_WORD_IN_THE_END; j++) {
			actual_value[j] = input_text[i][j];
		}

		int actual_value2 = insert_word_in_the_end(actual_value, input_word[i], STRING_SIZE_INSERT_WORD_IN_THE_END, input_insetring_index[i],
							   input_put_space_in_the_end_bool[i]);

		ck_assert_str_eq(expected_values1[i], actual_value);
		ck_assert_int_eq(expected_values2[i], actual_value2);
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
	TCase *tc_core = tcase_create("lab06");

	tcase_add_test(tc_core, test_get_greatest_common_divisor);
	tcase_add_test(tc_core, test_get_real_word_size);
	tcase_add_test(tc_core, test_insert_word_in_the_end);
	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}