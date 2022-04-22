/**
 * @file lib.c
 * @brief Файл з реалізаціями функцій для отримання та виведення оберненої матриці
 *
 * @author fomgleb
 * @date 18.01.2022
 * @version 1.0
*/

#include "lib.h"
#include <stdio.h>
#include <stdbool.h>

void print_matrix(long double **matrix, size_t width, size_t height)
{
	if (matrix == NULL || width == 0 || height == 0) {
		return;
	}

	for (size_t i = 0; i < height; i++) {
		printf("[");
		for (size_t j = 0; j < width; j++) {
			if (j == width - 1)
				printf("%.3Lf", matrix[i][j]);
			else
				printf("%.3Lf\t", matrix[i][j]);
		}
		printf("]\n");
	}
}

long double **get_identity_matrix(size_t width_and_height)
{
	if (width_and_height <= 1) {
		return NULL;
	}

	long double **identity_matrix;
	identity_matrix = malloc(width_and_height * sizeof(long double *));
	for (size_t i = 0; i < width_and_height; i++) {
		identity_matrix[i] = malloc(width_and_height * sizeof(long double));
	}

	for (size_t i = 0; i < width_and_height; i++) {
		for (size_t j = 0; j < width_and_height; j++) {
			identity_matrix[i][j] = 0;
		}
	}

	for (size_t i = 0; i < width_and_height; i++) {
		identity_matrix[i][i] = 1;
	}

	return identity_matrix;
}

void swap_lines_in_matrix(long double *line1, long double *line2, size_t width)
{
	if (line1 == NULL || line2 == NULL || width == 0) {
		return;
	}

	for (size_t x = 0; x < width; x++) {
		long double temp = line1[x];
		line1[x] = line2[x];
		line2[x] = temp;
	}
}

void subtract_one_array_from_another(long double *subtrahend_array, long double subtrahend_line_multiplier, long double *minuend_array, size_t width)
{
	if (width == 0 || subtrahend_array == NULL || minuend_array == NULL) {
		return;
	}

	for (size_t x = 0; x < width; x++) {
		minuend_array[x] -= subtrahend_array[x] * subtrahend_line_multiplier;
	}
}

long double **append_identity_matrix(long double **matrix, size_t width_and_height)
{
	if (matrix == NULL || width_and_height == 0) {
		return NULL;
	}

	long double **appended_matrix = malloc(width_and_height * sizeof(long double *));
	for (size_t i = 0; i < width_and_height; i++) {
		appended_matrix[i] = malloc(width_and_height * 2 * sizeof(long double));
	}

	long double **identity_matrix = get_identity_matrix(width_and_height);

	for (size_t y = 0; y < width_and_height; y++) {
		for (size_t x = 0; x < width_and_height + width_and_height; x++) {
			if (x > width_and_height - 1) {
				appended_matrix[y][x] = identity_matrix[y][x - width_and_height];
			} else {
				appended_matrix[y][x] = matrix[y][x];
			}
		}
	}

	for (size_t i = 0; i < width_and_height; i++) {
		free(identity_matrix[i]);
	}
	free(identity_matrix);

	return appended_matrix;
}

void divide_array_by_number(long double *array, long double number, size_t width)
{
	for (size_t i = 0; i < width; i++) {
		array[i] /= number;
	}
}

long double **get_inverse_matrix(long double **matrix_to_inverse, size_t width_and_height)
{
	long double **appended_matrix = append_identity_matrix(matrix_to_inverse, width_and_height);
	size_t width = width_and_height * 2;
	size_t height = width_and_height;
	short sign = 1; // 1 = positive, -1 = negative

	for (size_t diagonal_index = 0; diagonal_index < width_and_height; diagonal_index++) {
		if (appended_matrix[diagonal_index][diagonal_index] == 0) { // Если на текущем элементе диагонали 0
			for (size_t y = diagonal_index + 1; y < height; y++) { // Переставляю строки чтобы на диагонали не было 0
				if (appended_matrix[y][diagonal_index] != 0) {
					swap_lines_in_matrix(appended_matrix[diagonal_index], appended_matrix[y], width);
					sign *= -1;
					break;
				}
			}
			if (appended_matrix[diagonal_index][diagonal_index] == 0) { // Если 0 так и остался, то значит determinant = 0
				for (size_t i = 0; i < height; i++) {
					free(appended_matrix[i]);
				}
				free(appended_matrix);

				return NULL;
			}
		}

		divide_array_by_number(appended_matrix[diagonal_index], appended_matrix[diagonal_index][diagonal_index], width);

		for (size_t y = 0; y < height; y++) {
			if (y != diagonal_index) {
				subtract_one_array_from_another(appended_matrix[diagonal_index], appended_matrix[y][diagonal_index],
								appended_matrix[y], width);
			}
		}
	}

	long double **inverse_matrix = malloc(height * sizeof(long double *));
	for (size_t i = 0; i < height; i++) {
		inverse_matrix[i] = malloc(width / 2 * sizeof(long double));
	}

	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width / 2; j++) {
			inverse_matrix[i][j] = appended_matrix[i][j + width / 2];
		}
	}

	for (size_t i = 0; i < height; i++) {
		free(appended_matrix[i]);
	}
	free(appended_matrix);

	return inverse_matrix;
}