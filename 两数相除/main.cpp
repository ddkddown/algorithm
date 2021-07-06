#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
    vector<vector<char>> table = {{'0','0','0'}, {'a','b','c'},
        {'d','e','f'}, {'g','h','i'}, {'j','k','i'}, {'m','n','o'},
        {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}
    };
    
    set<string> ret;
    
    void combineLetter(string x, string& digits, int i){
        if(i >= digits.size()){
            ret.insert(x);
            return;
        }
        
        if('7' == digits[i]){
            combineLetter(x+table[6][0], digits, i++);
            combineLetter(x+table[6][1], digits, i++);
            combineLetter(x+table[6][2], digits, i++);
            combineLetter(x+table[6][3], digits, i++);
        }
        
        if('9' == digits[i]){
            combineLetter(x+table[8][0], digits, i++);
            combineLetter(x+table[8][1], digits, i++);
            combineLetter(x+table[8][2], digits, i++);
            combineLetter(x+table[8][3], digits, i++);
        }
        
        combineLetter(x+table[digits[i]-48][0], digits, i+1);
        combineLetter(x+table[digits[i]-48][1], digits, i+1);
        combineLetter(x+table[digits[i]-48][2], digits, i+1);
    }
public:
    vector<string> letterCombinations(string digits) {
        string a = "", b = "", c = "";
        combineLetter(a, digits, 1);
        combineLetter(b, digits, 1);
        combineLetter(c, digits, 1);
        
        vector<string> tmp;
        for (auto i = ret.begin(); i != ret.end(); ++i) {
            tmp.push_back(*i);
        }
        
        return tmp;
    }
};
