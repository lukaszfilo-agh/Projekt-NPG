#ifndef SNAKE_MENU_HPP
#define SNAKE_MENU_HPP
#include <iostream>
//void err_check(std::function<void (std::string)> func);  // DO ZROBIENIA

class MenuData {          // klasa obslugujaca wszystkie dane pobierane w menu (calkowicie przerobiona)
public:
    MenuData(const int diff_level = 1, const std::string &snake_name = "snake",
             const std::string &snake_color = "zielony", const std::string &background_color = "bialy")
            : diff_level_(diff_level), snake_name_(snake_name), snake_color_(snake_color),
              background_color_(background_color) {}; // konstruktor domyslny

    int get_diff_level() const { return diff_level_; }

    std::string get_snake_name() const { return snake_name_; }              // gettery

    std::string get_snake_color() const { return snake_color_; }

    std::string get_background_color() const { return background_color_; }

    void set_diff_level() { std::cin >> diff_level_; }

    void set_snake_name() { std::cin >> snake_name_; }               // settery

    void set_snake_color() { std::cin >> snake_color_; }

    void set_background_color() { std::cin >> background_color_; }

private:
    int diff_level_;
    std::string snake_name_;
    std::string snake_color_;
    std::string background_color_;
};

// PONIZEJ FUNKCJE TYPOWO DO OBSLUGI MENU W KOLEJNOSCI UZYCIA

void whole_menu();                                                       // calosciowa obsluga menu

void menu_display();                                                     // wyswietlanie opcji w menu

void select_difficulty_level(MenuData &menuData);                        // wybor poziomu trudnosci

void select_snake_name(MenuData &menuData);                              // wybor nazwy weza

void select_snake_color(MenuData &menuData);                             // wybor koloru weza

void select_background_color(MenuData &menuData);                        // wybor koloru tla

void exit_game();                                                        // wyjscie z menu

#endif //SNAKE_MENU_HPP
