/**
 * @mainpage
 * # Загальне завдання
 *	Зробити програму з використанням введення/виведення.
 *
 *	# Індивідуальне завдання
 *	(4) Визначити зворотню матрицю.
 *
 * @author fomgleb
 * @date 18.01.2022
 * @version 1.0
*/

/**
 * @file main.c
 * @brief Головний файл в програмі.
 *
 * @author fomgleb
 * @date 18.01.2022
 * @version 1.0
*/

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - виведення інформації з файлу про лабораторну та виконавця;
 * - введення всіх необхідних даних: ширина та висота матриці, елементи матриці;
 * - виклик функції `get_inverse_matrix`, передача всіх необхідних аргументів та запис результату функції в новий масив;
 * - виведення елементив масиву;
 * - визволення пам'яті.
 * @return успішний код повернення з програми (0)
 */
int main()
{
	char laboratory_data_file_path[100] = "./assets/input.txt";
	FILE *laboratory_data_file;
	laboratory_data_file = fopen(laboratory_data_file_path, "r");
	if (laboratory_data_file == NULL) {
		printf("Failed to read file %s", laboratory_data_file_path);
	}
	int const STRING_SIZE = 100;
	char string[STRING_SIZE];
	while (!feof(laboratory_data_file)) {
		if (fgets(string, STRING_SIZE, laboratory_data_file)) {
			printf("%s", string);
		}
	}
	fclose(laboratory_data_file);

	long double **matrix_to_inverse;
	size_t width_and_height;
	printf("Width and height of the matrix: ");
	scanf("%zi", &width_and_height);
	matrix_to_inverse = malloc(width_and_height * sizeof(long double *));
	for (size_t i = 0; i < width_and_height; i++) {
		*(matrix_to_inverse + i) = malloc(width_and_height * sizeof(long double));
	}

	printf("\n");
	for (size_t i = 0; i < width_and_height; i++) {
		for (size_t j = 0; j < width_and_height; j++) {
			printf("matrix[%zi][%zi] = ", i, j);
			scanf("%Lf", *(matrix_to_inverse + i) + j);
		}
	}
	printf("\n");

	printf("Вхідна матриця:");
	printf("\n");
	print_matrix(matrix_to_inverse, width_and_height, width_and_height);
	printf("\n");

	long double **inverse_matrix = get_inverse_matrix(matrix_to_inverse, width_and_height);

	printf("Зворотня матриця:");
	printf("\n");
	if (inverse_matrix == NULL) {
		printf("Зворотню матрицю неможливо знайти так як детермінант матриці дорівнює нулю\n");
	} else {
		print_matrix(inverse_matrix, width_and_height, width_and_height);
	}

	// Releasing
	for (size_t i = 0; i < width_and_height; i++) {
		free(matrix_to_inverse[i]);
	}
	free(matrix_to_inverse);

	if (inverse_matrix != NULL) {
		for (size_t i = 0; i < width_and_height; i++) {
			free(inverse_matrix[i]);
		}

		free(inverse_matrix);
	}

	return 0;
}
