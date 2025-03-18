#include <iostream>
using namespace std;

#include "player.h"

class TicTacToe {
private:
    char** board;

public:
    // Constructor
    TicTacToe() {
        board = new char*[3];
        for (int i = 0; i < 3; ++i) {
            board[i] = new char[3]{ ' ', ' ', ' ' };
        }
    }

    // Destructor
    ~TicTacToe() {
        for (int i = 0; i < 3; ++i) {
            delete[] board[i];
        }
        delete[] board;
    }

    void displayBoard() {
        std::cout << "displayBoard // Hello World!" << std::endl;
    }

    bool makeMove(int row, int col, Player player) {
        std::cout << "makeMove!" << std::endl;
        return true;
    }

    bool checkWin(Player player) {
        std::cout << "checkWin!" << std::endl;
        return true;
    };
};