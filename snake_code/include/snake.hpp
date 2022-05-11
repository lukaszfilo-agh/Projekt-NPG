#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <iostream>
#include <unistd.h>
#include "snake.hpp"
#include "food.hpp"


std::string znaki();

std::string w_nazwa_weza();

std::string w_kolor_weza();

void sleep();

int w_poziom_trudnosci();

void menu_display();

//void err_check(std::function<std::string ()> func);

#endif
