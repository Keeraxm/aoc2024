#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "../Kersplit.h"
using namespace std;

int part_one(vector<int> left, vector<int> right){
    int tot_dis = 0;
    
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for(int i = 0; i < left.size(); i++){
        tot_dis += abs(left[i] - right[i]);
    }

    return tot_dis;
}

int part_two(vector<int> left, vector<int> right){
    int tot = 0;
    map<int, int> count;
    
    for(int i = 0; i < right.size(); i++){
        count[right[i]]++;
    }
    for(int i = 0; i < left.size(); i++){
        tot += left[i] * count[left[i]];
    }
    return tot;
}

int main(){
    vector<int> left;
    vector<int> right;
    
    vector<string> split_line;
    string line;
    string delimiter = "   ";
    
    ifstream f("1.txt");
    while(getline(f, line)){
        split_line = ker_split_str(line, delimiter);
        left.push_back(stoi(split_line[0]));
        right.push_back(stoi(split_line[1]));
        
    }
    f.close();

    cout << part_one(left, right) << endl;
    cout << part_two(left, right);
    return 0;
}