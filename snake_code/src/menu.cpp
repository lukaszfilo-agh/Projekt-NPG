#include "menu.hpp"
#include "universal.hpp"

// wypelnienie map

const std::map<int, std::string> MenuData::snake_colors_ = {{1, "zielony"},
                                                            {2, "czerwony"},
                                                            {3, "niebieski"},
                                                            {4, "pomaranczowy"}};
const std::map<int, std::string> MenuData::background_colors_ = {{1, "czarny"},
                                                                 {2, "bialy"},
                                                                 {3, "rozowy"},
                                                                 {4, "brazowy"}};

const std::map<int, std::string> MenuData::board_chars_ = {{1, "#"},
                                                           {2, "$"},
                                                           {3, "*"},
                                                           {4, "&"}};

const std::map<int, std::string> MenuData::diff_map_ = {{1, "Latwy"},
                                                        {2, "Sredni"},
                                                        {3, "Trudny"}};

const std::map<int, std::string> MenuData::menu_text_ = {{1, "Nowa Gra"},
                                                         {2, "Poziom Trudnosci"},
                                                         {3, "Nazwa weza"},
                                                         {4, "Kolor weza"},
                                                         {5, "Kolor tla"},
                                                         {6, "Rozmiar planszy"},
                                                         {7, "Rodzaj planszy"},
                                                         {8, "Wyjdz z gry"}};

//wypisywanie map

void MenuData::print_background_diff_map() {
    for (auto const &pair: diff_map_) {
        std::cout << pair.first << ". " << pair.second << std::endl;
    }
}

void MenuData::print_background_color_map() {
    for (auto const &pair: background_colors_) {
        std::cout << pair.first << ". " << pair.second << std::endl;
    }
}

void MenuData::print_snake_color_map() {
    for (auto const &pair: snake_colors_) {
        std::cout << pair.first << ". " << pair.second << std::endl;
    }
}

void MenuData::print_board_chars_map() {
    for (auto const &pair: board_chars_) {
        std::cout << pair.first << ". " << pair.second << std::endl;
    }
}

void MenuData::print_menu_text() {
    for (auto const &pair: menu_text_) {
        std::cout << pair.first << ". " << pair.second << std::endl;
    }
}

// PONIZEJ FUNKCJE DO OBSLUGI MENU W KOLEJNOSCI UZYCIA

void menu(MenuData menuData) {
    int choice = 0;
    while (choice != 1 && choice != 8) {
        menu_display(menuData);                            // wyswietlanie menu
        std::cout << "Wybierz opcje z menu: ";
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
        } else if (choice < 1 ||
                   choice > 8) {                         // podanie złej opcji konczy sie przeladowaniem menu
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
        std::cout << "Grasz na poziomie trudnosci: " << menuData.get_diff_map(menuData.get_diff())
                  << std::endl;
        std::cout << "Nazwa twojego weza to: " << menuData.get_snake_name() << std::endl;
        std::cout << "Kolor twojego weza to: " << menuData.get_snake_color_map(menuData.get_snake_color()) << std::endl;
        std::cout << "Kolor twojego tla to: " << menuData.get_background_color_map(menuData.get_background_color())
                  << std::endl;
        std::cout << "Rozmiar twojej planszy to: " << menuData.get_size_x() << " X " << menuData.get_size_y()
                  << std::endl;
        std::cout << "Wybrales plansze: " << menuData.get_board_chars(menuData.get_board()) << std::endl;
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

void menu_display(MenuData &menuData) {                       // wyswietlanie opcji w menu
    clear_console();
    signs();
    std::cout << "                 ===MENU GLOWNE===" << std::endl;
    menuData.print_menu_text();
    signs();
}

void select_difficulty_level(MenuData &menuData) {             // obsluguje wybor poziomu trudnosci
    clear_console();
    signs();
    std::cout << "Dostepne poziomy:" << std::endl;
    menuData.print_background_diff_map();
    signs();
    std::cout << "Wybierz poziom trudnosci: ";
    menuData.set_diff();
    clear_console();
    signs();
    std::cout << "Wybrales poziom " << menuData.get_diff_map(menuData.get_diff()) << std::endl;
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
    menuData.print_snake_color_map();
    signs();
    std::cout << "Wybierz swoj kolor: ";
    menuData.set_snake_color();
    clear_console();
    signs();
    std::cout << "Wybrales kolor ";
    std::cout << menuData.get_snake_color_map(menuData.get_snake_color()) << "!" << std::endl;
    signs();
    menu_wait();
}

void select_background_color(MenuData &menuData) {             // obsluguje wybor koloru tla
    clear_console();
    signs();
    std::cout << "Dostepne kolory to:" << std::endl;
    menuData.print_background_color_map();
    signs();
    std::cout << "Wybierz swoj kolor: ";
    menuData.set_background_color();
//    while (menuData.get_background_color() > 4) { //error checker
//        signs();
//        std::cout << "Wybrano niepoprawny kolor planszy: ";
//        menuData.set_background_color();
//    }
    clear_console();
    signs();
    std::cout << "Wybrales kolor ";
    std::cout << menuData.get_background_color_map(menuData.get_background_color()) << "!" << std::endl;
    signs();
    menu_wait();
}

void select_size(MenuData &menuData) {               // rozmiar planszy
    clear_console();
    signs();
    std::cout << "Wybierz szerokosc planszy(max 50): ";
    menuData.set_size_x();
    while (menuData.get_size_x() > 50) {
        signs();
        std::cout << "Wybrano za duza szerokosc planszy, podaj poprawna(max 50): ";
        menuData.set_size_x();
    }
    signs();
    std::cout << "Wybierz wysokosc planszy(max 50): ";
    menuData.set_size_y();
    while (menuData.get_size_y() > 50) {
        signs();
        std::cout << "Wybrano za duza wysokosc planszy, podaj poprawna(max 50): ";
        menuData.set_size_y();
    }
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
    menuData.print_board_chars_map();
    signs();
    std::cout << "Wybierz rodzaj planszy: ";
    menuData.set_board();
    std::cout << "Wybrales plansze " << menuData.get_board_chars(menuData.get_board()) << std::endl;
    menu_wait();
}

void exit_game() {                                  // opuszczanie menu
    signs();
    std::cout << "Do zobaczenia!" << std::endl;
    std::cout << "Zamykanie..." << std::endl;
    signs();
    normal_wait(2);
}