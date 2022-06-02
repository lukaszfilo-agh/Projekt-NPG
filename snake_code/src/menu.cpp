#include <unistd.h>
#include "menu.hpp"
#include "universal.hpp"
#include "menu_map.cpp"

// PONIZEJ FUNKCJE DO OBSLUGI MENU W KOLEJNOSCI UZYCIA

void menu(MenuData& menuData) {
    int choice = 0;
    while (choice != 1 && choice != 8) {
        menu_display(menuData);                    //!wyswietlanie menu
        std::cout << "Wybierz opcje z menu: ";
        choice = read<int>();
        if (choice == 2) {
            select_difficulty_level(menuData);     //!funcja modyfikujaca obiekt w klasie (zmieniajaca opcje)
        } else if (choice == 3) {
            select_snake_name(menuData);           //!funcja modyfikujaca obiekt w klasie (zmieniajaca opcje)
        } else if (choice == 4) {
            select_snake_color(menuData);          //!funcja modyfikujaca obiekt w klasie (zmieniajaca opcje)
        } else if (choice == 5) {
            select_background_color(menuData);     //!funcja modyfikujaca obiekt w klasie (zmieniajaca opcje)
        } else if (choice == 6) {
            select_size(menuData);
        } else if (choice == 7) {
            select_board(menuData);
        } else if (choice < 1 ||
                   choice > 8) {                   //!podanie złej opcji konczy sie przeladowaniem menu
            clear_console();
            signs();
            std::cout << "Podano nieznana opcje!" << std::endl;
            signs();
            menu_wait();
        }
    }
    if (choice == 1) {   // warunek rozpoczecia gry
        clear_console();
        menuData.set_game_end(false);
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
        menu_exit(menuData);
    }
}

void instructions_menu(){
    clear_console();
    std::cout << std::endl << "Za chwile twoim oczom ukaze sie menu..." << std::endl;
    sleep(2);
    clear_console();
    std::cout << std::endl << "Ale zanim do tego przejdziemy musisz poznac pare zasad jego obslugi: " << std::endl;
    sleep(3);
    clear_console();
    std::cout << std::endl <<"1. wybieraj opcje menu za pomoca cyfr od 1 - 8 potwierdzajac swoj wybor klawiszem Enter;" << std::endl;
    sleep(3);
    std::cout << std::endl << "2. po wybraniu opcji od 2 - 7 (bez 3) program poprosi Cie o wybranie jednej opcji z podanych odpowiednim klawiszem," << std::endl <<
                 "po dokonaniu wyboru, potwierdz go klikajac Enter; " << std::endl;
    sleep(3);
    std::cout << std::endl << "3. po wybraniu opcji 3, gra poprosi Cie o wprowadzenie dowolnej nazwy swojego Snake'a. Po wpisaniu swojej nazwy" << std::endl <<
                 "zatwierdz ja klikajac klawisz Enter;"<< std::endl;
    sleep(3);
    std::cout << std::endl << "4. po wybraniu opcji 1 rozpoczniesz nowa gre z domyslnymi ustawieniami (kazde z nich zostanie Ci wyswietlona przed" << std::endl << "rozpoczeciem gry), natomiast" <<
                 "po wyborze opcji 8 - opuscisz gre a jesli juz grales to zostanie Ci wyswietlony twoj dotychczasowy wynik." << std::endl << std::endl;

    normal_wait(3);
}


void menu_display(MenuData& menuData) {                             //!wyswietlanie opcji w menu
    clear_console();
    signs();
    std::cout << "                 ===MENU GLOWNE===" << std::endl;
    menuData.print_menu_text();
    signs();
}

void select_difficulty_level(MenuData& menuData) {                  //!obsluguje wybor poziomu trudnosci
    clear_console();
    signs();
    std::cout << "Dostepne poziomy:" << std::endl;
    menuData.print_background_diff_map();
    signs();
    std::cout << "Wybierz poziom trudnosci: ";
    menuData.set_diff();
    clear_console();
    signs();
    std::cout << "Wybrales poziom " << menuData.get_diff_map(menuData.get_diff()) << "!" << std::endl;
    signs();
    menu_wait();
}

void select_snake_name(MenuData& menuData) {                        //!obsluguje wybor nazwy weza
    clear_console();
    signs();
    std::cout << "Podaj nazwe swojego weza: ";
    menuData.set_snake_name();
    clear_console();
    signs();
    std::cout << "Twoj waz to: " << menuData.get_snake_name() << "!" << std::endl;
    signs();
    menu_wait();
}

void select_snake_color(MenuData& menuData) {                       //!obsluguje wybor koloru weza
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

void select_background_color(MenuData& menuData) {                   //!obsluguje wybor koloru tla
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

void select_size(MenuData& menuData) {                               //!rozmiar planszy
    clear_console();
    signs();
    std::cout << "Wybierz szerokosc planszy(max 60): ";
    menuData.set_size_x();
    while (menuData.get_size_x() > 60) {
        signs();
        std::cout << "Wybrano za duza szerokosc planszy, podaj poprawna(max 60): ";
        menuData.set_size_x();
    }
    signs();
    std::cout << "Wybierz wysokosc planszy(max 30): ";
    menuData.set_size_y();
    while (menuData.get_size_y() > 30) {
        signs();
        std::cout << "Wybrano za duza wysokosc planszy, podaj poprawna(max 30): ";
        menuData.set_size_y();
    }
    clear_console();
    signs();
    std::cout << "Wybrales rozmiar: " << menuData.get_size_x() << " X " << menuData.get_size_y() << std::endl;
    signs();
    menu_wait();
}

void select_board(MenuData& menuData) {                              //!wybor mapy
    clear_console();
    signs();
    std::cout << "Dostepne plansze: " << std::endl;
    menuData.print_board_chars_map();
    signs();
    std::cout << "Wybierz rodzaj planszy: ";
    menuData.set_board();
    clear_console();
    std::cout << "Wybrales plansze " << menuData.get_board_chars(menuData.get_board()) << std::endl;
    signs();
    menu_wait();
}

void menu_exit(MenuData& menuData) {                                 //!opuszczanie menu
    clear_console();
    signs();
    std::cout << "              Twoj koncowy wynik to: " << menuData.get_score() << std::endl;
    signs();
    sleep(2);
    clear_console();
    signs();
    std::cout << "Do zobaczenia!" << std::endl;
    std::cout << "Zamykanie..." << std::endl;
    signs();
    sleep(2);
}

