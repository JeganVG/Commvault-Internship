#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(Node* &head, int val){
    Node* newNode = new Node(val);

    newNode->next=head;
    if(head!=NULL){
        head->prev=newNode;
    }
    head = newNode;
}

void insertAtTail(Node* &head, int val){
    Node* tail = head;
    Node* newNode = new Node(val);

    while(tail->next!=NULL){
        tail=tail->next;
    }
    if(tail!=NULL){
        tail->next = newNode;
        newNode->prev = tail;
    }
}
int getSize(Node* &head){
    Node* temp = head;
    int counter =0;

    while(temp->next!=NULL){
        counter++;
        temp=temp->next;
    }
    return counter;
}

void insertAtLocation(Node* &head, int val, int location){
    Node* nextNode = head;
    Node* newNode = new Node(val);

    int counter=0;

    int totalSize = getSize(head);
    if(location==0) insertAtHead(head, val);

    else if(location==totalSize) insertAtTail(head,val);

    else{
        while(counter!=location){
            counter++;
            nextNode=nextNode->next;
        }
        Node* prevNode = nextNode->prev;
        prevNode->next = newNode;
        newNode->prev = prevNode; 
        nextNode->prev = newNode;
        newNode->next = nextNode;
    }
}
void deleteNodeUsingValue(Node* &head, int val){
    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->data==val) break;
        temp=temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<"NULL\n";
};

void reverse(Node* &head){
    if(head == NULL) return;
    Node* temp = head;
    Node* nextNode;
    while(temp!=NULL){
        nextNode = temp->next;
        temp->next = temp->prev;
        temp->prev = nextNode; 
        if (nextNode == NULL) {
            head = temp;
        }
        temp=nextNode;
    }
}

int main(){
    Node* head=NULL;
    display(head);
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    display(head);
    insertAtTail(head,4);
    display(head);
    insertAtLocation(head,5,1);
    display(head);
    insertAtLocation(head,7,1);
    display(head);
    deleteNodeUsingValue(head,7);
    display(head);
    insertAtLocation(head,7,1);
    display(head);
    insertAtLocation(head,8,1);
    display(head);
    reverse(head);
    display(head);
}