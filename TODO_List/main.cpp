#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "csv_handle.cpp"
using namespace std;

void menu();

int main(){
    TASK_list database("todo.csv");
    int choose;
    while(1){
        menu();
        cout<<"Enter your choice :- ";cin>>choose;
        if(choose == 1){
            DATA x;
            x.DATE = time(0);
            x.status = 'N';

            cout<<"Task :- ";
            getline(cin>>ws, x.task);
            database.add_task(x);
        }
        else if (choose == 2){
            time_t t;char c;
            cout << "Time of task you went to update:- ";
            cin >> t;
            cout << "Update value (Y/N) --> ";
            cin >> c;
            database.update_status(t,c);
            cout << "DONE !!\n";
        }
        else if (choose == 3){
            time_t t;
            cout << "Time of task you went to remove:- ";
            cin >> t;
            database.remove_task(t);
            cout << "DONE !!\n";
        }
        else if (choose == 4){
            char c;
            cout << "Display (pending(N)/done(Y)) :- ";
            cin >> c;
            database.Display(c);
        }
        else if(choose == 5){
            database.save();
            break;
        }
    }

    return 0;
}

// Display menu to the user
void menu(){
    cout<<"1. ADD a task\n";
    cout<<"2. UPDATE task status\n";
    cout<<"3. REMOVE a task\n";
    cout<<"4. DISPLAY all task\n";
    cout<<"5. EXIT\n";
}
