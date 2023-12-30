#pragma once

#include <iostream>
#include <string>

using namespace std;

class TicTacToe{
    private:
    char board[3][3];
    string player1;  // nought
    string player2;  // cross
    int state_no;
    int input;
    char win_sym;

    public:
    TicTacToe(string p1, string p2){
        player1 = p1;
        player2 = p2;
        state_no = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                board[i][j] = 48 + 3*i + j;
            }
        }
    }

    void run(){
        bool a = false;
        while(!a){
            display_board();
            move();
            a = check_match();
        }
        display_board();
    }

    void move(){
        if(state_no%2 == 0){
            cout << player1 << " turn (O) :- ";
        }
        else{
            cout << player2 << " turn (X) :- ";
        }
        cin >> input;
        if(board[input/3][input%3] == 'X' || board[input/3][input%3] == 'O'){
            cout << "Invalid Move\n";
            return;
        }
        board[input/3][input%3] = (state_no%2 == 0)?'O':'X';
        state_no++;
    }

    bool check_match(){
        if(state_no >= 9){
            win_sym = 'D';
            return true;
        }
        for(int i=0; i<3; i++){
            if(board[i][0]==board[i][1] && board[i][0]==board[i][2]){
                win_sym = board[i][0];
                return true;
            }
            if(board[0][i]==board[1][i] && board[0][i]==board[2][i]){
                win_sym = board[0][i];
                return true;
            }
        }
        if(board[0][0]==board[1][1] && board[0][0]==board[2][2]){
                win_sym = board[0][0];
                return true;
            }
        if(board[0][2]==board[1][1] && board[0][2]==board[2][0]){
            win_sym = board[0][2];
            return true;
        }
        return false;
    }

    void winner(){
        if(win_sym == 'O'){
            cout << "Winner is " << player1 << "🎉\n";
        }
        else if(win_sym == 'X'){
            cout << "Winner is " << player2 << "🎉\n";
        }
        else{
            cout << "Draw between " << player1 << " and " << player2 << "\n";
        }
    }

    void display_board(){
        system("clear");
        cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<'\n';
        cout<<"----------\n";
        cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<'\n';
        cout<<"----------\n";
        cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<'\n';
    }

};