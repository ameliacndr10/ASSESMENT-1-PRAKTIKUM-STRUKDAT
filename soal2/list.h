#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <iostream>
#include <string>

using namespace std;

struct Product{
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen; 
    float HargaAkhir;   
};

typedef Product dataProduct;
typedef struct Node *address;

struct Node {
    Product info;
    address next;
};

struct List{
    address head;
};

void hitungHargaAkhir(address N);
bool isEmpty(List L);
void createList(List &L);
address alokasi(string Nama, string SKU, int Jumlah, float HargaSatuan, float DiskonPersen);
void dealokasi(address &addr);

void insertFirst(List &L, address nodeBaru);
void insertLast(List &L, address nodeBaru);
void insertAfter(List &L, address Q, address nodeBaru); 


void delFirst(List &L, Product &P);
void delLast(List &L, Product &P);
void delAfter(List &L, address nodePrev, Product &P);

void updateAtPosition(List &L, int posisi);
void viewList(List L);
void searchByPriceRange(List L, float minPrice, float maxPrice);

#endif