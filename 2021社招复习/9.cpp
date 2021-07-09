/*
寻找一个二维数组里是否含有一个整数
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
        bool tmp(vector<vector<int>> map, int i, int j, int val) {
            if(map[i][j] == val) {
                return true;
            }

            if(map[i][j] < val && j < map[i].size()) {
                return tmp(map, i, j+1, val);
            }
        }
    pubic:
        bool Solve(vector<vector<int>> &map, int val) {
            for(int i = 0; i < map.size(); ++i) {
                if(tmp(map, i, 0, val)) return true;
            }

            return false;
        }

};