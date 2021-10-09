# Лабораторна робота №2. Вступ до програмування. Основи debug процессу #

## Виконав Фоменко Гліб Володимирович КІТ 121Г ##

Хід роботи:
1. У мене вже є аккаунт на github та репозиторій programing-fomenko

2. Я склонував репозиторій programing-fomenko на комп’ютер командою git clone https://github.com/fomgleb/programing-fomenko. В консоль мені видало: “Username for 'https://github.com':”, я ввів своє ім’я. Після цього мені вивело: “Password for 'https://fomgleb@github.com':” і я ввів токен, який я створив на github

3. Так як я вже скопіював файли та директорії з зовнішнього репозиторія, що був наданий викладачем в попередній лабораторній роботі, я створив директорію lab02 та перемістив туди всі файли та папки з директорії lab01 окрім папки doc з фалом lab01.pdf

4. Додав файли до комміту командою: "git add .". Зробив комміт командою: git commit -m "Initial copy of sample_project" -a

5. Я вже зробив зміни в попередній лабораторній роботі. Output програми:

        Інформація про тварину №01: Кіт: зріст = 101 см, маса = 109 гр.
        Інформація про тварину №02: Свиня: зріст = 34 см, маса = 116 гр.
        Інформація про тварину №03: Свиня: зріст = 15 см, маса = 80 гр.
        Інформація про тварину №04: Собака: зріст = 60 см, маса = 62 гр.
        Інформація про тварину №05: Свиня: зріст = 115 см, маса = 62 гр.
        Інформація про тварину №06: Свиня: зріст = 110 см, маса = 64 гр.
        Інформація про тварину №07: Собака: зріст = 25 см, маса = 9 гр.
        Інформація про тварину №08: Собака: зріст = 44 см, маса = 21 гр.
        Інформація про тварину №09: Общажный таракан: зріст = 79 см, маса = 30 гр.
        Інформація про тварину №10: Общажный таракан: зріст = 18 см, маса = 28 гр.
        Інформація про тварину №11: Общажный таракан: зріст = 4 см, маса = 2 гр.
        Інформація про тварину №12: Кіт: зріст = 62 см, маса = 29 гр.
        Інформація про тварину №13: Кіт: зріст = 63 см, маса = 44 гр.
        Інформація про тварину №14: Собака: зріст = 9 см, маса = 96 гр.
        Інформація про тварину №15: Свиня: зріст = 4 см, маса = 84 гр.
Я додав Общажного таракана до списку, це звісно не людина, як написано в Лабораторному практикумі, але підійде.

6. Я ввів команду: `lldb lab02/dist/main.bin`. Мені видало:

        Current executable set to '/home/fomgleb/programing-fomenko/lab02/dist/main.bin' (x86_64).

* Далі я ввів команду: `l 1` щоб подивитись де ставити брейкпоїнт

* Я поставив брейкпоїнт на 40 рядку командою: `b 40`

