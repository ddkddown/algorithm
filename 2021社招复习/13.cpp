/*
调整数组顺序来使得奇数位于偶数前面
*/
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    void adjustSituation(vector<int> &arr) {
        int i = 0;
        int j = arr.size()-1;

        while(i < j) {
            while(i < j && arr[i]%2 != 0) ++i;
            while(j > i && arr[j]%2 == 0) --j;

            swap(arr[i], arr[j]);
        }
    }
};

