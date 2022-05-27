#include "game.hpp"
#include <ctime>

int game_main(MenuData& menuData) {
    while(menuData.get_game_end()) {
        menu(menuData);
        if (menuData.get_game_end()) {
            menuData.~MenuData();
            return 0;
        }
        else {
            Snake snake({static_cast<SHORT>(menuData.get_size_x() / 2), static_cast<SHORT>(menuData.get_size_y() / 2)},
                        menuData);
            Fruit fruit;
            game(menuData, snake, fruit);
            snake.~Snake();
            fruit.~Fruit();
        }
    }
    return 0;
}


void end_game(MenuData& menuData) {
    clear_console();
    signs();
    std::cout << "                     KONIEC GRY!" << std::endl;
    signs();
    normal_wait(1);
    clear_console();
    signs();
    std::cout << "Twoj wynik to: " << menuData.get_score() << "!" << std::endl;
    std::cout << "Gratulacje!!!" << std::endl;
    signs();
    menu_wait();
    clear_console();
}

void board(const Snake& snake, const MenuData& menuData, Fruit& fruit) {

    menuData.print_score();
    std::cout << fruit.get_position().X << "." << fruit.get_position().Y;

    for (int i = 0; i < menuData.get_size_y(); i++) {
        std::cout << "\t" + menuData.get_board_chars(menuData.get_board());
        for (int j = 0; j < menuData.get_size_x() - 2; j++) {
            if (i == 0 || i == menuData.get_size_y() - 1) {
                std::cout << menuData.get_board_chars(menuData.get_board());
            }

            else if (i == snake.get_position().Y && j + 1 == snake.get_position().X) {
                std::cout << '0';
            }
            else if (i == fruit.get_position().Y && j + 1 == fruit.get_position().X) {
                std::cout << '@';
            }

            else {
                bool isBodyPart = false;
                for (int k = 0; k < snake.get_body_size() - 1; k++) {
                    if (i == snake.get_body_elem(k).Y && j + 1 == snake.get_body_elem(k).X) {
                        std::cout << 'o';
                        isBodyPart = true;
                        break;
                    }
                }

                if (!isBodyPart) {
                    std::cout << ' ';
                }
            }
        }
        std::cout << menuData.get_board_chars(menuData.get_board()) + "\n";
    }
}

void game(MenuData& menuData, Snake& snake, Fruit& fruit) {
    srand(time(nullptr));
    clear_console();
    fruit.generate(menuData);
    console_cursor(false);

    while (!menuData.get_game_end()) {     // warunek konca gry
        board(snake, menuData, fruit);            // !!!!!!! gra konczy sie po pewnym czasie, mamy problem
        if (kbhit()) {                            // jak damy znowu nowa gre po przegranej to sie wyłącza
            switch (getch()) {
                case 'w':
                    snake.direction('u');
                    break;
                case 'a':
                    snake.direction('l');
                    break;
                case 's':
                    snake.direction('d');
                    break;
                case 'd':
                    snake.direction('r');
                    break;
            }
        }

        if (snake.collided(menuData)) {
            menuData.set_game_end(true);
        }

        if (snake.eaten(fruit)) {
            fruit.generate(menuData);
            snake.grow();
            menuData.score_add();
        }

        snake.move();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }
    end_game(menuData);
}