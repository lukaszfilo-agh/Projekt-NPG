#include "game.hpp"
#include "fruit.hpp"

void board(const Snake& snake, const MenuData& menuData, const Fruit& fruit){
        COORD snake_pos = snake.snake_get_position();

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
                    for(int k = 0; k < snake.get_length() - 1; k++)
                    {
                        if(i == snake.snake_get_position().X && j + 1 == snake.snake_get_position().Y)
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