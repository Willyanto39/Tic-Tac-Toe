#include <iostream>
#include "header/board.h"
#include "header/player.h"
#include "header/tictactoe.h"
#include <cstdlib>
#include <ctime>
#include <string>

int main()
{
    srand(time(NULL));

    Player players[2];
    std::string playerName[2];

    //Prompts players to input their name
    for(int k = 0; k < 2; k++)
    {
        do
        {
            std::cout << "Input player" << k+1 << " name [1 - 10 character]: ";
            std::getline(std::cin,playerName[k]);
        }while(playerName[k].length() < 1 || playerName[k].length() > 10);

        players[k].setName(playerName[k]);
    }

    while(true)
    {
        //randomize player's turn
        int whoseTurn = rand()%2 + 1;

        TicTacToe tictactoe;
        Board gameBoard;

        while(!tictactoe.isDraw())
        {
            players[0].setMark('O');
            players[1].setMark('X');
            int spot;

            std::cout << std::endl;
            gameBoard.display();

            do
            {
                std::cout << "\nIt's ";

                //If player's name ends with 's'
                if(players[whoseTurn-1].getName().find("s") == players[whoseTurn-1].getName().length()-1)
                {
                    std::cout << players[whoseTurn-1].getName() << "' turn.";
                }
                else
                {
                    std::cout << players[whoseTurn-1].getName() << "'s turn.";
                }

                std::cout << " Input a number [1 - 9]: ";

                std::cin >> spot;
                std::cin.sync();
                std::cin.clear();
            }while(spot < 0 || spot > 9 || !tictactoe.isOccupied(spot,gameBoard));

            gameBoard.changeBoard(spot,players[whoseTurn-1].getMark());
            tictactoe.incrementTurn();

            if(tictactoe.isGameOver(gameBoard,players[whoseTurn-1]))
            {
                break;
            }
            else
            {
                whoseTurn = tictactoe.togglePlayer(whoseTurn);
            }

        }

        whoseTurn = tictactoe.togglePlayer(whoseTurn);

        if(!tictactoe.playAgain())
        {
            break;
        }
    }

    return 0;
}
