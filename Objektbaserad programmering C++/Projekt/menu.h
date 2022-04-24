#ifndef MENU_H
#define MENU_H

#include <algorithm>
#include <iostream>

void menu();
void welcome_Screen();
bool IsDigits(const std::string &str);
bool is_Odd(const size_t &number);
size_t input_Dim();
size_t input_Positive_Number();
size_t input_Option(size_t, size_t);

#endif