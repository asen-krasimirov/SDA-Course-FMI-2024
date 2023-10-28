#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

/* 10/100 */

struct Node {
    long long key;
    long long val;
    Node *next;
    Node *prev;

    Node(long long key, long long val, Node *next = nullptr, Node *prev = nullptr) : key(key), val(val), next(next),
                                                                                     prev(prev) {}
};

struct LinkedList {
    Node *head, *tail;
    long long size, maxSize;

    explicit LinkedList(long long maxSize, long long overload) : head(nullptr), tail(nullptr), size(0),
                                                                 maxSize(maxSize) {}

//    ~LinkedList() {
//        Node *current = head;
//        while (current != nullptr) {
//            Node *temp = current->next;
//            delete current;
//            current = temp;
//        }
//    }

    Node *find_elem(long long key) {
        Node *elem = head;
        while (elem != nullptr) {
            if (elem->key == key) {
                if (head == elem) return elem;
                if (tail == elem) tail = elem->prev;
                elem->prev->next = elem->next;
                elem->next = head;
                head = elem;
                elem->prev->prev = elem;
                elem->prev = nullptr;
                return elem;
            }
            elem = elem->next;
        }

        return nullptr;
    }

    long long get_elem(long long key) {
        Node *elem = find_elem(key);

        if (elem != nullptr) {
            return elem->val;
        }
        return -1;
    }

    void push_front(long long key, long long val) {
        Node *elem = find_elem(key);
        if (elem != nullptr) {
            elem->val = val;
        } else {
            if (head == nullptr) {
                head = new Node(key, val, nullptr, nullptr);
                tail = head;
            } else {
                head->prev = new Node(key, val, head, nullptr);
                head = head->prev;
            }

            if (size++ == maxSize) {
                pop_back();
            }
        }
    }

    void pop_back() {
        if (head == nullptr || tail == nullptr) return;

        Node *temp = tail;

        tail = tail->prev;
        if (tail != nullptr) tail->next = nullptr;
        if (head == temp) head = nullptr;

//        delete temp;
        size--;
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
    long long N, Q, K;
    cin >> N >> Q >> K;

    string command;
    long long key, val;

    LinkedList hash(N, K);

    for (long long i = 1; i <= Q; ++i) {
        cin >> command;

        if (command == "put") {
            cin >> key >> val;
            hash.push_front(key, val);
        }
        else if (command == "get") {
            cin >> key;
            cout << hash.get_elem(key) << endl;
        }

        if (i % K == 0) hash.pop_back();
    }

    return 0;
}
