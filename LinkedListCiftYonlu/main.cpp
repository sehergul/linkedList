#include <iostream>

using namespace std;

struct node{
    int data;
    node *prev;
    node *next;};

void display(node *r){
    while(r!=NULL){
        cout << r->data << " -> ";
        r=r->next;}
    cout << endl;}

node * ekle(node *r, int x){
    if(r==NULL){ //node bos ise
        r= new node;
        r->prev= NULL;
        r->next=NULL;
        r->data=x;
        return r;}

    if((r->data) > x){ //basa eklenecek ise
        node * temp = new node;
        temp->data= x;
        temp->prev=NULL;
        temp->next=r;
        r->prev=temp;
        return temp; } //yeni root

    node *iter= r;
    while(iter->next!=NULL && (iter->next->data)<x)
        iter= iter->next;
    node *temp = new node;
    temp->data=x;
    temp->next=iter->next;
    temp->prev= iter;
    if(iter->next!=NULL)
        iter->next->prev=temp; //sona eklendiginde null varsa bu islem yapilamaz
    iter->next=temp;
    return r;}


node * sil(node*r, int x){
    node *iter=r;
    node *temp= new node;
    if(r->data==x){ //ilk eleman silinecekse
        temp=r;
        r= r->next;
        r->prev=NULL;
        free(temp);
        return r;}

    while(iter->next!=NULL && iter->next->data!=x)
        iter= iter->next;

    if(iter->next==NULL){
        cout << "Silmek istediginiz sayi bulunamadi!" << endl;
        return r;}

    temp= iter->next;
    iter->next=temp->next;
    if(iter->next!=NULL){
        iter->next->prev=temp->prev;} //son node silinirse prev'i olmaz
    free(temp);
    return r;

    }





int main(){

    node *root= new node;
    root=NULL;
    root = ekle(root,400);
    root = ekle(root,40);
    root = ekle(root,4);
    root = ekle(root,450);
    root = ekle(root,50);
    display(root);
    root= sil(root,50);
    display(root);
    root= sil(root,999);
    display(root);
    root= sil(root,4);
    display(root);
    root= sil(root,450);
    display(root);
    return 0;
}
