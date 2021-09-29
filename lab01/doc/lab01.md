Лабораторна робота №1. Вступ до програмування. Освоєння командної строки Linux

Виконав Фоменко Гліб Володимирович КІТ 121Г

Хід роботи:

1. Встановив Windows Subsystem for Linux виконуючи інструкцію Manual Installation Steps: https://docs.microsoft.com/en-us/windows/wsl/install-win10

2. Виконав команди: 
sudo apt-get update
sudo apt-get upgrade
sudo reboot;

3. Інсталював мінімально-необхідні пакети (програмні додатки): git, gcc, clang, clang-format, clang-tidy, tree, make, cppcheck використовуючи команду sudo apt-get install <назва додатку>

4. Виконав клонування репозиторію командою: git clone https://github.com/davydov-vyacheslav/sample_project

5. Виконав команду tree і побачив дерево файлів:
.
├── README.md
├── lab00
│   ├── Doxyfile
│   ├── Makefile
│   ├── README.md
│   ├── doc
│   │   ├── assets
│   │   │   ├── algorithm-generateAnimal.png
│   │   │   ├── algorithm-main.png
│   │   │   ├── algorithm-showAnimals.png
│   │   │   ├── animal-fields.png
│   │   │   └── lab00.drawio
│   │   ├── lab00.docx
│   │   ├── lab00.md
│   │   └── lab00.pdf
│   ├── src
│   │   ├── lib.c
│   │   ├── lib.h
│   │   └── main.c
│   └── test
│       └── test.c
└── lab03-sample
    └── doc
        └── lab03.txt

7 directories, 17 files

6. Перейшов до каталогу де знаходиться Makefile
Перевірив наявність файлу Makefile за допомогою команди ls Makefile. Мені видало Makefile - це значить що такий файл існує
Виконав команду: make clean prep compile check. Вдосконалився що помилок немає
Виконав команду tree та знайшов створені файли:
.
├── README.md
├── lab00
│   ├── Doxyfile
│   ├── Makefile
│   ├── README.md
│   ├── dist						+
│   │   ├── main.bin					+
│   │   └── test.bin					+
│   ├── doc
│   │   ├── assets
│   │   │   ├── algorithm-generateAnimal.png
│   │   │   ├── algorithm-main.png
│   │   │   ├── algorithm-showAnimals.png
│   │   │   ├── animal-fields.png
│   │   │   └── lab00.drawio
│   │   ├── lab00.docx
│   │   ├── lab00.md
│   │   └── lab00.pdf
│   ├── src
│   │   ├── lib.c
│   │   ├── lib.c.dump				+
│   │   ├── lib.h
│   │   ├── main.c
│   │   └── main.c.dump				+
│   └── test
│       ├── test.c
│       └── test.c.dump				+
└── lab03-sample
    └── doc
        └── lab03.txt

8 directories, 22 files

7. Виконав зміни в lib.c:
case PIG:
                result = "Свиня";
                break;
+       	case COCKROACH:
+               result = "Общажный таракан";
+               break;
        	default:
                result = "N/A";
        }

	Зміни в lib.h:
 /**
  * Кількість тварин у масиві
  */
-#define ANIMAL_COUNT 10
+#define ANIMAL_COUNT 15

enum animal_type {
        COW, /**< Корова */
        DOG, /**< Собака */
        CAT, /**< Кіт */
+       COCKROACH, /**< Таракан */
        ANIMAL_TYPE_COUNT /**< Кількість тварин */
 };


8. Перекомпілював проект та непобачив помилок
	Console output до змін у коді:
		Інформація про тварину №01: Свиня: зріст = 121 см, маса = 74 гр.
Інформація про тварину №02: Корова: зріст = 126 см, маса = 115 гр.
Інформація про тварину №03: Корова: зріст = 124 см, маса = 7 гр.
Інформація про тварину №04: Кіт: зріст = 72 см, маса = 45 гр.
Інформація про тварину №05: Свиня: зріст = 78 см, маса = 82 гр.
Інформація про тварину №06: Собака: зріст = 19 см, маса = 111 гр.
Інформація про тварину №07: Собака: зріст = 16 см, маса = 0 гр.
Інформація про тварину №08: Свиня: зріст = 51 см, маса = 62 гр.
Інформація про тварину №09: Собака: зріст = 25 см, маса = 81 гр.
Інформація про тварину №10: Корова: зріст = 35 см, маса = 70 гр.

	Console output після змін у коді:
		Інформація про тварину №01: Кіт: зріст = 104 см, маса = 86 гр.
