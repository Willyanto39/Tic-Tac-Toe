#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#define BOARD_DIMENSION 3
#define BOARD_CELLS BOARD_DIMENSION * BOARD_DIMENSION

#include <iostream>

#include "mark.h"

class Board
{
private:
    char board[BOARD_DIMENSION][BOARD_DIMENSION];

public:
    Board();
    void changeBoard(int boardNum, char mark);
    void displayBoard();
    char getBoardSquare(int boardNum);
    char getBoardSquare(int row, int column);
    void printBoardColumn(int row);
    void printSectionBetweenRow();
    void resetBoard();
    ~Board();
};

#endif // BOARD_H_INCLUDED

