#include "snake.hpp"

Snake::Snake(COORD position, int velocity)
{
    this->position_ = position;
    this->velocity_ = velocity;

    direction_ = 'n';
    lenght_ = 1;

    body_.push_back(position);
}

bool Snake::snake_eaten(COORD food) {
    if(position_.X == food.X && position_.Y == food.Y)
        return true;
    else
        return false;
}