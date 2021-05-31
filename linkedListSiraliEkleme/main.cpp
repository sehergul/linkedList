#include <iostream>

using namespace std;

struct node{
    int data;
    node * next;};


void display(node *r){
    while(r!=NULL){
        cout << r->data << " -> ";
        r=r->next;}}


node * siraliEkle(node * r, int x){
    if(r==NULL){ //liste bos ise
        r= new node;
        r->next=NULL;
        r->data = x;
        return r;}

    if((r->data)>x){ //x degeri ilk elemandan kucukse
        node * temp= new node;
        temp->data= x;
        temp->next= r;
        return temp; //root degistiriliyor
        }

    node * iter= r;
    while(iter->next!=NULL && (iter->next->data) < x){
        iter = iter->next;}
    node * temp = new node;
    temp->next = iter->next;
    iter->next= temp;
    temp->data= x;
    return r; //root degismedi

}

int main()
{
    node * root= new node;
    root= NULL;
    //her seferinde root degismis olabilir diye
    root = siraliEkle(root,400);
    root = siraliEkle(root,40);
    root = siraliEkle(root,4);
    root = siraliEkle(root,450);
    root = siraliEkle(root,50);

    display(root);



    return 0;
}
