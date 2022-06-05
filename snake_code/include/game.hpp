#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include "snake.hpp"
#include "fruit.hpp"
#include <conio.h>

void board(const Snake &snake, const MenuData &menuData, Fruit &fruit);         //!wyswietlanie planszy

void game(MenuData &menuData, Snake &snake, Fruit &fruit);                      //!obsluga gry

void instructions_game();                                                       //!Do dodania: wyswietlanie zasad gry i instrukcji

void end_game(MenuData &menuData);                                              //!koniec gry - warunek

int game_main(MenuData &menuData);


#endif //SNAKE_GAME_HPP
