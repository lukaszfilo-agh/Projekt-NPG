#include "menu.hpp"
#include "game.hpp"

int main() {
    maximize_screen();
    MenuData menuData;        //!obiekt przechowujacy dane menu
    welcome_message();        //!wiadomosc powitalna
    instructions_menu();      //!instrukcje obslugi menu
    game_main(menuData);
    menuData.~MenuData();
    return 0;
}