#include <unistd.h>
#include "snake.hpp"

Snake::Snake(COORD position, const MenuData &menuData) {         //konstruktor snake
    this->position_ = position;
    this->velocity_ = menuData.get_diff();

    direction_ = 'n';
    length_ = 1;

    body_.push_back(position);
}

bool Snake::collided(const MenuData &menuData) {                   //metoda sprawdzajaca czy snake wszedl w siebie albo obramowanie planszy
    if (position_.X < 1 || position_.X > menuData.get_size_x() - 2 || position_.Y < 1 ||
        position_.Y > menuData.get_size_y() - 2)
        return true;
    for (std::vector<COORD>::size_type i = 0; i < length_ - 1; i++) {
        if (position_.X == body_[i].X && position_.Y == body_[i].Y)
            return true;
    }
    return false;
}

bool Snake::eaten(const Fruit &fruit) {                             //metoda sprawdzajaca czy snake napotkal na owoc
    if (position_.X == fruit.get_position().X && position_.Y == fruit.get_position().Y)
        return true;
    else
        return false;
}

void Snake::move()            //poruszanie wezem
{
    switch (direction_) {
        case 'u':
            position_.Y -= velocity_;                               //zmiana kierunku w dół
            break;
        case 'd':
            position_.Y += velocity_;                               //zmiana kierunku w górę
            break;
        case 'l':
            position_.X -= velocity_;                               //zmiana kierunku w lewo
            break;
        case 'r':
            position_.X += velocity_;                               //zmiana kierunku w prawo
            break;
    }

    body_.push_back(position_);

    if (body_.size() > length_) {
        body_.erase(body_.begin());
    }
    usleep(20000);         //odczekanie 200 milisekund
}
