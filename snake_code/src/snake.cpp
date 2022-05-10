#include <iostream>
#include "snake.hpp"


int w_poziom_trudnosci() {
    std::cout << "Wybierz poziom trudnosci:" << std::endl;
    std::cout << "1. Latwy" << std::endl;
    std::cout << "2. Sredni" << std::endl;
    std::cout << "3. Trudny" << std::endl;

    int poziom_trudnosci;
    std::cin >> poziom_trudnosci;
    if (poziom_trudnosci == 1)
        std::cout << "Wybrales poziom latwy" << std::endl;
    else if (poziom_trudnosci == 2)
        std::cout << "Wybrales poziom sredni" << std::endl;
    else if (poziom_trudnosci == 3)
        std::cout << "Wybrales poziom trudny" << std::endl;

    return poziom_trudnosci;
}


std::string w_nazwa_weza() {
    std::cout << "Podaj nazwe swojego weza: ";
    std::string nazwa_weza;
    std::cin >> nazwa_weza;
    std::cout << "Twoj waz to " << nazwa_weza << std::endl;

    return nazwa_weza;
}
