#include "snake.hpp"
#include "food.hpp"

std::string signs() {
    std::ostringstream oss;
    oss << "------------------------------------------------------" << std::endl;
    return oss.str();
}

void clear_console(){
    std::system("cls");
};

void wait() {
    sleep(1);
}

//void  err_check(std::function<std::string ()> func){
//    if(std::cin.fail()){
//        std::cin.clear();
//        std::cin.ignore();
//        std::cout << "Podana zła wartosc" << std::endl;
//       func();
//    }
//}

void menu_display(){
    clear_console();
    std::cout << signs() << "===MENU GLOWNE===" << std::endl;
    std::cout << "1. Nowa Gra" << std::endl;
    std::cout << "2. Poziom Trudnosci" << std::endl;
    std::cout << "3. Nazwa weza" << std::endl;
    std::cout << "4. Kolor weza" << std::endl;
    std::cout << "5. Kolor tla" << std::endl;
    std::cout << "6. Wyjdz z gry" << std::endl;
    std::cout << signs();
    std::cout << "Wybierz opcje z menu: ";
}

void exit_game() {
    std::cout << "Do zobaczenia!" << std::endl;
    std::cout << "Zamykanie...";
    wait();
}

int select_difficulty_level() {
    clear_console();
    std::cout << signs();
    std::cout << "Dostepne poziomy:" << std::endl;
    std::cout << "1. Latwy" << std::endl;
    std::cout << "2. Sredni" << std::endl;
    std::cout << "3. Trudny" << std::endl;
    std::cout << signs();
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
    wait();
    return poziom_trudnosci;
}

std::string select_snake_name() {
    clear_console();
    std::cout << "Podaj nazwe swojego weza: ";
    std::string nazwa_weza;
    std::cin >> nazwa_weza;
    //err_check(select_snake_name);
    std::cout << "Twoj waz to: " << nazwa_weza << std::endl;
    wait();
    return nazwa_weza;
}

std::string select_snake_color() {
    clear_console();
    std::string kolor;
    std::cout << signs();
    std::cout << "Dostepne kolory to:" << std::endl;
    std::cout << "- zielony," << std::endl;
    std::cout << "- czerwony," << std::endl;
    std::cout << "- niebieski," << std::endl;
    std::cout << "- pomaranczowy." << std::endl;
    std::cout << signs();
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
    wait();
    return kolor;
}
