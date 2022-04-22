# Лабораторна робота №11. Взаємодія з користувачем шляхом механізму введення/виведення

## 1 Вимоги

### 1.1 Розробник

* Фоменко Гліб Володимирович;
* студент групи КН-921Г;
* 12.01.2022 - 22.04.2022.

### 1.2 Загальне завдання

Розробити програму з використанням механізму введення/виведення.

### 1.3 Індивідуальне завдання

(5) Визначити зворотню матрицю.

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для отримання зворотньої матриці;
Вхідний масив повинен бути long double, як і вихідний;
Результат зберігається у змінній *inverse_matrix*;
Демонстрація знайдених результатів передбачає покрокове виконання програми в режимі налагодження та виведення на єкран командною строкою.

### 2.2 Опис логічної структури

В прогрмі використовується спосіб Жордана-Гаусса, тобто спочатку до матриці дописується одинична матриця, потім, способом елементарних перетворень головна матриця перероблюється в одиничну, а матриця що була дописана спочатку і є зворотня.

#### Функція допису одиничної матриці

```c
    long double **append_identity_matrix(long double **matrix, size_t width_and_height)
```

*Призначення*: допис одиничної матриці до основної.

*Опис роботи*: створює одиничну матрицю, створює пустий масив та записує вхідну матрицю та одиничну матрицю справа в пустий масив.

**Аргументи**

- *matrix* - вхідний масив, справа якого буде дописана одинична матриця;
- *width_and_height* - ширина та висота матриці;

#### Функція брання зворотньої матриці

```c
	long double **get_inverse_matrix(long double **matrix_to_inverse, size_t width_and_height)
```

*Призначення*: знаходження зворотньої матриці.

*Опис роботи*: дописує одиничну матрицю до вхідного масиву та способом елементарних перетворень, перетворює вхідну матрицю в одиничну. Повертається матриця що була дописана до вхідної спочатку.

**Аргументи**:

- *matrix_to_inverse* - матриця, що буде інвертуванися;
- *width_and_height* - ширина та висота матриці.

#### Основна функція

```c
	int main()
```

*Призначення*: головна функція.

*Опис роботи*: 

- виведення інформації з файлу про лабораторну та виконавця;
- введення всіх необхідних даних: ширина та висота матриці, елементи матриці;
- виклик функції `get_inverse_matrix`, передача всіх необхідних аргументів та запис результату функції в новий масив;
- виведення елементив масиву;
- визволення пам'яті.

#### Структура проекту

```
	lab11
	├── Doxyfile
	├── Makefile
	├── README.md
	├── assets
	│   └── input.txt
	├── doc
	│   └── lab11.md
	├── src
	│   ├── lib.c
	│   ├── lib.h
	│   └── main.c
	└── test
		└── test.c
```

### 2.3 Важливі фрагменти програми

#### Покриття тестами

```
Filename                                             Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/home/fomgleb/programing-fomenko/lab11/src/lib.c         115                25    78.26%           7                 1    85.71%         146                30    79.45%
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                                                    115                25    78.26%           7                 1    85.71%         146                30    79.45%
```

#### Функція знаходження зворотньої матриці

```c
	long double **get_inverse_matrix(long double **matrix_to_inverse, size_t width_and_height)
	{
		long double **appended_matrix = append_identity_matrix(matrix_to_inverse, width_and_height);
		size_t width = width_and_height * 2;
		size_t height = width_and_height;
		short sign = 1; // 1 = positive, -1 = negative

		for (size_t diagonal_index = 0; diagonal_index < width_and_height; diagonal_index++) {
			if (appended_matrix[diagonal_index][diagonal_index] == 0) { // Если на текущем элементе диагонали 0
				for (size_t y = diagonal_index + 1; y < height; y++) { // Переставляю строки чтобы на диагонали не было 0
					if (appended_matrix[y][diagonal_index] != 0) {
						swap_lines_in_matrix(appended_matrix[diagonal_index], appended_matrix[y], width);
						sign *= -1;
						break;
					}
				}
				if (appended_matrix[diagonal_index][diagonal_index] == 0) { // Если 0 так и остался, то значит determinant = 0
					for (size_t i = 0; i < height; i++) {
						free(appended_matrix[i]);
					}
					free(appended_matrix);

					return NULL;
				}
			}

			divide_array_by_number(appended_matrix[diagonal_index], appended_matrix[diagonal_index][diagonal_index], width);

			for (size_t y = 0; y < height; y++) {
				if (y != diagonal_index) {
					subtract_one_array_from_another(appended_matrix[diagonal_index], appended_matrix[y][diagonal_index],
									appended_matrix[y], width);
				}
			}
		}

		long double **inverse_matrix = malloc(height * sizeof(long double *));
		for (size_t i = 0; i < height; i++) {
			inverse_matrix[i] = malloc(width / 2 * sizeof(long double));
		}

		for (size_t i = 0; i < height; i++) {
			for (size_t j = 0; j < width / 2; j++) {
				inverse_matrix[i][j] = appended_matrix[i][j + width / 2];
			}
		}

		for (size_t i = 0; i < height; i++) {
			free(appended_matrix[i]);
		}
		free(appended_matrix);

		return inverse_matrix;
}
```

## 3 Варіанти використання

Для демонстрації результатів задачі використовується:

- покрокове виконання програми в утиліті lldb;
- виведення на в командній строці.

**Варіант з lldb**: послідовність дій для запуску програми у режимі відлагодження:

- запустити програму у відлагоднику lldb;
- поставити точку зупинки на функції main (рядок, до виконання функції free);
- запустити програму;
- подивитись результати виконання програми, оглядаючи значення матриці inverse_matrix.

```
* thread #1, name = 'main.bin', stop reason = breakpoint 1.1
    frame #0: 0x0000000000401e84 main.bin`main at main.c:85:14
   82           }
   83  
   84           // Releasing
-> 85           for (size_t i = 0; i < width_and_height; i++) {
   86                   free(matrix_to_inverse[i]);
   87           }
   88           free(matrix_to_inverse);
(lldb) p inverse_matrix[0][0]
(long double) $0 = -2
(lldb) p inverse_matrix[0][1]
(long double) $1 = 1
(lldb) p inverse_matrix[1][0]
(long double) $2 = 1.5
(lldb) p inverse_matrix[1][1]
(long double) $3 = -0.5
```

**Варіант із виведенням в командну строку**

- запустити програму;
- ввести дані;
- подивитись результат виконання.

```
Автор: Фоменко Гліб;
Лабораторна робота N№11;
Взаємодія з користувачем шляхом механізму введення/виведення;

Width and height of the matrix: 2

matrix[0][0] = 1
matrix[0][1] = 2
matrix[1][0] = 3
matrix[1][1] = 4

Вхідна матриця:
[1.000  2.000]
[3.000  4.000]

Зворотня матриця:
[-2.000 1.000]
[1.500  -0.500]
```

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи із механізмом введення/виведення та зчитуванням даних з файлу.