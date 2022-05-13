#include "menu.hpp"

int main() {
    MenuData menuData; // obiekt przechowujacy dane menu
    welcome_message();
    menu(menuData);
    std::cout << "nowa gra" << std::endl;
    system("pause");
    return 0;
}