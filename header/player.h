#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>

class Player
{
private:
    std::string name;
    char mark;

public:
    Player();
    void setMark(char playerMark);
    void setName(std::string name);
    char getMark();
    std::string getName();
    ~Player();
};

#endif // PLAYER_H_INCLUDED
