// 求数组集合
/*输入: nums1 = [1,2,2,1], nums2 = [2,2]

输出: [2,2]*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//数组无序的情况
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

//数组有序的情况
vector<int> solution_2(vector<int> &a, vector<int> &b) {
    int i = 0, j = 0;
    vector<int> ret;

    while(1) {
        if(i >= a.size()) break;
        if(j >= b.size()) break;

        if(a[i] < b[j]) ++i;
        else if(a[i] > b[j]) ++j;
        else {
            ret.push_back(a[i]);
            ++i;
            ++j;
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
    cout<<"----------------"<<endl;

    a = {4,9,5};
    b = {9,4,9,8,4};
    c = solution(a, b);
    for(auto &i : c) {
        cout<<i<<endl;
    }
    cout<<"----------------"<<endl;
    
    a = {4,5,6,7,8,9};
    b = {6,7,8,9};
    c = solution_2(a, b);
    for(auto &i : c) {
        cout<<i<<endl;
    }
}

