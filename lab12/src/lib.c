/**
 * @file lib.c
 * @brief Файл з реалізаціями функцій для отримання частотної таблиці символів у тексті
 *
 * @author fomgleb
 * @date 28.04.2022
 * @version 1.0
*/

#include "lib.h"
#include <stdio.h>
#include <stdbool.h>

float *get_percentage(const size_t *input_numbers, size_t input_numbers_length)
{
	float *percentage = malloc(input_numbers_length * sizeof(float));

	size_t number_of_elements = 0;
	for (size_t i = 0; i < input_numbers_length; i++) {
		number_of_elements += input_numbers[i];
	}

	for (size_t i = 0; i < input_numbers_length; i++) {
		percentage[i] = (float)input_numbers[i] * (float)100 / (float)number_of_elements;
	}

	return percentage;
}

size_t *get_repeating_chars_counts(const char input_text[], size_t input_text_length, char *output_repeating_chars)
{
	size_t *repeating_chars_counts = malloc(input_text_length * sizeof(size_t));

	size_t output_arrays_length = 0;
	for (size_t i = 0; input_text[i] != '\0'; i++) {
		int char_index_in_output_repeating_chars = get_element_index(output_repeating_chars, output_arrays_length, input_text[i]);
		if (char_index_in_output_repeating_chars == -1) { // если в масиве такого элемента нету
			output_repeating_chars[output_arrays_length] = input_text[i]; // в конец массивов добавляю данные
			repeating_chars_counts[output_arrays_length] = 1;
			output_arrays_length++;
		} else { // иначе, прибавляю +1 к масиву количества элементов
			repeating_chars_counts[char_index_in_output_repeating_chars]++;
		}
	}

	output_repeating_chars[output_arrays_length] = '\0';
	output_arrays_length++;

	repeating_chars_counts = realloc(repeating_chars_counts, output_arrays_length * sizeof(size_t));

	return repeating_chars_counts;
}

int get_element_index(const char elements[], size_t elements_length, char element_to_find)
{
	for (size_t i = 0; i < elements_length; i++) {
		if (element_to_find == elements[i]) {
			return (int)i;
		}
	}
	return -1;
}