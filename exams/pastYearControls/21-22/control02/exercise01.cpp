

#include <iostream>
#include <sstream>
#include <stack>

#include <vector>

using namespace std;

struct Node
{
    int value;
    Node* next;
    // Constructor with two arguments, one of which is default
    Node(int value, Node* next = nullptr) : value(value), next(next) {};
};

struct SinglyLinkedList
{
    Node* head, * tail;
    int size;

    SinglyLinkedList() :head(nullptr), tail(nullptr), size(0) {}; // Default constructor

    void addAtHead(int X); // Utility function for add
    void addAtTail(int X); // Utility function for add
    void add(int X, int pos);

    void remove(int pos);

    void reverse(); // Iterative

    Node* reverseRecursiveUtil(Node* head); // Utility function for recursive reverse function
    void reverseRecursive(); // Recursive

    bool isPalindrom();

    int count(int X);

    void removeAll(int X);

    void group(int start, int end);

    // Instead of print function
    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list);
};



int main()
{
    size_t N, Q; std::cin >> N;

    int el(0), pos(0);

    for (size_t i = 0; i < N; i++)
    {
        SinglyLinkedList list;
        std::cin >> Q; std::cin.ignore();
        for (size_t i = 0; i < Q; i++)
        {

            std::string line; getline(std::cin, line);
            std::istringstream istr(line);

            std::string command; istr >> command;

            if (command == "add")
            {
                istr >> el >> pos;
                list.add(el, pos);
            }
            else if (command == "print")
            {
                std::cout << list;
            }
            else if (command == "remove")
            {
                istr >> pos;
                list.remove(pos);
            }
            else if (command == "remove_all")
            {
                istr >> el;
                list.removeAll(el);
            }
            else
            {
                int count(0);
                while (istr)
                {
                    istr >> command;
                    count++;
                }
                i += count-1;
            }
        }
        std::cout << '\n';
    }
    return 0;
}

std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list)
{
    Node* traverse = list.head;
    while (traverse != nullptr)
    {
        os << traverse->value << '#';
        traverse = traverse->next;
    } //os << '\n';
    return os;
}

void SinglyLinkedList::addAtHead(int X)
{
    Node* newNode = new Node(X);
    if (head == nullptr) // tail will then also point to nullptr
    {
        head = tail = newNode;
    }
    else
    {
        Node* temp = head;
        newNode->next = temp;
        head = newNode;
    }
    size++;
}

void SinglyLinkedList::addAtTail(int X)
{
    Node* newNode = new Node(X);
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void SinglyLinkedList::add(int X, int pos)
{
    if (pos == 0){
        addAtHead(X);
    }
    else if (pos < 0 || pos > size )
    {
        addAtTail(X);
        std::cout << "add_last";
    }
    else if (pos == size)
    {
        addAtTail(X);
    }
    else
    {
        Node* newNode = new Node(X);
        Node* traverse = head;
        for (int i = 1; i < pos; i++)
        {
            traverse = traverse->next;
        } // traverse points to (pos-1)th Node
        Node* temp = traverse->next; // pos-th Node  :  traverse - newNode - temp
        traverse->next = newNode;
        newNode->next = temp;
        size++;
    }
}

void SinglyLinkedList::remove(int pos)
{
    if (pos < 0 || pos >= (int)size)
    {
        std::cout << "remove_failed";
    }
    else if (pos == 0)
    {
        Node* temp = head->next;
        delete head;
        head = temp;
        size--;
    }
    else
    {
        Node* traverse = head;
        for (int i = 0; i < pos - 1; i++)
        {
            traverse = traverse->next;
        } // traverseNode points to (pos-1)th Node
        Node* temp = traverse->next; // pos-th Node (node we want to remove)
        traverse->next = temp->next; // (pos+1)th Node
        if (temp->next == nullptr)
        {
            tail = traverse;
        }
        delete temp; // remove temp;
        size--;
    }
}


void SinglyLinkedList::removeAll(int x) {
    vector<int> vals;

    Node *temp = head;

    while (temp) {
        if (temp->value != x) {
            vals.push_back(temp->value);
        }
        temp = temp->next;
    }

    if (vals.size() > 0) {
        temp = new Node(vals[0], nullptr);
        head = temp;
    } else {
        head = nullptr;
    }

    for (int i = 1; i < vals.size(); ++i) {
        temp->next = new Node(vals[i], nullptr);

        if (i == vals.size() - 1) {
            tail = temp;
        }

        temp = temp->next;
    }
}
