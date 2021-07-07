/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        for(auto &str : strs) {
            bool flag = true;

            for(int i = 0; i < ret.size(); ++i) {
                map<char, int> m;
                for(int j = 0; j < ret[i][0].length(); ++j) {
                    m[ret[i][0][j]] = 1;
                }
                
                for(int l = 0; l < str.length(); ++l) {
                    if(m[str[l]]) {
                        continue;
                    } else {
                        flag = false;
                        break;
                    }
                }

                if(!flag) {
                    continue;
                } else {
                    ret[i].push_back(str);
                    break;
                }
            }

            if(!flag) {
                vector<string> tmp;
                tmp.push_back(str);
                ret.push_back(tmp);
            }
        }

        return ret;
    }
};

int main() {
    vector<string> t = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution a;
    a.groupAnagrams(t);

}

