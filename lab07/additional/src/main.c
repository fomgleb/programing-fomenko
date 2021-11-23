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
