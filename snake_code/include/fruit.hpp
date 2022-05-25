#ifndef SNAKE_FRUIT_HPP
#define SNAKE_FRUIT_HPP

#include <windows.h>
#include "menu.hpp"

class Fruit {
private:
    COORD position_;

public:
    Fruit() = default;
    ~Fruit() = default;

    COORD fruit_get_position() const { return position_; } //uzyskanie pozycji owoca

    void fruit_generate(const MenuData& menuData);
};

#endif //SNAKE_FRUIT_HPP
