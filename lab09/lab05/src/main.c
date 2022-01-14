/**
 * @mainpage
 * # Загальне завдання
 * **Сформувати** функцію, яка буде знаходити найбільший залальний дільник двух цілих чисел 
 *
 * @author fomgleb
 * @date 08-dec-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Головний файл в програмі.
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
 * - Перевіка чи є якісь аргументи з командної строки, якщо є, то запис в {@link first_num} та {@link second_num}, else заповнення випадковими числами
 * - Визов функції {@link get_greatest_common_divisor} та запис в змінну передаваючи в функцію {link first_num} та {@link second_num}
 * @return успішний код повернення з програми (0)
 */
int main(int argc, char **argv)
{
	int first_num;
	int second_num;
	if (argc == 1) {
		srandom((unsigned int)time(NULL));
		first_num = (int)random();
		second_num = (int)random();
	} else {
		first_num = (int)strtod(argv[1], 0);
		second_num = (int)strtod(argv[2], 0);
	}
	int greatest_common_divisor = get_greatest_common_divisor(first_num, second_num);

	return 0;
}