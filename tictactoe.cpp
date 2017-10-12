#include "header/tictactoe.h"
#include "header/board.h"
#include "header/player.h"

TicTacToe::TicTacToe()
{
    turn = 0;
}

bool TicTacToe::isDraw()
{
    if(turn == 9)
    {
        std::cout << "It's a draw" << std::endl;
        return true;
    }

    return false;
}

//check if a square is already occupied by 'X' or 'O'
bool TicTacToe::isOccupied(int boardNum, Board& gameBoard)
{
    if(gameBoard.board[(boardNum-1)/3][(boardNum-1)%3] == 'X' || gameBoard.board[(boardNum-1)/3][(boardNum-1)%3] == 'O')
    {
        return false;
    }

    return true;
}

bool TicTacToe::playAgain()
{
    char anotherGame;

    do{
        std::cout << "Play Again [y/n]?";
        std::cin >> anotherGame;
        std::cin.sync();
        std::cin.clear();
    }while(anotherGame != 'Y' && anotherGame != 'y' && anotherGame != 'N' && anotherGame != 'n');

    if(anotherGame == 'Y' || anotherGame == 'y')
    {
        return true;
    }

    return false;
}

int TicTacToe::togglePlayer(int turn)
{
    if(turn == 1)
    {
        return 2;
    }

    return 1;
}

bool TicTacToe::checkBoard(char ch1, char ch2, char ch3)
{
    if((ch1 == ch2) && (ch1 == ch3))
    {
        return true;
    }

    return false;
}

bool TicTacToe::isGameOver(Board& gameBoard,Player& playerObj)
{
    //Check the column
    for(int i = 0; i < 3; i++)
    {
        if(checkBoard(gameBoard.board[i][0],gameBoard.board[i][1],gameBoard.board[i][2]))
        {
            std::cout << playerObj.getName() << " won." << std::endl;
            gameBoard.display();
            return true;
        }
    }

    //Check the row
    for(int i = 0; i < 3; i++)
    {
        if(checkBoard(gameBoard.board[0][i],gameBoard.board[1][i],gameBoard.board[2][i]))
        {
            std::cout << playerObj.getName() << " won." << std::endl;
            gameBoard.display();
            return true;
        }
    }

    //Check diagonals
    if(checkBoard(gameBoard.board[0][0],gameBoard.board[1][1],gameBoard.board[2][2]))
    {
        std::cout << playerObj.getName() << " won." << std::endl;
        gameBoard.display();
        return true;
    }

    //Check diagonals
    if(checkBoard(gameBoard.board[0][2],gameBoard.board[1][1],gameBoard.board[2][0]))
    {
        std::cout << playerObj.getName() << " won." << std::endl;
        gameBoard.display();
        return true;
    }

    return false;
}

int TicTacToe::getTurn()
{
    return turn;
}

void TicTacToe::incrementTurn()
{
    turn++;
}

TicTacToe::~TicTacToe()
{

}
