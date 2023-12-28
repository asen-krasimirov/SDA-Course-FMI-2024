// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedList* merged=new SinglyLinkedList();
    SinglyLinkedListNode* prev1=nullptr;
    SinglyLinkedListNode* prev2=nullptr;
    SinglyLinkedListNode* curr1=head1;
    SinglyLinkedListNode* curr2=head2;
    
    while(curr1!=nullptr && curr2!=nullptr){
        int temp=0;
        if(curr1->data<curr2->data){
            temp=curr1->data;
            prev1=curr1;
            curr1=curr1->next;
                merged->insert_node(temp);
        }
        else {
            temp=curr2->data;
            prev2=curr2;
            curr2=curr2->next;
                merged->insert_node(temp);
        }
    
    }
    while(curr1!=nullptr){
        int temp=curr1->data;
        prev1=curr1;
        curr1=curr1->next;
        merged->insert_node(temp);
    }
    while(curr2!=nullptr){
        int temp=curr2->data;
        prev2=curr2;
        curr2=curr2->next;
        merged->insert_node(temp);
    }
    return merged->head;
}
