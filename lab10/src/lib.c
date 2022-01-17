/**
 * @file lib.c
 * @brief Файл з реалізаціями функцій для отримання інформації про повторення значень в масиві
 *
 * @author fomgleb
 * @date 30-dec-2021
 * @version 2.0
 */

#include "lib.h"

int *get_random_numbers(size_t length, int min_value, int max_value)
{
	int *numbers = malloc(length * sizeof(int));

	srandom((unsigned int)time(NULL));
	for (size_t i = 0; i < length; i++) {
		*(numbers + i) = min_value + (int)random() % (max_value - min_value);
	}

	return numbers;
}

size_t get_count_of_number_repetitions(const int *numbers, size_t length, int number_to_check)
{
	size_t repetitions_counter = 0;

	for (size_t i = 0; i < length; i++) {
		if (numbers + i != NULL && *(numbers + i) == number_to_check) {
			repetitions_counter++;
		}
	}

	return repetitions_counter;
}

int *get_copied_array(const int *array_to_copy, size_t length)
{
	int *copied_array = malloc(length * sizeof(int));

	for (size_t i = 0; i < length; i++) {
		*(copied_array + i) = *(array_to_copy + i);
	}

	return copied_array;
}

int *get_information_about_repeating_numbers(const int *numbers, size_t length)
{
	int *information = malloc(length * sizeof(int));
	size_t length_of_information = 0;

	char *used_numbers_mask = malloc(length * sizeof(char)); // '1' - вже використане число, '0' - ще не використане число
	for (size_t i = 0; i < length; i++) {
		*(used_numbers_mask + i) = '0';
	}

	for (size_t i = 0; i < length; i++) {
		size_t current_number_repetition_count = get_count_of_number_repetitions(numbers, length, *(numbers + i));

		if (*(used_numbers_mask + i) == '1') {
			continue;
		}

		if (current_number_repetition_count > 1) {
			length_of_information += 2;

			*(information + length_of_information - 2) = *(numbers + i);
			*(information + length_of_information - 1) = (int)current_number_repetition_count;
		}

		for (size_t j = 0; j < length; j++) {
			if (*(numbers + j) == *(numbers + i)) {
				*(used_numbers_mask + j) = '1';
			}
		}
	}

	if (length_of_information > 0) {
		information = realloc(information, length_of_information * sizeof(int));
	} else {
		information = realloc(information, 2 * sizeof(int));
		*(information) = 0;
		*(information + 1) = 0;
	}

	free(used_numbers_mask);

	return information;
}