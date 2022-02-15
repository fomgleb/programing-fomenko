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
 * - Виклик функції {@link get_random_numbers}, щоб отримати масив з рандомними числами
 * - Виклик функції {@link get_information_about_repeating_numbers}, для отримання інформації про числа що повторюються
 * - Визволення пам'яті за допомогою функції free()
 * @return успішний код повернення з програми (0)
 */
int main()
{
	//double **matrix = get_random_matrix(33, 33, -1000, 1000, 0.001);

	double **matrix;
	size_t size;
	printf("Width and height of the matrix: ");
	scanf("%zi", &size);
	matrix = malloc(size * sizeof(double*));
	for (size_t i = 0; i < size; i++) {
		*(matrix + i) = malloc(size * sizeof(double));
	}
	
	printf("\n");
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			printf("matrix[%zi][%zi] = ", i, j);
			scanf("%lf", (*(matrix + i)) + j);
			printf("\n");
		}
	}
	

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			printf("%f\t", matrix[i][j]);
			printf("\n\t## %.3f ##\n\t", matrix[i][j]);
		}
		
	}
	

	return 0;
}
