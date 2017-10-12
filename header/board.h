#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "tictactoe.h"

class Player;

class Board
{
private:
    char board[3][3];
    const static int boardSize = 9;

public:
    Board();
    void changeBoard(int boardNum,char mark);
    void display();
    friend bool TicTacToe::isGameOver(Board& gameBoard,Player& playerObj);
    friend bool TicTacToe::isOccupied(int boardNum, Board& gameBoard);
    ~Board();
};

#endif // BOARD_H_INCLUDED

#ifndef IOSTREAM_H_INCLUDED
#define IOSTREAM_H_INCLUDED
#include <iostream>
#endif // IOSTREAM_H_INCLUDED

