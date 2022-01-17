# Лабораторна робота №10. Вступ до показчиків

## 1 Вимоги

### 1.1 Розробник

* Фоменко Гліб Володимирович;
* студент групи КІТ-121Г;
* 12.01.2022.

### 1.2 Загальне завдання

Розробити програму з використанням показчиків.

### 1.3 Індивідуальне завдання

(11) Дано масив з N цілих чисел. Визначити, чи є в масиві елементи, що повторюються;
якщо такі є, то створити масив, в якому вказати, скільки разів які елементи повторюються.
Таким чином, в результуючому масиві кожен непарний елемент - число, що повторюються;
кожен парний елемент - кількість повторювань.

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для отримання інформації про числа які повторюються в масиві.

Масив який буде перевірятись має бути інтовим.

Результат зберігається у змінній *information*.

Демонстрація знайдених результатів передбачає покрокове виконання програми в режимі налагодження.

### 2.2 Опис логічної структури

#### Функція генерації масиву випадкових чисел

```c
    int *get_random_numbers(size_t length, int min_value, int max_value)
```

*Призначення*: генерування масиву випадкових інтових чисел.

*Опис роботи*: динамічно виділяє пам'ять для масиву та заповнює його випадковими числами від min_value до max_value.

**Аргументи**

- *length* - довжина масиву який буде згенерований;
- *min_value* - мінімальне значення елементу масиву; 
- *max_value* - максимальне значення елементу масиу.

#### Функція брання інформації про елементи які повторюються в масиві

```c
	int *get_information_about_repeating_numbers(const int *input_numbers, size_t length)
```

*Призначення*: повернення інформації про повторення чисел в масиві.

*Опис роботи*: функція перевіряє кожен елемент масиву, та повертає масив. Кожен непарний елемент масиву - число яке повторюється,
кожен парний - кількість повторювань. 

**Аргументи**:

- *input_numbers* - масив з якого буде братися інформація;
- *length* - довжина цього масиву з якого буде братися інформація.

#### Основна функція

```c
	int main()
```

*Призначення*: головна функція.

*Опис роботи*: 

- створення масиву з випадковими числами;
- виклик функції `get_information_about_repeating_numbers` та запис інформації в новий масив;
- визволення пам'яті.

#### Структура проекту

```
	lab10
	├── Doxyfile
	├── Makefile
	├── README.md
	├── doc
	│   └── lab10.md
	├── src
	│   ├── lib.c
	│   ├── lib.h
	│   └── main.c
	└── test
		└── test.c
```

### 2.3 Важливі фрагменти програми

#### Покриття тестами

Filename                                             Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/home/fomgleb/programing-fomenko/lab10/src/lib.c          36                 0   100.00%           4                 0   100.00%          72                 0   100.00%
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                                                     36                 0   100.00%           4                 0   100.00%          72                 0   100.00%

#### Функція генерування інформації про елемети які повторюються в масиві

```c
	int *get_information_about_repeating_numbers(const int *numbers, size_t length)
	{
		int *information = malloc(length * sizeof(int)); // виділення пам'яті для результуючого масиву
		size_t length_of_information = 0; // довжина результуючого масиву

		// ця маска потрібна для того щоб бачити, яке число вже було використане
		char *used_numbers_mask = malloc(length * sizeof(char)); // '1' - вже використане число, '0' - ще не використане число
		for (size_t i = 0; i < length; i++) {
			*(used_numbers_mask + i) = '0'; // заповнюю цей масив '0'
		}

		for (size_t i = 0; i < length; i++) {
			// беремо кількість повторювань і-того числа
			size_t current_number_repetition_count = get_count_of_number_repetitions(input_numbers, length, *(input_numbers + i));

			if (*(used_numbers_mask + i) == '1') { // якщо це число вже використовувалось, то пропускаємо його
				continue;
			}

			if (current_number_repetition_count > 1) { // якщо число повторюється більше одного разу, то записуємо в масив це число і його кількість
				length_of_information += 2;

				*(information + length_of_information - 2) = *(numbers + i);
				*(information + length_of_information - 1) = (int)current_number_repetition_count;
			}

			for (size_t j = 0; j < length; j++) { // заповнюємо маску одиничками, там де є це число
				if (*(numbers + j) == *(numbers + i)) {
					*(used_numbers_mask + j) = '1';
				}
			}
		}

		if (length_of_information > 0) {
			information = realloc(information, length_of_information * sizeof(int)); // змінюємо виділену кількість байт в залежності від length_of_information
		} else { // якщо функція не знайшла ніяких повторювань, то первий і другий елемент масиву = 0
			information = realloc(information, 2 * sizeof(int)); 
			*(information) = 0;
			*(information + 1) = 0;
		}

		free(used_numbers_mask);

		return information;
	}
```

## 3 Варіант використання

Для демонстрації результатів задачі використовується:

- покрокове виконання програми в утиліті lldb.

**Єдиний варіант використання**: послідовність дій для запуску програми у режимі відлагодження:

- запустити програму у відлагоднику lldb;
- поставити точку зупинки на функції main (рядок, до виконання функції free);
- запустити програму;
- подивитись результати виконання програми, оглядаючи значення масивів numbers та information.

```
Process 7524 stopped
* thread #1, name = 'main.bin', stop reason = breakpoint 1.1
    frame #0: 0x0000000000401579 main.bin`main at main.c:43:7
   40           int *numbers = get_random_numbers(length, min_value, max_value);
   41           int *information = get_information_about_repeating_numbers(numbers, length);
   42
-> 43           free(numbers);
   44           free(information);
   45
   46           return 0;
(lldb) p numbers[0]
(int) $0 = -10
(lldb) p numbers[1]
(int) $1 = 4
(lldb) p numbers[2]
(int) $2 = 9
(lldb) p numbers[3]
(int) $3 = 3
(lldb) p numbers[4]
(int) $4 = -10
(lldb) p numbers[5]
(int) $5 = -7
(lldb) p numbers[6]
(int) $6 = 4
(lldb) p numbers[7]
(int) $7 = -2
(lldb) p numbers[8]
(int) $8 = 1
(lldb) p numbers[9]
(int) $9 = 1
(lldb) p information[0]
(int) $10 = -10
(lldb) p information[1]
(int) $11 = 2
(lldb) p information[2]
(int) $12 = 4
(lldb) p information[3]
(int) $13 = 2
(lldb) p information[4]
(int) $14 = 1
(lldb) p information[5]
(int) $15 = 2
(lldb) p information[6]
(int) $16 = 0
(lldb) p information[7]
(int) $17 = 0
```

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи із показчиками, передаванням показчиків як аргументів функцій та операціями над показчиками.