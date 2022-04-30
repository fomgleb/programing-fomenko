/**
 * @mainpage
 *	# Загальне завдання
 *	Зробити програму працюючи зі строками.
 *
 *	# Індивідуальне завдання
 *	(21) Сформувати частотну таблицю символів у тексту та вивести її на екран (з вказанням
 *	кількості та процентного відношення). Обмеження - виводити тільки ті символи, що
 *	зустрічаються у тексті.
 *
 * @author fomgleb
 * @date 29.04.2022
 * @version 1.0
*/

/**
 * @file main.c
 * @brief Головний файл в програмі.
 *
 * @author fomgleb
 * @date 29.04.2022
 * @version 1.0
*/

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - виведення інформації з файлу про лабораторну та виконавця;
 * - введення тексту із стандартного потоку вводу;
 * - функціями з lib.c отримання кількоскі кожного тексту та відсоткового співвідношення;
 * - виведення даних;
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
	char inventory_data_string[STRING_SIZE];
	while (!feof(laboratory_data_file)) {
		if (fgets(inventory_data_string, STRING_SIZE, laboratory_data_file)) {
			printf("%s", inventory_data_string);
		}
	}
	fclose(laboratory_data_file);

	printf("Input the text, please:\n");
	size_t text_length = 5000;
	char *inputed_text = malloc(text_length);
	fgets(inputed_text, (int)text_length, stdin);
	int last_element_index = get_element_index(inputed_text, text_length, '\n');
	inputed_text[last_element_index] = '\0';
	text_length = (size_t)last_element_index + 1;

	char *output_repeating_chars = malloc(text_length * sizeof(char));
	size_t *repeating_chars_counts = get_repeating_chars_counts(inputed_text, text_length, output_repeating_chars);

	size_t repeating_chars_counts_length = (size_t)get_element_index(output_repeating_chars, text_length, '\0');
	float *repeating_chars_percentage = get_percentage(repeating_chars_counts, repeating_chars_counts_length);

	for (size_t i = 0; output_repeating_chars[i] != '\0'; i++) {
		printf("|%c| - %zu шт, %.1f %%\n", output_repeating_chars[i], repeating_chars_counts[i], repeating_chars_percentage[i]);
	}

	free(inputed_text);
	free(output_repeating_chars);
	free(repeating_chars_percentage);
	free(repeating_chars_counts);

	return 0;
}
