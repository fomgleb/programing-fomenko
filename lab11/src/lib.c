/**
 * @file lib.c
 * @brief Файл з реалізаціями функцій для отримання та виведення оберненої матриці
 *
 * @author fomgleb
 * @date 18.01.2022
 * @version 1.0
*/

#include "lib.h"

double **get_random_matrix(size_t width, size_t height, int min_value, int max_value, double min_step)
{
	double **matrix = malloc(height * sizeof(double *));
	for (size_t i = 0; i < height; i++) {
		*(matrix + i) = malloc(width * sizeof(double));
	}

	int max_number_after_point = 1;
	for (double i = min_step; i < 1; i *= 10) {
		max_number_after_point *= 10;
	}

	int integer_part_of_number = 0;
	int fractional_part_of_number = 0;
	srandom((unsigned int)time(NULL));
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
			integer_part_of_number = min_value + (int)random() % (max_value - min_value);
			fractional_part_of_number = (int)random() % (max_number_after_point);

			double fractional_part = (double)fractional_part_of_number * (double)min_step;

			*((*(matrix + i)) + j) = (double)integer_part_of_number + ((double)fractional_part_of_number / (double)max_number_after_point);
		}
	}

	return matrix;
}
