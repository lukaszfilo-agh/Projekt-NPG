#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <iostream>
#include <unistd.h>
#include <windows.h>
#include <sstream>
#include <conio.h>
#include "snake.hpp"
#include "food.hpp"


std::string znaki();

std::string w_nazwa_weza();

std::string w_kolor_weza();

void wait();

int w_poziom_trudnosci();

void menu_display();

void clear_console();

void exit_game();

//void err_check(std::function<std::string ()> func);

#endif
