#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> m;
        for(auto i : nums){
            m[i] += 1;
        }

        int ret = 0;
        for(auto i = m.begin(); i != m.end(); ++i){
            if(i->second > 1){
                ret += (i->second * (i->second-1)) / 2;
            }
        }

        return ret;
    }
};