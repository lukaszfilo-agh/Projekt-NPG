#include "snake.hpp"

Snake::Snake(COORD position, const MenuData& menuData) {
    this->position_ = position;
    this->velocity_ = menuData.get_diff();

    direction_ = 'n';
    length_ = 1;

    body_.push_back(position);
}

bool Snake::snake_eaten(const Fruit& fruit) {
    if (position_.X == fruit.fruit_get_position().X && position_.Y == fruit.fruit_get_position().Y)
        return true;
    else
        return false;
}

bool Snake::snake_collided(const MenuData& menuData) {
    if (position_.X < 1 || position_.X > menuData.get_size_x() - 2 || position_.Y < 1 ||
        position_.Y > menuData.get_size_y() - 2)
        return true;
    for (std::vector<COORD>::size_type i = 0; i < length_ - 1; i++) {
        if (position_.X == body_[i].X && position_.Y == body_[i].Y)
            return true;
    }
    return false;
}

void Snake::snake_move()            //porusdzanie wezem
{
    switch (direction_) {
        case 'u':
            position_.Y -= velocity_;
            break;
        case 'd':
            position_.Y += velocity_;
            break;
        case 'l':
            position_.X -= velocity_;
            break;
        case 'r':
            position_.X += velocity_;
            break;
    }

    body_.push_back(position_);

    if (body_.size() > length_) {
        body_.erase(body_.begin());
    }
}
