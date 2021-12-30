/**
 * @file lib.h
 * @brief Файл з описом функції знаходження найбільшого спільного дільника
 *
 * @author fomgleb
 * @date 29-dec-2021
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