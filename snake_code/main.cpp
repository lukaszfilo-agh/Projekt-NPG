#include "menu.hpp"
#include "snake.hpp"

int main() {
    MenuData menuData; // obiekt przechowujacy dane menu
    welcome_message();
    menu(menuData);
    std::cout << "nowa gra" << std::endl;
    Snake snake({static_cast<SHORT>(menuData.get_size_x()/2), static_cast<SHORT>(menuData.get_size_y()/2)}, menuData);
    system("pause");
    return 0;
}