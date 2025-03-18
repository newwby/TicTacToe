// CPP Demo Project.cpp : Defines the entry point for the application.
//

#include "main.h"
#include "src/classes/player.h"
#include "src/classes/tic_tac_toe.h"

using namespace std;

int main()
{

    TicTacToe game;
    Player currentPlayer = Player::X;

    int row = 0;
    int col = 0;
    cout << "---\nHello world!\n---";

    // Demo calls
    game.displayBoard();
    game.makeMove(row, col, currentPlayer);
}
