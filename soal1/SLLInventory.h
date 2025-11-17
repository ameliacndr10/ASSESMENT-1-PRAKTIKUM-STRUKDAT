#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

struct Product{
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;

};

typedef Product dataProduct;
typedef struct node *address;

struct node {
    Product info;
    address next;
};

struct list{
    address head;
};

bool isEmpty(list L);
void createList(list &L);
address alokasi( string Nama,string SKU,int Jumlah,float HargaSatuan,float DiskonPersen);
void dealokasi(address &addr);
void hitungHargaAkhir(address N);
void insertFirst(list &L, address nodeBaru);
void insertLast(list &L, address nodebaru);
void insertAfter(list &L, address Q, address nodeBaru);
void delFirst(list &L, Product &P);
void delLast(list &L, Product &P);
void delAfter(list &L, address Q, Product &P, address nodePrev);

void updateAtPosition(list &L, int posisi);
void viewList(list L);
void searchBYFinalPriceRange(list L, float minPrice, float maxPrice);

#endif