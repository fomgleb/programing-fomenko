/**
 * @mainpage
 *	# Загальне завдання
 *	З розділу “Індивідуальні завдання комплексної роботи” взяти прикладну галузь стосовно
 *	номеру варіанту за попередньо-визначеною формулою. Створити структуру, що відображає “базовий клас”.
 *
 *	# Індивідуальне завдання
 *	(22) Необхідно описати країни які існували під час Другої Світової війни.
 *
 * @author fomgleb
 * @date 04.05.2022
 * @version 1.0
*/

/**
 * @file main.c
 * @brief Головний файл в програмі.
 *
 * @author fomgleb
 * @date 04.05.2022
 * @version 1.0
*/

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - Програма виводить на екран список команд;
 * - Можна додати нову країну в масив;
 * - Можна відсортувати масив країн по якомусь полі структури;
 * - Можна знайти та вивести на екран усі країни, в яких було змінено устрій після війни;
 * - Можна зберегти масив країн в файл;
 * - Можна завантажити країни з файлу в масив;
 * - Можна вийти з програми.
 * @return успішний код повернення з програми (0)
 */
int main()
{
	const char *PATH_TO_COUNTRIES_FILE = "assets/countries.txt";

	struct country *countries = NULL;
	size_t countries_count = 0;

	char user_command = '\0';

	system("clear");

	while (user_command != 'q') {
		printf("\nКоманди:\n");
		printf("a - додати нову країну;\n");
		printf("c - відсортувати країни;\n");
		printf("f - знайти усі країни, в яких було змінено устрій після війни;\n");
		printf("p - вивести на екран країни;\n");
		printf("s - зберегти країни в файл;\n");
		printf("l - завантажити країни з файлу;\n");
		printf("q - вийти;\n");

		printf("\nВведіть команду: ");
		__fpurge(stdin);
		scanf("%c", &user_command);

		switch (user_command) {
		case 'a': {
			system("clear");
			struct country new_country = { "", false, 0, { 0, 0, 0 }, 0, 0 };
			new_country.name = malloc(MAX_SIZE_OF_COUNTRY_NAME);
			printf("\nДодавання нової країни:\n");
			printf("Ім'я: ");
			scanf("%s", new_country.name);
			printf("Зараз воює (так/ні): ");
			char *new_country_is_fighting_string = malloc(1000 * sizeof(char));
			while (true) {
				scanf("%s", new_country_is_fighting_string);
				if (strcmp(new_country_is_fighting_string, "так") == 0) {
					new_country.is_fighting = true;
					break;
				} else if (strcmp(new_country_is_fighting_string, "ні") == 0) {
					new_country.is_fighting = false;
					break;
				} else {
					printf("＞﹏＜ Невірно, введи \"так\" або \"ні\": ");
				}
			}
			printf("Площа території кв. км: ");
			scanf("%lf", &new_country.area);
			printf("Кількість піхоти: ");
			scanf("%zu", &new_country.Combat_power.number_of_infantry);
			printf("Кількість повітряних збройних сил: ");
			scanf("%zu", &new_country.Combat_power.number_of_air_forces);
			printf("Кількість морських збройних сил: ");
			scanf("%zu", &new_country.Combat_power.number_of_naval_forces);
			printf("Існуючі устрої:\n");
			print_all_country_systems();
			printf("Устій до війни: ");
			int new_country_system_before_war_int = 0;
			while (true) {
				scanf("%i", &new_country_system_before_war_int);
				new_country.Country_system_before_war = (unsigned int)new_country_system_before_war_int;
				if (new_country.Country_system_before_war >= COUNTRY_SYSTEM_MAX || new_country.Country_system_before_war < 0) {
					printf("(⊙ _⊙ )? Невірно, вибери із існуюцих устроїв: ");
				} else
					break;
			}
			printf("Устрій після війни: ");
			int new_country_system_after_war_int = 0;
			while (true) {
				scanf("%i", &new_country_system_after_war_int);
				new_country.Country_system_after_war = (unsigned int)new_country_system_after_war_int;
				if (new_country.Country_system_after_war >= COUNTRY_SYSTEM_MAX || new_country.Country_system_after_war < 0) {
					printf("≧ ﹏≦ Невірно, вибери із існуючих устроїв: ");
				} else
					break;
			}
			countries = realloc(countries, ++countries_count * sizeof(struct country));
			countries[countries_count - 1] = new_country;
		} break;

		case 'p': {
			system("clear");
			printf("Країни:\n");
			print_countries(countries, countries_count);
		} break;

		case 's': {
			system("clear");
			printf("Збереження...\n");
			save_countries_to_file(countries, countries_count, PATH_TO_COUNTRIES_FILE);
			printf("Успішно збережено!\n");
		} break;

		case 'l': {
			system("clear");
			printf("Завантаження...\n");
			countries = load_countries_from_file(PATH_TO_COUNTRIES_FILE, &countries_count);
			printf("Успішно завантажено!\n");
		} break;

		case 'c': {
			system("clear");
			printf("Критерії:\n");
			for (size_t i = 0; i < CRITERIO_MAX; i++) {
				printf("\t[%zu] - %s;\n", i, get_criterio_string((unsigned int)i));
			}
			printf("Відсортувати за критерієм: ");
			enum criterio selected_criterio = 0;
			scanf("%ui", &selected_criterio);
			switch (selected_criterio) {
			case IS_FIGHTING:
				qsort(countries, countries_count, sizeof(struct country), (int (*)(const void *, const void *))sort_by_is_fighting);
				break;
			case AREA:
				qsort(countries, countries_count, sizeof(struct country), (int (*)(const void *, const void *))sort_by_area);
				break;
			case NUMBER_OF_INFANTRY:
				qsort(countries, countries_count, sizeof(struct country),
				      (int (*)(const void *, const void *))sort_by_number_of_infantry);
				break;
			case NUMBER_OF_AIR_FORCES:
				qsort(countries, countries_count, sizeof(struct country),
				      (int (*)(const void *, const void *))sort_by_number_of_air_forces);
				break;
			case NUMBER_OF_NAVAL_FORCES:
				qsort(countries, countries_count, sizeof(struct country),
				      (int (*)(const void *, const void *))sort_by_number_of_neval_forces);
				break;
			case COUNTRY_SYSTEM_BEFORE_WAR:
				qsort(countries, countries_count, sizeof(struct country),
				      (int (*)(const void *, const void *))sort_by_country_system_before_war);
				break;
			case COUNTRY_SYSTEM_AFTER_WAR:
				qsort(countries, countries_count, sizeof(struct country),
				      (int (*)(const void *, const void *))sort_by_country_system_after_war);
				break;
			default:
				break;
			}
			printf("\nУспішно відсортовано!\n");
		} break;

		case 'f': {
			system("clear");
			struct country *found_countries = malloc(countries_count * sizeof(struct country));
			size_t found_countries_count = 0;
			for (size_t i = 0; i < countries_count; i++) {
				if (countries[i].Country_system_before_war != countries[i].Country_system_after_war) {
					found_countries[found_countries_count++] = countries[i];
				}
			}

			printf("Знайдені країни:\n");
			print_countries(found_countries, found_countries_count);
		} break;

		case 'q':
			break;

		default:
			system("clear");
			break;
		}
	};

	return 0;
}