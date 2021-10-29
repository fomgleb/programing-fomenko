# Лабораторна робота №4. Розробка програм, що розгалужуються #

## Виконав Фоменко Гліб Володимирович КІТ 121-Г ##

Хід роботи:

0. Скопіював всі файли з попередньої лабораторної та зробив таку структуру:

		lab04
		├── Makefile
		├── README.md
		├── doc
		│   └── lab04.md
		└── src
		    ├── main.c
		    └── main.c.dump

20. Я створив файл main.c, зайшов в ньго командою `vim src/main.c` та написав такий код:

		/*
		 * Сalculate some value depending on user command.
		 * Formula of circumference: 2 * PI * radius
		 * Formula of square: PI * radius * radius
		 * Formula of volume: (4/3) * PI * radius * radius * radius
		 *
		 * input data:
		 *      - PI, constant
		 *      - radius, unsigned float
		 *      - command, char
		 *
		 * output data:
		 *      result =
		 *              - if command was 'l': calculate circumference, unsigned float
		 *              - if command was 's': calculate square, unsigned float
		 *              - if command was 'v': calculate volume, unsigned float
		 */

		#include <stdio.h>
		int main()
		{
		// input data
		#define PI 3.14f // число пі
			float radius; // радіус з плаваючою комою
			char command = ' '; // команда яку введе користувач
			// output data
			float result; // результат виконання якоїсь команди

			while (command != 'q') { // поки command не дорівнюе 'q' виконуемо цей кусок кода
				printf("\nEnter the radius of circle/sphere: ");
				scanf("%f", &radius);
				printf("Enter what to do with this radius ('l' - lenght of a circumference, 's' - square of a circle, 'v' - volume of a sphere, 'q' - quit): ");
				scanf("%s", &command);

				switch (command) { // оператор switch case щоб не мусорити іфами
				case 'l': // if (command == 'l')
					result = 2 * PI * radius;
					printf("Circumference equals %f\n", result);
					break;
				case 's': // if (command == 's')
					result = PI * radius * radius;
					printf("Square equals %f\n", result);
					break;
				case 'v': // if (command == 'v')
					result = 4 / 3 * PI * radius * radius * radius;
					printf("Volume equals %f\n", result);
					break;
				default: // else
					break;
				}
			}

			return 0;
		}

* Вийшов з файлу та запустив программу командою `make run`, ввів радіус:

		rm -rf dist
		mkdir dist
		clang -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla  src/main.c -o ./dist/main.bin
		./dist/main.bin

		Enter the radius of circle/sphere: 2.56

* Вввв команду `l` - довжина кола:

		Enter what to do with this radius ('l' - lenght of a circumference, 's' - square of a circle, 'v' - volume of a sphere, 'q' - quit): l

* Мені видало:

		Circumference equals 16.076786

		Enter the radius of circle/sphere:

* Провірив на калькуляторі і все зійшлось, далі провірив команду `s`:

		Enter the radius of circle/sphere: 2.56
		Enter what to do with this radius ('l' - lenght of a circumference, 's' - square of a circle, 'v' - volume of a sphere, 'q' - quit): s
		Square equals 20.578266

* Команду `v`:

		Enter the radius of circle/sphere: 2.56
		Enter what to do with this radius ('l' - lenght of a circumference, 's' - square of a circle, 'v' - volume of a sphere, 'q' - quit): v
		Volume equals 52.680309

* Але 4 / 3 * 3.14 * 2.56^3 дорівнюе 70,2406, а не 52.680309, десь mistake

* Зкомпілював командою `make all` та зайшов в відлагодник командою 'lldb dist/main.bin', поставив брейкпоїнт на 46 рядку командою `b 46` та запустив командою `run`:

		Process 556 launched: '/home/fomgleb/programing-fomenko/lab04/dist/main.bin' (x86_64)

		Enter the radius of circle/sphere: 2.56
		Enter what to do with this radius ('l' - lenght of a circumference, 's' - square of a circle, 'v' - volume of a sphere, 'q' - quit): v
		Process 556 stopped
		* thread #1, name = 'main.bin', stop reason = breakpoint 1.1
		    frame #0: 0x000000000040126b main.bin`main at main.c:46:33
		   43                           break;
		   44                   case 'v': // if (command == 'v')
		   45                           result = 4 / 3 * PI * radius * radius * radius;
		-> 46                           printf("Volume equals %f\n", result);
		   47                           break;
		   48                   default: // else
		   49                           break;
		(lldb)

* Ввів `p result`:

		(float) $1 = 52.6803093

* Трохи подумав і ввів `p 4 / 3`:

		(int) $2 = 1

* Все зрозуміло, щоб вирішити цю проблему мені треба щоб або 4 або 3 була float:

		(lldb) p 4.0f / 3
		(float) $4 = 1.33333337

* Тепер все буде добре. Виправив з `4 / 3` на `(float)4 / 3`

* Запустив командою `make run` та перевірив все в калькуляторі.

* Зкомпілював і все.

Висновок: Я навчився працювати з printf та scanf, а все інше я і до цього знав
