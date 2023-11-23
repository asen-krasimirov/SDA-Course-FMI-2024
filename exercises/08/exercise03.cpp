#include <vector>
#include <queue>

using namespace std;

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // priority_queue<pair<int, int>> pq;
        priority_queue<int, vector<int>, greater<int>> pq;

        // ListNode *current = nullptr;
        for (auto list : lists) {
            auto temp = list;

            while (temp != nullptr) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        if (pq.empty()) {
            return nullptr;
        }

        ListNode *current = new ListNode(pq.top());
        ListNode *head = current;
        pq.pop();

        while (!pq.empty()) {
            head->next = new ListNode(pq.top());
            head = head->next;
            pq.pop();
        }

        return current;
    }
};
