/*
 * Find the greatest common divisor of two numbers
 *
 * input:
 * 	int first_num;
 * 	int second_num;
 *
 * output:
 * 	int GCD;
 *	
 *
 *
 */

#include <stdio.h> // імпортую бібліотеку stdio.h, щоб працювати з printf та scanf
int main() // точка входу
{
	// input
	int first_num = 0;
	int second_num = 0;

	// output
	int GCD;

	while (first_num >= 0 || second_num >= 0) {
		GCD = 0;

		printf("\nFirst number: ");
		scanf("%i", &first_num);
		printf("Second number: ");
		scanf("%i", &second_num);

		/*
		for (; GCD == 0;) {
			if (first_num > second_num) {
				first_num = first_num % second_num;
			} else {
				second_num = second_num % first_num;
			}

			if (first_num == 0 || second_num == 0) {
				GCD = first_num == 0 ? second_num : first_num;
				printf("The greater common divisor: %i\n", GCD);
			}
		}
		*/

		// використовую метод ейлера
		while (GCD == 0) {
			if (first_num > second_num) {
				first_num = first_num % second_num;
			} else {
				second_num = second_num % first_num;
			}

			if (first_num == 0 || second_num == 0) { // вивожу, только ести или first_num или second_num равно нулю
				GCD = first_num == 0 ? second_num : first_num;
				printf("The greater common divisor: %i\n", GCD);
			}
		}

		/*
		do {
			if (first_num > second_num) {
				first_num = first_num % second_num;
			} else {
				second_num = second_num % first_num;
			}

			if (first_num == 0 || second_num == 0) {
				GCD = first_num == 0 ? second_num : first_num;
				printf("The greater commot divisor: %i\n", GCD);
			}
		} while (GCD == 0);
		*/
	}

	return 0;
}
