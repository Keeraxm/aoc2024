#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> split(string s, string delimiter){
    vector<string> tokens;
    int left = 0, right = 0;
    while(right < s.length()){
        if(s.substr(right, delimiter.length()) == delimiter){
            tokens.push_back(s.substr(left, right - left));
            right += delimiter.length();
            left = right;
        }
        else{
            right++;
        }
    }
    tokens.push_back(s.substr(left, right));

    return tokens;
}

int part_one(vector<int> left, vector<int> right){
    int tot_dis = 0;
    while(left.size() != 0){
        vector<int>::iterator min_left = min_element(left.begin(), left.end());
        vector<int>::iterator min_right = min_element(right.begin(), right.end());

        tot_dis += abs(*min_left - *min_right);

        left.erase(left.begin() + distance(left.begin(), min_left));
        right.erase(right.begin() + distance(right.begin(), min_right));
    }
    return tot_dis;
}

int part_two(vector<int> left, vector<int> right){
    int tot = 0;
    int count = 0;
    for(auto i : left){
        count = 0;
        for(auto j : right){
            if( i == j){
                count++;
            }
        }
        tot += i*count;
    }
    return tot;
}

int main(){
    string line;
    string delimiter = "   ";
    
    vector<string> line_split;
    vector<int> left;
    vector<int> right;
    
    int itr = 0;
    
    ifstream f("1.txt");
    while(getline(f, line)){
        line_split = split(line, delimiter);
        left.push_back(stoi(line_split[0]));
        right.push_back(stoi(line_split[1]));
    }
    f.close();
    cout << part_one(left, right) << endl;
    cout << part_two(left, right);
    return 0;
}