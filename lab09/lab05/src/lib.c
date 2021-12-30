/**
 * @file lib.c
 * @brief Файл з реалізацією функції знаходження найбільшого спільного дільника
 *
 * @author fomgleb
 * @date 29-dec-2021
 * @version 1.0
 */

#include "lib.h"

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