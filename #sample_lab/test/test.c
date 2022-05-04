/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій для роботи з країнами які існували під час другої світової війни.
 *
 * @author fomgleb
 * @date 04.05.2022
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
	TCase *tc_core = tcase_create("lab14");
	//tcase_add_test(tc_core, test_get_max_matrix_element);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}