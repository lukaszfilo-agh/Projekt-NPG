#include "universal.hpp"
#include <iostream>
#include <unistd.h>
#include <functional>

//-----------------------------------------------------------------
// Ponizej funckje uniwersanlne

//void err_check() {             // DO ZROBIENIA
//
//    }
//}

void signs() {
    std::cout << "------------------------------------------------------" << std::endl;
}

void clear_console() {
    system("cls");
}

void menu_wait() {               // domyslne oczekiwanie z informacja
    sleep(2);
    std::cout << "Powrot do okna menu..." << std::endl << std::endl;
    sleep(1);
}

void normal_wait(int i) {       // samo oczekiwanie z wyborem czasu trwania
    sleep(i);
}
