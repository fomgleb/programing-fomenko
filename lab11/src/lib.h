/**
 * @file lib.h
 * @brief Файл з описом функцій отримання та виведення оберненої матриці
 *
 * @author fomgleb
 * @date 18.01.2022
 * @version 1.0
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief вивести матрицю в консоль
 * 
 * @param matrix - матриця, яку треба вивести
 * @param width - ширина матриці
 * @param height - висота матриці
 */
void print_matrix(long double **matrix, size_t width, size_t height);

/**
 * @brief отримати одиничну матрицю
 * 
 * @param width_and_height ширина та висота одиничної матриці
 */
long double **get_identity_matrix(size_t width_and_height);

/**
 * @brief поміняти місцями значення двох масивів
 * 
 * @param line1 - перша строка
 * @param line2 - друга строка
 * @param width - ширина однієї та другої строки
 */
void swap_lines_in_matrix(long double *line1, long double *line2, size_t width);

/**
 * @brief відняти всі елементи одного масиву від всіх елементів іншого масиву
 * 
 * @param subtrahend_array - масив, елементи якого будуть від'ємниками
 * @param subtrahend_line_multiplier - число, на яке будуть перемножені елементи-від'ємники
 * @param minuend_line - масив елементів від яких будуть відніматися елементи-від'ємники помножені на число множник
 * @param width - ширина масиву
 */
void subtract_one_array_from_another(long double *subtrahend_array, long double subtrahend_array_multiplier, long double *minuend_array,
				     size_t width);

/**
 * @brief додати одиничну матрицю справа до вхідної матриці
 * 
 * @param matrix - матриця, до якої буде додана одинична матриця
 * @param width_and_height - ширина та висота матриці
 */
long double **append_identity_matrix(long double **matrix, size_t width_and_height);

/**
 * @brief поділити елементи масиву на число
 * 
 * @param array - масив, елементи якого будуть ділитися
 * @param number - число, на яке буде ділитися
 * @param width - ширина матриці
 */
void divide_array_by_number(long double *array, long double number, size_t width);

/**
 * @brief отримати зворотню матрицю
 * 
 * @param matrix_to_inverse - матриця, з якої буде зроблена зворотня
 * @param width_and_height - ширина та висота матриці
 */
long double **get_inverse_matrix(long double **matrix_to_inverse, size_t width_and_height);