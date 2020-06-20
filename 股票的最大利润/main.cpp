#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        if(prices.empty()){
            return 0;
        }
        
        int max = 0;
        vector<int> v;
        v.push_back(prices[0]);

        for(auto i = prices.begin(); i != prices.end(); ++i){
            if(*i == v.back()){
                continue;
            }

            while(!v.empty() && v.back() > *i){
                v.pop_back();
            }
            v.push_back(*i);

            if((*i - v[0]) > max){
                max = (*i - v[0]);
            }
        }

        return max;
    }
};
