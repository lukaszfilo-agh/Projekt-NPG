#include <iostream>
#include "snake.hpp"



void menu() {
    std::cout << "MENU GLOWNE" << std::endl;
    std::cout << "1. Nowa Gra" << std::endl;
    std::cout << "2. Poziom Trudnosci" << std::endl;
    std::cout << "3. Nazwa weza" << std::endl;

    std::cout << "Wybierz opcje z menu: ";
    int wybor = 0;
    std::cin >> wybor;
    if (wybor == 1)
    {

    }
    else if (wybor == 2)
    {
        poziom_trudnosci();
    }
    else if (wybor == 3)
    {
        nazwa_weza();
    }
}

int poziom_trudnosci() {
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

    menu();
    return poziom_trudnosci;
}


std::string nazwa_weza() {
    std::cout << "Podaj nazwe swojego weza: ";
    std::string nazwa_weza;
    std::cin >> nazwa_weza;
    std::cout << "Twoj waz to " << nazwa_weza << std::endl;

    menu();
    return nazwa_weza;
}
