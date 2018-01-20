#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

#define NUMBER_OF_PLAYERS 2
#define MAXIMUM_NAME_LENGTH 30

#include <iostream>

#include "board.h"
#include "mark.h"
#include "player.h"

class TicTacToe
{
private:
    int turnCount;
    bool gameIsWon;
    bool gameIsDrawn;

public:
    TicTacToe();
    void incrementTurnCount();
    bool isDraw();
    bool isWon(Board& gameBoard, Player& playerObj);
    bool playAgain();
    int togglePlayer(int turn);
    bool checkHorizontal(Board& gameBoard);
    bool checkVertical(Board& gameBoard);
    bool checkDiagonal(Board& gameBoard);
    bool isAnOccupiedSquare(int boardNum, Board& gameBoard);
    bool isAValidMove(int boardNum, Board& gameBoard);
    bool checkCharacter(char ch1, char ch2, char ch3);
    void showWinner(Player& player);
    bool getGameIsWon();
    bool getGameIsDrawn();
    void resetGame();
    ~TicTacToe();
};


#endif // TICTACTOE_H_INCLUDED
