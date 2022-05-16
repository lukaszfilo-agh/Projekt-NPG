#include "snake.hpp"

Snake::Snake(COORD position, int velocity)
{
    this->position_ = position;
    this->velocity_ = velocity;

    direction_ = 'n';
    lenght_ = 1;

    body_.push_back(position_);
}