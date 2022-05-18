#include "fruit.hpp"

void Fruit::fruit_generate(const MenuData& menuData) {
    position_.X = (rand() % menuData.get_size_x() - 3) + 1;
    position_.Y = (rand() % menuData.get_size_y() - 3) + 1;
}