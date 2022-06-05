#include "menu.hpp"
#include "universal.hpp"


// wypelnienie map

const std::map<int, std::string> MenuData::menu_text_ = {{1, "Nowa Gra"},               //!mapowanie tekstu w menu
                                                         {2, "Poziom Trudnosci"},
                                                         {3, "Nazwa weza"},
                                                         {4, "Kolor weza"},
                                                         {5, "Kolor tla"},
                                                         {6, "Rozmiar planszy"},
                                                         {7, "Rodzaj planszy"},
                                                         {8, "Wyjdz z gry"}};

const std::map<int, std::string> MenuData::diff_map_ = {{1, "Latwy"},                   //!mapowanie poziomu trudnosci
                                                        {2, "Sredni"},
                                                        {3, "Trudny"}};

const std::map<int, std::string> MenuData::snake_colors_ = {{1, "bialy"},               //!mapowanie kolorow weza
                                                            {2, "zielony"},
                                                            {3, "niebieski"},
                                                            {4, "pomaranczowy"}};

const std::map<int, std::string> MenuData::background_colors_ = {{1, "czarny"},         //!mapowanie kolorow tla
                                                                 {2, "bialy"},
                                                                 {3, "rozowy"},
                                                                 {4, "brazowy"}};

const std::map<int, std::string> MenuData::board_chars_ = {{1, "#"},                    //!mapowanie rodzajow obramowania
                                                           {2, "$"},
                                                           {3, "*"},
                                                           {4, "&"}};



//wypisywanie map

void MenuData::print_menu_text() {
    for (auto const& pair: menu_text_) {
        std::cout << pair.first << ". " << pair.second << std::endl;
    }
}

void MenuData::print_background_diff_map() {
    for (auto const& pair: diff_map_) {
        std::cout << pair.first << ". " << pair.second << std::endl;
    }
}

void MenuData::print_snake_color_map() {
    for (auto const& pair: snake_colors_) {
        std::cout << pair.first << ". " << pair.second << std::endl;
    }
}

void MenuData::print_background_color_map() {
    for (auto const& pair: background_colors_) {
        std::cout << pair.first << ". " << pair.second << std::endl;
    }
}

void MenuData::print_board_chars_map() {
    for (auto const& pair: board_chars_) {
        std::cout << pair.first << ". " << pair.second << std::endl;
    }
}
