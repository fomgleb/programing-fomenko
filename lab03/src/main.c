/*
 * Calculate the sum of numbers in a given range
 *
 * input data:
 * 	- firstNumOfRange, int
 * 	- lastNumOfRange, int
 *
 * output data:
 * 	- sumOfEachNumOfRange, int
 *
*/

int main() // Це точка входу
{
	int firstNumOfRange = 2; // Ініціалізую змінну, число від якого буде починатися розрахунок
	int lastNumOfRange = 4; // Ініціалізую змінну, число до якого буде розрахунок
	int sumOfEachNumOfRange = 0; // Ініціалізую змшнну, число, сумма всіх чисел від firstNum до SecondNum

	// В цьому циклу ініціалізується змінна <i>; Цей цикл буде виконуванися доки <i> не буде менше або дорівнювати змінній secondNum; Кожну ітерацію змінна <i> буде збільшуватися на <i>.
	for (int i = firstNumOfRange; i <= lastNumOfRange; i++) {
		sumOfEachNumOfRange += i; // Кожну ітерацію до змінної rangeOfNums буде додаватися <i>
	}

	return 0;
}
