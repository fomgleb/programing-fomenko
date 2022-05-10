/**
 * @file lib.c
 * @brief Файл з реалізацією функцій для роботи з країнами які існували під час Другої Світової війни.
 *
 * @author fomgleb
 * @date 05.05.2022
 * @version 1.0
*/

#include "lib.h"

#pragma region Зберегти / Завантажити
bool save_countries_to_file(struct country *countries, size_t countries_count, const char *path_to_file)
{
	FILE *countries_file = fopen(path_to_file, "w");
	if (countries_file == NULL) {
		return false;
	}

	fprintf(countries_file, "%zu\n", countries_count);

	for (size_t i = 0; i < countries_count; i++) {
		fprintf(countries_file, "%s %d %.1f %zu %zu %zu %i %i\n", countries[i].name, countries[i].is_fighting, countries[i].area,
			countries[i].Combat_power.number_of_infantry, countries[i].Combat_power.number_of_air_forces,
			countries[i].Combat_power.number_of_naval_forces, countries[i].Country_system_before_war,
			countries[i].Country_system_after_war);
	}

	fclose(countries_file);

	return true;
}

struct country *load_countries_from_file(const char *path_to_file, size_t *output_countries_count)
{
	FILE *loading_file = fopen(path_to_file, "r");
	if (loading_file == NULL) {
		return NULL;
	}

	fscanf(loading_file, "%zu", output_countries_count);

	struct country *loading_countries = malloc(*output_countries_count * sizeof(struct country));
	for (size_t i = 0; i < *output_countries_count; i++) {
		struct country loading_country = { "", 0, 0, { 0, 0, 0 }, 0, 0 };
		int is_fighting = 0;
		fscanf(loading_file, "%s %d %lf %zu %zu %zu %i %i", loading_country.name, &is_fighting, &loading_country.area,
		       &loading_country.Combat_power.number_of_infantry, &loading_country.Combat_power.number_of_air_forces,
		       &loading_country.Combat_power.number_of_naval_forces, &loading_country.Country_system_before_war,
		       &loading_country.Country_system_after_war);
		loading_country.is_fighting = is_fighting;
		loading_countries[i] = loading_country;
	}

	fclose(loading_file);

	return loading_countries;
}
#pragma endregion

#pragma region Додавання та видалення
struct country *add_country_in_the_end(struct country *countries, size_t *countries_count, struct country new_country)
{
	countries = realloc(countries, (*countries_count + 1) * sizeof(struct country));
	(*countries_count)++;
	countries[*countries_count - 1] = new_country;

	return countries;
}

struct country *remove_country_by_index(struct country *countries, size_t *countries_count, size_t removing_index)
{
	for (size_t i = removing_index; i < *countries_count - 1; i++) {
		countries[i] = countries[i + 1];
	}
	(*countries_count)--;
	countries = realloc(countries, *countries_count * sizeof(struct country));

	return countries;
}
#pragma endregion

#pragma region Виведення на екран
void print_all_country_systems()
{
	for (size_t i = 0; i < COUNTRY_SYSTEM_MAX; i++) {
		printf("\t[%zu] - %s\n", i, get_country_system_string((unsigned int)i));
	}
}

void print_countries(struct country *countries, size_t countries_count)
{
	for (size_t i = 0; i < countries_count; i++) {
		printf("\t[Номер елементу]: %zu\n", i);
		printf("\t[Ім'я]: %s\n", countries[i].name);
		printf("\t[Воює]: %s\n", countries[i].is_fighting ? "так" : "ні");
		printf("\t[Площа території]: %.1f\n", countries[i].area);
		printf("\t[Бойова міць]:\n");
		printf("\t\t[Кількість піхоти]: %zu\n", countries[i].Combat_power.number_of_infantry);
		printf("\t\t[Кількість повітряних збройних сил]: %zu\n", countries[i].Combat_power.number_of_air_forces);
		printf("\t\t[Кількість морських збройних сил]: %zu\n", countries[i].Combat_power.number_of_naval_forces);
		printf("\t[Устрій до віни]: %s\n", get_country_system_string(countries[i].Country_system_before_war));
		printf("\t[Устрій після віни]: %s\n\n", get_country_system_string(countries[i].Country_system_after_war));
	}
}
#pragma endregion

#pragma region Сортування
void sort_by_criterion(struct country *countries, size_t countries_count, enum criterion sorting_criterion)
{
	switch (sorting_criterion) {
	case IS_FIGHTING:
		qsort(countries, countries_count, sizeof(struct country), (int (*)(const void *, const void *))sort_by_is_fighting);
		break;
	case AREA:
		qsort(countries, countries_count, sizeof(struct country), (int (*)(const void *, const void *))sort_by_area);
		break;
	case NUMBER_OF_INFANTRY:
		qsort(countries, countries_count, sizeof(struct country), (int (*)(const void *, const void *))sort_by_number_of_infantry);
		break;
	case NUMBER_OF_AIR_FORCES:
		qsort(countries, countries_count, sizeof(struct country), (int (*)(const void *, const void *))sort_by_number_of_air_forces);
		break;
	case NUMBER_OF_NAVAL_FORCES:
		qsort(countries, countries_count, sizeof(struct country), (int (*)(const void *, const void *))sort_by_number_of_neval_forces);
		break;
	case COUNTRY_SYSTEM_BEFORE_WAR:
		qsort(countries, countries_count, sizeof(struct country), (int (*)(const void *, const void *))sort_by_country_system_before_war);
		break;
	case COUNTRY_SYSTEM_AFTER_WAR:
		qsort(countries, countries_count, sizeof(struct country), (int (*)(const void *, const void *))sort_by_country_system_after_war);
		break;
	default:
		break;
	}
}

