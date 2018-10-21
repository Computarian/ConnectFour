#include "game.h"

int main(){
    std::string input;
    srand(time(nullptr));

    do{
        input = "";
        std::cout<<"1. Play Connect Four"<<std::endl;
        std::cout<<"2. Quit"<<std::endl;
        getline(std::cin, input);
        if(input == "1"){
            Game();
        }
    }while(input !="2");
}
