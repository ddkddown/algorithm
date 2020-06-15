#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        
        string ans = strs[0];
        for(int i = 1; i < strs.size(); ++i){
            int j = 0;
            while((j < ans.length()) && (j < strs[i].length()) && ans[j] == strs[i][j]) ++j;
            if(0 == j){
                return "";
            }
            ans = ans.substr(0,j);
        }

        return ans;
    }
};