int sort_by_is_fighting(struct country *country1, struct country *country2)
{
	return country1->is_fighting < country2->is_fighting;
}

int sort_by_area(struct country *country1, struct country *country2)
{
	return country1->area < country2->area;
}

int sort_by_number_of_infantry(struct country *country1, struct country *country2)
{
	return country1->Combat_power.number_of_infantry < country2->Combat_power.number_of_infantry;
}

int sort_by_number_of_air_forces(struct country *country1, struct country *country2)
{
	return country1->Combat_power.number_of_air_forces < country2->Combat_power.number_of_air_forces;
}

int sort_by_number_of_neval_forces(struct country *country1, struct country *country2)
{
	return country1->Combat_power.number_of_naval_forces < country2->Combat_power.number_of_naval_forces;
}

int sort_by_country_system_before_war(struct country *country1, struct country *country2)
{
	return country1->Country_system_before_war < country2->Country_system_before_war;
}

int sort_by_country_system_after_war(struct country *country1, struct country *country2)
{
	return country1->Country_system_after_war < country2->Country_system_after_war;
}
#pragma endregion

#pragma region Отримати строку по enums
char *get_country_system_string(enum country_system Country_system)
{
	switch (Country_system) {
	case MONARCHY:
		return "монархія";
	case REPUBLIC:
		return "республіка";
	default:
		printf("switch треба доповнити новими устроями.");
		exit(1);
		break;
	}
}

char *get_criterio_string(enum criterion Criterio)
{
	switch (Criterio) {
	case IS_FIGHTING:
		return "Воює";
	case AREA:
		return "Площа території";
	case NUMBER_OF_INFANTRY:
		return "Кількість піхоти";
	case NUMBER_OF_AIR_FORCES:
		return "Кількість повітряних збройних сил";
	case NUMBER_OF_NAVAL_FORCES:
		return "Кількість морських збройних сил";
	case COUNTRY_SYSTEM_BEFORE_WAR:
		return "Устрій до війни";
	case COUNTRY_SYSTEM_AFTER_WAR:
		return "Устрій після війни";
	default:
		printf("switch треба доповнити новими крітеріями.");
		exit(1);
		break;
	}
}
#pragma endregion

#pragma region Пошук
struct country *find_countries_with_two_different_criteria(struct country *countries, size_t countries_count, enum criterion criterion_1,
							   enum criterion criterion_2, size_t *output_countries_with_different_criteria_count)
{
	struct country *countries_with_different_critera = malloc(countries_count * sizeof(struct country));
	*output_countries_with_different_criteria_count = 0;

	for (size_t i = 0; i < countries_count; i++) {
		double criterion_value_1 = 0;
		switch (criterion_1) {
		case IS_FIGHTING:
			criterion_value_1 = countries[i].is_fighting;
			break;
		case AREA:
			criterion_value_1 = countries[i].area;
			break;
		case NUMBER_OF_INFANTRY:
			criterion_value_1 = (double)countries[i].Combat_power.number_of_infantry;
			break;
		case NUMBER_OF_AIR_FORCES:
			criterion_value_1 = (double)countries[i].Combat_power.number_of_air_forces;
			break;
		case NUMBER_OF_NAVAL_FORCES:
			criterion_value_1 = (double)countries[i].Combat_power.number_of_naval_forces;
			break;
		case COUNTRY_SYSTEM_BEFORE_WAR:
			criterion_value_1 = countries[i].Country_system_before_war;
			break;
		case COUNTRY_SYSTEM_AFTER_WAR:
			criterion_value_1 = countries[i].Country_system_after_war;
			break;
		default:
			printf("find switch треба доповнити новими крітеріями.");
			exit(1);
			break;
		}

		double criterion_value_2 = 0;
		switch (criterion_2) {
		case IS_FIGHTING:
			criterion_value_2 = countries[i].is_fighting;
			break;
		case AREA:
			criterion_value_2 = countries[i].area;
			break;
		case NUMBER_OF_INFANTRY:
			criterion_value_2 = (double)countries[i].Combat_power.number_of_infantry;
			break;
		case NUMBER_OF_AIR_FORCES:
			criterion_value_2 = (double)countries[i].Combat_power.number_of_air_forces;
			break;
		case NUMBER_OF_NAVAL_FORCES:
			criterion_value_2 = (double)countries[i].Combat_power.number_of_naval_forces;
			break;
		case COUNTRY_SYSTEM_BEFORE_WAR:
			criterion_value_2 = countries[i].Country_system_before_war;
			break;
		case COUNTRY_SYSTEM_AFTER_WAR:
			criterion_value_2 = countries[i].Country_system_after_war;
			break;
		default:
			printf("find switch треба доповнити новими крітеріями.");
			exit(1);
			break;
		}

		if (criterion_value_1 != criterion_value_2) {
			countries_with_different_critera[*output_countries_with_different_criteria_count] = countries[i];
			(*output_countries_with_different_criteria_count)++;
		}
	}

	countries_with_different_critera =
		realloc(countries_with_different_critera, *output_countries_with_different_criteria_count * sizeof(struct country));

	return countries_with_different_critera;
}
#pragma endregion