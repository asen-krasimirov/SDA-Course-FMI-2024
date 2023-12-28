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

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *sortedCur = nullptr;
    SinglyLinkedListNode *current1 = head1;
    SinglyLinkedListNode *current2 = head2;

    if (current1->data < current2->data) {
        sortedCur = new SinglyLinkedListNode(current1->data);
        current1 = current1->next;
    }
    else {
        sortedCur = new SinglyLinkedListNode(current2->data);
        current2 = current2->next;
    }

    SinglyLinkedListNode *sortedHead = sortedCur;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->data < current2->data) {
            sortedCur->next = new SinglyLinkedListNode(current1->data);
            current1 = current1->next;
        }
        else {
            sortedCur->next = new SinglyLinkedListNode(current2->data);
            current2 = current2->next;
        }

        sortedCur = sortedCur->next;
    }

    while (current1 != nullptr) {
        sortedCur->next = new SinglyLinkedListNode(current1->data);
        sortedCur = sortedCur->next;
        current1 = current1->next;
    }

    while (current2 != nullptr) {
        sortedCur->next = new SinglyLinkedListNode(current2->data);
        sortedCur = sortedCur->next;
        current2 = current2->next;
    }

    return sortedHead;
}
