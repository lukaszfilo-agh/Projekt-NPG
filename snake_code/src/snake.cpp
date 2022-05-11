#include "snake.hpp"
#include <sstream>

std::string znaki() {
    std::ostringstream oss;
    oss << "------------------------------------------------------" << std::endl;
    return oss.str();
}

void sleep() {
    std::cout << "Naciśnij ENTER aby kontynuowac..." << std::endl;
    std::cin.get();
}

void menu_display(){
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
};

int w_poziom_trudnosci() {
    std::cout << znaki() << std::endl;
    std::cout << "Dostepne poziomy:" << std::endl;
    std::cout << "1. Latwy" << std::endl;
    std::cout << "2. Sredni" << std::endl;
    std::cout << "3. Trudny" << std::endl;
    std::cout << znaki() << std::endl;
    std::cout << "Wybierz poziom trundosci: ";

    int poziom_trudnosci;
    std::cin >> poziom_trudnosci;
    if (poziom_trudnosci == 1) {
        std::cout << "Wybrales poziom latwy." << std::endl;
    } else if (poziom_trudnosci == 2) {
        std::cout << "Wybrales poziom sredni." << std::endl;
    } else if (poziom_trudnosci == 3) {
        std::cout << "Wybrales poziom trudny." << std::endl;
    }
    return poziom_trudnosci;
}


std::string w_nazwa_weza() {
    std::cout << "Podaj nazwe swojego weza: ";
    std::string nazwa_weza;
    std::cin >> nazwa_weza;
    std::cout << "Twoj waz to: " << nazwa_weza << std::endl;
    return nazwa_weza;
}

std::string w_kolor_weza() {
    std::string kolor;
    std::cout << znaki() << std::endl;
    std::cout << "Dostepne kolory to:" << std::endl;
    std::cout << "- zielony," << std::endl;
    std::cout << "- czerwony," << std::endl;
    std::cout << "- niebieski," << std::endl;
    std::cout << "- pomaranczowy." << std::endl;
    std::cout << znaki();
    std::cout << "Wybierz swoj kolor: ";
    std::cin >> kolor;
    if (kolor == "zielony") {
        std::cout << "Wybrales kolor " << kolor << "!";
    } else if (kolor == "czerwony") {
        std::cout << "Wybrales kolor " << kolor << "!";
    } else if (kolor == "niebieski") {
        std::cout << "Wybrales kolor " << kolor << "!";
    } else if (kolor == "pomaranczowy") {
        std::cout << "Wybrales kolor " << kolor << "!";
    }
    return kolor;
}
