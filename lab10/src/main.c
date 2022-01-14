/**
 * @mainpage
 * # Загальне завдання
 *	Розробити програму з використанням показчиків.
 *
 *	# Індивідуальне завдання
 *	(11) Дано масив з N цілих чисел. Визначити, чи є в масиві елементи, що повторюються;
 *	якщо такі є, то створити масив, в якому вказати, скільки разів які елементи повторюються.
 *	Таким чином, в результуючому масиві кожен непарний елемент - число, що повторюються;
 *	кожен парний елемент - кількість повторювань.
 *
 * @author fomgleb
 * @date 09.01.2022
 * @version 1.0
*/

/**
 * @file main.c
 * @brief Головний файл в програмі.
 *
 * @author fomgleb
 * @date 09.01.2022
 * @version 1.0
*/

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - Виклик функції {@link get_random_numbers}, щоб отримати масив з рандомними числами
 * - Виклик функції {@link get_information_about_repeating_numbers}, для отримання інформації про числа що повторюються
 * - Визволення пам'яті за допомогою функції free()
 * @return успішний код повернення з програми (0)
 */
int main()
{
	size_t length = 10;
	int min_value = -10;
	int max_value = 10;

	int *numbers = get_random_numbers(length, min_value, max_value);
	int *information = get_information_about_repeating_numbers(numbers, length);

	free(numbers);
	free(information);

	return 0;
}
