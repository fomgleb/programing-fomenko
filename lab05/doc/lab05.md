# Лабораторна робота № 5. Циклічні конструкції #

## Виконав Фоменко Гліб Володимирович КІТ 121-Г ##

Хід роботи:

0. Скопіював папку lab04, командою `cp -r lab04 lab05`.

22. Створив файл main.c в src та написав такий код, выкористовуючи while:

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

		#include <stdio.h>
		int main()
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

				while (GCD == 0) {
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
			}

			return 0;
		}

* Зробив варіант з for:

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

		#include <stdio.h>
		int main()
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

				for (;GCD == 0;) {
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

		/*		while (GCD == 0) {
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
			}

			return 0;
		}

* Зробив варіант з do while:

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

		#include <stdio.h>
		int main()
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

				/*
				while (GCD == 0) {
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
			}

			return 0;
		}

* Все працюе однаково з for, while або do while, але конкретно в цьому випадку, красивіше й доречніше виглядає while, тому я його і залишу:

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

		#include <stdio.h>
		int main()
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

				while (GCD == 0) {
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

* Додав коментарі до коду:

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

* Скомпілював, провірив роботу і т. д. все usually.

Висновок: Я реалізував програму за допомогою трьох типів циклів: for, while-do, do-while та отримав три однакових результату. В мойому випадку доречніше використовувати while.
