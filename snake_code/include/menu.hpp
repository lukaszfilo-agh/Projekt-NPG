#ifndef SNAKE_MENU_HPP
#define SNAKE_MENU_HPP

#include <iostream>
#include "universal.hpp"

class MenuData {          // klasa obslugujaca wszystkie dane pobierane w menu (calkowicie przerobiona)
public:
    MenuData(const int diff_level = 1, const std::string &snake_name = "snake",
             const int &snake_color = 1, const int &background_color = 1, const int &size_x = 10, const int &size_y = 10, const int &board = 1)
            : diff_level_(diff_level), snake_name_(snake_name), snake_color_(snake_color),
              background_color_(background_color), size_x_(size_x), size_y_(size_y), board_(board) {}; // konstruktor domyslny

    int get_diff_level() const { return diff_level_; }

    std::string get_snake_name() const { return snake_name_; }              // gettery

    int get_snake_color() const { return snake_color_; }

    int get_background_color() const { return background_color_; }

    int get_size_x () const { return size_x_;}

    int get_size_y () const { return size_y_;}

    int get_board() const { return board_;}

    void set_diff_level() { diff_level_ = read<int>(); }

    void set_snake_name() { snake_name_ = read<std::string>(); }               // settery

    void set_snake_color() { snake_color_ = read<int>(); }

    void set_background_color() { background_color_ = read<int>(); }

    void set_board() { board_ = read<int>(); }

    void set_size_x() { size_x_ = read<int>(); }

    void set_size_y() { size_y_ = read<int>();}

private:
    int diff_level_;
    std::string snake_name_;
    int snake_color_;
    int background_color_;
    int size_x_;
    int size_y_;
    int board_;

};

// PONIZEJ FUNKCJE TYPOWO DO OBSLUGI MENU W KOLEJNOSCI UZYCIA

void welcome_message();

void menu(MenuData menuData);                                            // calosciowa obsluga menu

void menu_display();                                                     // wyswietlanie opcji w menu

void select_difficulty_level(MenuData &menuData);                        // wybor poziomu trudnosci

void select_snake_name(MenuData &menuData);                              // wybor nazwy weza

void select_snake_color(MenuData &menuData);                             // wybor koloru weza

void select_background_color(MenuData &menuData);                        // wybor koloru tla

void select_size(MenuData & menuData);                                   // rozmiar planszy

void select_board(MenuData &menuData);                                   // wybor planszy

void exit_game();                                                        // wyjscie z menu

#endif //SNAKE_MENU_HPP
