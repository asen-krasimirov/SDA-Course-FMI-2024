struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        int i = 0;
        while (fast != nullptr) {
            fast = fast->next;
            if (fast == nullptr) {
                break;
            }

            if (++i % 2 == 0) {
                slow = slow->next;
            }

            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};
