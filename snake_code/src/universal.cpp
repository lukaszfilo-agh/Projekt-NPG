#include "universal.hpp"
#include <iostream>
#include <unistd.h>
#include <windows.h>

// Ponizej funckje uniwersanlne

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

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