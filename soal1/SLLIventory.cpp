#include "SLLInventory.h"
#include <iostream>
using namespace std;


bool isEmpty(list L){
    if(L.head == NULL){
        return true; 
    } else {
        return false;
    }
}

void createList(list &L){
    L.head = NULL;
}


address alokasi( string Nama,string SKU,int Jumlah,float HargaSatuan,float DiskonPersen) { 
    address nodeBaru = new node; 
    nodeBaru->info.Nama = Nama;
    nodeBaru->info.SKU = SKU; 
    nodeBaru->info.Jumlah = Jumlah;
    nodeBaru->info.HargaSatuan = HargaSatuan;
    nodeBaru->info.DiskonPersen = DiskonPersen;
    nodeBaru->next= NULL;
    return nodeBaru;
}

void dealokasi(address &addr){
    addr->next = NULL;
    delete addr;
}

void hitungHargaAkhir(address N) {
    if (N != NULL) {
        float diskonFactor = 1.0 - (N->info.DiskonPersen / 100.0);
        N->info.DiskonPersen = N->info.HargaSatuan * diskonFactor;
    }
}
void insertFirst(list &L, address nodeBaru){
    nodeBaru->next = L.head;
    L.head = nodeBaru;
}
void insertLast(list &L, address nodeBaru){
    if(isEmpty (L)){
        L.head = nodeBaru;
    }else{
        address nodeBantu = L.head;
        while(nodeBantu->next != NULL){
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}
void insertAfter(list &L, address Q, address P){
    if(P != NULL){
        Q->next = P->next;
        P->next = Q;
    }else{
        cout << "Node sebelumnya tidak valid" << endl;
    }
}
void delFirst(list &L, Product &P){
    address nodeHapus;
    if(isEmpty(L) == false) {
        nodeHapus = L.head;
        L.head = L.head->next;
        nodeHapus->next = NULL;
        dealokasi(nodeHapus);
    }else{
        cout << "list kosong" << endl;
    }
}
void delLast(list &L, Product &P){
    address nodeHapus, nodePrev;
    if(isEmpty(L) == false){
        nodeHapus = L.head;
        if(nodeHapus->next == NULL){
            L.head->next = NULL;
            dealokasi(nodeHapus);
        }else{
            while(nodeHapus->next != NULL){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = NULL;
            dealokasi(nodeHapus);
        }
    }else{
        cout << "list kosong" << endl;
    }
}
void delAfter(list &L, address Q, Product &P, address nodePrev){
    if(isEmpty(L) == true){
        cout << "list kosong" << endl;
    }else{
        if(nodePrev != NULL && nodePrev->next != NULL){
            Q = nodePrev->next;       
            nodePrev->next = Q->next;  
            Q->next = NULL;         
            dealokasi(Q);
        } else{
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}


void updateAtPosition(list &L, int posisi) {
    if (isEmpty(L)){
        cout << "List kosong." << endl;
        return;
    }
    
    address current = L.head;
    int count = 1;
    
    while (current != nullptr && count < posisi) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Posisi " << posisi << " melebihi panjang List atau posisi tidak valid." << endl;
    } else {
        cout << "--- Memperbarui Produk pada Posisi ke-" << posisi << " (" << current->info.Nama << ") ---" << endl;
        
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
        
        cout << "Data Berhasil Diupdate pada posisi " << posisi << "!" << endl;
        cout << "Harga Akhir baru: " << current->info.DiskonPersen << endl;
    }
}

void viewList(list L){
    if(isEmpty(L)){
        cout << "list kosong "<< endl;
    }else{
        address nodeBantu = L.head;
        while (nodeBantu != NULL){
            cout << "Nama : " << nodeBantu->info.Nama;
            cout << "SKU : " << nodeBantu->info.SKU;
            cout << "Jumlah : " << nodeBantu->info.Jumlah;
            cout << "Hargasatuan : " << nodeBantu->info.HargaSatuan;
            cout << "Diskon persen : " << nodeBantu->info.DiskonPersen;
            nodeBantu = nodeBantu->next;
        }
    }
}

void searchBYFinalPriceRange(list L, float minPrice, float maxPrice){
    if(isEmpty(L)== true){
        cout << "list kosong" << endl;
    }else{
        address nodeBantu = L.head;
        int posisi =0;
        bool found = false;
        
        while(nodeBantu != NULL){
            posisi++;
            float harga = nodeBantu->info.HargaSatuan;
            if(harga >= minPrice && harga <= maxPrice){
                cout << "min : " << minPrice;
                cout << "max : " << maxPrice;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
}
