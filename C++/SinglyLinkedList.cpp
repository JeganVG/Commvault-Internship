#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val){
    Node* newNode = new Node(val);

    if(head == NULL) head = newNode;
    else{
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node* &head, int val){
    Node* newNode = new Node(val);

    if(head == NULL) head = newNode;
    else{
        Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newNode;
    }
}

void deleteUsingValue(Node* &head, int val){
    Node* temp = head;
    Node* tempPrev = NULL;

    while(temp->next!=NULL){
        if(temp->data == val) break;
        else {
            tempPrev = temp;
            temp=temp->next;
        }
    }
    if(tempPrev!=NULL) tempPrev->next = temp->next;
    else head = temp->next;
    free(temp);
}

void reverse(Node* &head){
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;

    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void display(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

int main(){
    Node* head = NULL;
    insertAtHead(head, 1);
    display(head);
    insertAtTail(head,2);
    display(head);
    insertAtHead(head,3);
    display(head);
    insertAtTail(head,4);
    display(head);
    deleteUsingValue(head,1);
    display(head);
    deleteUsingValue(head,3);
    display(head);
    deleteUsingValue(head,4);
    display(head);
    insertAtHead(head,1);
    display(head);
    insertAtTail(head,3);
    display(head);
    insertAtHead(head,4);
    display(head);
    reverse(head);
    display(head);
    return 0;
}