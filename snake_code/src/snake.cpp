#include "snake.hpp"

Snake::Snake(COORD position, const MenuData& menuData) {
    this->position_ = position;
    this->velocity_ = menuData.get_diff();

    direction_ = 'n';
    length_ = 1;

    body_.push_back(position);
}

bool Snake::snake_eaten(COORD food) {
    if (position_.X == food.X && position_.Y == food.Y)
        return true;
    else
        return false;
}

bool Snake::snake_collided(const MenuData& menuData) {
    if (position_.X < 1 || position_.X > menuData.get_size_x() - 2 || position_.Y < 1 ||
        position_.Y > menuData.get_size_y() - 2)
        return true;
    for (int i = 0; i < length_ - 1; i++) {
        if (position_.X == body_[i].X && position_.Y == body_[i].Y)
            return true;
    }
    return false;
}

//void Snake::snake_move()            //porusdzanie wezem
//{
  //  switch(dir)
   // {
     //   case 'u': pos.Y -= vel; break;
       // case 'd': pos.Y += vel; break;
       // case 'l': pos.X -= vel; break;
        //case 'r': pos.X += vel; break;
    //}

    //body.push_back(pos);
    //if(body.size() > len) body.erase(body.begin());
//}
