#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <vector>
#include <windows.h>

class Snake {
private:
    COORD position_;
    std::vector<COORD> body_;
    int lenght_;            //dlugosc weza
    int velocity_;          //predkosc przesuwania sie weza, ustalona wedlug poziomu trudnosci
    char direction_;

public:
    Snake(COORD position, int velocity);   //konstruktor snakea

    void snake_move() {}; //poruszanie snakem

    void snake_grow() { lenght_++; };   //wydluzanie weza

    COORD snake_get_position() { return position_; };   //uzyskanie pozycji

    void snake_direction(char direction) { this->direction_ = direction; }; //przypisanie kierunku weza

    std::vector<COORD> get_body() { return body_; };

    bool snake_eaten(COORD food);

    //bool snake_collided();    //czy snake zderzyl sie
};

#endif
