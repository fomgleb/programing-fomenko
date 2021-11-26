# Лабораторна робота № 7. Функції #
## Виконав Фоменко Гліб Володимирович КІТ 121-Г ##

Хід роботи:

* Зробив таку структуру директорії:

		.
		├── README.md
		├── doc
		├── lab05
		│   ├── Makefile
		│   └── src
		│       └── main.c
		└── lab06
		    ├── Makefile
		    └── src
			└── main.c
* В lab5/src/main.c написав такий код:

		/*
		 * Find the greatest common divisor of two numbers
		 *
		 * input:
		 *      int first_num;
		 *      int second_num;
		 *
		 * output:
		 *      int GCD;
		 *
		 */

		int GetGreatestCommonDivisor(int first_num, int second_num);

		#include <time.h>
		#include <stdlib.h>
		int main(int argc, char **argv) // точка входу
		{
			int first_num;
			int second_num;

			if (argc == 1) {
				srandom((unsigned int)time(NULL));
				first_num = (int)random();
				second_num = (int)random();
			} else {
				first_num = (int)strtod(argv[1], 0);
				second_num = (int)strtod(argv[2], 0);
			}

			int greatest_common_divisor = GetGreatestCommonDivisor(first_num, second_num);

			return 0;
		}

		int GetGreatestCommonDivisor(int first_num, int second_num)
		{
			// використовую метод ейлера
			int greatest_common_divisor = 0;
			while (greatest_common_divisor == 0) {
				if (first_num > second_num) {
					first_num = first_num % second_num;
				} else {
					second_num = second_num % first_num;
				}

				if (first_num == 0 || second_num == 0) {
					greatest_common_divisor = first_num == 0 ? second_num : first_num;
				}
			}
			return greatest_common_divisor;
		}
* Виходить що, якщо user не передає аргументи в main, то береться 2 рандомних числа

* Далі написав такий код в lab06/src/main.c:

		#define RESULT_COUNT 100
		#define FIGURES_COUNT 20
		#define TENS_COUNT 10
		#define STRING_SIZE 10
		#define RESULTING_ARRAY_COUNT 8
		#define MAX_NUMBER 9999
		#define MIN_NUMBER -9999

		char printableResult[RESULT_COUNT];

		void make_string_from_number(int number);

		#include <time.h>
		#include <stdlib.h>
		int main(int argc, char **argv)
		{

			// input
			int number = 0;
			if (argc == 1) {
				srandom((unsigned int)time(NULL));
				number = MIN_NUMBER + (int)random()%(MAX_NUMBER - MIN_NUMBER);
			} else {
				number = (int)strtod(argv[1], 0);
			}

			make_string_from_number(number);

			return 0;
		}

		void make_string_from_number(int number) {
			char figures[FIGURES_COUNT][STRING_SIZE] = { "zero",     "one",     "two",     "three",     "four",     "five",    "six",
								     "seven",    "eight",   "nine",    "ten",       "eleven",   "twelve",  "thirteen",
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

			// Write from array into sting

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
				if (printableResult[i] == ' ' &&
				    ((printableResult[i + 1] == ' ' ||
				      printableResult[i + 1] == '\0'))) {
					continue;
				}
				printableResult[j] = printableResult[i];
				j++;
			}
		}
* Так як ми не вміємо використовувати вказівники в си, я винес printableResult за функцію main, тому що я не можу вернути массив.

* Далі я вирішив виконати перше завдання складного рівня:

		#include <stdarg.h>

		int get_count_bigger_than_next_numbers(int count, ...);

		int main()
		{
			int result = get_count_bigger_than_next_numbers(5, 2, 4, 5, 3, 2);

			return 0;
		}

		int get_count_bigger_than_next_numbers(int count, ...)
		{
			va_list variables;
			va_list variables_copy;
			int counter = 0;

			va_start(variables, count);
			va_copy(variables_copy, variables);

			va_arg(variables_copy, int);

			for (int i = 0; i < count - 1; i++) {
				if (va_arg(variables, int) > va_arg(variables_copy, int)) {
					counter++;
				}
			}

			return counter;
		}
