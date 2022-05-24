#include <unistd.h>
#include "game.hpp"
#include <unistd.h>

void end_game(MenuData& menuData){
    clear_console();
    signs();
    std::cout << "                     KONIEC GRY!" << std::endl;
    signs();
    sleep(1);
    clear_console();
    menu_wait();
    menu(menuData);
}

void board(const Snake& snake, const MenuData& menuData, Fruit& fruit){
        COORD snake_pos = snake.snake_get_position();

        menuData.print_score();

        for(int i = 0; i < menuData.get_size_y(); i++)
        {
            std::cout << "\t\t" + menuData.get_board_chars(menuData.get_board());
            for(int j = 0; j < menuData.get_size_x() - 2; j++)
            {
                if(i == 0 || i == menuData.get_size_y() - 1) std::cout << menuData.get_board_chars(menuData.get_board());

                else if(i == snake_pos.Y && j + 1 == snake_pos.X) std::cout << '0';
                else if(i == fruit.fruit_get_position().X && j+1 == fruit.fruit_get_position().Y) std::cout << '@';

                else
                {
                    bool isBodyPart = false;
                    for(int k = 0; k < snake.get_body_size() - 1; k++)
                    {
                        if(i == snake.get_body_elem(k).Y && j + 1 == snake.get_body_elem(k).X)
                        {
                            std::cout << 'o';
                            isBodyPart = true;
                            break;
                        }
                    }

                    if(!isBodyPart) std::cout << ' ';
                }
            }
            std::cout << menuData.get_board_chars(menuData.get_board()) + "\n";
        }
}

void game(MenuData& menuData, Snake& snake, Fruit& fruit) {
    srand(time(NULL));

    bool game_over = false;   // warunek konca gry
    clear_console();
    fruit.fruit_generate(menuData);
    console_cursor(false);

    while(!game_over){
        board(snake, menuData, fruit);
        if(kbhit())
        {
            switch(getch())
            {

                case 'w': snake.snake_direction('u'); break;
                case 'a': snake.snake_direction('l'); break;
                case 's': snake.snake_direction('d'); break;
                case 'd': snake.snake_direction('r'); break;
            }
        }

        if(snake.snake_collided(menuData)) game_over = true;

        if(snake.snake_eaten(fruit))
        {
            fruit.fruit_generate(menuData);
            snake.snake_grow();
            menuData.score_add();
        }

        snake.snake_move();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
        usleep(500);
    }
    end_game(menuData);
}