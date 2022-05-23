#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <vector>
#include <windows.h>
#include "menu.hpp"

class Snake {
private:
    COORD position_;
    std::vector<COORD> body_;
    int length_;            //dlugosc weza
    int velocity_;          //predkosc przesuwania sie weza, ustalona wedlug poziomu trudnosci
    char direction_;

public:
    Snake(COORD position, const MenuData& menudata);   //konstruktor snakea

    //void snake_move(); //poruszanie snakem

    int get_length() const {return length_;}

    void snake_grow() { length_++; };   //wydluzanie weza

    COORD snake_get_position() const { return position_; };   //uzyskanie pozycji

    void snake_direction(const char direction) { this->direction_ = direction; }; //przypisanie kierunku weza

    std::vector<COORD> get_body() { return body_; };

    bool snake_eaten(COORD food);

    bool snake_collided(const MenuData& menuData);    //czy snake zderzyl sie
};

#endif
