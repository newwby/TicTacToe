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
    std::cout << "Displaying the board...\n";
}

bool TicTacToe::makeMove(int row, int col, Player player) {
    std::cout << "Making a move at (" << row << ", " << col << ") for player " << (player == Player::X ? "X" : "O") << "\n";
    return true;
}

bool TicTacToe::checkWin(Player player) {
    std::cout << "Checking for a win...\n";
    return false;
}
