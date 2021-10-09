Лабораторна робота №3. Розробка лінійних програм

Виконав Фоменко Гліб Володимирович КІТ 121-Г

Хід роботи
0. Створив папку lab03, скопіював Makefile з другої лабораторної. Взагалом зробив таку структуру:

.
├── Makefile
├── README.md
├── doc
│   └── lab03.md
└── src
    └── main.c

* Змінив Makefile з такого:
	CC = clang
	LAB_OPTS = -I./src src/lib.c
	C_OPTS = -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)

	clean:
        	rm -rf dist
	prep:
        	mkdir dist
	compile: main.bin

	main.bin: src/main.c
	        $(CC) $(C_OPTS) $< -o ./dist/$@
	test.bin: test/test.c
	        $(CC) $(C_OPTS) $< -o ./dist/$@
	test: clean prep compile
	        ./dist/test.bin
	run: clean prep compile
	        ./dist/main.bin
	doxygen:
	        doxygen Doxyfile
	check:
	        clang-format --verbose -dry-run --Werror src/* test/*
	        cppcheck --enable=all --inconclusive --addon=cert --error-exitcode=1  -v --suppress=unreadVariable:*/main.c --suppress=knownConditionTrueFalse:*/main.c --suppress=missingIncludeSystem  --check-config --suppress=*:*/test.c  --suppress=unmatchedSuppression:*/main.c .

	all: clean prep compile check

	# TODO: clang-tidy; scan-build

* на такий:
	CC = clang
	C_OPTS = -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)

	clean:
        	rm -rf dist
	prep:
	        mkdir dist
	compile: main.bin

	main.bin: src/main.c
	        $(CC) $(C_OPTS) $< -o ./dist/$@
	run: clean prep compile
	        ./dist/main.bin
	doxygen:
	        doxygen Doxyfile
	check:
	        clang-format --verbose -dry-run --Werror src/*
	        cppcheck --enable=all --inconclusive --addon=cert --error-exitcode=1  -v --suppress=unreadVariable:*/main.c --suppress=knownConditionTrueFalse:*/main.c --check-config  --suppress=unmatchedSuppression:*/main.c .

	all: clean prep compile check

	# TODO: clang-tidy; scan-build

20. Я створив файл main.c, зайшов в нього командаю "vim src/main.c", та написав такий код:
/*
 * Calculate the sum of numbers in a given range
 *
 * input data:
 *      - firstNumOfRange, int
 *      - lastNumOfRange, int
 *
 * output data:
 *      - sumOfEachNumOfRange, int
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

* Потім я вийшов командою :wq, та скомпілював программу командою "make all", мені видало:
rm -rf dist
mkdir dist
clang -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla  src/main.c -o ./dist/main.bin
clang-format --verbose -dry-run --Werror src/*
Formatting src/main.c
Formatting src/main.c.dump
cppcheck --enable=all --inconclusive --addon=cert --error-exitcode=1  -v --suppress=unreadVariable:*/main.c --suppress=knownConditionTrueFalse:*/main.c --check-config  --suppress=unmatchedSuppression:*/main.c .
Checking src/main.c ...
Defines:
Undefines:
Includes:
Platform:Native

Це значить що все добре, немає ніяких помилок.
* Далі я ввів команду "lldb dist/main.bin" щоб подивитися значення в змінній sumOfEachNumOfRange, мені видало:
(lldb) target create "dist/main.bin"
Current executable set to '/home/fomgleb/programing-fomenko/lab03/dist/main.bin' (x86_64).
(lldb)

* Ввів команди "l 1", щоб подивитися вихідний код і поставив брейкпоїнт на 12 рядку командою "b 12" та запустив программу командою "r", далі ввів "p sumOfEachNumOfRange" і мені видало: (int) $0 = 9. Так, все працює добре, 2 + 3 + 4 = 9, як і видала программма. ізі.

* Вирішив спробувати змінити значенн змінних в відлагоднику. Знову відкрив відлагодник, поставив брейкпоїнт на ініціалізації змінної sumOfEachNumOfRange та запустив программу. Командою "p firstNumOfRange=50", я змінив значення змінної на 50. Аналогічно я зробив для lastNumofRange - змінив на 52. Поставив брейкпоїнт на кінець программи та продовжив її виконання. Далі подивився значення змінної sumOfEachNumOfRange та мені видало:
(int) $2 = 153

Висновок: точка входу в язику с, це main(), вона призначена для того щоб почати виконування программи. В цій лабораторній роботі я узнав як на льоту змінювати значення змінних в дебагеру. А ще зрозумів що цикли такі ж як в С#.
