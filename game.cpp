#include "game.h"

Game::Game()
{
    makeStartingBoard();
    current_player_ = 1;
    playGame();
}

void Game::makeStartingBoard(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            game_board_[i][j] = ' ';
        }
    }
}

void Game::playGame(){
    std::cout<<"Welcome to Connect Four!"<<std::endl;
    while(gameOver()){
        takeTurn();
        if(current_player_ == 1){
            current_player_ = 2;
        }else{
            current_player_ = 1;
        }
    }
    printBoard();
    if(current_player_ == 0){
        std::cout<<"Nobody wins!"<<std::endl;
    }else{
        if(current_player_ == 1){
            current_player_ = 2;
        }else{
            current_player_ = 1;
        }
        std::cout<<"Player "<<current_player_<<" wins!"<<std::endl;
    }
}

void Game::takeTurn(){
    std::string input;
    int numCol;
    printBoard();

    do{
        input = "";
        std::cout<<"Player "<<current_player_<<"'s turn"<<std::endl;
        std::cout<<"Select a column to drop a connect four piece into"<<std::endl;
        getline(std::cin,input);
    }while(validMove(input));
    numCol = stoi(input);
    addPiece(numCol);
}

void Game::addPiece(int numCol){
    char piece;
    if(current_player_ == 1){
        piece = 'O';
    }else{
        piece = 'X';
    }
    for(int i = ROWS-1; i >= 0; i--){
        for(int j = COLS-1; j >= 0; j--){
            if(numCol == j && game_board_[i][j] != 'O' && game_board_[i][j] != 'X'){
                game_board_[i][j] = piece;
                return;
            }
        }
    }
}

void Game::printBoard(){
    for(int i = 0; i < COLS+1;i++){
        if(i == 0){
            std::cout<<"  ";
        }else{
            std::cout<<i-1<<" ";
        }
    }
    std::cout<<std::endl;

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS+1; j++){
            if(j == 0){
                std::cout<<i<<" ";
            }else{
                std::cout<<game_board_[i][j-1]<<" ";
            }
        }
        std::cout<<std::endl;
    }

}

bool Game::validMove(std::string input){

    if(input.empty())
    {
        std::cout<<"Input is empty"<<std::endl;
        return true;
    }
    for(int i = 0; i < input.length();i++){
        if(!isdigit(input[i])){
            std::cout<<"Input is not an integer"<<std::endl;
            return true;
        }
    }
    int num = stoi(input);
    if(num < 0 || num > COLS){
        std::cout<<"Out of bounds"<<std::endl;
        return true;
    }
    for(int i = 0; i < 1; i++){
        for(int j = 0; j < COLS; j++){
            if(j == num && (game_board_[i][j] == 'O' || game_board_[i][j] == 'X')){
                std::cout<<"Column is full"<<std::endl;
                return true;
            }
        }
    }
    return false;
}

bool Game::gameOver(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(game_board_[i][j]  == 'O'){
                if(game_board_[i][j+1] == 'O' && game_board_[i][j+2] == 'O' && game_board_[i][j+3] == 'O' && j+3 <=COLS){
                    return false;
                }if(game_board_[i][j-1] == 'O' && game_board_[i][j-2] == 'O' && game_board_[i][j-3] == 'O' && j-3 >= COLS){
                    return false;
                }if(game_board_[i+1][j] == 'O' && game_board_[i+2][j] == 'O' && game_board_[i+3][j] == 'O' && i+3 <= ROWS){
                    return false;
                }if(game_board_[i-1][j] == 'O' && game_board_[i-2][j] == 'O' && game_board_[i-3][j] == 'O' && i-3 >= ROWS){
                    return false;
                }
            }
            if(game_board_[i][j] == 'X'){
                if(game_board_[i][j+1] == 'X' && game_board_[i][j+2] == 'X' && game_board_[i][j+3] == 'X' && j+3 <=COLS){
                    return false;
                }if(game_board_[i][j-1] == 'X' && game_board_[i][j-2] == 'X' && game_board_[i][j-3] == 'X' && j-3 >= COLS){
                    return false;
                }if(game_board_[i+1][j] == 'X' && game_board_[i+2][j] == 'X' && game_board_[i+3][j] == 'X' && i+3 <= ROWS){
                    return false;
                }if(game_board_[i-1][j] == 'X' && game_board_[i-2][j] == 'X' && game_board_[i-3][j] == 'X' && i-3 >= ROWS){
                    return false;
                }
            }
        }
    }
    int drawCheck = 0;
    for(int i = 0; i < 1; i++){
        for(int j = 0; j < COLS; j++){
            if(game_board_[i][j] == 'O' || game_board_[i][j] == 'X'){
                drawCheck++;
            }
        }
    }
    if(drawCheck == 7){
        current_player_ = 0;
        return false;
    }
}

