#include <iostream>
#include <stack>

using namespace std;

class CQueue {
    stack<int> front;
    stack<int> tail;
public:
    CQueue() {}
    
    void appendTail(int value) {
        tail.push(value);
    }
    
    int deleteHead() {
        if(tail.empty()){
            return -1;
        }

        while(!tail.empty()){
            front.push(tail.top());
            tail.pop();
        }

        int ret = front.top();
        front.pop();

        while(!front.empty()){
            tail.push(front.top());
            front.pop();
        }

        return ret;
    }
};