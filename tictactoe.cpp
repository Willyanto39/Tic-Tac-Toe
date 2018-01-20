#include "header/tictactoe.h"

TicTacToe::TicTacToe()
{
    resetGame();
}

bool TicTacToe::isDraw()
{
    if(turnCount == BOARD_CELLS)
    {
        std::cout << "\n\tIt's a draw\n" << std::endl;
        gameIsDrawn = true;
        return true;
    }

    return false;
}

bool TicTacToe::isAnOccupiedSquare(int boardNum, Board& gameBoard)
{
    //board square is occupied by either 'O' or 'X'
    if(gameBoard.getBoardSquare(boardNum) == 'O' || gameBoard.getBoardSquare(boardNum) == 'X')
    {
        return false;
    }

    return true;
}

bool TicTacToe::isAValidMove(int boardNum, Board& gameBoard)
{
    //user inputs invalid number
    if(boardNum > BOARD_CELLS - 1 || boardNum < 0)
    {
        return false;
    }

    return isAnOccupiedSquare(boardNum, gameBoard);
}

//asks the player for another game
bool TicTacToe::playAgain()
{
    char anotherGame;

    do{
        std::cout << "\nPlay Again [y/n]?";
        std::cin >> anotherGame;
        std::cin.sync();
        std::cin.clear();
    }while(anotherGame != 'Y' && anotherGame != 'y' && anotherGame != 'N' && anotherGame != 'n');

    if(anotherGame == 'Y' || anotherGame == 'y')
    {
        resetGame();
        return true;
    }

    return false;
}

int TicTacToe::togglePlayer(int turn)
{
    if(turn == O)
    {
        return X;
    }

    return O;
}

bool TicTacToe::checkCharacter(char ch1, char ch2, char ch3)
{
    if((ch1 == ch2) && (ch1 == ch3))
    {
        return true;
    }

    return false;
}

bool TicTacToe::checkDiagonal(Board& gameBoard)
{
   if(checkCharacter(gameBoard.getBoardSquare(0, 0), gameBoard.getBoardSquare(1, 1), gameBoard.getBoardSquare(2, 2)))
   {
       return true;
   }

   if(checkCharacter(gameBoard.getBoardSquare(0, 2), gameBoard.getBoardSquare(1, 1), gameBoard.getBoardSquare(2, 0)))
   {
       return true;
   }

   return false;
}

bool TicTacToe::checkHorizontal(Board& gameBoard)
{
    for(int i = 0; i < BOARD_DIMENSION; i++)
    {
       if(checkCharacter(gameBoard.getBoardSquare(i, 0), gameBoard.getBoardSquare(i, 1), gameBoard.getBoardSquare(i, 2)))
       {
           return true;
       }
    }

    return false;
}

bool TicTacToe::checkVertical(Board& gameBoard)
{
    for(int i = 0; i < BOARD_DIMENSION; i++)
    {
        if(checkCharacter(gameBoard.getBoardSquare(0, i), gameBoard.getBoardSquare(1, i), gameBoard.getBoardSquare(2, i)))
        {
            return true;
        }
    }

    return false;
}

bool TicTacToe::isWon(Board& gameBoard,Player& playerObj)
{
    if(checkDiagonal(gameBoard) || checkHorizontal(gameBoard) || checkVertical(gameBoard))
    {
        gameIsWon = true;
        return true;
    }

    return false;
}

void TicTacToe::showWinner(Player& player)
{
    std::cout << "\n\t" << player.getName() << " won\n" << std::endl;
}

void TicTacToe::incrementTurnCount()
{
    turnCount++;
}

bool TicTacToe::getGameIsDrawn()
{
    return gameIsDrawn;
}

bool TicTacToe::getGameIsWon()
{
    return gameIsWon;
}

void TicTacToe::resetGame()
{
    turnCount = 0;
    gameIsDrawn = gameIsWon = false;
}

TicTacToe::~TicTacToe()
{

}
