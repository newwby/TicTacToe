
#include "main.h"
#include "src/classes/player.h"
#include "src/classes/tic_tac_toe.h"
// for sleep
#include <windows.h>

using namespace std;

int main()
{

    TicTacToe game;
    Player currentPlayer = Player::X;

    const int MAX_MOVES = 9;

    int row = 0;
    int col = 0;

    int total_moves = 0;

    bool game_active = true;
    bool input_valid = false;

    while (game_active) {
        row = 0;
        col = 0;

        while (!input_valid) {

            // reset board
            // cmd only, no handling for linux
            system("cls");
            row = 0;
            col = 0;

            // draw the board
            game.displayBoard();

            // handle ties
            if (total_moves == MAX_MOVES) {
                cout << "It's a draw!\n";
                game_active = false;
                break;
            }
            else {
                // Handle input for making a move
                cout << "Player " << ((currentPlayer == Player::X) ? 'X' : 'O') << ", enter row (between 1 & 3): ";
                cin >> row;
                cout << "Player " << ((currentPlayer == Player::X) ? 'X' : 'O') << ", enter column (between 1 & 3): ";
                cin >> col;

                // Validate input, make move if successful else go back to the start of the loop
                try {
                    if ((row >= 1) && (row <= 3) && (col >= 1) && (col <= 3)) {

                        // Handle player making a move/if they've won or made an invalid move
                        // Need to convert from human readable (1-3) to array index (0-2)
                        if (game.makeMove(row - 1, col - 1, currentPlayer)) {
                            total_moves++;
                            if (game.checkWin(currentPlayer)) {
                                // cmd only
                                system("cls");
                                game.displayBoard();
                                cout << "Player " << ((currentPlayer == Player::X) ? 'X' : 'O') << " wins!\n";
                                game_active = false;
                                break;
                            }
                            // Switch player after making move (if valid and doesn't cause victory)
                            currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
                        }
                        else {
                            cout << "Invalid move. Try again.\n";
                        }

                    }
                    else {
                        //TODO add row/col to error
                        string error_message = "Invalid input!";
                        throw(error_message);
                    }
                }
                catch (string error_string) {
                    cout << error_string;
                    // Clear the invalid input
                    cin.clear();
                    cin.ignore(10000, '\n');
                    Sleep(1000);
                }

            }


        };





    };

}