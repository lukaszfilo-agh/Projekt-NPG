#include <conio.h>
#include "menu.hpp"
#include "snake.hpp"
#include "game.hpp"
#include "fruit.hpp"

int main() {
    MenuData menuData; // obiekt przechowujacy dane menu
    welcome_message();
    menu(menuData);
    Snake snake({static_cast<SHORT>(menuData.get_size_x()/2), static_cast<SHORT>(menuData.get_size_y()/2)}, menuData);
    bool game_over = false;   // warunek konca gry
    Fruit fruit;
    fruit.fruit_generate(menuData);
    clear_console();
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

        if(snake.snake_eaten(fruit.fruit_get_position()))
        {
            fruit.fruit_generate(menuData);
            snake.snake_grow();
            menuData.score_add();
        }

        snake.snake_move();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }
    return 0;
}