#import <iostream>
using namespace std;

/**
* LeetCode contest: https://leetcode.com/problems/intersection-of-two-linked-lists/description/
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int len(ListNode *head) {
        int ctr = 0;
        ListNode *current = head;
        while (current != nullptr) {
            current = current->next;
            ctr++;
        };
        return ctr;
    }

    ListNode *getNodeOnIndex(ListNode *head, int idx) {
        ListNode *current = head;
        for (int i = 0; i < idx; ++i) {
            current = current->next;
        }
        return current;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = len(headA), lenB = len(headB);

        if (lenB > lenA) {
            swap(lenB, lenA);
            swap(headB, headA);
        }

        int delta = lenA - lenB;
        ListNode *curA = getNodeOnIndex(headA, delta);
        ListNode *curB = headB;

        while (curA != nullptr && curB != nullptr) {
            if (curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
    }
};
