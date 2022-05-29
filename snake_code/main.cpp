#include "menu.hpp"
#include "game.hpp"

int main() {
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    MenuData menuData;        // obiekt przechowujacy dane menu
    welcome_message();        // wiadomosc powitalna
    instructions_menu();      // instrukcje obslugi menu
    game_main(menuData);
    return 0;
}