#include "universal.hpp"
#include <iostream>
#include <unistd.h>
#include <functional>

//-----------------------------------------------------------------
// Ponizej funckje uniwersanlne

void signs() {
    std::cout << "------------------------------------------------------" << std::endl;
}

void clear_console() {
    system("cls");
}

void menu_wait() {               // domyslne oczekiwanie z informacja
    std::cout << "Nacisnij ENTER aby kontynuowac." << std::endl;
    std::cin.ignore();
    std::cin.get();
    std::cout << "Powrot do okna menu..." << std::endl;
    sleep(1);
}

void normal_wait() {       // samo oczekiwanie z wyborem czasu trwania
    sleep(1);
    signs();
    std::cout << "Nacisnij ENTER aby kontynuowac." << std::endl;
    signs();
    std::cin.get();
}