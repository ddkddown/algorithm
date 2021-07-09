#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 用两个栈实现一个队列
class Solution {
public:
    void push_back(int val) {
        s_2.push(val);
    }

    void pop() {
        if(s_1.empty()) {
            while(!s_2.empty()){
                s_1.push(s_2.top());
                s_2.pop();
            }
        }
        s_1.pop();
    }

    int top() {
        if(s_1.empty()) {
            while(!s_2.empty()){
                s_1.push(s_2.top());
                s_2.pop();
            }
        }

        return s_1.top();
    }

private:
    stack<int> s_1, s_2;
};


// 用两个队列实现一个栈
// 用判断是否是最后一个数，来模拟栈的弹出操作