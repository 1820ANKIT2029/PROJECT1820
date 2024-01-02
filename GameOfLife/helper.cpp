#pragma once

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

#define SYM 'O' 

class GameOfLife{
    private:
    char **grid;        // current state
    char **next_grid;   // next state
    int size;

    public:
    GameOfLife(char** init_state, int s){
        size = s+2; // 2 more for boundary error hnadling
        grid = init_state;
    }

    ~GameOfLife(){
        for(int i=0; i<size; i++){
            delete[] grid[i];
        }
        delete[] grid;
    }

    void display(){
        system("clear");
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                cout << grid[i][j] << " ";
            }
            cout<<"\n";
        }
    }

    void new_state(){
        // 2d array structure
        next_grid = new char*[size];
        for(int i=0; i<size; i++){
            next_grid[i] = new char[size];
        }
        /*
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                next_grid[i][j] = ' ';
            }
        }
        */
       // improve version of above quoted code
        for(int i=0; i<size; i++){
            next_grid[0][i] = ' ';
            next_grid[size-1][i] = ' ';
            next_grid[i][0] = ' ';
            next_grid[i][size-1] = ' ';
        }
        

        int n;
        for(int i=1; i<size-1; i++){
            for(int j=1; j<size-1; j++){
                n = count_neighbour(i,j);
                if(n<2){
                    next_grid[i][j] = ' ';
                }
                else if(n==2){
                    next_grid[i][j] = grid[i][j];
                }
                else if(n==3){
                    next_grid[i][j] = SYM;
                }
                else{
                    next_grid[i][j] = ' ';
                }
            }
        }

        for(int i=0; i<size; i++){
            delete[] grid[i];
        }
        delete[] grid;

        grid = next_grid;
    }

    void run(){
        while(true){
            display();
            new_state();
            this_thread::sleep_for(chrono::milliseconds(400));
            /*if(cin.peek() != EOF){
                break;
            }*/
        }
    }

    // count neighbours
    /*
    Need improvement
    what if cell is at boundary --> Segmentation fault
    Problem solved by increasing 2d array size by 2
    */
    int count_neighbour(int i, int j){
        int sum = 0;
        if (grid[i-1][j-1] == SYM) sum++;
        if (grid[i-1][j] == SYM) sum++;
        if (grid[i-1][j+1] == SYM) sum++;

        if (grid[i][j-1] == SYM) sum++;
        if (grid[i][j+1] == SYM) sum++;

        if (grid[i+1][j-1] == SYM) sum++;
        if (grid[i+1][j] == SYM) sum++;
        if (grid[i+1][j+1] == SYM) sum++;

        return sum;
    }
    
};