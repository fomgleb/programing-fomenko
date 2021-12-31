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

/**
 * @brief Верифікація роботи функції {@link get_greatest_common_divisor}
 * на основі набору масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_get_greatest_common_divisor)
{
#define DATA_SIZE_SUM 4
	int input_data_a[] = { 25, 9, 415, 79 };
	int input_data_b[] = { 5, 8, 38405, 79 };
	int expected_values[] = { 5, 1, 5, 79 };
	for (int i = 0; i < DATA_SIZE_SUM; i++) {
		int actual_value = get_greatest_common_divisor(input_data_a[i], input_data_b[i]);
		ck_assert_int_eq(expected_values[i], actual_value);
	}
}
END_TEST

/**
 * Точка входу модуля тестування.
 *
 * Запускає розроблені функції верифікації функцій роботи з структурой
 * {@link animal}.
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
	TCase *tc_core = tcase_create("lab05");
	tcase_add_test(tc_core, test_get_greatest_common_divisor);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}