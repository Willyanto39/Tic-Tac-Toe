#include "header/board.h"

Board::Board()
{
    resetBoard();
}

void Board::changeBoard(int boardNum, char mark)
{
    board[boardNum / BOARD_DIMENSION][boardNum % BOARD_DIMENSION] = mark;
}

void Board::displayBoard()
{
    for(int i = 0; i < BOARD_DIMENSION; i++)
    {
           printBoardColumn(i);

           if(i < BOARD_DIMENSION - 1)
           {
               printSectionBetweenRow();
           }
    }
}

void Board::printBoardColumn(int row)
{
    std::cout << "\t " << board[row][0] << " | " << board[row][1] << " | " << board[row][2] << std::endl;
}

void Board::printSectionBetweenRow()
{
   std::cout << "\t---+---+---" << std::endl;
}

char Board::getBoardSquare(int boardNum)
{
    return board[boardNum / BOARD_DIMENSION][boardNum % BOARD_DIMENSION];
}

char Board::getBoardSquare(int row, int column)
{
    return board[row][column];
}

void Board::resetBoard()
{
    for(int i = 0; i < BOARD_CELLS; i++)
    {
        board[i / BOARD_DIMENSION][i % BOARD_DIMENSION] = '1' + i;
    }
}

Board::~Board()
{

}


