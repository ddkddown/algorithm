#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<int> merge(vector<int>& a, vector<int>& b){
        vector<int> ret;
        auto i = a.begin(), j = b.begin();
        while(i != a.end() && j != b.end()){
            if(*i > *j){
                ret.push_back(*j);
                ++j;
            }else{
                ret.push_back(*i);
                ++i;
            }
        }
        
        while(i != a.end()){
            ret.push_back(*i);
            ++i;
        }
        
        while(j != b.end()){
            ret.push_back(*j);
            ++j;
        }
        return ret;
    }
};

int main(){
    Solution a;
    vector<int>x = {1,3,5,7,9}, y = {2,4,6,8,10};
    auto ret = a.merge(x, y);
    for(auto i : ret){
        cout<<i;
    }
}
