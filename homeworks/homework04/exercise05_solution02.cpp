#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

struct Node {
    long long val;
    Node *next;
    Node *prev;

    Node(long long val, Node *next = nullptr, Node *prev = nullptr) : val(val), next(next), prev(prev) {}
};

struct LinkedList {
    Node *head, *mid, *tail;
    long long size;

    LinkedList() : head(nullptr), mid(nullptr), tail(nullptr), size(0) {}
    ~LinkedList() {
        Node *current = head;
        while (current != nullptr) {
            Node *temp = current->next;
            delete current;
            current = temp;
        }
    }

    void push_back(long long val) {
        if (head == nullptr) {
            head = new Node(val);
            tail = mid = head;
        }
        else {
            tail->next = new Node(val, nullptr, tail);
            tail = tail->next;
        }

        if (++size == 2) mid = head;
        else if (size % 2 == 0) mid = mid->next;
    }

    void pop_back() {
        if (head == nullptr || tail == nullptr) return;
        if (tail == head) {
            delete tail;
            tail = mid = head = nullptr;
            --size;
            return;
        }

        Node *temp = tail;

        tail = tail->prev;
        if (tail != nullptr) tail->next = nullptr;
        if (mid == temp) mid = nullptr;
        if (head == temp) head = nullptr;

        delete temp;

        if (--size % 2 == 1 && mid != nullptr) mid = mid->prev;
    }

    void switch_mid() {
        if (head == nullptr || mid == nullptr || tail == nullptr) return;

        tail->next = head;
        head->prev = tail;

        Node *prevMid = mid;
        mid = mid->next;
        mid->prev = nullptr;
        prevMid->next = nullptr;

        swap(prevMid, tail);
        swap(prevMid, mid);
        swap(prevMid, head);

        if (size % 2 != 0) mid = mid->prev;
    }

    void print() const {
        cout << size << endl;

        Node *current = head;
        while (current != nullptr) {
            cout << current->val << " ";
            current = current->next;
        }
    }
};

int main() {
    long long N;
    cin >> N;

    string command;

    LinkedList notes;

    long long note;

    for (long long i = 0; i < N; ++i) {
        cin >> command;

        if (command == "add") {
            cin >> note;
            notes.push_back(note);
        }
        else if (command == "gun") notes.pop_back();
        else if (command == "milen") notes.switch_mid();
    }

    notes.print();

    return 0;
}
