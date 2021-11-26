/*
 * Find the determinant of integer matrix
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

long long get_determinant(int input_matrix[], size_t size);
long double get_value(long double matrix[], size_t width, size_t x, size_t y);
void convert_matrix(int input_matrix[], size_t width, size_t height, long double output_matrix[]);
void rearrange_lines(long double matrix[], size_t width, size_t line1_index, size_t line2_index);
void subtract_main_line_from_another(long double matrix[], size_t width, size_t subtrahend_line_index, size_t minuend_line_index,
				     long double subtrahend_line_multiplier);
bool is_equals_to_zero(long double number_to_compare);

#define SIZE 5

int main(int argc, char **argv)
{
	int matrix[SIZE * SIZE] = { 58, 67, 56, 55, 34,
								84, 56, 56, 44, 21,
								67, 54, 45, 65, 65,
								67, 654, 56, 76, 63,
								12, 64, 67, 12, 9 };

	if (argc == SIZE * SIZE + 1) {
		for (size_t i = 0; i < SIZE * SIZE; i++) {
			matrix[i] = (int)strtod(argv[i + 1], 0);
		}
	}

	long long result = get_determinant(matrix, SIZE);

	return 0;
}

long long get_determinant(int input_matrix[], size_t size)
{
	long double matrix[SIZE * SIZE];
	convert_matrix(input_matrix, size, size, matrix);

	short sign = 1; // 1 = plus, -1 = minus
	long double result = 1;

	for (size_t diagonal_index = 0; diagonal_index < size; diagonal_index++) { // Иду по диагонали

		if (is_equals_to_zero(get_value(matrix, size, diagonal_index, diagonal_index))) { // Если на текущем элементе диагонали 0
			for (size_t y = diagonal_index + 1; y < size; y++) { // Переставляю строки чтобы на диагонали неыбыло 0
				if (!is_equals_to_zero(get_value(matrix, size, diagonal_index, y))) {
					rearrange_lines(matrix, size, diagonal_index, y);
					sign *= -1;
					break;
				}
			}
			if (is_equals_to_zero(
				    get_value(matrix, size, diagonal_index, diagonal_index))) { // Если 0 так и остался, то значит determinant = 0
				return 0;
			}
		}

		for (size_t y = diagonal_index + 1; y < size; y++) { // Иду вниз с текущего элемента диагонали
			if (!is_equals_to_zero(get_value(matrix, size, diagonal_index,
							 y))) { // Если не ноль => Делаю элементарные преобразования, а именно выченание был 0
				subtract_main_line_from_another(matrix, size, diagonal_index, y,
								get_value(matrix, size, diagonal_index, y) /
									get_value(matrix, size, diagonal_index,
										  diagonal_index)); // 7 * x = 3; x = 3/7
			}
		}

		result *= get_value(matrix, size, diagonal_index, diagonal_index);
	}

	return result > 0 ? (long)(result + 0.5) * sign : (long)(result - 0.5) * sign;
}

long double get_value(long double matrix[], size_t width, size_t x, size_t y)
{
	return matrix[y * width + x];
}

void convert_matrix(int input_matrix[], size_t width, size_t height, long double output_matrix[])
{
	for (size_t i = 0; i < width * height; i++) {
		output_matrix[i] = (long double)input_matrix[i];
	}
}

void rearrange_lines(long double matrix[], size_t width, size_t line1_index, size_t line2_index)
{
	for (size_t x = 0; x < width; x++) {
		long double ancillary = matrix[line1_index * width + x];
		matrix[line1_index * width + x] = matrix[line2_index * width + x];
		matrix[line2_index * width + x] = ancillary;
	}
}

void subtract_main_line_from_another(long double matrix[], size_t width, size_t subtrahend_line_index, size_t minuend_line_index,
				     long double subtrahend_line_multiplier)
{
	for (size_t x = 0; x < width; x++) {
		matrix[minuend_line_index * width + x] -= matrix[subtrahend_line_index * width + x] * subtrahend_line_multiplier;
	}
}

bool is_equals_to_zero(long double number_to_compare)
{
	long double zero = 0.00000000001;
	if (number_to_compare > 0) {
		return number_to_compare <= zero;
	} else if (number_to_compare < 0) {
		return number_to_compare >= zero;
	} else {
		return true;
	}
}