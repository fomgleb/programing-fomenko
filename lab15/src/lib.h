/**
 * @file lib.h
 * @brief Файл з описом функцій та структур для роботи з країнами які існували під час Другої Світової війни.
 *
 * @author fomgleb
 * @date 05.05.2022
 * @version 1.0
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_OF_COUNTRY_NAME 50

#pragma region Перерахування(enums)
/**
 * @brief Всі існуючі устрої країн
 */
enum country_system { MONARCHY, REPUBLIC, COUNTRY_SYSTEM_MAX };

/**
 * @brief Всі критерії за якими можно провести сортировку
 * 
 */
enum criterion {
	IS_FIGHTING,
	AREA,
	NUMBER_OF_INFANTRY,
	NUMBER_OF_AIR_FORCES,
	NUMBER_OF_NAVAL_FORCES,
	COUNTRY_SYSTEM_BEFORE_WAR,
	COUNTRY_SYSTEM_AFTER_WAR,
	CRITERIO_MAX
};
#pragma endregion

#pragma region Структури
/**
 * @brief бойова міць
 */
struct combat_power {
	size_t number_of_infantry;
	size_t number_of_air_forces;
	size_t number_of_naval_forces;
};

/**
 * @brief базовий клас (країна)
 */
struct country {
	char name[MAX_SIZE_OF_COUNTRY_NAME];
	bool is_fighting;
	double area;
	struct combat_power Combat_power;
	enum country_system Country_system_before_war;
	enum country_system Country_system_after_war;
};
#pragma endregion

#pragma region Зберегти / Завантажити
/**
 * @brief завантажити країни з файлу
 * 
 * @param path_to_file - шлях до завантажуваного файлу
 * @param output_countries_count - кількість країн, які завантажились з файлу
 */
struct country *load_countries_from_file(const char *path_to_file, size_t *output_countries_count);

/**
 * @brief зберегти країни в файл
 * 
 * @param countries - країни які треба зберегти
 * @param countries_count - кількість країн
 * @param path_to_file - шлях до збережуваного файлу
 * @return true - вдалося відкрити/створити файл
 * @return false - не вдалось відкрити/створити файл
 */
bool save_countries_to_file(struct country *countries, size_t countries_count, const char *path_to_file);
#pragma endregion

#pragma region Робота із списком
/**
 * @brief додати країну в кінець
 * 
 * @param countries - масив країн
 * @param countries_count - кількість країн
 * @param new_country - нова країна, яка буде додана в кінець
 */
struct country *add_country_in_the_end(struct country *countries, size_t *countries_count, struct country new_country);

/**
 * @brief видаляє країну по індексу
 * 
 * @param countries - масив країн
 * @param countries_count - кількість країн
 * @param removing_index - індекс країни, яку треба видалити
 */
struct country *remove_country_by_index(struct country *countries, size_t *countries_count, size_t removing_index);
#pragma endregion

#pragma region Виведення на екран
/**
 * @brief вивести всі державні устрої
 */
void print_all_country_systems();

/**
 * @brief вивести дані про країни
 * 
 * @param countries - масив країн
 * @param countries_count - кількість країн
 */
void print_countries(struct country *countries, size_t countries_count);
#pragma endregion

#pragma region Сортування
/**
 * @brief Відсортувати за критерієм
 * 
 * @param countries масив країн які треба відсортувати
 * @param countries_count кількість країн
 * @param sorting_criterion критерій сортування (поле по якому треба сортувати)
 */
void sort_by_criterion(struct country *countries, size_t countries_count, enum criterion sorting_criterion);

int sort_by_is_fighting(struct country *country1, struct country *country2);

int sort_by_area(struct country *country1, struct country *country2);

int sort_by_number_of_infantry(struct country *country1, struct country *country2);

int sort_by_number_of_air_forces(struct country *country1, struct country *country2);

int sort_by_number_of_neval_forces(struct country *country1, struct country *country2);

int sort_by_country_system_before_war(struct country *country1, struct country *country2);

int sort_by_country_system_after_war(struct country *country1, struct country *country2);
#pragma endregion

#pragma region Отримати строку по enum
/**
 * @brief отримати строку назви державного устрою
 * 
 * @param Country_system - державний устрій (enum)
 */
char *get_country_system_string(enum country_system Country_system);

/**
 * @brief отримати строку назви крітерія для сортування
 * 
 * @param Criterio - критерій (enum)
 */
char *get_criterio_string(enum criterion Criterio);
#pragma endregion

#pragma region Пошук
/**
 * @brief Знайти всі країни в яких відрізнаються два критерія
 * 
 * @param countries - країни серед яких буде проводитися пошут
 * @param countries_count - кількість країн
 * @param criterion_1 - перший критерій
 * @param criterion_2 - другий критерій
 * @param output_countries_with_different_criteria_count - кількість країн із різними крітеріями
 * 
 */
struct country *find_countries_with_two_different_criteria(struct country *countries, size_t countries_count, enum criterion criterion_1,
							   enum criterion criterion_2, size_t *output_countries_with_different_criteria_count);
#pragma endregion