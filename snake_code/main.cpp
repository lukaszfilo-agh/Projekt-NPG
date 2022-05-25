#include "menu.hpp"
#include "snake.hpp"
#include "game.hpp"
#include "fruit.hpp"

int main() {
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    MenuData menuData; // obiekt przechowujacy dane menu
    welcome_message();

    while(menuData.get_game_end()) {
        menu(menuData);
        if (menuData.get_game_end()) {
            menuData.~MenuData();
            return 0;
        }
        else {
            Snake snake({static_cast<SHORT>(menuData.get_size_x() / 2), static_cast<SHORT>(menuData.get_size_y() / 2)},
                        menuData);
            Fruit fruit;
            game(menuData, snake, fruit);
            snake.~Snake();
            fruit.~Fruit();
        }
    }
}