/**
* LeetCode contest: https://leetcode.com/problems/linked-list-cycle/description/
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
    bool hasCycle(ListNode *head) {
        ListNode *fastPointer = head;
        ListNode *slowPointer = head;

        int i = 1;
        while(fastPointer != nullptr) {
            fastPointer = fastPointer->next;

            if (i % 2 == 0) {
                slowPointer = slowPointer->next;
            }

            if (fastPointer == slowPointer) {
                return true;
            }

            i++;
        }

        return false;
    }
};
