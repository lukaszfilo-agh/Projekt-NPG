#include "universal.hpp"
#include <iostream>
#include <unistd.h>
#include <windows.h>

// Ponizej funckje uniwersanlne

void console_cursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void welcome_message() {
    signs();
    std::cout << "              ===Witaj w grze snake===" << std::endl;
    signs();
    normal_wait(1);
}

void signs() {
    std::cout << "------------------------------------------------------" << std::endl;
}

void clear_console() {
    system("cls");
}

void menu_wait() {// domyslne oczekiwanie z informacja
    console_cursor(false);
    signs();
    std::cout << "Nacisnij ENTER aby kontynuowac." << std::endl;
    signs();
    std::cin.ignore();
    std::cin.get();
    signs();
    std::cout << "Powrot do okna menu..." << std::endl;
    signs();
    sleep(1);
    console_cursor(true);
}

void normal_wait(const int i) {       // samo oczekiwanie z wyborem czasu trwania
    console_cursor(false);
    sleep(i);
    signs();
    std::cout << "Nacisnij ENTER aby kontynuowac." << std::endl;
    signs();
    std::cin.get();
    console_cursor(true);
}