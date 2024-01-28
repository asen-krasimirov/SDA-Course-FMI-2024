#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;

    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }


    void reverse(int from, int to) {
        Node* tempHead = head;
        vector<int> arr;
        while (tempHead) {
            arr.push_back(tempHead->data);
            tempHead = tempHead->next;
        }
        if (from > arr.size())
            return;

        if (to <= arr.size()) {
            int k = (to-1 + from-1) / 2;
            for (int i = from-1; i <= (k+to-1) / 2; i++) {
                swap(arr[i], arr[k + to - 1 - i - 1]);
            }
            List* newHead = new List();
            for (auto& el : arr) {
                newHead->add(el);
            }
            delete head;
            head = newHead->head;
            tail = newHead->tail;
        }
        else {
            int newTo = arr.size() - 1;
            int k = (newTo + from - 1) / 2;
            for (int i = 0; i < k / 2; i++)
                swap(arr[i], arr[k - i - 1]);
            List* newHead = new List();
            for (auto& el : arr) {
                newHead->add(el);
            }
            delete head;
            head = newHead->head;
            tail = newHead->tail;
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

        while (curr) {
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