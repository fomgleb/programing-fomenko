/**
 * @file lib.h
 * @brief Файл з описом функцій для отримання частотної таблиці символів у тексті
 *
 * @author fomgleb
 * @date 29.04.2022
 * @version 1.0
*/

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief отримати відсоткове співвідношення
 * 
 * @param input_numbers - масив чисел, в якому буде знайдено відсоткове співвідношення
 * @param input_numbers_length - розмір масиву чисел
 */
float *get_percentage(const size_t *input_numbers, size_t input_numbers_length);

/**
 * @brief отримати кількість кожного повторюваного символа
 * 
 * @param input_text - масив символів, кількість повторюваних символів якого буде розглядатися
 * @param input_text_length - розмір масиву символів
 * @param output_repeating_chars - вихідний масив символів які повторюються, в якому індекс кожного символу відповідає індексу кожньої кількоскі повторюваних символів в вихідному масиві
 * @return масив кількостей символів
 */
size_t *get_repeating_chars_counts(const char input_text[], size_t input_text_length, char output_repeating_chars[]);

/**
 * @brief Отримати перший індекс символа який треба знайти
 * 
 * @param elements - масив елементів, в якому шукати
 * @param elements_length - розмів масиву елементів
 * @param element_to_find - символ який треба знайти
 */
int get_element_index(const char elements[], size_t elements_length, char element_to_find);