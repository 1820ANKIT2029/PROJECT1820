#pragma once

#include <iostream>
#include <unordered_map>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct DATA{
    time_t DATE;
    string task;
    char status;
};

DATA split(string a){
    DATA x;
    stringstream ss(a);
    string part1, part2, part3;

    getline(ss, part1, ',');
    getline(ss, part2, ',');
    getline(ss, part3);

    // Store the values in variables
    x.DATE = stoi(part1);
    x.status = part2[0];
    x.task = part3;

    return x;
}

class TASK_list{
    private:
    unordered_map<time_t, DATA> Values;
    string file_name;
    public:
    TASK_list(string filename){
        file_name = filename;
        fstream file(filename, ios::in);
        string line;
        DATA x;
        while(getline(file, line)){
            x = split(line);
            Values[x.DATE] = x;
        }
        file.close();
    }

    void add_task(DATA t){
        Values[t.DATE] = t;
    }

    void remove_task(time_t t){
        Values.erase(t);
    }

    void update_status(time_t t, char c){
        DATA x = Values[t];
        x.status = c;
        Values.erase(t);
        Values[t] = x;
    }

    void save(){
        fstream file(file_name, ios::out);
        for(auto [key, x]: Values){
            file << x.DATE << "," << x.status << "," << x.task << "\n";
        }
        file.close();
    }

    void Display(char c){
        for(auto [key, x]: Values){
            if(x.status == c){
                struct tm* task_time = localtime(&x.DATE);
                char buffer[80];
                strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", task_time);
                cout << buffer << "  " << x.status << "  "<< x.task <<"\n";
            }
        }
    }
};

