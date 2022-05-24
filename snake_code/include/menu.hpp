#ifndef SNAKE_MENU_HPP
#define SNAKE_MENU_HPP

#include <iostream>
#include <map>
#include "universal.hpp"

class MenuData {          // klasa obslugujaca wszystkie dane pobierane w menu (calkowicie przerobiona)
public:
    MenuData(const std::string &snake_name = "snake", const int diff = 1,
             const int &snake_color = 1, const int &background_color = 1, const int &size_x = 50,
             const int &size_y = 25, const int &board = 1, const int &score = 0)
            : snake_name_(snake_name), diff_(diff), snake_color_(snake_color),
              background_color_(background_color), size_x_(size_x), size_y_(size_y),
              board_(board), score_(score){}; // konstruktor domyslny

    // gettery
    std::string get_snake_name() const { return snake_name_; }

    int get_diff() const { return diff_; }

    std::string get_diff_map(int index) const { return diff_map_.at(index); };

    int get_snake_color() const { return snake_color_; }

    std::string get_snake_color_map(int index) const { return snake_colors_.at(index); };

    int get_background_color() const { return background_color_; }

    std::string get_background_color_map(int index) const { return background_colors_.at(index); }

    int get_size_x() const { return size_x_; }

    int get_size_y() const { return size_y_; }

    int get_board() const { return board_; }

    std::string get_board_chars(int index) const { return board_chars_.at(index); }

    int get_score() const { return score_; }

    // settery

    void set_diff() { diff_ = read<int>(); }

    void set_snake_name() { snake_name_ = read<std::string>(); }

    void set_snake_color() { snake_color_ = read<int>(); }

    void set_background_color() { background_color_ = read<int>(); }

    void set_board() { board_ = read<int>(); }

    void set_size_x() { size_x_ = read<int>(); }

    void set_size_y() { size_y_ = read<int>(); }

    void score_add() { score_ += 10;}

    //wypisywanie map

    void print_score() const { std::cout << "WYNIK: " << score_ << std::endl;}

    void print_background_diff_map();

    void print_snake_color_map();

    void print_background_color_map();

    void print_board_chars_map();

    void print_menu_text();

private:
    std::string snake_name_;
    int diff_;
    int snake_color_;
    int background_color_;
    int size_x_;
    int size_y_;
    int board_;
    int score_;
    const static std::map<int, std::string> diff_map_;
    const static std::map<int, std::string> snake_colors_;
    const static std::map<int, std::string> background_colors_;
    const static std::map<int, std::string> board_chars_;
    const static std::map<int, std::string> menu_text_;

};

// PONIZEJ FUNKCJE TYPOWO DO OBSLUGI MENU W KOLEJNOSCI UZYCIA

void welcome_message();

void menu(MenuData &menuData);                                            // calosciowa obsluga menu

void menu_display(MenuData &menuData);                                   // wyswietlanie opcji w menu

void select_difficulty_level(MenuData &menuData);                        // wybor poziomu trudnosci

void select_snake_name(MenuData &menuData);                              // wybor nazwy weza

void select_snake_color(MenuData &menuData);                             // wybor koloru weza

void select_background_color(MenuData &menuData);                        // wybor koloru tla

void select_size(MenuData &menuData);                                   // rozmiar planszy

void select_board(MenuData &menuData);                                   // wybor planszy

void exit_game();                                                        // wyjscie z menu

#endif //SNAKE_MENU_HPP
