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

double **get_random_matrix(size_t width, size_t height, int min_value, int max_value, double min_step);