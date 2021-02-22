#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        int table[numCourses] = {-1};
        for(int i = 0; i < prerequisites.size(); ++i){
            auto tmp = prerequisites[i];
            int l = tmp[0];
            int r = tmp[1];
            if(table[r] == l) return false;
            while(table[r] != -1){
                r = table[r];
            }
            table[l] = r;
        }

        return true;
    }
};