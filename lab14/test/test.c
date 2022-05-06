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

void assert_countries(struct country country_1, struct country country_2)
{
	ck_assert_str_eq(country_1.name, country_2.name);
	ck_assert_int_eq(country_1.is_fighting, country_2.is_fighting);
	ck_assert_int_eq(country_1.area, country_2.area);
	ck_assert_int_eq(country_1.Combat_power.number_of_infantry, country_2.Combat_power.number_of_infantry);
	ck_assert_int_eq(country_1.Combat_power.number_of_air_forces, country_2.Combat_power.number_of_air_forces);
	ck_assert_int_eq(country_1.Combat_power.number_of_naval_forces, country_2.Combat_power.number_of_naval_forces);
	ck_assert_int_eq(country_1.Country_system_before_war, country_2.Country_system_before_war);
	ck_assert_int_eq(country_1.Country_system_after_war, country_2.Country_system_after_war);
}

/**
 * @brief Верифікація роботи функції {@link save_countries_to_file} та {@link load_countries_from_file}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_save_countries_to_file_and_load_countries_from_file)
{
	const char PATH_TO_FILE[] = "test/test.txt";

	size_t input_and_expected_countries_count = 2;
	struct country *input_and_expected_countries = malloc(input_and_expected_countries_count * sizeof(struct country));
	struct country input_country_1 = { "Японія", 1, 50, { 20, 90, 10 }, 1, 0 };
	struct country input_country_2 = { "СРСР", 0, 20, { 50, 80, 40 }, 1, 1 };
	input_and_expected_countries[0] = input_country_1;
	input_and_expected_countries[1] = input_country_2;

	save_countries_to_file(input_and_expected_countries, input_and_expected_countries_count, PATH_TO_FILE);
	size_t actual_countries_count = 0;
	struct country *actual_countries = load_countries_from_file(PATH_TO_FILE, &actual_countries_count);

	ck_assert_int_eq(actual_countries_count, input_and_expected_countries_count);

	for (size_t i = 0; i < input_and_expected_countries_count; i++) {
		assert_countries(input_and_expected_countries[i], actual_countries[i]);
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