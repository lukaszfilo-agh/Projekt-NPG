#include "menu.hpp"
#include "universal.hpp"
// PONIZEJ FUNKCJE DO OBSLUGI MENU W KOLEJNOSCI UZYCIA

void menu(MenuData menuData) {
    int choice = 0;
    while (choice != 1 && choice != 8) {
        menu_display();                            // wyswietlanie menu
        choice = read<int>();
        if (choice == 2) {
            select_difficulty_level(menuData);     // funcja modyfikujaca obiekt w klasie (zmieniajaca opcje)
        } else if (choice == 3) {
            select_snake_name(menuData);           // funcja modyfikujaca obiekt w klasie (zmieniajaca opcje)
        } else if (choice == 4) {
            select_snake_color(menuData);          // funcja modyfikujaca obiekt w klasie (zmieniajaca opcje)
        } else if (choice == 5) {
            select_background_color(menuData);     // funcja modyfikujaca obiekt w klasie (zmieniajaca opcje)
        } else if (choice == 6) {
            select_size(menuData);
        } else if (choice == 7) {
            select_board(menuData);
        } else {                         // podanie złej opcji konczy sie przeladowaniem menu
            clear_console();
            signs();
            std::cout << "Podano nieznana opcje!" << std::endl;
            signs();
            menu_wait();
        }
    }
    if (choice == 1) {   // warunek rozpoczecia gry
        clear_console();
        signs();
        std::cout << "              ===ROZPOCZYNASZ NOWA GRE===" << std::endl;
        std::cout << "Grasz na poziomie trudnosci nr: " << menuData.get_diff_level() << std::endl;
        std::cout << "Nazwa twojego weza to: " << menuData.get_snake_name() << std::endl;
        std::cout << "Kolor twojego weza to: " << menuData.get_snake_color() << std::endl;
        std::cout << "Kolor twojego tla to: " << menuData.get_background_color() << std::endl;
        std::cout << "Rozmiar twojej planszy to: " << menuData.get_size_x() << " X " << menuData.get_size_y()
                  << std::endl;
        std::cout << "Wybrales plansze: " << menuData.get_board() << std::endl;
        signs();
        std::cin.ignore();
        normal_wait(1);
    } else {                     // wyjscie z menu
        exit_game();
    }
}

void welcome_message() {
    signs();
    std::cout << "              ===Witaj w grze snake===" << std::endl;
    signs();
    normal_wait(1);
}

void menu_display() {                       // wyswietlanie opcji w menu
    clear_console();
    signs();
    std::cout << "                 ===MENU GLOWNE===" << std::endl;
    std::cout << "1. Nowa Gra" << std::endl;
    std::cout << "2. Poziom Trudnosci" << std::endl;
    std::cout << "3. Nazwa weza" << std::endl;
    std::cout << "4. Kolor weza" << std::endl;
    std::cout << "5. Kolor tla" << std::endl;
    std::cout << "6  Rozmiar planszy" << std::endl;
    std::cout << "7  Rodzaj  planszy" << std::endl;
    std::cout << "8. Wyjdz z gry" << std::endl;
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
    clear_console();
    signs();
    if (menuData.get_diff_level() == 1) {
        std::cout << "Wybrales poziom latwy." << std::endl;
    } else if (menuData.get_diff_level() == 2) {
        std::cout << "Wybrales poziom sredni." << std::endl;
    } else if (menuData.get_diff_level() == 3) {
        std::cout << "Wybrales poziom trudny." << std::endl;
    }
    signs();
    menu_wait();
}

void select_snake_name(MenuData &menuData) {               // obsluguje wybor nazwy weza
    clear_console();
    std::cout << "Podaj nazwe swojego weza: ";
    menuData.set_snake_name();
    clear_console();
    signs();
    std::cout << "Twoj waz to: " << menuData.get_snake_name() << std::endl;
    signs();
    menu_wait();
}

void select_snake_color(MenuData &menuData) {             // obsluguje wybor koloru weza
    clear_console();
    signs();
    std::cout << "Dostepne kolory to:" << std::endl;
    std::cout << "1. zielony," << std::endl;
    std::cout << "2. czerwony," << std::endl;
    std::cout << "3. niebieski," << std::endl;
    std::cout << "4. pomaranczowy." << std::endl;
    signs();
    std::cout << "Wybierz swoj kolor: ";
    menuData.set_snake_color();
    clear_console();
    signs();
    if (menuData.get_snake_color() == 1) {
        std::cout << "Wybrales kolor zielony!" << std::endl;
    } else if (menuData.get_snake_color() == 2) {
        std::cout << "Wybrales kolor czerwony!" << std::endl;
    } else if (menuData.get_snake_color() == 3) {
        std::cout << "Wybrales kolor niebieski!" << std::endl;
    } else if (menuData.get_snake_color() == 4) {
        std::cout << "Wybrales kolor pomaranczowy!" << std::endl;
    }
    signs();
    menu_wait();
}

void select_background_color(MenuData &menuData) {             // obsluguje wybor koloru tla
    clear_console();
    signs();
    std::cout << "Dostepne kolory to:" << std::endl;
    std::cout << "1. czarny," << std::endl;
    std::cout << "2. bialy," << std::endl;
    std::cout << "3. rozowy," << std::endl;
    std::cout << "4. brazowy." << std::endl;
    signs();
    std::cout << "Wybierz swoj kolor: ";
    menuData.set_background_color();
    clear_console();
    signs();
    if (menuData.get_background_color() == 1) {
        std::cout << "Wybrales kolor czarny!" << std::endl;
    } else if (menuData.get_background_color() == 2) {
        std::cout << "Wybrales kolor bialy!" << std::endl;
    } else if (menuData.get_background_color() == 3) {
        std::cout << "Wybrales kolor rozowy!" << std::endl;
    } else if (menuData.get_background_color() == 4) {
        std::cout << "Wybrales kolor brazowy!" << std::endl;
    }
    signs();
    menu_wait();
}

void select_size(MenuData &menuData) {               // rozmiar planszy
    clear_console();
    signs();
    std::cout << "Wybierz szerokosc planszy: ";
    menuData.set_size_x();
    std::cout << "Wybierz wysokosc planszy: ";
    menuData.set_size_y();
    clear_console();
    signs();
    std::cout << "Wybrales rozmiar: " << menuData.get_size_x() << " X " << menuData.get_size_y() << std::endl;
    signs();
    menu_wait();
}

void select_board(MenuData &menuData) {                     //wybor mapy
    clear_console();
    signs();
    std::cout << "Dostepne plansze: " << std::endl;
    std::cout << "1. #," << std::endl;
    std::cout << "2. $," << std::endl;
    std::cout << "3. *," << std::endl;
    std::cout << "4. &," << std::endl;
    signs();
    std::cout << "Wybierz rodzaj planszy: ";
    menuData.set_board();
    if (menuData.get_board() == 1) {
        std::cout << "Wybrales plansze #." << std::endl;
    } else if (menuData.get_board() == 2) {
        std::cout << "Wybrales plansze $." << std::endl;
    } else if (menuData.get_board() == 3) {
        std::cout << "Wybrales plansze *" << std::endl;
    } else if (menuData.get_board() == 4) {
        std::cout << "Wybrales plansze &" << std::endl;
    }
    menu_wait();
}

void exit_game() {                                  // opuszczanie menu
    signs();
    std::cout << "Do zobaczenia!" << std::endl;
    std::cout << "Zamykanie..." << std::endl;
    signs();
    normal_wait(2);
}