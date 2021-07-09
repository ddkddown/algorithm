/*
从尾到头打印链表
*/

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int m_key;
    ListNode* m_p;
};


void Print(ListNode *p) {
    if(nullptr == p) {
        return;
    }

    if(p->m_p) {
        Print(p->m_p);
    }

    cout<<p->m_key<<endl;
}

void Print(ListNode *p) {
    stack<ListNode> a;
    while(p) {
        a.push(p);
        p = p->m_p;
    }

    while(!a.empty()) {
        cout<<a.top().m_key<<endl;
        a.pop();
    }
}