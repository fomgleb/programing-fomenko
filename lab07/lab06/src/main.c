/*
 * Translate a number to string (min: -9999, max: 9999).
 *
 * Example: 3562 => "three thousand fife hundred and sixty two"
 *
 */

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
		if (printableResult[i] == ' ' &&
		    ((printableResult[i + 1] == ' ' ||
		      printableResult[i + 1] == '\0'))) {
			continue;
		}
		printableResult[j] = printableResult[i];
		j++;
	}	
}
