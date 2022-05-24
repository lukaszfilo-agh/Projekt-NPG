#include "menu.hpp"
#include "snake.hpp"
#include "game.hpp"
#include "fruit.hpp"

int main() {
    MenuData menuData; // obiekt przechowujacy dane menu
    welcome_message();
    menu(menuData);
    Snake snake({static_cast<SHORT>(menuData.get_size_x()/2), static_cast<SHORT>(menuData.get_size_y()/2)}, menuData);
    Fruit fruit;
    game(menuData, snake, fruit);
    return 0;
}