Інформація про тварину №02: Свиня: зріст = 28 см, маса = 66 гр.
Інформація про тварину №03: Свиня: зріст = 84 см, маса = 34 гр.
Інформація про тварину №04: Общажный таракан: зріст = 4 см, маса = 118 гр.
Інформація про тварину №05: Собака: зріст = 36 см, маса = 48 гр.
Інформація про тварину №06: Корова: зріст = 102 см, маса = 32 гр.
Інформація про тварину №07: Собака: зріст = 123 см, маса = 93 гр.
Інформація про тварину №08: Свиня: зріст = 22 см, маса = 64 гр.
Інформація про тварину №09: Общажный таракан: зріст = 5 см, маса = 91 гр.
Інформація про тварину №10: Корова: зріст = 9 см, маса = 87 гр.
Інформація про тварину №11: Корова: зріст = 99 см, маса = 65 гр.
Інформація про тварину №12: Корова: зріст = 98 см, маса = 85 гр.
Інформація про тварину №13: Корова: зріст = 73 см, маса = 34 гр.
Інформація про тварину №14: Корова: зріст = 44 см, маса = 38 гр.
Інформація про тварину №15: Общажный таракан: зріст = 102 см, маса = 74 гр.

9. Виконав зміни в Makefile:

	-compile: main.bin test.bin
+compile: main.bin

+all: clean prep compile check

10. Виконав команду: clang --version та дізнався версію clang: 12.0.0-3ubuntu1~21.04.1

	Виконав команду: make --version та дізнався версію make: 4.3

11. Команду “man” використовують для виводу довідкової інформації для будь-якої команди. Синтаксис: man <command_name>. Для того щоб використати пошук, слід натиснути “/”, написати строку пошуку та натиснути enter. Щоб переміститися до наступного збігу треба натиснути “n”, а до попереднього - Shift + “n”. Для зворотного пошуку - замість “/” потрібно ввести “?”. Клавішу “Q” - для вихіду. Клавішу “H’ - для отримання допомоги.

12. Виконав команду git diff та отримав такий результат:
	diff --git a/lab00/Makefile b/lab00/Makefile
index 088755f..65beac6 100644
--- a/lab00/Makefile
+++ b/lab00/Makefile
@@ -6,7 +6,7 @@ clean:
        rm -rf dist
 prep:
        mkdir dist
-compile: main.bin test.bin
+compile: main.bin

 main.bin: src/main.c
        $(CC) $(C_OPTS) $< -o ./dist/$@
@@ -22,4 +22,6 @@ check:
        clang-format --verbose -dry-run --Werror src/* test/*
        cppcheck --enable=all --inconclusive --addon=cert --error-exitcode=1  -v --suppress=unreadVariable:*/main.c --suppress=knownConditionTrueFalse:*/main.c --suppress=missingIncludeSystem  --check-config --suppress=*:*/test.c  --suppress=unmatchedSuppression:*/main.c .

+all: clean prep compile check
+
 # TODO: clang-tidy; scan-build
diff --git a/lab00/src/lib.c b/lab00/src/lib.c
index f7f86e0..6af6cce 100644
--- a/lab00/src/lib.c
+++ b/lab00/src/lib.c
@@ -25,6 +25,9 @@ const char *get_animal_type_name(enum animal_type type)
        case PIG:
                result = "Свиня";
                break;
+       case COCKROACH:
+               result = "Общажный таракан";
+               break;
        default:
                result = "N/A";
        }
diff --git a/lab00/src/lib.h b/lab00/src/lib.h
index 0fe857b..d3a3cd3 100644
--- a/lab00/src/lib.h
+++ b/lab00/src/lib.h
@@ -19,7 +19,7 @@
 /**
  * Кількість тварин у масиві
  */
-#define ANIMAL_COUNT 10
+#define ANIMAL_COUNT 15

 /**
  * Тип тварини
@@ -29,6 +29,7 @@ enum animal_type {
        COW, /**< Корова */
        DOG, /**< Собака */
        CAT, /**< Кіт */
+       COCKROACH, /**< Таракан */
        ANIMAL_TYPE_COUNT /**< Кількість тварин */
 };

Висновок: я навчився користуватися строкою Linux, пересуватися по діректоріям, компілювати проект. Трохи навчися (щоб не викидало помилки) редагувати Makefile та c1 файли проекту. Навчився клонувати репозиторій на комп’ютер та виводити на консоль зміни які я виконав в файлах. Дослідив роботу команди man, та дізнався що man це скорочення від manual, тобто - посібник.
