#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty()){
            return true;
        }
        
        stack<int> push;
        stack<int> pop;
        while(!pushed.empty()){
            if(push.empty()){
                push.push(pushed.front());
                pushed.erase(pushed.begin());
                continue;
            }

            if(push.top() != popped.front()){
                push.push(pushed.front());
                pushed.erase(pushed.begin());
                continue;
            }

            if(push.top() == popped.front()){
                push.pop();
                popped.erase(popped.begin());
                continue;
            }
        }

        while(!push.empty()){
            if(push.top() != popped.front()){
                return false;
            }

            push.pop();
            popped.erase(popped.begin());
        }

        return true;
    }
};

int main(){
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,3,5,1,2};

    Solution a;
    cout<<(a.validateStackSequences(pushed, popped)?"true":"false");
}