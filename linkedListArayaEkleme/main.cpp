#include <iostream>

using namespace std;



struct node{
    int data;
    node * next;};


void print(node *r){
    while(r!=NULL){
        cout << r->data << endl;
        r = r->next;}}

void sonaEkle(node *r, node *son){
    while(r->next!=NULL)
        r= r->next;
    r->next= son;}

void sondanCikar(node *r){
    while(r->next->next!=NULL)
        r= r->next;
    r->next=NULL;}

void arayaEkle(node *r, node *onuneEklenecek){

    while(r->next->data!=30)
        r=r->next;
    onuneEklenecek->next= r->next;
    r->next=onuneEklenecek;}

void arayaEkle2(node *r, node *sonunaEklenecek){
    while(r->data!=20)
        r=r->next;
    sonunaEklenecek->next=r->next;
    r->next= sonunaEklenecek;

}

int main()
{
    node * root = new node;
    root->data=0;
    node * iter;
    iter = root;
    for(int i=1; i<=5;i++)
    {
        iter-> next = new node;
        iter = iter->next;
        iter ->data = i*10;
        iter -> next = NULL;
    }
    node * pson= new node;
    pson->data=60;
    pson->next=NULL;
    while(iter->next!=NULL) //donguye girmez cunku onceki for dongusunden iter->next=NULL
        iter= iter->next;

    iter->next = pson;

    node * bukezson= new node;
    bukezson->data=70;
    bukezson->next=NULL;
    sondanCikar(root);
    sonaEkle(root,bukezson);

    node * sonunaEklenecekSayi= new node;
    sonunaEklenecekSayi->data=23;
    sonunaEklenecekSayi->next=NULL;
    arayaEkle2(root, sonunaEklenecekSayi);

    node * eklenecekSayi= new node;
    eklenecekSayi->data=25;
    eklenecekSayi->next=NULL;
    arayaEkle(root,eklenecekSayi);



    print(root);
    return 0;
}



