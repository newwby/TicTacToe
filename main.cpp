
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
    
    bool game_active = true;
    bool input_valid = false;

    while (game_active) {
        row = 0;
        col = 0;

        while (!input_valid) {
            // cmd only
            system("cls");
            game.displayBoard();
            cout << "Player " << ((currentPlayer == Player::X) ? 'X' : 'O') << ", enter row (between 1 & 3): ";
            cin >> row;
            cout << "Player " << ((currentPlayer == Player::X) ? 'X' : 'O') << ", enter column (between 1 & 3): ";
            cin >> col;
            try {
                if ((row >= 1) && (row <= 3) && (col >= 1) && (col <= 3)) {
                    game.makeMove(row, col, currentPlayer);
                    cout << "\nMade move!\n";
                    input_valid = true;
                }
                else {
                    //TODO add row/col to error
                    string error_message = "Invalid input!";
                    throw(error_message);
                }
            }
            catch (string error_string) {
                cout << error_string;
                input_valid = true;
            }
        };
        




    };

    // Demo calls
    //game.displayBoard();
    //game.makeMove(row, col, currentPlayer);
    //game.checkWin(currentPlayer);

}
