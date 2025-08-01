#include <iostream>
#include <fstream>
#include <vector>
#include "../Kersplit.h"
#include <algorithm>
#include <iterator>
#include <chrono>
using namespace std;

bool check_increment(vector<int> report){
    int increment;

    for(int i = 0; i+1 < report.size(); i++){
        increment = abs(report[i] - report[i+1]);
        if((increment > 3) || (increment == 0)){
            return false;
        }
    }
    return true;
}

bool get_safe(vector<int> report){
    //Check if report is ascending
    if(is_sorted(report.begin(), report.end())){
        // Check if the level increments are in the correct range.
        if(check_increment(report)){ 
            return true;
        }
    }
    // Descneding checks.
    else{
        reverse(report.begin(), report.end());
        if(is_sorted(report.begin(), report.end())){
            if(check_increment(report)){ 
                return true; 
            }
        }
    }
    return false;
}


int part_one(vector<vector<int>> reports){
    int counter = 0;

    for (int i = 0; i < reports.size(); i++){
        if(get_safe(reports[i])){ 
            counter++;
        }
    }
    return counter;
}

int part_two(vector<vector<int>> reports){
    int counter = 0;
    vector<int> temp_report;

    for (int i = 0; i < reports.size(); i++){
        if(get_safe(reports[i])){
            counter++;
        }
        else{
            // Brute force remove each element one by one and test it :(.
            for(int j = 0; j < reports[i].size(); j++){
                temp_report = reports[i];
                temp_report.erase(temp_report.begin() + j);
                if(get_safe(temp_report)){
                    counter++;
                    break;
                }
            }
        }
    }
    return counter;
}

int main(){
    vector<vector<int>> reports;
    
    vector<int> split_line;
    string line;
    ifstream f("2.txt");
    while(getline(f, line)){
        split_line = ker_split_int(line, " ");
        reports.push_back(split_line);
    }
    f.close();

    cout << part_one(reports) << endl;
    cout << part_two(reports) << endl;

    return 0;
}