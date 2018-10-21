#ifndef GAME_H
#define GAME_H

#define ROWS 6
#define COLS 7

#include <time.h>
#include <vector>
#include <iostream>

class Game
{
public:
    Game();
    void makeStartingBoard();
    void playGame();
    void takeTurn();
    void addPiece(int numCol);
    void printBoard();
    bool validMove(std::string input);
    bool gameOver();
private:
    char game_board_[ROWS][COLS];
    int current_player_;
};

#endif // GAME_H
