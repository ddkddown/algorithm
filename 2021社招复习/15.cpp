/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

#include <iostream>
using namespace std;

struct Val {
    int value;
    Val *next;
};

class Solution {
public:
    Val* answer(Val left, Val right) {
        Val tmp;
        Val *pre = &tmp;

        while(left && right) {
            if(left.value > right.value) {
                pre->next = right;
                right = right.next;
            } else {
                pre->next = left;
                left = left.next;
            }

            pre = pre->next;
        }

        while(left != nullptr) {
            pre->next = left;
            left = left.next;
            pre = pre->next;
        }

        while(right != nullptr) {
            pre->next = right;
            right = right.next;
            pre = pre->next;
        }

        return tmp.next;
    }

};