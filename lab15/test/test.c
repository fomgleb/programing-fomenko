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
 * @brief Верифікація роботи функції {@remove_country_by_index}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_remove_country_by_index)
{
	size_t input_and_actual_countries_count = 5;
	struct country *input_and_actual_countries = malloc(input_and_actual_countries_count * sizeof(struct country));
	struct country input_and_actual_country_1 = { "Польща", 0, 234, { 23, 245, 23 }, 0, 1 };
	struct country input_and_actual_country_2 = { "Канада", 0, 24, { 23423, 2345, 233 }, 1, 1 };
	struct country input_and_actual_country_3 = { "Росія", 1, 134, { 23, 245, 23 }, 0, 0 };
	struct country input_and_actual_country_4 = { "Україна", 1, 23324, { 2343, 24554, 2334 }, 0, 0 };
	struct country input_and_actual_country_5 = { "США", 0, 222834, { 223, 2425, 12323 }, 1, 0 };
	input_and_actual_countries[0] = input_and_actual_country_1;
	input_and_actual_countries[1] = input_and_actual_country_2;
	input_and_actual_countries[2] = input_and_actual_country_3;
	input_and_actual_countries[3] = input_and_actual_country_4;
	input_and_actual_countries[4] = input_and_actual_country_5;
	size_t input_removing_indexes[2] = { 4, 2 };
	size_t expected_countries_count = 3;
	struct country *expected_countries = malloc(expected_countries_count * sizeof(struct country));
	struct country expected_country_1 = { "Польща", 0, 234, { 23, 245, 23 }, 0, 1 };
	struct country expected_country_2 = { "Канада", 0, 24, { 23423, 2345, 233 }, 1, 1 };
	struct country expected_country_3 = { "Україна", 1, 23324, { 2343, 24554, 2334 }, 0, 0 };
	expected_countries[0] = expected_country_1;
	expected_countries[1] = expected_country_2;
	expected_countries[2] = expected_country_3;

	for (size_t i = 0; i < 2; i++) {
		input_and_actual_countries =
			remove_country_by_index(input_and_actual_countries, &input_and_actual_countries_count, input_removing_indexes[i]);
	}

	ck_assert_int_eq(input_and_actual_countries_count, expected_countries_count);

	for (size_t i = 0; i < expected_countries_count; i++) {
		assert_countries(input_and_actual_countries[i], expected_countries[i]);
	}
}
END_TEST

/**
 * @brief Верифікація роботи функції {@add_country_in_the_end}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_add_country_in_the_end)
{
	size_t input_and_actual_countries_count = 0;
	size_t expected_countries_count = 2;
	struct country *input_and_actual_countries = malloc(1 * sizeof(struct country));
	struct country *expected_countries = malloc(expected_countries_count * sizeof(struct country));
	struct country input_and_expected_adding_country_1 = { "Франция", 0, 234234, { 536, 4567, 45 }, 0, 1 };
	struct country input_and_expected_adding_country_2 = { "Германія", 0, 242534, { 532346, 453467, 43453 }, 1, 0 };
	expected_countries[0] = input_and_expected_adding_country_1;
	expected_countries[1] = input_and_expected_adding_country_2;

	input_and_actual_countries =
		add_country_in_the_end(input_and_actual_countries, &input_and_actual_countries_count, input_and_expected_adding_country_1);
	input_and_actual_countries =
		add_country_in_the_end(input_and_actual_countries, &input_and_actual_countries_count, input_and_expected_adding_country_2);

	ck_assert_int_eq(input_and_actual_countries_count, expected_countries_count);

	for (size_t i = 0; i < expected_countries_count; i++) {
		assert_countries(input_and_actual_countries[i], expected_countries[i]);
	}
}
END_TEST

/**
 * @brief Верифікація роботи функції {@find_countries_with_two_different_criteria}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_find_countries_with_two_different_criteria)
{
	size_t input_countries_count = 5;
	struct country *input_countries = malloc(input_countries_count * sizeof(struct country));
	struct country input_and_expected_country_1 = { "Японія", 1, 50, { 20, 90, 10 }, 1, 0 };
	struct country input_country_2 = { "СРСР", 0, 20, { 50, 80, 40 }, 1, 1 };
	struct country input_and_expected_country_3 = { "Германія", 0, 20, { 50, 80, 40 }, 1, 0 };
	struct country input_country_4 = { "Фрайнція", 0, 20, { 50, 80, 40 }, 0, 0 };
	struct country input_country_5 = { "Польща", 0, 20, { 50, 80, 40 }, 1, 1 };
	enum criterion input_criteria[2] = { COUNTRY_SYSTEM_BEFORE_WAR, COUNTRY_SYSTEM_AFTER_WAR };
	input_countries[0] = input_and_expected_country_1;
	input_countries[1] = input_country_2;
	input_countries[2] = input_and_expected_country_3;
	input_countries[3] = input_country_4;
	input_countries[4] = input_country_5;
	size_t expected_countries_count = 2;
	struct country *expected_countries = malloc(expected_countries_count * sizeof(struct country));
	expected_countries[0] = input_and_expected_country_1;
	expected_countries[1] = input_and_expected_country_3;

	size_t actual_countries_count = 0;
	struct country *actual_countries = find_countries_with_two_different_criteria(input_countries, input_countries_count, input_criteria[0],
										      input_criteria[1], &actual_countries_count);

	ck_assert_int_eq(expected_countries_count, actual_countries_count);
	for (size_t i = 0; i < expected_countries_count; i++) {
		assert_countries(expected_countries[i], actual_countries[i]);
	}

	free(input_countries);
	free(expected_countries);
	free(actual_countries);
}
END_TEST

/**
 * @brief Верифікація роботи функції {@sort_by_criterion}
 * на основі масивів вхідних та очікуваних даних
 * 
 * @return стан проходження тестів: 0 - тест пройшов успішно, 1 - тест
 * не пройшов
 */
START_TEST(test_sort_by_criterion)
{
	size_t countries_count = 3;
	struct country *input_and_actual_countries = malloc(countries_count * sizeof(struct country));
	struct country country_1 = { "СРСР", 0, 500, { 50, 80, 40 }, 1, 1 };
	struct country country_2 = { "Італія", 1, 204, { 50, 80, 40 }, 1, 1 };
	struct country country_3 = { "Нідерланди", 0, 2340, { 50, 80, 40 }, 1, 1 };
	input_and_actual_countries[0] = country_1;
	input_and_actual_countries[1] = country_2;
	input_and_actual_countries[2] = country_3;
	enum criterion input_sorting_criterion = AREA;
	struct country *expected_countries = malloc(countries_count * sizeof(struct country));
	expected_countries[0] = country_3;
	expected_countries[1] = country_1;
	expected_countries[2] = country_2;

	sort_by_criterion(input_and_actual_countries, countries_count, input_sorting_criterion);

	for (size_t i = 0; i < countries_count; i++) {
		assert_countries(input_and_actual_countries[i], expected_countries[i]);
	}

	free(input_and_actual_countries);
	free(expected_countries);
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
	TCase *tc_core = tcase_create("lab15");
	tcase_add_test(tc_core, test_save_countries_to_file_and_load_countries_from_file);
	tcase_add_test(tc_core, test_remove_country_by_index);
	tcase_add_test(tc_core, test_add_country_in_the_end);
	tcase_add_test(tc_core, test_find_countries_with_two_different_criteria);
	tcase_add_test(tc_core, test_sort_by_criterion);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}