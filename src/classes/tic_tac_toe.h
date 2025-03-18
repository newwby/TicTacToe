#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include "player.h"

class TicTacToe {
    public:
        TicTacToe();
        ~TicTacToe();
        void displayBoard();
        bool makeMove(int row, int col, Player player);
        bool checkWin(Player player);
};

#endif
