#include <iostream>

using namespace std;

struct node{
    int data;
    node * next;};

node * sil(node *r, int x){
    node *iter = r;
    node * temp= new node;
    if(r->data==x){
        temp= r;
        r= r->next;
        free(temp);
        return r;}

    while(iter->next!=NULL && iter->next->data!=x)
        iter= iter->next;
    if(iter->next==NULL){
        cout << "Silmek istediginiz sayi bulunamadi!" << endl;
        return r;}
    temp= iter->next;
    iter->next= iter->next->next;
    free(temp);
    return r;}


void aradanSil(node *r, int x){
    node * iter=r;
    node * temp = new node;
    while(iter->next->data!=x)
        iter= iter->next;
    temp = iter->next;
    iter->next= iter->next->next;
    free(temp);}

void display(node *r){
    while(r!=NULL){
        cout << r->data << " - > ";
        r=r->next;}
    cout << endl;}

int main(){
    node * root = new node;
    root->data=0;
    node * iter = root;
    for(int i=1; i<=5;i++){
        iter-> next = new node;
        iter = iter->next;
        iter ->data = i*10;
        iter -> next = NULL;}
    display(root);
    aradanSil(root,30);
    display(root);
    sil(root,10);
    display(root);
    sil(root,98);
    return 0;
}
