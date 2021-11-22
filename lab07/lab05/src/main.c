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

/*
	for (; GCD == 0;) {
		if (first_num > second_num) {
			first_num = first_num % second_num;
		} else {
			second_num = second_num % first_num;
		}

		if (first_num == 0 || second_num == 0) {
			GCD = first_num == 0 ? second_num : first_num;
		}
	}
	*/

/*
	do {
		if (first_num > second_num) {
			first_num = first_num % second_num;
		} else {
			second_num = second_num % first_num;
		}

		if (first_num == 0 || second_num == 0) {
			GCD = first_num == 0 ? second_num : first_num;
		}
	} while (GCD == 0);
	*/
