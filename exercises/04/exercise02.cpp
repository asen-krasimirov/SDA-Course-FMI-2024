/**
 * LeetCode contest: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current = head;
        ListNode *previous = nullptr;

        while (current != nullptr) {
            previous = current;
            current = current->next;

            while (current != nullptr && current->val == previous->val) {
                current = current->next;
            }

            previous->next = current;
        }

        return head;
    }
};
