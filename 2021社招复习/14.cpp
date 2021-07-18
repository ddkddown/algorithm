/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.
*/

#include <iostream>
using namespace std;

struct Val {
    int value;
    Val *next;
};

class Solution {
public:
    Val* answer(Val *val, int n){
        if(0 == n) {
            return val;
        }

        Val tmp;
        tmp.next = val;

        Val *pre = &tmp;
        Val *mid = tmp.next;
        Val *tail = tmp.next;

        while(n--) {
            tail = tail->next;
        }

        while(tail->next) {
            mid = mid->next;
            pre = pre->next;
        }

        pre->next = mid->next;
        return tmp.next;
    }
};