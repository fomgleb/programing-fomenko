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
 * @brief Верифікація роботи функції {@link save_countries_to_file} та {@link load_countries_from_file}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_save_countries_to_file_and_load_countries_from_file)
{
	const size_t COUNTRIES_COUNT = 2;
	const char PATH_TO_FILE[] = "test/test.txt";

	struct country *input_and_expected_countries = malloc(COUNTRIES_COUNT * sizeof(struct country));
	input_and_expected_countries[0].name = "Японія";
	input_and_expected_countries[0].is_fighting = true;
	input_and_expected_countries[0].area = 50;
	input_and_expected_countries[0].Combat_power.number_of_infantry = 20;
	input_and_expected_countries[0].Combat_power.number_of_air_forces = 90;
	input_and_expected_countries[0].Combat_power.number_of_naval_forces = 10;
	input_and_expected_countries[0].Country_system_before_war = MONARCHY;
	input_and_expected_countries[0].Country_system_after_war = REPUBLIC;
	input_and_expected_countries[1].name = "СРСР";
	input_and_expected_countries[1].is_fighting = false;
	input_and_expected_countries[1].area = 20;
	input_and_expected_countries[1].Combat_power.number_of_infantry = 50;
	input_and_expected_countries[1].Combat_power.number_of_air_forces = 80;
	input_and_expected_countries[1].Combat_power.number_of_naval_forces = 40;
	input_and_expected_countries[1].Country_system_before_war = MONARCHY;
	input_and_expected_countries[1].Country_system_after_war = MONARCHY;

	save_countries_to_file(input_and_expected_countries, COUNTRIES_COUNT, PATH_TO_FILE);
	size_t actual_countries_count = 0;
	struct country *actual_countries = load_countries_from_file(PATH_TO_FILE, &actual_countries_count);

	ck_assert_int_eq(actual_countries_count, COUNTRIES_COUNT);

	for (size_t i = 0; i < COUNTRIES_COUNT; i++) {
		ck_assert_str_eq(input_and_expected_countries[i].name, actual_countries[i].name);
		ck_assert_int_eq(input_and_expected_countries[i].is_fighting, actual_countries[i].is_fighting);
		ck_assert_int_eq(input_and_expected_countries[i].area, actual_countries[i].area);
		ck_assert_int_eq(input_and_expected_countries[i].Combat_power.number_of_infantry,
				 actual_countries[i].Combat_power.number_of_infantry);
		ck_assert_int_eq(input_and_expected_countries[i].Combat_power.number_of_air_forces,
				 actual_countries[i].Combat_power.number_of_air_forces);
		ck_assert_int_eq(input_and_expected_countries[i].Combat_power.number_of_naval_forces,
				 actual_countries[i].Combat_power.number_of_naval_forces);
		ck_assert_int_eq(input_and_expected_countries[i].Country_system_before_war, actual_countries[i].Country_system_before_war);
		ck_assert_int_eq(input_and_expected_countries[i].Country_system_after_war, actual_countries[i].Country_system_after_war);
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
	TCase *tc_core = tcase_create("lab14");
	tcase_add_test(tc_core, test_save_countries_to_file_and_load_countries_from_file);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}