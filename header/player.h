#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>

#include "board.h"
#include "player.h"

class Player
{
private:
    char mark;
    std::string name;

public:
    Player();
    void setMark(char mark);
    void setName(std::string name);
    char getMark();
    std::string getName();
    friend bool TicTacToe::isGameOver(Board& gameBoard,Player& playerObj);
    friend bool TicTacToe::isOccupied(int boardNum, Board& gameBoard);
    ~Player();
};

#endif // PLAYER_H_INCLUDED
