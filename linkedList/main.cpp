#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};


struct Node *head=nullptr;

void traverseLinkedList(){
    struct Node *temp= head;

    while(temp!=NULL){
        cout << temp->data << " -> ";
        temp= temp->next;}
}

int main()
{
    struct Node *newHead = new Node;
    newHead->data=0;
    newHead->next=NULL;
    head= newHead;

    struct Node *first= new Node;
    first->data=1;
    first->next=NULL;
    newHead->next=first;

    struct Node *second= new Node;
    second->data=2;
    second->next=NULL;
    first->next=second;

    struct Node *third= new Node;
    third->data=3;
    third->next=NULL;
    second->next=third;

    traverseLinkedList();
    cout << endl;

    struct Node *newNode = new Node;
    newNode->data=4;
    newNode->next=NULL;
    Node *t=head;

    while(t->next!=NULL){
        t=t->next;}
    t->next= newNode;

    traverseLinkedList();
    cout << endl;

    Node *t2= head;

    for(int i=0; i<2; i++)
        t2= t2->next;

    struct Node *newNode2 = new Node;
    newNode2->data=10;
    newNode2->next=third;
    second->next=newNode2;

    traverseLinkedList();
    cout << endl;

    struct Node* newNode3=new Node;
    newNode3->data = 56;
    newNode3->next = NULL;

    Node *temp=head;
    for(int i=0;i<2;i++){
        if(temp->next!=NULL)
            temp=temp->next;}

    newNode3->next=temp->next;
    temp->next=newNode3;

    traverseLinkedList();



    return 0;
}
