#ifndef SNAKE_FRUIT_HPP
#define SNAKE_FRUIT_HPP

#include <windows.h>
#include "menu.hpp"

class Fruit {
private:
    COORD position_;

public:
    COORD fruit_get_position() { return position_; } //uzyskanie pozycji owoca

    void fruit_generate(const MenuData& menuData);
};

#endif //SNAKE_FRUIT_HPP
