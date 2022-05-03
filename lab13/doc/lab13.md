# Лабораторна робота №13. Взаємодія з файлами

## 1 Вимоги

### 1.1 Розробник

* Фоменко Гліб Володимирович;
* студент групи КН-921Г;
* 02.05.2022.

### 1.2 Загальне завдання

Зробити програму взаємодіюци з файлами.

### 1.3 Індивідуальне завдання

(4) Дано файл, що містить інформацію про матрицю. Визначити максимальний елемент.

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для визначення максимального елементу матриці;
Демонстрація знайдених результатів передбачає покрокове виконання програми в режимі налагодження, виведення на єкран командною строкою та переглядання файлу output.txt.

### 2.2 Опис логічної структури

Програма зчитує файл з даними про матриці та визначає найбільший елемент перебераючі кожен  елемент матриці.

#### Функція визначення максимального елементу матриці

```c
    double get_max_matrix_element(double *const *const matrix, size_t matrix_height, size_t matrix_width)
```

*Призначення*: визначення максимального елементу матриці;

*Опис роботи*: перебирає кожен елемент матриці та зрівнює визначаючи максимальний.

#### Функція запису даних в файл

```c
	bool write_to_file(const char path_to_file[], const char writing_data[])
```

*Призначення*: запис даних (масиву символів) в файл;

*Опис роботи*: відкриває файл та записує дані функцією fprintf.

#### Основна функція

```c
	int main()
```

*Призначення*: головна функція;

*Опис роботи*: 
	- виведення інформації з файлу про лабораторну та виконавця;
	- введення даних про матрицю із файлу;
	- функцією get_max_matrix_element визначаю максимальний елемент матриці;
	- виведення максимального елемента матрці;
	- запис максимального елементу матриці в файл;
	- визволення пам'яті.

#### Структура проекту

```
	lab13
	├── Doxyfile
	├── Makefile
	├── README.md
	├── assets
	│   ├── input.txt
	│   └── input_matrix.txt
	├── doc
	│   └── lab13.md
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
/home/fomgleb/programing-fomenko/lab13/src/lib.c          24                 2    91.67%           3                 0   100.00%          53                 4    92.45%
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                                                     24                 2    91.67%           3                 0   100.00%          53                 4    92.45%
```

#### Зчитування даних про матрицю з файлу

```c
FILE *input_matrix_file = NULL;
double **matrix;
size_t matrix_width = 0;
size_t matrix_height = 0;
input_matrix_file = fopen(PATH_TO_INPUT_MATRIX_FILE, "r");
if (input_matrix_file == NULL) {
	printf("\n\n## Failed to open \"%s\" ##\n\n", PATH_TO_INPUT_MATRIX_FILE);
}
fscanf(input_matrix_file, "%zu %zu", &matrix_width, &matrix_height);
matrix = malloc(matrix_height * sizeof(double *));
for (size_t y = 0; y < matrix_height; y++) {
	matrix[y] = malloc(matrix_width * sizeof(double));
}
for (size_t y = 0; y < matrix_height; y++) {
	for (size_t x = 0; x < matrix_width; x++) {
		fscanf(input_matrix_file, "%lf", &matrix[y][x]);
	}
}
fclose(input_matrix_file);
```

## 3 Варіанти використання

Для демонстрації результатів задачі використовується:

- покрокове виконання програми в утиліті lldb;
- перегляд виведених даних командній строці;
- перегляд файлу output.txt.

**Варіант з lldb**: послідовність дій для запуску програми у режимі відлагодження:

- ввести дані в файл input_matrix.txt;
- запустити програму у відлагоднику lldb;
- поставити точку зупинки на функції main (рядок, до виконання функції free);
- запустити програму;
- подивитись результати виконання програми, оглядаючи значення змінної max_matrix_element.

```
fomgleb@Dellchik:~/programing-fomenko/lab13$ lldb ./dist/main.bin 
(lldb) target create "./dist/main.bin"
Current executable set to '/home/fomgleb/programing-fomenko/lab13/dist/main.bin' (x86_64).
(lldb) b 93
Breakpoint 1: where = main.bin`main + 992 at main.c:93:7, address = 0x0000000000401840
(lldb) r
Process 9451 launched: '/home/fomgleb/programing-fomenko/lab13/dist/main.bin' (x86_64)

Автор: Фоменко Гліб;
Лабораторна робота №12;
Строки (Null-terminateed C String);

Matrix width: 4
Matrix height: 3
Matrix:
        [82.00  8.32    93.00   0.00    ]
        [100.00 844.21  8.00    123.00  ]
        [8.43   0.43    83.00   546.00  ]
Max matrix element: 844.21
Process 9451 stopped
* thread #1, name = 'main.bin', stop reason = breakpoint 1.1
    frame #0: 0x0000000000401840 main.bin`main at main.c:93:7
   90           write_to_file(PATH_OUTPUT_FILE, writing_data);
   91  
   92           // Data releasing
-> 93           free(laboratory_data);
   94           for (size_t y = 0; y < matrix_height; y++) {
   95                   free(matrix[y]);
   96           }
(lldb) p max_matrix_element 
(double) $0 = 844.21000000000004
```

**Варіант із виведенням в командну строку**

- ввести дані в файл input_matrix.txt;
- запустити програму;
- подивитись результат виконання.

```
fomgleb@Dellchik:~/programing-fomenko/lab13$ ./dist/main.bin

Автор: Фоменко Гліб;
Лабораторна робота №12;
Строки (Null-terminateed C String);

Matrix width: 4
Matrix height: 3
Matrix:
        [82.00  8.32    93.00   0.00    ]
        [100.00 844.21  8.00    123.00  ]
        [8.43   0.43    83.00   546.00  ]
Max matrix element: 844.21
```

**Варіант із переглядом файлу output.txt**

- ввести дані в файл input_matrix.txt;
- запустити програму;
- переглянути файл output.txt.

```
844.21
```

## Висновки

При виконанні даної лабораторної роботи було набуто навичок роботи з файлами.