* Ввів: `r` щоб запустити дебагер і побачив наступне:

        Process 116 launched: '/home/fomgleb/programing-fomenko/lab02/dist/main.bin' (x86_64)
        Process 116 stopped
        * thread #1, name = 'main.bin', stop reason = breakpoint 1.1
            frame #0: 0x0000000000401316 main.bin`main at main.c:40:22
           37    */
           38   int main()
           39   {
        -> 40           srand((unsigned int)time(0));
           41           struct animal animals[ANIMAL_COUNT];
           42
           43           for (unsigned int i = 0; i < ANIMAL_COUNT; i++) {

* Ввів команду: "n", мене перемістило на 43 рядок:

        Process 116 stopped
        * thread #1, name = 'main.bin', stop reason = step over
            frame #0: 0x0000000000401322 main.bin`main at main.c:43:20
           40           srand((unsigned int)time(0));
           41           struct animal animals[ANIMAL_COUNT];
           42
        -> 43           for (unsigned int i = 0; i < ANIMAL_COUNT; i++) {
           44                   generate_animal(&animals[i]);
           45           }
           46           show_animals(animals, ANIMAL_COUNT);

* Ввів команду: "print animals" і мені видало:

        (animal [15]) $1 = {
          [0] = (type = PIG, height = 0, weight = 256)
          [1] = (type = PIG, height = 0, weight = 0)
          [2] = (type = PIG, height = 0, weight = 0)
          [3] = (type = PIG, height = 0, weight = 0)
          [4] = (type = PIG, height = 0, weight = 0)
          [5] = (type = PIG, height = 0, weight = 0)
          [6] = (type = PIG, height = 0, weight = 0)
          [7] = (type = PIG, height = 0, weight = 0)
          [8] = (type = 0x400040, height = 0, weight = 15775231)
          [9] = (type = PIG, height = 194, weight = 0)
          [10] = (type = CAT | COCKROACH | 0xffffe200, height = 32767, weight = 4294959622)
          [11] = (type = CAT | COCKROACH | 0x7ff8, height = 4199389, weight = 0)
          [12] = (type = 0xf7fbdfc8, height = 32767, weight = 4199312)
          [13] = (type = PIG, height = 0, weight = 0)
          [14] = (type = 0x401070, height = 0, weight = 4294959888)
        }
Щось незрозуміле, я думав тут повинно буди пусто

* Поставив брейкпоїнт на 46 рядок (щоб пропустити виконання циклу) командою: "b 46" і мені вивело:

        Breakpoint 2: where = main.bin`main + 117 at main.c:46:2, address = 0x0000000000401375

* Ввів команду: "c" щоб продовжити виконання программи:

        Process 116 resuming
        Process 116 stopped
        * thread #1, name = 'main.bin', stop reason = breakpoint 2.1
            frame #0: 0x0000000000401375 main.bin`main at main.c:46:2
           43           for (unsigned int i = 0; i < ANIMAL_COUNT; i++) {
           44                   generate_animal(&animals[i]);
           45           }
        -> 46           show_animals(animals, ANIMAL_COUNT);
           47
           48           return 0;
           49   }

* Ввів команду: "p animals" і отримав:

        (animal [15]) $0 = {
          [0] = (type = DOG, height = 79, weight = 98)
          [1] = (type = PIG, height = 18, weight = 39)
          [2] = (type = DOG, height = 23, weight = 29)
          [3] = (type = COCKROACH, height = 68, weight = 25)
          [4] = (type = DOG, height = 39, weight = 75)
          [5] = (type = DOG, height = 12, weight = 107)
          [6] = (type = DOG, height = 95, weight = 54)
          [7] = (type = COW, height = 38, weight = 55)
          [8] = (type = COW, height = 96, weight = 44)
          [9] = (type = COCKROACH, height = 68, weight = 4)
          [10] = (type = COW, height = 13, weight = 76)
          [11] = (type = DOG, height = 112, weight = 94)
          [12] = (type = PIG, height = 26, weight = 109)
          [13] = (type = COW, height = 114, weight = 42)
          [14] = (type = PIG, height = 109, weight = 82)
        }
* Тепер тут массив тварин, який заповнився циклом:

       43           for (unsigned int i = 0; i < ANIMAL_COUNT; i++) {
       44                   generate_animal(&animals[i]);
       45           }

* Щоб зробити крок із заходом до інших процедур треба використовувати команду: `step` или `s`. Крок без заходу: `next` или `n`. Щоб дойти до певного рядка, треба ввести команду: `thread until <номер рядку>`.

7. Завантажив репозиторій на github командою: `git push`.

Структура мого проекту на поточний час:

    ang-format
    ├── .clang-tidy
    ├── .git
    │   ├── HEAD
    │   ├── branches
    │   ├── config
    │   ├── description
    │   ├── hooks
    │   │   ├── applypatch-msg.sample
    │   │   ├── commit-msg.sample
    │   │   ├── fsmonitor-watchman.sample
    │   │   ├── post-update.sample
    │   │   ├── pre-applypatch.sample
    │   │   ├── pre-commit.sample
    │   │   ├── pre-merge-commit.sample
    │   │   ├── pre-push.sample
    │   │   ├── pre-rebase.sample
    │   │   ├── pre-receive.sample
    │   │   ├── prepare-commit-msg.sample
    │   │   └── update.sample
    │   ├── index
    │   ├── info
    │   │   └── exclude
    │   ├── logs
    │   │   ├── HEAD
    │   │   └── refs
    │   │       ├── heads
    │   │       │   └── master
    │   │       └── remotes
    │   │           └── origin
    │   │               └── HEAD
    │   ├── objects
    │   │   ├── info
    │   │   └── pack
    │   │       ├── pack-62ecafa38117dfb5866a1214a9313eae4a83916e.idx
    │   │       └── pack-62ecafa38117dfb5866a1214a9313eae4a83916e.pack
    │   ├── packed-refs
    │   └── refs
    │       ├── heads
    │       │   └── master
    │       ├── remotes
    │       │   └── origin
    │       │       └── HEAD
    │       └── tags
    ├── .gitignore
    ├── .gitlab-ci.yml
    ├── README.md
    ├── lab01
    │   ├── README.md
    │   └── doc
    │       └── lab01.pdf
    └── lab02
        ├── Doxyfile
        ├── Makefile
        ├── src
        │   ├── lib.c
        │   ├── lib.c.dump
        │   ├── lib.h
        │   ├── main.c
        │   └── main.c.dump
        └── test
            ├── test.c
            └── test.c.dump

8. Відкрив Makefile використовуючи vim та прибрав параметр -g в рядку: C_OPTS = -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)
Далі я зкомпілював програму та запустив в відлагоднику. Різниця:
З режимом компіляції без інформації про відлагодження я не можу поставити брейкпоїнт та продивитись код командою list, тому дебаггер втрачає сенс.

Висновок: я навчився працювати з lldb дебаггером. Навчився прибирати інформацію про відлагодження для Makefile. Зрозумів як працювати з git add, git commit та git push.
