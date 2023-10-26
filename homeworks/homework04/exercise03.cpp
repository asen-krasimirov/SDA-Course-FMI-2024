// For your reference:
class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        } else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

/*
 * Solution below:
 * */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    if (head == nullptr) return nullptr;

    SinglyLinkedListNode *current = head;

    for (int i = 1; i < position; ++i) {
        if (current == nullptr) return nullptr;
        current = current->next;
    }

    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    newNode->next = current->next;

    current->next = newNode;

    return head;
}
