#include "SLLInventory.h"
#include <iostream>

using namespace std;

int main() {
    list L;
    Product dataProduct;
    
    createList(L);
    
    address nodePulpen = alokasi("Pulpen", "A001", 20, 2500.0, 0.0);
    address nodePulpen = alokasi("Buku tulis", "A002", 15, 5000.0, 10.0); 
    address nodePulpen = alokasi("Penghapus", "A003", 30, 1500.0, 0.0);
    
    insertFirst(L, nodePulpen);

    address nodeBuku = alokasi("Buku Tulis", "B004", 40, 10000.0, 5.0);
    insertAfter(L, nodePulpen, nodeBuku); 

    cout << "List setelah Insert:" << endl;
    viewList(L);
    

    delFirst(L, dataProduct); 
    cout << "delFirst: Menghapus " << dataProduct.Nama << " (SKU: " << dataProduct.SKU << ")" << endl;

    address nodePrev = L.head; 
    cout << "delAfter: Menghapus " << dataProduct.Nama << " (SKU: " << dataProduct.SKU << ")" << endl;
    
    delLast(L, dataProduct); 
    cout << "delLast: Menghapus " << dataProduct.Nama << " (SKU: " << dataProduct.SKU << ")" << endl;

    cout << "\nList setelah Delete:" << endl;
    viewList(L);
    
    updateAtPosition(L, 1); 

    cout << "\nList setelah Update:" << endl;
    viewList(L);


    cout << "\n--- 5. SEARCH BY FINAL PRICE RANGE ---" << endl;
    float hargaMin = 5000.0;
    float hargaMax = 15000.0;
    
    searchBYFinalPriceRange(L, hargaMin, hargaMax);
    
    return 0;
}