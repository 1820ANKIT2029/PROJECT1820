#include <iostream>
#include "helper.cpp"
#include "pattern.cpp"  // all the initial state store in this file

using namespace std;

int main(){
    // change array name for different patterns
    int size = sizeof(Ankit_kumar[0]);

    char **a;
    a = new char*[size];
    for(int i=0; i<size; i++){
        a[i] = new char[size];
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            a[i][j] = Ankit_kumar[i][j]; // change array name for different patterns
        }
    }
    GameOfLife area38(a, size-2);
    area38.run();

    for(int i=0; i<size; i++){
        delete[] a[i];
    }
    delete[] a;
}
