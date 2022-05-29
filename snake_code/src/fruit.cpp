#include "fruit.hpp"

void Fruit::generate(const MenuData &menuData) {                   //generowanie owocow na planszy
    position_.X = (rand() % menuData.get_size_x() - 3) + 2;

    while (position_.X >= menuData.get_size_x() - 4 ||
           position_.X < 0) {     //kontrola pojawiania sie owocow **DO POPRAWIENIA**
        position_.X = (rand() % menuData.get_size_x() - 3) + 2;
    }

    position_.Y = (rand() % menuData.get_size_y() - 3) + 2;

    while (position_.Y >= menuData.get_size_y() - 4 || position_.Y < 0) {
        position_.Y = (rand() % menuData.get_size_y() - 3) + 2;
    }
}