#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for(auto &i : nums) {
            s.insert(i);
        }

        int longestStreak = 0;

        for(auto &i : nums) {
            if(!s.count(i-1)) {
                int currentStreak = 1;
                while(s.count(i+1)) {
                    ++i;
                    ++currentStreak;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
            
        }
        
        return longestStreak;

    }
};