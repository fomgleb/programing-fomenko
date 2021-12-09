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
 * @brief Головний та єдиний файл в програмі.
 *
 * @author fomgleb
 * @date 06-dec-2021
 * @version 1.0
 */

#include <time.h>
#include <stdlib.h>

/**
 * Return найбільшого загального дільника
 *
 * Функція знаходить найбільший загальний дільник використовуючи метод ейлера
 * @param first_num перше число
 * @param second_num друге число
 * @return найбільний загальний дільник
 */
int get_greatest_common_divisor(int first_num, int second_num);

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

int get_greatest_common_divisor(int first_num, int second_num)
{
	int greatest_common_divisor = 0;
	while (greatest_common_divisor == 0) {
		if (first_num > second_num) {
			first_num = first_num % second_num;
		} else {
			second_num = second_num % first_num;
		}

		if (first_num == 0 || second_num == 0) {
			greatest_common_divisor = first_num == 0 ? second_num : first_num;
		}
	}
	return greatest_common_divisor;
}