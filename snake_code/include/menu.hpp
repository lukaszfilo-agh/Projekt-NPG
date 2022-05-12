#ifndef SNAKE_MENU_HPP
#define SNAKE_MENU_HPP

#include <iostream>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#include <functional>

class Menu_Data {
public:
    Menu_Data(std::string str = "", int number = 0) : str_(str), int_(number) {};
    std::string get_str() { return str_;}
    int get_int() { return int_;}
    void set_str(std:: string str) { str_ = str;}
    void set_int(int number) {int_ = number;}
private:
    std::string str_;
    int int_;
};

void signs();

std::string select_snake_name();

std::string select_snake_color();

std::string select_background_color();

std::string select_difficulty_level();

void menu_wait();

void menu_display();

void clear_console();

void exit_game();

//void err_check(std::function<void (std::string)> func);

#endif //SNAKE_MENU_HPP
