#include <iostream>
#include "tic_tac_toe.h"
#include "player.h"

TicTacToe::TicTacToe() {
    board = new char* [3];
    for (int i = 0; i < 3; ++i) {
        board[i] = new char[3] { ' ', ' ', ' ' };
    }
}

TicTacToe::~TicTacToe() {
    for (int i = 0; i < 3; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

void TicTacToe::displayBoard() {
    std::cout << "\n";
    // draw column indicators
    std::cout << "     1   2   3 \n\n";
    // draw column
    for (int i = 0; i < 3; ++i) {
        // offset row from edge and draw row indicators
        std::cout << " " << i+1 << "   ";
        // draw row
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            // column separators after character unless last
            if (j < 2) std::cout << " | ";
        }
        // only new line after row is complete
        std::cout << "\n";
        // row separator after all column characters, unless last row
        if (i < 2) std::cout << "     - - - - -\n";
    }
    std::cout << "\n";
}

bool TicTacToe::makeMove(int row, int col, Player player) {
    std::cout << "Making a move at (" << row << ", " << col << ") for player " << (player == Player::X ? "X" : "O") << "\n";
    return true;
}

bool TicTacToe::checkWin(Player player) {
    std::cout << "Checking for a win...\n";
    return false;
}
