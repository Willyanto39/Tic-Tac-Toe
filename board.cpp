#include "header/board.h"

Board::Board()
{
    for(int i = 0; i < boardSize; i++)
    {
        board[i/3][i%3] = '1' + i;
    }
}

void Board::changeBoard(int boardNum, char mark)
{
    board[(boardNum-1)/3][(boardNum-1)%3] = mark;
}

void Board::display()
{
    for(int i = 0; i < boardSize; i++)
    {
        if(i % 3 == 1)
        {
            std::cout << "|" << board[i/3][i%3] << "|";
        }
        else if(i % 3 == 2)
        {
            std::cout << board[i/3][i%3];
        }
        else
        {
            std::cout << "\t" << board[i/3][i%3];
        }

        if( (i + 1) % 3 == 0)
        {
            std::cout << std::endl;
            std::cout << "\t-+-+-" << std::endl;
        }
    }
}

Board::~Board()
{

}


