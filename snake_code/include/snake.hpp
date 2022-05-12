#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <iostream>
#include <unistd.h>
#include <windows.h>
#include <sstream>
#include <conio.h>
#include <functional>
#include "snake.hpp"
#include "food.hpp"



std::string signs();

std::string select_snake_name();

std::string select_snake_color();

std::string select_background_color();

std::string select_difficulty_level();

void wait(const int i);

void menu_display();

void clear_console();

void exit_game();

void err_check(std::function<void (std::string)> func);

#endif
