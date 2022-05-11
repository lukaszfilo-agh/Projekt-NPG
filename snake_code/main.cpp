#include "snake.hpp"


int main() {
    int poziom_trudnosci = 1;
    std::string nazwa_weza = "snake";
    std::string kolor_weza = "zielony";
    std::cout << znaki() << "===Witaj w grze snake===" << std::endl << znaki();
    wait();
    int wybor = 0;
    while (wybor != 1) {
        menu_display();
        std::cin >> wybor;
        if (wybor == 2) {
            poziom_trudnosci = w_poziom_trudnosci();
        } else if (wybor == 3) {
            nazwa_weza = w_nazwa_weza();
        } else if (wybor == 4) {
            kolor_weza = w_kolor_weza();
        } else if (wybor == 6) {
            exit_game();
            return 0;
        }
    }

    if (wybor == 1) { // rozpoczecie gry
        clear_console();
        std::cout << znaki();
        std::cout << "===ROZPOCZYNASZ NOWA GRE===" << std::endl;
        std::cout << "Nazwa twojego weza to: " << nazwa_weza << std::endl;
        std::cout << "Kolor twojego weza to : " << kolor_weza << std::endl;
        std::cout << "Grasz na poziomie trudnosci nr: " << poziom_trudnosci << std::endl;
        std::cout << znaki();
        wait();
    }

    return 0;
}
