/*
 * Calculate some value depending on user command.
 * Formula of circumference: 2 * PI * radius
 * Formula of square: PI * radius * radius
 * Formula of volume: (4/3) * PI * radius * radius * radius
 *
 * input data:
 * 	- PI, constant
 * 	- radius, unsigned float
 * 	- command, char
 *
 * output data:
 * 	result =
 *		- if command was 'l': calculate circumference, unsigned float
 *		- if command was 's': calculate square, unsigned float
 *		- if command was 'v': calculate volume, unsigned float
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
			result = (float)4 / 3 * PI * radius * radius * radius;
			printf("Volume equals %f\n", result);
			break;
		default: // else
			break;
		}
	}

	return 0;
}
