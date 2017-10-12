#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

class Player;

class Board;

class TicTacToe
{
private:
    int turn;

public:
    TicTacToe();
    int getTurn();
    void incrementTurn();
    bool isDraw();
    bool isGameOver(Board& gameBoard,Player& playerObj);
    bool checkBoard(char ch1, char ch2, char ch3);
    bool playAgain();
    int togglePlayer(int turn);
    bool isOccupied(int boardNum, Board& gameBoard);
    ~TicTacToe();
};


#endif // TICTACTOE_H_INCLUDED
