#include "SLLInventory.h"
#include <iostream>

using namespace std;


void hitungHargaAkhir(address N) {
    if (N != nullptr) {
        float diskonFactor = 1.0 - (N->info.DiskonPersen / 100.0);
        N->info.HargaAkhir = N->info.HargaSatuan * diskonFactor;
    }
}

bool isEmpty(List L){
    return L.head == nullptr;
}

void createList(List &L){
    L.head = nullptr;
}

address alokasi(string Nama, string SKU, int Jumlah, float HargaSatuan, float DiskonPersen) { 
    address nodeBaru = new Node; 
    nodeBaru->info.Nama = Nama;
    nodeBaru->info.SKU = SKU; 
    nodeBaru->info.Jumlah = Jumlah;
    nodeBaru->info.HargaSatuan = HargaSatuan;
    nodeBaru->info.DiskonPersen = DiskonPersen;
    
    hitungHargaAkhir(nodeBaru);
    
    nodeBaru->next = nullptr;
    return nodeBaru;
}

void dealokasi(address &addr){
    if (addr != nullptr) {
        delete addr;
        addr = nullptr;
    }
}


void insertFirst(List &L, address nodeBaru){
    nodeBaru->next = L.head;
    L.head = nodeBaru;
}

void insertLast(List &L, address nodeBaru){
    if(isEmpty (L)){
        L.head = nodeBaru;
    }else{
        address nodeBantu = L.head;
        while(nodeBantu->next != nullptr){
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void insertAfter(List &L, address Q, address nodeBaru){
    if(Q != nullptr){
        nodeBaru->next = Q->next; 
        Q->next = nodeBaru;       
    }else{
        cout << "Node sebelumnya (Q) tidak valid" << endl;
    }
}



void delFirst(List &L, Product &P){
    if(!isEmpty(L)) {
        address nodeHapus = L.head;
        P = nodeHapus->info; 
        L.head = L.head->next;
        dealokasi(nodeHapus);
    }else{
        cout << "list kosong" << endl;
    }
}

void delLast(List &L, Product &P){
    address nodeHapus, nodePrev = nullptr;
    if(!isEmpty(L)){
        nodeHapus = L.head;
        
        if(nodeHapus->next == nullptr){ 
            P = nodeHapus->info;
            L.head = nullptr;
            dealokasi(nodeHapus);
        }else{
            while(nodeHapus->next != nullptr){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            P = nodeHapus->info; 
            nodePrev->next = nullptr;
            dealokasi(nodeHapus);
        }
    }else{
        cout << "list kosong" << endl;
    }
}

void delAfter(List &L, address nodePrev, Product &P){
    if(isEmpty(L)){
        cout << "list kosong" << endl;
    }else{
        if(nodePrev != nullptr && nodePrev->next != nullptr){
            address nodeHapus = nodePrev->next; 
            P = nodeHapus->info; 
            nodePrev->next = nodeHapus->next; 
            dealokasi(nodeHapus);
        } else{
            cout << "Node sebelumnya (nodePrev) tidak valid atau tidak memiliki node setelahnya!" << endl;
        }
    }
}


void updateAtPosition(List &L, int posisi) {
    if (isEmpty(L)){
        cout << "list kosong" << endl;
        return;
    }
    
    address current = L.head;
    int count = 1;
    
    while (current != nullptr && count < posisi) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Posisi " << posisi << " melebihi panjang List." << endl;
    } else {
        cout << "--- Memperbarui Posisi ke-" << posisi << " ---" << endl;
        cout << "Nama baru        : ";
        cin >> current->info.Nama;
        cout << "SKU baru         : ";
        cin >> current->info.SKU;
        cout << "Jumlah baru      : ";
        cin >> current->info.Jumlah ;
        cout << "Harga Satuan baru: ";
        cin >> current->info.HargaSatuan;
        cout << "Diskon persen baru: ";
        cin >> current->info.DiskonPersen;

        hitungHargaAkhir(current); 
        
        cout << "Data Berhasil Diupdate!" << endl;
    }
}


void viewList(List L){   
    if (isEmpty(L)) {
        cout << "|                                            *** LIST KOSONG *** |" << endl;
    } else {
        address current = L.head;
        int index = 1;
        while (current != nullptr) {
            cout << fixed << setprecision(2);
            cout << "| " << setw(3) << index << " | "
                << setw(4) << current->info.SKU << " | "
                << setw(15) << left << current->info.Nama.substr(0, 15) << right << " | "
                << setw(6) << current->info.Jumlah << " | "
                << setw(12) << current->info.HargaSatuan << " | "
                << setw(10) << current->info.DiskonPersen << " | "
                << setw(11) << current->info.HargaAkhir << " |" << endl;
            current = current->next;
            index++;
        }
    }
    cout << "===================================================================================================================" << endl;
}

void searchByPriceRange(List L, float minPrice, float maxPrice){

    address current = L.head;
    int index = 1;
    bool found = false;

    while (current != nullptr) {
        if (current->info.HargaAkhir >= minPrice && current->info.HargaAkhir <= maxPrice) {
            found = true;
            cout << fixed << setprecision(2);
            cout << "| " << setw(3) << index << " | "
                << setw(4) << current->info.SKU << " | "
                << setw(15) << left << current->info.Nama.substr(0, 15) << right << " | "
                << setw(11) << current->info.HargaAkhir << " |" << endl;
        }
        current = current->next;
        index++;
    }

    if (!found) {
        cout << "|       *** TIDAK DITEMUKAN PRODUK DALAM RENTANG HARGA *** |" << endl;
    }
    cout << "=================================================================" << endl;
}