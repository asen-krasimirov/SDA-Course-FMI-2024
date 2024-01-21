#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;

    void add(int value) {
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


    void reverse(int from, int to) {
        vector<int> newVals;
        vector<int> reversedVals;

        Node *temp = head;
        for (int i = 1; i < from && temp != nullptr; ++i) {
            newVals.push_back(temp->data);
            temp = temp->next;
        }

        for (int i = from; i <= to && temp != nullptr; ++i) {
            reversedVals.push_back(temp->data);
            temp = temp->next;
        }

        std::reverse(reversedVals.begin(), reversedVals.end());

        for (auto e : reversedVals) {
            newVals.push_back(e);
        }

        while (temp) {
            newVals.push_back(temp->data);
            temp = temp->next;
        }

        head = nullptr;
        tail = nullptr;

        for (auto e : newVals) {
            add(e);
        }
    }

    void print() {
        Node* temp = head;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~List() {
        Node* curr = head;

        while(curr) {
            Node* prev = new Node;
            prev = curr;
            curr = curr->next;
            delete prev;
        }

        delete curr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    List testList;

    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

        string op;
        cin >> op;

        if (op == "add") {
            int num;
            cin >> num;
            testList.add(num);
        }

        if (op == "print") {
            testList.print();
        }

        if (op == "reverse") {
            int from, to;
            cin >> from >> to;
            testList.reverse(from, to);
        }
    }

    return 0;
}