#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;

    explicit Node(int value, Node *next = nullptr) : value(value), next(next) {

    }
};

class LinkedList {
private:
    Node *head = nullptr;
    Node *tail = nullptr;

public:

    void push_front(int value) {
        Node *newHead = new Node(value, head);
        head = newHead;

        if (tail == nullptr) {
            tail = head;
        }
    }

    void push_back(int value) {
        if (head == nullptr) {
            head = new Node(value, nullptr);
            tail = head;
        }
        else {
            tail->next = new Node(value, nullptr);
            tail = tail->next;
        }
    }

    void insert(int value, int idx) {
        if (idx == 0) {
            push_front(value);
        }
        else if (head == nullptr) {
            return;
        }

        Node *current = head;
        Node *previous = nullptr;

        for (int i = 0; i < idx; ++i) {
            if (current == nullptr) {
                return;
            }

            previous = current;
            current = current->next;
        }

        previous->next = new Node(value, current);

        if (tail == previous) {
            tail = previous->next;
        }
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }
        else if (head == tail) {
            tail = nullptr;
        }

        Node *oldHead = head;
        head = oldHead->next;
        delete oldHead;
    }

    void pop_back() {
        Node *current = head;
        Node *previous = nullptr;

        while (current != nullptr) {
            previous = current;
            current = current-> next;
        }

        tail = previous;
        delete previous->next;
        previous->next = nullptr;
    }

    void popAt(int idx) {
        if (idx == 0) {
            pop_front();
            return;
        }
        else if (head == nullptr) {
            return;
        }

        Node *current = head;
        Node *previous = nullptr;

        for (int i = 0; i < idx; ++i) {
            if (current == nullptr) {
                return;
            }

            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        if (tail == current) {
            tail = previous;
        }
        delete current;
    }

    bool isInside(int value) {
        Node *current = head;

        while (current != nullptr) {
            if (current->value == value) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    void print() {
        Node *current = head;

        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }

        cout << '\n';
    }
};

int main() {
    LinkedList *linkedList = new LinkedList();


    return 0;
}