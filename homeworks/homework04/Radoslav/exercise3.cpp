SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode=new SinglyLinkedListNode(data);
    if(llist==nullptr){
        llist=newNode;
        return llist;
    }
    if(position==0){
        SinglyLinkedListNode *temp = llist;
        llist = new SinglyLinkedListNode(data);
        llist->next = temp;
        return llist;
    }
    SinglyLinkedListNode* prev=nullptr;
    SinglyLinkedListNode* curr=llist;
    for(int i=0;i<position;i++){
        if(curr!=nullptr){
            prev=curr;
            curr=curr->next;
        }
    }
    newNode->next=curr;
    prev->next=newNode;
    return llist;
}