* В завданні цьому написано що треба знайти кількість пар чисел перше якого менше наступного але в прикладі показано { 3, 2, 4, 3, 1} = 3. Але три виходить тільки якщо перше більше наступного. Тому я зробив якщо більше але це можно змінити просто змінивши знак на протилежний  в if (va_arg(variables, int) > va_arg(variables_copy, int)) (змінити `>` на `<`).

* І мені дуже сподобалось друге додаткове завдання і я його зробив:

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
		void subtract_main_line_from_another(long double matrix[], size_t width, size_t subtrahend_line_index, size_t minuend_line_index, long double subtrahend_line_multiplier);
		bool is_equals_to_zero(long double number_to_compare);

		#define SIZE 5

		int main(int argc, char **argv) {
			int matrix[SIZE*SIZE] = {58,  67, 56, 55, 34,
									84,  56,  56, 44, 21,
									67,  54, 45, 65, 65,
									67, 654, 56, 76, 63,
									12, 64, 67, 12, 9};

			if (argc == SIZE*SIZE+1) {
				for (size_t i = 0; i < SIZE*SIZE; i++)
				{
					matrix[i] = (int)strtod(argv[i+1], 0);
				}
				
			}

			long long result = get_determinant(matrix, SIZE);

			return 0;
		}

		long long get_determinant(int input_matrix[], size_t size) {
			long double matrix[SIZE*SIZE];
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
					if (is_equals_to_zero(get_value(matrix, size, diagonal_index, diagonal_index))) { // Если 0 так и остался, то значит determinant = 0
						return 0;
					}
				}

				for (size_t y = diagonal_index + 1; y < size; y++) { // Иду вниз с текущего элемента диагонали
					if (!is_equals_to_zero(get_value(matrix, size, diagonal_index, y))) { // Если не ноль => Делаю элементарные преобразования, а именно выченание был 0
						subtract_main_line_from_another(matrix, size, diagonal_index, y, get_value(matrix, size, diagonal_index, y) / get_value(matrix, size, diagonal_index, diagonal_index)); // 7 * x = 3; x = 3/7
					}
				}

				result *= get_value(matrix, size, diagonal_index, diagonal_index);
			}

			 return result > 0 ? (long)(result + 0.5) * sign : (long)(result - 0.5) * sign;
		}

		long double get_value(long double matrix[], size_t width, size_t x, size_t y) {
			return matrix[y * width + x];
		}

		void convert_matrix(int input_matrix[], size_t width, size_t height, long double output_matrix[]) {
			for (size_t i = 0; i < width * height; i++) {
				output_matrix[i] = (long double)input_matrix[i];
			}
		}

		void rearrange_lines(long double matrix[], size_t width, size_t line1_index, size_t line2_index) {
			for (size_t x = 0; x < width; x++) {
				long double ancillary = matrix[line1_index * width + x];
				matrix[line1_index * width + x] = matrix[line2_index * width + x];
				matrix[line2_index * width + x] = ancillary;
			}
		}

		void subtract_main_line_from_another(long double matrix[], size_t width, size_t subtrahend_line_index, size_t minuend_line_index, long double subtrahend_line_multiplier) {
			for (size_t x = 0; x < width; x++) {
				matrix[minuend_line_index * width + x] -= matrix[subtrahend_line_index * width + x] * subtrahend_line_multiplier;
			}
		}

		bool is_equals_to_zero(long double number_to_compare) {
			long double zero = 0.00000000001;
			if (number_to_compare > 0) {
				return number_to_compare <= zero;
			} else if (number_to_compare < 0) {
				return number_to_compare >= zero;
			} else {
				return true;
			}
		}

* В цій программі, якщо число дуже велике, то може бути не точніть, щоб це виправити треба писати структуру для дробу. Ця неточність виходить тому що, я там ділю числа і виходить наприклад: 3.9984592834759334 - неточне число, якщо їх таких раза 4 перемножити то і в результаті получиться неточне.

* Висновок: Щоб зробити программу 6 лаборатоної нормальною треба вчити вказівники. Мені дуже сподобалась друге додаткове завдання, я б його зробив ідеальним використовуючи структуру, але поки що ми таке не вчили.
