#ifndef SNAKE_UNIVERSAL_HPP
#define SNAKE_UNIVERSAL_HPP

#include <iostream>

template<class T>
inline T read() {
    while (true) {
        if (std::cin.eof()) //We reached the end of file, or the user hit ctrl-d
            return T(); //Alternatively, we could throw an exception
        T retval;
        std::cin >> retval;
        if (!std::cin) {
            std::cin.clear(); //Clear error code
            std::string s;
            std::cin >> s; //Remove the word that caused the error
            std::cout << "Podano niepoprawna wartosc, sprobuj ponownie: ";
            continue;
        }
        return retval;
    }
}

void signs();        // znaki ozdobne

void clear_console();       // czyszczenie konsoli

void menu_wait();                // sleep domyslny z informacja

void normal_wait(int i);         // sleep do wyboru czasu oczekiwania

#endif