#include "menu.hpp"

void signs() {
    std::cout << "------------------------------------------------------" << std::endl;
}

void clear_console(){
    system("cls");
};

void wait(const int i) {
    sleep(i);
}

//void  err_check(std::string (func())) {
//  if (std::cin.fail()) {
//    std::cin.clear();
//   std::cin.ignore();
//  std::cout << "Podana zła wartosc" << std::endl;
// func();
// }
//}

void menu_display(){
    signs();
    std::cout << "                 ===MENU GLOWNE===" << std::endl;
    std::cout << "1. Nowa Gra" << std::endl;
    std::cout << "2. Poziom Trudnosci" << std::endl;
    std::cout << "3. Nazwa weza" << std::endl;
    std::cout << "4. Kolor weza" << std::endl;
    std::cout << "5. Kolor tla" << std::endl;
    std::cout << "6. Wyjdz z gry" << std::endl;
    signs();
    std::cout << "Wybierz opcje z menu: " << std::endl;
}

void exit_game() {
    std::cout << "Do zobaczenia!" << std::endl;
    wait(1);
    std::cout << "Zamykanie...";
    wait(2);
}

std::string select_difficulty_level() {
    signs();
    std::cout << "Dostepne poziomy:" << std::endl;
    std::cout << "1. Latwy" << std::endl;
    std::cout << "2. Sredni" << std::endl;
    std::cout << "3. Trudny" << std::endl;
    signs();
    std::cout << "Wybierz poziom trundosci: ";
    std::string poziom_trudnosci;
    std::cin >> poziom_trudnosci;
    if (poziom_trudnosci == "1") {
        std::cout << "Wybrales poziom latwy." << std::endl;
    } else if (poziom_trudnosci == "2") {
        std::cout << "Wybrales poziom sredni." << std::endl;
    } else if (poziom_trudnosci == "3") {
        std::cout << "Wybrales poziom trudny." << std::endl;
    }
    wait(2);
    std::cout << "Powrot do okna menu..." << std::endl << std::endl;
    wait(1);
    return poziom_trudnosci;
}

std::string select_snake_name() {
    std::cout << "Podaj nazwe swojego weza: ";
    std::string nazwa_weza;
    std::cin >> nazwa_weza;
    std::cout << "Twoj waz to: " << nazwa_weza << std::endl;
    wait(2);
    std::cout << "Powrot do okna menu..." << std::endl << std::endl;
    wait(1);
    return nazwa_weza;
}

std::string select_snake_color() {
    std::string kolor;
    signs();
    std::cout << "Dostepne kolory to:" << std::endl;
    std::cout << "- zielony," << std::endl;
    std::cout << "- czerwony," << std::endl;
    std::cout << "- niebieski," << std::endl;
    std::cout << "- pomaranczowy." << std::endl;
    signs();
    std::cout << "Wybierz swoj kolor: ";
    std::cin >> kolor;
    if (kolor == "zielony") {
        std::cout << "Wybrales kolor " << kolor << "!" << std::endl;
    } else if (kolor == "czerwony") {
        std::cout << "Wybrales kolor " << kolor << "!" << std::endl;
    } else if (kolor == "niebieski") {
        std::cout << "Wybrales kolor " << kolor << "!" << std::endl;
    } else if (kolor == "pomaranczowy") {
        std::cout << "Wybrales kolor " << kolor << "!"<< std::endl;
    }
    wait(2);
    std::cout << "Powrot do okna menu..." << std::endl << std::endl;
    wait(1);
    return kolor;
}
std::string select_background_color()
{
    std::string kolor;
    signs();
    std::cout << "Dostepne kolory to:" << std::endl;
    std::cout << "- bialy," << std::endl;
    std::cout << "- czarny," << std::endl;
    std::cout << "- rozowy," << std::endl;
    std::cout << "- brazowy." << std::endl;
    signs();
    std::cout << "Wybierz swoj kolor: ";
    std::cin >> kolor;
    if (kolor == "bialy") {
        std::cout << "Wybrales kolor " << kolor << "!" << std::endl;
    } else if (kolor == "czarny") {
        std::cout << "Wybrales kolor " << kolor << "!" << std::endl;
    } else if (kolor == "rozowy") {
        std::cout << "Wybrales kolor " << kolor << "!" << std::endl;
    } else if (kolor == "brazowy") {
        std::cout << "Wybrales kolor " << kolor << "!" << std::endl;
    }
    wait(2);
    std::cout << "Powrot do okna menu..." << std::endl << std::endl;
    wait(1);
    return kolor;
}

