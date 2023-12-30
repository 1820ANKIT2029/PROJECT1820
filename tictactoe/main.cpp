#include <iostream>
#include <string>
#include "helper.cpp"

using namespace std;

void menu();

int main(){
    string p1;
    string p2;
    int choose;

    while(1){
        menu();
        cout<<"Enter your Choice :- ";
        cin>>choose;

        if(choose == 1){
            cout<<"Player 1 (Nought O) :- ";
            getline(cin>>ws, p1);
            cout<<"Player 2 (Cross X) :- ";
            getline(cin>>ws, p2);
            TicTacToe game(p1, p2);
            game.run();
            game.winner();
        }
        else if(choose == 2){
            break;
        }
    }

    return(0);
}

void menu(){
    cout<<"Menu of Tic-tac-toe\n";
    cout<<"1. New game\n";
    cout<<"2. exit\n";
}