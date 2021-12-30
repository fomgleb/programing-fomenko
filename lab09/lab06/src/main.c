/**
 * @mainpage
 * # Загальне завдання
 * 1. **Сформувати** функцію, що переводе число в речення з слів. Ліміт числа: від -9999 до 9999
 *
 * @author fomgleb
 * @date 06-dec-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Головний та єдиний файл в програмі.
 *
 * @author fomgleb
 * @date 06-dec-2021
 * @version 1.0
 */

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - Перевіка чи є якісь аргументи з командої строки, якщо є, то запис в {@link number}, else запис випадковим числом.
 * - Визов функції {@link make_string_from_number} передаваючи {@link number} як аргумент.
 * @return успішний код повернення з програми (0)
 */
int main(int argc, char **argv)
{
#define RESULTING_STRING_COUNT 100
#define MAX_NUMBER 9999
#define MIN_NUMBER -9999

	int number = 0;
	if (argc == 1) {
		srandom((unsigned int)time(NULL));
		number = MIN_NUMBER + (int)random() % (MAX_NUMBER - MIN_NUMBER);
	} else {
		number = (int)strtod(argv[1], 0);
	}

	char result[RESULTING_STRING_COUNT];
	make_string_from_number(number, result);

	return 0;
}
