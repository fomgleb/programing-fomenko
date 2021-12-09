/**
 * @mainpage
 * # Загальне завдання
 * 1. **Сформувати** функцію, що переводе число в речення з слів. Ліміт числа: від -9999 до 9999
 *
 * @author fomgleb
 * @date 06-dec-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Головний та єдиний файл в програмі.
 *
 * @author fomgleb
 * @date 06-dec-2021
 * @version 1.0
 */

#include <time.h>
#include <stdlib.h>

/**
 * Довжина результуючої строки
 */
#define RESULT_COUNT 100
/**
 * Кількість елементів в масиві figures
 */
#define FIGURES_COUNT 20
/**
 * Кількість елементів в масиві tens
 */
#define TENS_COUNT 10
/**
 * Довжина кожного слова в figures та tens
 */
#define STRING_SIZE 10
/**
 * Довжина результуючого масиву
 */
#define RESULTING_ARRAY_COUNT 8
/**
 * Максимальне число для заповнення рандомно
 */
#define MAX_NUMBER 9999
/**
 * Мінімальне число для заповнення рандомно
 */
#define MIN_NUMBER -9999

/**
 * Запис в змінну {@link printableResult} речення, переведене з числа
 *
 * Функція переводить число в слова та записує в змінну {@link printableResult}, наприклад:
 * 3925 => three thousand nine hundred and twenty five
 * @param number число, яке треба перевести в речення
 */
void make_string_from_number(int number, char printableResult[]);

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - Перевіка чи є якісь аргументи з командої строки, якщо є, то запис в {@link number}, else запис випадковим числом.
 * - Визов функції {@link make_string_from_number} передаваючи {@link number} як аргумент.
 * @return успішний код повернення з програми (0)
 */
int main(int argc, char **argv)
{
	// lab06
	int number = 0;
	if (argc == 1) {
		srandom((unsigned int)time(NULL));
		number = MIN_NUMBER + (int)random() % (MAX_NUMBER - MIN_NUMBER);
	} else {
		number = (int)strtod(argv[1], 0);
	}
	char result[RESULT_COUNT];
	make_string_from_number(number, result);

	return 0;
}

void make_string_from_number(int number, char printableResult[])
{
	char figures[FIGURES_COUNT][STRING_SIZE] = { "zero",	 "one",	    "two",     "three",	    "four",	"five",	   "six",
						     "seven",	 "eight",   "nine",    "ten",	    "eleven",	"twelve",  "thirteen",
						     "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	char tens[TENS_COUNT][STRING_SIZE] = { "", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	char thousand[9] = "thousand";
	char hundred[7] = "hundred";
	char and[3] = "and";
	char minus[6] = "minus";

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

	char result[RESULTING_ARRAY_COUNT][STRING_SIZE] = { "", "", "", "", "", "", "", "" };
	for (int i = 0; i < RESULTING_ARRAY_COUNT; i++) {
		switch (i) {
		// minus or zero
		case 0:
			if (firstFigure == 0 && secondFigure == 0 && thirdFigure == 0 && fourthFigure == 0) {
				for (int j = 0; j < STRING_SIZE; j++) {
					result[i][j] = figures[i][j];
				}
				break;
			}
			if (thereIsMinus == 1) {
				for (int j = 0; j < (int)sizeof(minus); j++) {
					result[i][j] = minus[j];
				}
			}
			break;
		// one, two, three... thousand
		case 1:
			if (firstFigure > 0) {
				for (int j = 0; j < STRING_SIZE; j++) {
					result[i][j] = figures[firstFigure][j];
				}
				i++;
				for (int j = 0; j < (int)sizeof(thousand); j++) {
					result[i][j] = thousand[j];
				}
			}
			break;
		// one, two, three... hundred
		case 3:
			if (secondFigure > 0) {
				for (int j = 0; j < STRING_SIZE; j++) {
					result[i][j] = figures[secondFigure][j];
				}
				i++;
				for (int j = 0; j < (int)sizeof(hundred); j++) {
					result[i][j] = hundred[j];
				}
			}
			break;
		// and
		case 5:
			if ((firstFigure != 0 || secondFigure != 0) && (thirdFigure != 0 || fourthFigure != 0)) {
				for (int j = 0; j < (int)sizeof(and); j++) {
					result[i][j] = and[j];
				}
			}
			break;
		// one, two, three... eleven, twelve... twenty one, thirty one
		case 6:
			if (thirdFigure == 1) {
				for (int j = 0; j < STRING_SIZE; j++) {
					result[i][j] = figures[thirdFigure * 10 + fourthFigure][j];
				}
				i++;

			} else if (thirdFigure > 1) {
				for (int j = 0; j < STRING_SIZE; j++) {
					result[i][j] = tens[thirdFigure][j];
				}
				i++;
				for (int j = 0; j < STRING_SIZE; j++) {
					result[i][j] = figures[fourthFigure][j];
				}
			}
			break;
		// one, two, three
		case 7:
			if (fourthFigure > 0) {
				for (int j = 0; j < (int)sizeof(figures)[0]; j++) {
					result[i][j] = figures[fourthFigure][j];
				}
			}
			break;
		default:
			break;
		}
	}

	int limitingChar;
	for (int i = 0, k = 0; i < (int)sizeof(result) / (int)sizeof(result[0]); i++) {
		for (int j = 0; j < STRING_SIZE; j++, k++) {
			if (result[i][j] == '\0') {
				break;
			}
			printableResult[k] = result[i][j];
		}
		if (result[i][0] != '\0') {
			printableResult[k] = ' ';
			k++;
		}
		limitingChar = k;
	}
	printableResult[limitingChar] = '\0';

	// Remove useless spaces
	for (int i = 0, j = 0; i < RESULT_COUNT; i++) {
		if (printableResult[i] == ' ' && ((printableResult[i + 1] == ' ' || printableResult[i + 1] == '\0'))) {
			continue;
		}
		printableResult[j] = printableResult[i];
		j++;
	}
}
