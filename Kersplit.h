#pragma once
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<std::string> ker_split_str(std::string s, std::string delimiter){
    std::vector<std::string> tokens;
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

std::vector<int> ker_split_int(std::string s, std::string delimiter){
    std::vector<int> tokens;
    int left = 0, right = 0;
    while(right < s.length()){
        if(s.substr(right, delimiter.length()) == delimiter){
            tokens.push_back(stoi(s.substr(left, right - left)));
            right += delimiter.length();
            left = right;
        }
        else{
            right++;
        }
    }
    tokens.push_back(stoi(s.substr(left, right)));

    return tokens;
}