/**
 * @file lib.c
 * @brief Файл з реалізаціями функцій для отримання максимального елементу матриці
 *
 * @author fomgleb
 * @date 02.05.2022
 * @version 1.0
*/

#include "lib.h"

double get_max_matrix_element(double *const *const matrix, size_t matrix_height, size_t matrix_width)
{
	double max_element = __DBL_MIN__;
	for (size_t y = 0; y < matrix_height; y++) {
		for (size_t x = 0; x < matrix_width; x++) {
			if (matrix[y][x] > max_element) {
				max_element = matrix[y][x];
			}
		}
	}
	return max_element;
}

bool write_to_file(const char path_to_file[], const char writing_data[])
{
	FILE *writing_file = NULL;

	writing_file = fopen(path_to_file, "w");
	if (writing_file == NULL) {
		return false;
	}

	fprintf(writing_file, "%s", writing_data);
	fclose(writing_file);

	return true;
}

char *read_from_file(const char path_to_file[], size_t buffer_size, size_t data_length)
{
	FILE *reading_file = NULL;
	char *file_content = NULL;
	size_t file_content_index = 0;
	char *buffer_string = NULL;

	reading_file = fopen(path_to_file, "r");
	if (reading_file == NULL) {
		return NULL;
	}

	file_content = malloc(data_length * sizeof(char));
	buffer_string = malloc(buffer_size * sizeof(char));

	while (!feof(reading_file)) {
		if (fgets(buffer_string, (int)buffer_size, reading_file)) {
			for (size_t i = 0; buffer_string[i] != '\0'; i++) {
				file_content[file_content_index++] = buffer_string[i];
			}
		}
	}
	fclose(reading_file);

	file_content[file_content_index] = '\0';

	free(buffer_string);

	return file_content;
}