/**
 * @mainpage
 *	# Загальне завдання
 *	Зробити програму взаємодіючи з файлами.
 *
 *	# Індивідуальне завдання
 *	(4) Дано файл, що містить інформацію про матрицю. Визначити максимальний елемент.
 *
 * @author fomgleb
 * @date 01.05.2022
 * @version 1.0
*/

/**
 * @file main.c
 * @brief Головний файл в програмі.
 *
 * @author fomgleb
 * @date 01.05.2022
 * @version 1.0
*/

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - виведення інформації з файлу про лабораторну та виконавця;
 * - введення даних про матрицю із файлу;
 * - функцією get_max_matrix_element визначаю максимальний елемент матриці;
 * - виведення максимального елемента матрці;
 * - запис максимального елементу матриці в файл;
 * - визволення пам'яті.
 * @return успішний код повернення з програми (0)
 */
int main()
{
	const char PATH_TO_LABORATORY_DATA_FILE[] = "assets/input.txt";
	const char PATH_TO_INPUT_MATRIX_FILE[] = "assets/input_matrix.txt";
	const char PATH_OUTPUT_FILE[] = "assets/output.txt";

	// Information about laboratory work
	char *laboratory_data = read_from_file(PATH_TO_LABORATORY_DATA_FILE, 20, 1000);
	if (laboratory_data == NULL) {
		printf("\n\n## Failed to open \"%s\" ##\n\n", PATH_TO_LABORATORY_DATA_FILE);
	}
	printf("\n%s", laboratory_data);

	// Input matrix from file
	FILE *input_matrix_file = NULL;
	double **matrix;
	size_t matrix_width = 0;
	size_t matrix_height = 0;
	input_matrix_file = fopen(PATH_TO_INPUT_MATRIX_FILE, "r");
	if (input_matrix_file == NULL) {
		printf("\n\n## Failed to open \"%s\" ##\n\n", PATH_TO_INPUT_MATRIX_FILE);
	}
	fscanf(input_matrix_file, "%zu %zu", &matrix_width, &matrix_height);
	matrix = malloc(matrix_height * sizeof(double *));
	for (size_t y = 0; y < matrix_height; y++) {
		matrix[y] = malloc(matrix_width * sizeof(double));
	}
	for (size_t y = 0; y < matrix_height; y++) {
		for (size_t x = 0; x < matrix_width; x++) {
			fscanf(input_matrix_file, "%lf", &matrix[y][x]);
		}
	}
	fclose(input_matrix_file);

	// Print information about inputed matrix
	printf("Matrix width: %zu\n", matrix_width);
	printf("Matrix height: %zu\n", matrix_height);
	printf("Matrix:\n");
	for (size_t y = 0; y < matrix_height; y++) {
		printf("\t[");
		for (size_t x = 0; x < matrix_width; x++) {
			printf("%.2f\t", matrix[y][x]);
		}
		printf("]\n");
	}

	// Max matrix element
	double max_matrix_element = get_max_matrix_element(matrix, matrix_height, matrix_width);
	printf("Max matrix element: %.2f\n", max_matrix_element);

	// Write max matrix element to file
	char writing_data[10];
	sprintf(writing_data, "%.2f", max_matrix_element);
	write_to_file(PATH_OUTPUT_FILE, writing_data);

	// Data releasing
	free(laboratory_data);
	for (size_t y = 0; y < matrix_height; y++) {
		free(matrix[y]);
	}
	free(matrix);

	return 0;
}