#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <windows.h>
#include <vector>

class Snake {
private:
    COORD position_;
    std::vector<COORD> body_;
    int lenght_;            //dlugosc weza
    int velocity_;          //predkosc przesuwania sie weza, ustalona wedlug poziomu trudnosci
    char direction_;

public:
    Snake(COORD position_, int velocity_);

    void snake_move() {};

    void snake_grow() { lenght_++; };   //wydluzanie weza

    COORD snake_get_position() { return position_; };   //uzyskanie pozycji
};

#endif
