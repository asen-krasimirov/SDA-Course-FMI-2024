#include<bits/stdc++.h>
using namespace std;

struct Node{
    long long value;
    Node* prev;
    Node* next;
     Node(long long value, Node *next = nullptr, Node *prev = nullptr) : value(value),prev(prev), next(next)  {}
};
struct List{
    Node* head;
    Node* tail;
    Node* mid;
    int size=0;
    List():head(nullptr),mid(nullptr),tail(nullptr),size(0){
        
    }
    ~List(){
        Node* curr=head;
        while(curr){
            Node* temp=curr->next;
            delete curr;
            curr=temp;
        }
    }
    void push_back(long long newValue){
        if(!head){
            head=new Node(newValue);
            tail=mid=head;
        }
        else{
            tail->next=new Node(newValue,nullptr,tail);
            tail=tail->next;
        }
        if(++size==2) {
            mid=head;
        }
        else  if(size%2==0){
            mid=mid->next;
        }
    }
    void pop_back(){
        if(!head || !tail){
            return;
        }
        if(size==1){
            delete tail;
            tail=mid=head=nullptr;
            size=0;
            return;
        }
        tail=tail->prev;
        delete tail->next;
        tail->next=nullptr;
        if(size>=2){
            if(size%2==0){
                mid=mid->prev;
            }
        }
        else {
            mid=head;
        }
        --size;
    }
    void switch_mid(){
        if(size<2){
            return;
        }
        Node *temp = tail;
        
        head->prev = tail;
        tail->next = head;
        head = mid->next;
        tail =mid;
        
        head->prev = nullptr;
        tail->next = nullptr;

        mid = (this->size % 2 ? temp->prev : temp );
    }
    void print()const{
        cout<<size<<'\n';
         Node *current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        } 
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    size_t n;
    cin>>n;
    List listOfGuns;
    string command;
    size_t number,size=0;
    for(int i=0;i<n;i++){
        cin>>command;
        if(command=="add"){
            cin>>number;
            listOfGuns.push_back(number);
            size++;
        }
        else if(command=="gun"){
            listOfGuns.pop_back();
            size--;
        }
        else if(command=="milen"){
            listOfGuns.switch_mid();
        } 
    }
   listOfGuns.print();
    return 0;
}
