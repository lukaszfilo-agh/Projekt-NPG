#include "universal.hpp"
#include <iostream>
#include <unistd.h>
// Ponizej funckje uniwersanlne

void signs() {
    std::cout << "------------------------------------------------------" << std::endl;
}

void clear_console() {
    system("cls");
}

void menu_wait() {// domyslne oczekiwanie z informacja
    signs();
    std::cout << "Nacisnij ENTER aby kontynuowac." << std::endl;
    signs();
    std::cin.ignore();
    std::cin.get();
    signs();
    std::cout << "Powrot do okna menu..." << std::endl;
    signs();
    sleep(1);
}

void normal_wait(const int i) {       // samo oczekiwanie z wyborem czasu trwania
    sleep(i);
    signs();
    std::cout << "Nacisnij ENTER aby kontynuowac." << std::endl;
    signs();
    std::cin.get();
}