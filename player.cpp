#include "header/player.h"

Player::Player()
{
    mark = ' ';
}

void Player::setMark(char mark)
{
    this->mark = mark;
}

void Player::setName(std::string playerName)
{
    name = playerName;
}

char Player::getMark()
{
    return mark;
}

std::string Player::getName()
{
    return name;
}

Player::~Player()
{

}
