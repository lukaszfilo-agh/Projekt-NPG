#include "menu.hpp"

int main() {
    MenuData menuData; // obiekt przechowujacy dane menu
    welcome_message();
    menu(menuData);
    return 0;
}