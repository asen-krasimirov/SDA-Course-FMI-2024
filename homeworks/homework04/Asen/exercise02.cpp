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

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* list) {
    SinglyLinkedListNode *current = list;
    SinglyLinkedListNode* previous = nullptr;

    while (current != nullptr) {
        previous = current;
        current = current->next;

        while (current != nullptr && current->data == previous->data) {
            current = current->next;
        }

        previous->next = current;
    }

    return list;
}
