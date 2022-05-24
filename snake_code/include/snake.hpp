#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <vector>
#include <windows.h>
#include "menu.hpp"
#include "fruit.hpp"

class Snake {
private:
    COORD position_;
    std::vector<COORD> body_;
    std::vector<COORD>::size_type length_;            //dlugosc weza
    int velocity_;          //predkosc przesuwania sie weza, ustalona wedlug poziomu trudnosci
    char direction_;

public:
    Snake(COORD position, const MenuData& menudata);   //konstruktor snakea

    void snake_move(); //poruszanie snakem

    int get_length() const {return length_;}

    void snake_grow() { length_++; };   //wydluzanie weza

    COORD snake_get_position() const { return position_; };   //uzyskanie pozycji

    void snake_direction(const char direction) { this->direction_ = direction; }; //przypisanie kierunku weza

    std::vector<COORD> get_body() const { return body_; }

    COORD get_body_elem(int i) const { return body_[i]; }

    int get_body_size() const { return body_.size(); }

    bool snake_eaten(const Fruit& fruit);

    bool snake_collided(const MenuData& menuData);    //czy snake zderzyl sie
};

#endif
