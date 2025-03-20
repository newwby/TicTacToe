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

// does not validate move this happens in main loop
bool TicTacToe::makeMove(int row, int col, Player player) {
    if (board[row][col] == ' ') {
        // symbol determined by player enum
        board[row][col] = (player == Player::X) ? 'X' : 'O';
        // move is made
        return true;
    }
    // spot already taken
    return false;
}

bool TicTacToe::checkWin(Player player) {
    // get symbol according to enum
    char symbol = (player == Player::X) ? 'X' : 'O';

    // Check rows and columns - if any row or column is filled iwth this players symbol, they win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true;
    }
    // player has not won yet
    return false;
}

