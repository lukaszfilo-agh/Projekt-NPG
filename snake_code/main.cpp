#include <iostream>
#include "snake.hpp"
#include "food.hpp"

int main() {
    int poziom_trudnosci = 1;
    std::string nazwa_weza = "snake";

    std::cout << "===Witaj w grze snake===" << std::endl;

    int wybor = 0;
    while (wybor != 1) {
        std::cout << std::endl << "===MENU GLOWNE===" << std::endl;
        std::cout << "1. Nowa Gra" << std::endl;
        std::cout << "2. Poziom Trudnosci" << std::endl;
        std::cout << "3. Nazwa weza" << std::endl;
        std::cout << "4. Kolor weza" << std::endl;
        std::cout << "5. Kolor tla" << std::endl;
        std::cout << "6. Wyjdz z gry" << std::endl;

        std::cout << "Wybierz opcje z menu, nastepnie nacisnij ENTER: ";

        std::cin >> wybor;

        if (wybor == 2)
            poziom_trudnosci = w_poziom_trudnosci();
        else if (wybor == 3)
            nazwa_weza = w_nazwa_weza();
        else if (wybor == 6)
            return 0;
    }

    if (wybor == 1) {   // rozpoczecie gry
        std::cout << "Rozpoczynasz nowa gre, nazwa twojego weza to: " << nazwa_weza << std::endl;
        std::cout << "Grasz na poziomie trudnosci nr: " << poziom_trudnosci;
        }


    return 0;
}
