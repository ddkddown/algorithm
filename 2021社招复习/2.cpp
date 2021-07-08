/*编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，则返回""
输入: ["flower","flow","flight"]
输出: "fl"

输入: ["dog","racecar","car"]
输出: ""
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string findMaxPrefix(const string &a, const string &b) {
    string ret = "";
    int i = 0, j = 0;
    while(i < a.length() && j < b.length()) {
        if(a[i] == b[j]) {
            ret.push_back(a[i]);
            ++i;
            ++j;
            continue;
        }
        break;
    }

    return ret;
}

string Solution(vector<string> strs) {
    if(0 == strs.size()) {
        return "";
    }

    if(1 == strs.size()) {
        return strs[0];
    }

    auto base = findMaxPrefix(strs[0], strs[1]);

    for(int j = 2; j < strs.size(); ++j) {
        if(base.empty()) {
            return "";
        }

        base = findMaxPrefix(base, strs[j]);
    }
    
    return base;
}

int main() {
    vector<string> a = {"flower", "flow", "fl", "dman"};
    cout<<Solution(a)<<endl;
}
