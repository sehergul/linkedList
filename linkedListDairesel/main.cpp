#include <iostream>

using namespace std;

struct node{
    int data;
    node * next;};

typedef node node;

void display(node *r){
    node * iter = r;
    cout << iter->data << " -> ";
    iter= iter->next;
    while(iter!=r){
        cout << iter->data << " -> ";
        iter= iter->next;}
    cout << endl;}

void sonunaEkle(node *r, int x){
    node * iter= r;
    while(iter->next!=r)
        iter= iter->next;

    iter->next = new node;
    iter->next->next=r;
    iter->next->data= x;}

node * siraliEkle(node *r, int x){
    if(r==NULL){ //liste bossa
        r = new node;
        r->next=r;
        r->data= x;
        return r;}

    if((r->data)>x){
        node * temp= new node;
        temp->next= r;
        temp->data= x;
        node * iter= r;
        while(iter->next!=r)
            iter= iter->next;
        iter->next= temp;
        return temp;}

    node *iter= r;
    while((iter->next!=r) && (iter->next->data)<x)
        iter= iter->next;
    node * temp= new node;
    temp->next= iter->next;
    iter->next= temp;
    temp->data=x;
    return r;}


node * sil(node *r, int x){
    node * temp;
    node * iter= r;
    if((r->data)==x){ //ilk elemani silmek istersek
        while(iter->next!=r) //son elemani yeni ilk elemana baglamak icin
            iter=iter->next;
        iter->next= r->next; //iter->next: yeni root
        free(r); //eski root serbest birakildi
        return iter->next; //yeni root
    }


    while((iter->next!=r) && (iter->next->data!=x))
        iter= iter->next;

    if(iter->next == r){ //sona gelindiyse
        cout << "Silmek istediginiz sayi bulunamadi!" << endl;
        return r;} //root degismedi

    temp= iter->next;
    iter->next = iter->next->next; //istenilen node aradan cikarildiktan sonra baglama islemi yapilir
    free(temp); //silinmek istenen node serbest birakiliyor
    return r; //root degismedi



    }


int main()
{
    node * root = new node;
    root= NULL;
    root= siraliEkle(root,400);
    root= siraliEkle(root,40);
    root= siraliEkle(root,4);
    root= siraliEkle(root,450);
    root= siraliEkle(root,50);
    sonunaEkle(root, 1000);
    display(root);
    root = sil(root,50);
    display(root);
    root = sil(root,999);
    display(root);
    root = sil(root,4);
    display(root);
    root = sil(root,450);
    display(root);



    return 0;
}
