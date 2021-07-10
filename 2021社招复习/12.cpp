/*
    矩阵中的深度优先搜索。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool GetCount(vector<vector<int>> &map, int &val, int i, 
                            int j, int &count, int &max) {
        ++count;
        if(count > max) {
            max = count;
        }

        if((i+1)< map.size() && map[i+1][j] != 0) {
            map[i+1][j] = 1;
            GetCount(map, val, i+1, j, count, max);
            map[i+1][j] = 0;
        }

        if((i-1) >= 0 && map[i-1][j] != 0) {
            map[i-1][j] = 1;
            GetCount(map, val, i+1, j, count, max);
            map[i-1][j] = 0;
        }
    }

public:
    int MaxCount(vector<vector<int>> &map, int val) {
        int count = 0;
        int max = 0;
        GetCount(map, val, 0, 0, count, max);
    }
};