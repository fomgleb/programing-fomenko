/**
 * @file lib.h
 * @brief Файл з описом функцій переведення числа в рядок
 *
 * @author fomgleb
 * @date 30-dec-2021
 * @version 2.0
 */

#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Функція переводить число в слова та записує в змінну {@link result}, наприклад:
 * 3925 => three thousand nine hundred and twenty five
 * 
 * @param number число, яке треба перевести в речення, від -9999 до 9999
 * @param result массив, в який буде записаний результат переведення числа в речення
 */
void make_string_from_number(int number, char result[]);

/**
 * @brief Функція бере переданий параметр {@link word}, та знаходить кількість символів без символа '\0'
 * 
 * @param word - массив, у котрого треба знайти реальний розмір
 * @param size - неправдивий розмір слова
 * @return кількість символів в массиві не враховуючи символ '\0'
 */
int get_real_word_size(char word[], int size);

/**
 * @brief Функція додавє в кінець массиву {@link text} - слово {@link word}
 * 
 * @param text - массив, в в кінець якого додається {@link word}
 * @param word - слово, яке додається в кінець массиву {@link text}
 * @param word_size - розмір слова
 * @param inserting_index - індекс массиву {@link text}, з якого буде починатися додавання {@link word}
 * @param add_space_in_the_end - якщо true - в кінець {@link text} буде доданий спейс, та навпаки 
 * @return кількість символів які були додані в массив {@link text} при виконанні функції
 */
int insert_word_in_the_end(char text[], char word[], int word_size, int inserting_index, bool add_space_in_the_end);