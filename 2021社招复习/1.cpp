// 求数组集合
/*输入: nums1 = [1,2,2,1], nums2 = [2,2]

输出: [2,2]*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> &a, vector<int> &b) {
    map<int, int> m;
    for(auto &i : a) {
        m[i]++;
    }
    
    vector<int> ret;
    for(auto &j : b) {
        if(m[j]) {
            ret.push_back(j);
            m[j]--;
        }
    }

    return ret;
}


int main() {
    vector<int> a = {1,2,2,1}, b = {2,2};

    auto c = solution(a, b);

    for(auto &i : c) {
        cout<<i<<endl;
    }

    a = {4,9,5};
    b = {9,4,9,8,4};
    c = solution(a, b);
    for(auto &i : c) {
        cout<<i<<endl;
    }
    
}

