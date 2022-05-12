#include "snake.hpp"
#include "menu.hpp"


int main() {
    std::string poziom_trudnosci = "1";
    std::string nazwa_weza = "snake";
    std::string kolor_weza = "zielony";
    std::string kolor_tla = "bialy";
    signs();
    std::cout << "              ===Witaj w grze snake===" << std::endl;
    signs();
    int wybor = 0;
    while (wybor != 1) {
        menu_display();
        std::cin >> wybor;
        if (wybor == 2) {
            poziom_trudnosci = select_difficulty_level();
        } else if (wybor == 3) {
            nazwa_weza = select_snake_name();
        }
        else if (wybor == 4) {
            kolor_weza = select_snake_color();
        }
        else if(wybor == 5) {
            kolor_tla = select_background_color();
        }
        else if (wybor == 6) {
            exit_game();
            return 0;
        }
        else if (wybor < 1 || wybor > 6){
            std::cout << "Podano nieznana opcje!" << std::endl;
            menu_wait();
        }
    }
    if (wybor == 1) { // rozpoczecie gry
        signs();
        std::cout << "              ===ROZPOCZYNASZ NOWA GRE===" << std::endl;
        std::cout << "Nazwa twojego weza to: " << nazwa_weza << std::endl;
        std::cout << "Kolor twojego weza to: " << kolor_weza << std::endl;
        std::cout << "Kolor twojego tla to: " << kolor_tla << std::endl;
        std::cout << "Grasz na poziomie trudnosci nr: " << poziom_trudnosci << std::endl;
        signs();
        sleep(5); //tymczasowo
    }

    return 0;
}
