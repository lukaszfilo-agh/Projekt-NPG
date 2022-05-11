#include "snake.hpp"


int main() {
    int poziom_trudnosci = 1;
    std::string nazwa_weza = "snake";
    std::string kolor_weza = "zielony";
    std::cout << "===Witaj w grze snake===" << std::endl;
    sleep();
    int wybor = 0;
    while (wybor != 1) {
        std::system("clear");
        std::cout << znaki() << "===MENU GLOWNE===" << std::endl;
        std::cout << "1. Nowa Gra" << std::endl;
        std::cout << "2. Poziom Trudnosci" << std::endl;
        std::cout << "3. Nazwa weza" << std::endl;
        std::cout << "4. Kolor weza" << std::endl;
        std::cout << "5. Kolor tla" << std::endl;
        std::cout << "6. Wyjdz z gry" << std::endl;
        std::cout << znaki();
        std::cout << "Wybierz opcje z menu: ";
        std::cin >> wybor;
        if (wybor == 2) {
            poziom_trudnosci = w_poziom_trudnosci();
        }
        else if (wybor == 3) {
            nazwa_weza = w_nazwa_weza();
        }
        else if(wybor == 4) {
            kolor_weza = w_kolor_weza();
        }
        else if (wybor == 6) {
            std::cout << "Do zobaczenia!" << std::endl;
            std::cout<< "Zamykanie...";
            return 0;
        }
    }

    if(wybor == 1) {
        std:: cout << znaki();
        std::cout << "===ROZPOCZYNASZ NOWA GRE===" << std::endl;
        std::cout << "Nazwa twojego weza to: " << nazwa_weza << std::endl;
        std:: cout << "Kolor twojego weza to : " << kolor_weza << std::endl; // rozpoczecie gry
        std::cout << "Grasz na poziomie trudnosci nr: " << poziom_trudnosci;
        std::cout << znaki();
    }

    return 0;
}
