#include <iostream>
#include "header/board.h"
#include "header/player.h"
#include "header/tictactoe.h"
#include <cstdlib>
#include <ctime>
#include <string>

#define NUMBER_OF_NEW_LINES 50

int main()
{
    srand(time(NULL));

    Player player[NUMBER_OF_PLAYERS];

    TicTacToe ticTacToe;
    Board gameBoard;

    int playerOrder = rand() % NUMBER_OF_PLAYERS;
    char mark[NUMBER_OF_PLAYERS] = {'O', 'X'};

    for(int i = 0; i < NUMBER_OF_PLAYERS; i++)
    {
        std::string name;

        do
        {
            std::cout << "Enter player" << i + 1 << "'s name [max 30 characters]: ";
            std::getline(std::cin, name);
            std::cin.sync();
            std::cin.clear();
        }while(name.length() > MAXIMUM_NAME_LENGTH);

        player[i].setName(name);
    }

    //The game code
    do
    {
        do
        {
            for(int i = 0; i < NUMBER_OF_NEW_LINES; i++)
            {
                std::cout << "\n";
            }

            gameBoard.displayBoard();

            int input;

            do
            {
                std::cout << "\nIt is " << player[playerOrder].getName() << "'(s) turn." << std::endl;
                std::cout << "Enter a number [1 - " << BOARD_CELLS << "]: ";
                std::cin >> input;
            }while(!ticTacToe.isAValidMove(input - 1, gameBoard));

            gameBoard.changeBoard(input - 1, mark[playerOrder]);
            ticTacToe.incrementTurnCount();

            if(ticTacToe.isWon(gameBoard, player[playerOrder]))
            {
                ticTacToe.showWinner(player[playerOrder]);
                break;
            }

            ticTacToe.isDraw();
            playerOrder = ticTacToe.togglePlayer(playerOrder);
        }while(!ticTacToe.getGameIsDrawn() && !ticTacToe.getGameIsWon());

        gameBoard.displayBoard();
        gameBoard.resetBoard();
        ticTacToe.resetGame();

        //give the first turn to the player who lost the game
        ticTacToe.togglePlayer(playerOrder);
    }while(ticTacToe.playAgain());


    return 0;
}
