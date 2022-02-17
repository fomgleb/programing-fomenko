/**
 * @file lib.h
 * @brief Файл з описом функцій отримання інформації про повторення чисел в масиві
 *
 * @author fomgleb
 * @date 09.01.2022
 * @version 1.0
*/

#include <time.h>
#include <stdlib.h>

/**
 * @brief Отримати масив випадкових цілочислених чисел
 * 
 * @param length - довжина масиву
 * @param min_value - мінімальне значення елементу масиву
 * @param max_value - максимальне значення елементу масиву
 * @return цілочислений масив
 */
int *get_random_numbers(size_t length, int min_value, int max_value);

/**
 * @brief Отримати кількість повторювань числа в масиві
 * 
 * @param numbers - масив в якому будуть перевірятися повторювання
 * @param length - довжина масиву
 * @param number_to_check - число, кількість повторювань якого требя перевірити
 * @return кількість повторювань
 */
size_t get_count_of_number_repetitions(const int *numbers, size_t length, int number_to_check);

/**
 * @brief Отримати масив який містить інформацію про числа які повторюються,
 * кожен непарний елемент масиву - число, яке повторюється. Кожен парний -
 * кількість повторювань. Наприклад: array[0] = 8, array[1] = 3, 8 - число,
 * яке повторюється, 3 - кількість повторювань
 * 
 * @param input_numbers - масив чисел, елементи якого будуть перевірятися
 * @param length - довжина масиву чисел
 * @return масив чисел з інформацією про повторення. Повертає array[0] = 0,
 * array[1] = 0, якщо в масиві нема чисел які повторюються
 */
int *get_information_about_repeating_numbers(const int *input_numbers, size_t length);