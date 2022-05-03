/**
 * @file lib.h
 * @brief Файл з описом функцій для отримання максимального елементу матриці
 *
 * @author fomgleb
 * @date 02.05.2022
 * @version 1.0
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Визначає максимальний елемент матриці
 * 
 * @param matrix - матриця яка перевіряється
 * @param matrix_height - висота матриці
 * @param matrix_width - ширина матриці
 */
double get_max_matrix_element(double *const *const matrix, size_t matrix_height, size_t matrix_width);

/**
 * @brief Записуе дані в файл
 * 
 * @param path_to_file - шлях до файлу
 * @param writing_data - дані, які будуть записані в файл
 * @return true - успішний запис в файл
 * @return false - невдалося відкрити/створити файл
 */
bool write_to_file(const char path_to_file[], const char writing_data[]);

/**
 * @brief Читає дані з файлу
 * 
 * @param path_to_file - шлях до файлу
 * @param buffer_size - розмір буферу, максимальна відстань від пробілу до пробілу в файлі
 * @param data_length - розмір даних в файлі
 * @return NULL - не вдалося відкрити файл
 */
char *read_from_file(const char path_to_file[], size_t buffer_size, size_t data_length);