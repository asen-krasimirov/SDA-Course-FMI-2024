#include <bits/stdc++.h>
using namespace std;


typedef unsigned long long ll;

struct Node {
    Node *next;
    int data;
};

class LinkedList{
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList(){
        Node* temp;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value){
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    void print(){
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    vector<ll> getNums() {
        vector<ll> res;

        Node* curr = head;
        while(curr != nullptr){
            res.push_back(curr->data);
            curr = curr->next;
        }

        return res;
    }

private:
    Node *head, *tail;
};

void handleTakeOver(int &takeOver, int &totalCtr, int temp, vector<ll> &res) {
    if (takeOver != 0) {
        while (takeOver && temp < res.size()) {
            res[temp] += takeOver;

            if (res[temp] >= 10) {
                res[temp] -= 10;
                takeOver = 1;
            } else {
                takeOver = 0;
            }

            temp++;
        }

        if (takeOver && temp == res.size()) {
            res.push_back(1);
            totalCtr++;
            takeOver = 0;
        }
    }
}

void solve(LinkedList& num1, LinkedList& num2){
    vector<ll> nums1 = num1.getNums();
    vector<ll> nums2 = num2.getNums();

    if (nums1.size() < nums2.size()) {
        swap(nums1, nums2);
    }

    vector<ll> res(nums1.size() + 1, 0);

    int totalCtr = nums1.size();

    int i = 0;
    int takeOver = 0;

    for (; i < nums2.size(); ++i) {
        handleTakeOver(takeOver, totalCtr, i, res);

        res[i] = nums1[i] + nums2[i] + res[i];

        if (res[i] >= 10) {
            res[i] -= 10;
            takeOver = 1;
        } else {
            takeOver = 0;
        }
    }

    for (; i < nums1.size(); ++i) {
        handleTakeOver(takeOver, totalCtr, i, res);

        res[i] = nums1[i] + res[i];

        if (res[i] >= 10) {
            res[i] -= 10;
            takeOver = 1;
        } else {
            takeOver = 0;
        }
    }

    handleTakeOver(takeOver, totalCtr, i, res);

    if (nums1.size() == nums2.size()) {
        totalCtr++;
    }

    for (int i = totalCtr - 1; i >= 0; --i) {
        cout << res[i];
    }

}

int main(){
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for(int i = 0 ; i < size1 ; i++){
        int digit;
        cin >> digit;
        num1.add(digit);
    }

    cin >> size2;
    for(int i = 0 ; i < size2 ; i++){
        int digit;
        cin >> digit;
        num2.add(digit);
    }

    solve(num1, num2);
}
