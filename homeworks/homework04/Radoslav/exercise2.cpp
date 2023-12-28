/*
 * Complete the 'removeDuplicates' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* prev=nullptr;
    SinglyLinkedListNode* curr=llist;
    while(curr!=nullptr){
        if(prev && prev->data==curr->data){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    return llist;
}
