#include <iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n < 0){
            return 0;
        }
    
        if(1 == n || 0 == n){
            return 1;
        }
        
        if(2 == n){
            return 2;
        }

        long long a1 = 1, a2 = 2, count = 2;
        while(count++ < n){
            long long tmp = a2;
            a2 = a2 + a1;
            a1 = tmp;
        }

        return a2;
    }
};