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
    std::vector<COORD>::size_type length_;                   //dlugosc weza
    int velocity_;                                           //predkosc przesuwania sie weza, ustalona wedlug poziomu trudnosci
    char direction_;                                         //obsluga kierunku porusznania

public:
    Snake(COORD position, const MenuData &menudata);         //konstruktor snakea

    ~Snake() = default;                                      //destruktor domyslny

    //gettery
    int get_length() const { return length_; }               //uzyskanie dlugosci

    COORD get_position() const { return position_; };        //uzyskanie pozycji

    std::vector<COORD> get_body() const { return body_; }    //uzyskanie ciala

    COORD get_body_elem(int i) const { return body_[i]; }    //uzyskanie elementu ciala

    int get_body_size() const { return body_.size(); }       //uzyskanie rozmiaru ciala

    //metody

    bool eaten(const Fruit &fruit);             //czy snake zjadl owoc

    bool collided(const MenuData &menuData);    //czy snake zderzyl sie

    void direction(const char direction) { this->direction_ = direction; };     //przypisanie kierunku weza

    void grow() { length_++; };                 //wydluzanie weza

    void move();                                //poruszanie snakem
};

#endif
