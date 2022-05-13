#include "menu.hpp"
#include "universal.hpp"
#include <unistd.h>
// PONIZEJ FUNKCJE TYPOWO DO OBSLUGI MENU W KOLEJNOSCI UZYCIA

void whole_menu() {
    MenuData menuData;  // wszystkie domyslne dane znajduja sie w tym obiekcie
    signs();
    std::cout << "              ===Witaj w grze snake===" << std::endl;
    signs();

    int choice = 0;
    while (choice != 1 && choice != 6) {
        menu_display();                            // wyswietlanie menu
        std::cin >> choice;
        if (choice == 2) {
            select_difficulty_level(menuData);     // funcja modyfikujaca obiekt w klasie (zmieniajaca opcje)
        } else if (choice == 3) {
            select_snake_name(menuData);           // funcja modyfikujaca obiekt w klasie (zmieniajaca opcje)
        } else if (choice == 4) {
            select_snake_color(menuData);          // funcja modyfikujaca obiekt w klasie (zmieniajaca opcje)
        } else if (choice == 5) {
            select_background_color(menuData);     // funcja modyfikujaca obiekt w klasie (zmieniajaca opcje)
        } else if (choice < 1 || choice > 6) {                         // podanie złej opcji konczy sie zakonczeniem gry
            std::cout << "Podano nieznana opcje!" << std::endl;
            menu_wait();
        }
    }
    if (choice == 1) {   // warunek rozpoczecia gry
        std::cout << "              ===ROZPOCZYNASZ NOWA GRE===" << std::endl;
        std::cout << "Nazwa twojego weza to: " << menuData.get_snake_name() << std::endl;
        std::cout << "Kolor twojego weza to: " << menuData.get_snake_color() << std::endl;
        std::cout << "Kolor twojego tla to: " << menuData.get_background_color() << std::endl;
        std::cout << "Grasz na poziomie trudnosci nr: " << menuData.get_diff_level() << std::endl;
        signs();
        sleep(2); //tymczasowo. Edit : zmieniono
    } else if (choice == 6) {                     // !!!!!!!!!!!!! wyjscie z menu (poprawiono dzialanie)
        exit_game();
    }
}

void menu_display() {                       // wyswiwetlanie opcji w menu
    clear_console();
    signs();
    std::cout << "                 ===MENU GLOWNE===" << std::endl;
    std::cout << "1. Nowa Gra" << std::endl;
    std::cout << "2. Poziom Trudnosci" << std::endl;
    std::cout << "3. Nazwa weza" << std::endl;
    std::cout << "4. Kolor weza" << std::endl;
    std::cout << "5. Kolor tla" << std::endl;
    std::cout << "6. Wyjdz z gry" << std::endl;
    signs();
    std::cout << "Wybierz opcje z menu: ";
}

void select_difficulty_level(MenuData &menuData) {             // obsluguje wybor poziomu trudnosci
    clear_console();
    signs();
    std::cout << "Dostepne poziomy:" << std::endl;
    std::cout << "1. Latwy" << std::endl;
    std::cout << "2. Sredni" << std::endl;
    std::cout << "3. Trudny" << std::endl;
    signs();
    std::cout << "Wybierz poziom trudnosci: ";
    menuData.set_diff_level();

    if (menuData.get_diff_level() == 1) {
        std::cout << "Wybrales poziom latwy." << std::endl;
    } else if (menuData.get_diff_level() == 2) {
        std::cout << "Wybrales poziom sredni." << std::endl;
    } else if (menuData.get_diff_level() == 3) {
        std::cout << "Wybrales poziom trudny." << std::endl;
    }
    menu_wait();
}

void select_snake_name(MenuData &menuData) {               // obsluguje wybor nazwy weza
    clear_console();
    std::cout << "Podaj nazwe swojego weza: ";
    menuData.set_snake_name();
    std::cout << "Twoj waz to: " << menuData.get_snake_name() << std::endl;
    menu_wait();
}

void select_snake_color(MenuData &menuData) {             // obsluguje wybor koloru weza
    clear_console();
    signs();
    std::cout << "Dostepne kolory to:" << std::endl;
    std::cout << "- zielony," << std::endl;
    std::cout << "- czerwony," << std::endl;
    std::cout << "- niebieski," << std::endl;
    std::cout << "- pomaranczowy." << std::endl;
    signs();
    std::cout << "Wybierz swoj kolor: ";
    menuData.set_snake_color();
    if (menuData.get_snake_color() == "zielony") {
        std::cout << "Wybrales kolor " << menuData.get_snake_color() << "!" << std::endl;
    } else if (menuData.get_snake_color() == "czerwony") {
        std::cout << "Wybrales kolor " << menuData.get_snake_color() << "!" << std::endl;
    } else if (menuData.get_snake_color() == "niebieski") {
        std::cout << "Wybrales kolor " << menuData.get_snake_color() << "!" << std::endl;
    } else if (menuData.get_snake_color() == "pomaranczowy") {
        std::cout << "Wybrales kolor " << menuData.get_snake_color() << "!" << std::endl;
    }
    menu_wait();
}

void select_background_color(MenuData &menuData) {             // obsluguje wybor koloru tla
    clear_console();
    signs();
    std::cout << "Dostepne kolory to:" << std::endl;
    std::cout << "- bialy," << std::endl;
    std::cout << "- czarny," << std::endl;
    std::cout << "- rozowy," << std::endl;
    std::cout << "- brazowy." << std::endl;
    signs();
    std::cout << "Wybierz swoj kolor: ";
    menuData.set_background_color();
    if (menuData.get_background_color() == "bialy") {
        std::cout << "Wybrales kolor " << menuData.get_background_color() << "!" << std::endl;
    } else if (menuData.get_background_color() == "czarny") {
        std::cout << "Wybrales kolor " << menuData.get_background_color() << "!" << std::endl;
    } else if (menuData.get_background_color() == "rozowy") {
        std::cout << "Wybrales kolor " << menuData.get_background_color() << "!" << std::endl;
    } else if (menuData.get_background_color() == "brazowy") {
        std::cout << "Wybrales kolor " << menuData.get_background_color() << "!" << std::endl;
    }
    menu_wait();
}

void exit_game() {                                  // opuszczanie menu
    std::cout << "Do zobaczenia!" << std::endl;
    normal_wait(1);
    std::cout << "Zamykanie...";
    normal_wait(1);
}

