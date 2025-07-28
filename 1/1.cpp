#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
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