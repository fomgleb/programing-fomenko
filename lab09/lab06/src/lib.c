/**
 * @file lib.c
 * @brief Файл з реалізаціями функцій для переводу числа в рядок
 *
 * @author fomgleb
 * @date 30-dec-2021
 * @version 2.0
 */

#include "lib.h"

void make_string_from_number(int number, char result[])
{
#define MIN_NUMBER -9999
#define MAX_NUMBER 9999
#define MAX_WORDS_COUNT 10
#define MAX_WORD_SIZE 10

	char figures[][MAX_WORD_SIZE] = { "zero",     "one",	 "two",	    "three",	 "four",     "five",	"six",
					  "seven",    "eight",	 "nine",    "ten",	 "eleven",   "twelve",	"thirteen",
					  "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	char tens[][MAX_WORD_SIZE] = { "", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	char thousand_word[] = "thousand";
	char hundred_word[] = "hundred";
	char and_word[] = "and";
	char minus_word[] = "minus";

	// out of range check
	if (number > MAX_NUMBER) {
		number = MAX_NUMBER;
	} else if (number < MIN_NUMBER) {
		number = MIN_NUMBER;
	}

	// minus check
	short thereIsMinus = 0;
	if (number < 0) {
		number *= -1;
		thereIsMinus = 1;
	}

	int firstFigure = number / 1000;
	int secondFigure = (number / 100) % 10;
	int thirdFigure = (number / 10) % 10;
	int fourthFigure = number % 10;

	int max_symbols_in_result = MAX_WORDS_COUNT * MAX_WORD_SIZE;
	int writed_symbols = 0;
	// zero
	if (firstFigure == 0 && secondFigure == 0 && thirdFigure == 0 && fourthFigure == 0) {
		writed_symbols += insert_word_in_the_end(result, figures[0], MAX_WORD_SIZE, writed_symbols, false);
	} else {
		//minus
		if (thereIsMinus == 1) {
			writed_symbols += insert_word_in_the_end(result, minus_word, MAX_WORD_SIZE, writed_symbols, true);
		}

		// (one || two || three || four || five || six || seven || eight || nine) thousand
		if (firstFigure > 0) {
			writed_symbols += insert_word_in_the_end(result, figures[firstFigure], MAX_WORD_SIZE, writed_symbols, true);
			writed_symbols += insert_word_in_the_end(result, thousand_word, MAX_WORD_SIZE, writed_symbols, true);
		}

		// (one || two || three || four || five || six || seven || eight || nine) hundred
		if (secondFigure > 0) {
			writed_symbols += insert_word_in_the_end(result, figures[secondFigure], MAX_WORD_SIZE, writed_symbols, true);
			writed_symbols += insert_word_in_the_end(result, hundred_word, MAX_WORD_SIZE, writed_symbols, true);
		}

		// and
		if ((firstFigure != 0 || secondFigure != 0) && (thirdFigure != 0 || fourthFigure != 0)) {
			writed_symbols += insert_word_in_the_end(result, and_word, MAX_WORD_SIZE, writed_symbols, true);
		}

		// ten || eleven || twelve || thirteen || fourteen || fifteen || sixteen || seventeen || eighteen || nineteen
		if (thirdFigure == 1) {
			writed_symbols += insert_word_in_the_end(result, figures[10 + fourthFigure], MAX_WORD_SIZE, writed_symbols, false);
			// twenty || thirty || ... || eighty || ninety ||
		} else if (thirdFigure > 1) {
			writed_symbols += insert_word_in_the_end(result, tens[thirdFigure], MAX_WORD_SIZE, writed_symbols, false);
		}

		if (fourthFigure > 0) {
			// -one || -two || ... || -eight || -nine
			if (thirdFigure > 1) {
				writed_symbols += insert_word_in_the_end(result, "-", MAX_WORD_SIZE, writed_symbols, false);
				writed_symbols += insert_word_in_the_end(result, figures[fourthFigure], MAX_WORD_SIZE, writed_symbols, false);
			}
			// one || two || ... || eight || nine
			if (thirdFigure == 0) {
				writed_symbols += insert_word_in_the_end(result, figures[fourthFigure], MAX_WORD_SIZE, writed_symbols, false);
			}
		}
	}

	if (result[writed_symbols - 1] == ' ') {
		result[writed_symbols - 1] = '\0';
	} else {
		result[writed_symbols] = '\0';
	}
}

int get_real_word_size(char word[], int size)
{
	int word_size = 0;
	for (int i = 0; i < size; i++) {
		if (word[i] != '\0') {
			word_size++;
		} else {
			break;
		}
	}

	return word_size;
}

int insert_word_in_the_end(char text[], char word[], int word_size, int inserting_index, bool add_space_in_the_end)
{
	int real_word_size = get_real_word_size(word, word_size);
	int writed_symbols = 0;

	for (int i = 0; i < real_word_size; i++) {
		text[inserting_index + i] = word[i];
		writed_symbols++;
	}
	if (add_space_in_the_end) {
		text[inserting_index + real_word_size] = ' ';
		writed_symbols++;
	}

	return writed_symbols;
}