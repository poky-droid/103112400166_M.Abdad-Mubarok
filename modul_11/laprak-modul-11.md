# <h1 align="center">Laporan Praktikum Modul 11 Multi Linked List </h1>
<p align="center">M. Abdad mubarok - 103112400166</p>

## Dasar Teori
### A. Multi Linked List<br/>
Multi Linked List merupakan pengembangan dari struktur data linked list yang memungkinkan satu data memiliki lebih dari satu hubungan (link) ke data lainnya. Struktur ini biasanya digunakan untuk merepresentasikan relasi kompleks, seperti hubungan satu-ke-banyak atau banyak-ke-banyak antar entitas data. Berbeda dengan single linked list yang hanya memiliki satu pointer, multi linked list memiliki lebih dari satu pointer yang menghubungkan node ke node lain sesuai kebutuhan relasi data.
Menurut penelitian yang dilakukan oleh Mbejo dkk. (2025) dalam Jurnal Sains Informatika Terapan [1], linked list digunakan untuk mengelola data yang bersifat dinamis dan saling terhubung tanpa keterbatasan ukuran memori tetap. Konsep ini menjadi dasar pengembangan multi linked list, di mana satu node dapat terhubung ke beberapa node lain melalui pointer yang berbeda.
Selain itu, Wijoyo dkk. (2024) dalam JRIIN [2] menjelaskan bahwa struktur linked list dengan lebih dari satu referensi pointer sangat efektif digunakan dalam sistem yang membutuhkan fleksibilitas hubungan data, seperti sistem basis data sederhana dan struktur graf.


#### 
#### B.Operasi Dasar Multi Linked List<br/>


###
#### C.Implementasi Multi Linked List<br/>


###
#### D.Implementasi Multi Linked List<br/>

###


## Guided 

###  guided 1
file multi.h 
```C++
 #ifndef MULTI_H
#define MULTI_H
#include <iostream>
using namespace std;

typedef struct nodeParent* NodeParent;
typedef struct nodeChild* NodeChild;

struct nodeChild
{
string idMakanan;
string namaMakanan;
NodeChild next;
NodeChild prev;
};

struct listAnak
{
    NodeChild first;
    NodeChild last;
};

struct nodeParent { //node parent
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk
{
    NodeParent first;
    NodeParent last;
    /* data */
};

void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);
NodeParent alokasiNodeParent(string idkategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruInduk);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodeprev);

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodeprev);
void findChildById(listInduk LInduk, string idCari);

void printStructurMLL(listInduk LInduk);





#endif
```
multi.cpp
```C++
#include "multi.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildById(listInduk LInduk, string idCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == idCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStructurMLL(listInduk LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

```
main.cpp
```C++
#include "multi.h"
#include <iostream>
using namespace std;

int main() {
    //1. Inisialisasi List
    listInduk LInduk ;
    createListInduk(LInduk);
    //2. Membuat Data Parent (Kategori Makanan)
    NodeParent K01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, K01);
    NodeParent K02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, K02);
    NodeParent K03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, K03);
    cout << endl;

    //3. Memasukkan Data Child (menu Makanan) ke kategori tertentu
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng Spesial");
    insertLastChild(K01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(K01->L_Anak, M02);
    // --> Isi Kategori Minuman (K02)
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(K02->L_Anak, D02);
    NodeChild D01 = alokasiNodeChild("D01", "Es Teh Manis");
    insertLastChild(K02->L_Anak, D01);
    // --> Isi Kategori Dessert (K03)
    NodeChild S01 = alokasiNodeChild("S01", "Puding Coklat");
    insertLastChild(K03->L_Anak, S01);
    cout << endl;

    //4. Print mll setelah insert-insert
    printStructurMLL(LInduk);
    cout << endl;

    //5. Searching node child
    findChildById(LInduk, "D01");
    cout << endl;
    
    //6. Delete node child
    deleteAfterChild(K02->L_Anak, D01); //menghapus node child ayam bakar madu
    cout << endl;

    //7. delete ndoe parent
    deleteAfterParent(LInduk, K02); //menghapus node parent dessert
    cout << endl;

    //8. Print mll setelah delete-delete
    printStructurMLL(LInduk);
    cout << endl;

    return 0;
}

```


penjelasan singkat guided 1


## Unguided 

### 1.SOAL ”



file multi.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <string>
using namespace std;

struct golonganHewan {
string idGolongan;
string namaGolongan;
};

struct dataHewan {
string idHewan;
string namaHewan;
string habitat;
bool ekor; 
float bobot; // 
};

struct nodeChild;
struct nodeParent;

typedef nodeParent* NodeParent;
typedef nodeChild* NodeChild;

struct nodeChild {
dataHewan isidata;
NodeChild next;
NodeChild prev;
};

struct listChild {
NodeChild first;
NodeChild last;
};

struct nodeParent {
golonganHewan isidata;
NodeParent next;
NodeParent prev;
listChild L_Child;
};

struct listParent {
NodeParent first;
NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void deleteListChild(listChild &LChild);
void printMLLStructure(listParent &LParent);
void searchHewanByEkor(listParent &LParent, bool tail);

#endif



```
file multi.cpp
```C++


#include <iostream>
#include "Multi.h"
using namespace std;

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL && LParent.last == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL && LChild.last == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        deleteListChild(P->L_Child);
        if (LParent.first == LParent.last) {
            LParent.first = LParent.last = NULL;
        } else {
            LParent.first = P->next;
            LParent.first->prev = NULL;
        }
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent P = NPrev->next;
        deleteListChild(P->L_Child);
        NPrev->next = P->next;
        if (P->next != NULL)
            P->next->prev = NPrev;
        else
            LParent.last = NPrev;
        deallocNodeParent(P);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild C = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = LChild.last = NULL;
        } else {
            LChild.first = C->next;
            LChild.first->prev = NULL;
        }
        deallocNodeChild(C);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild C = NPrev->next;
        NPrev->next = C->next;
        if (C->next != NULL)
            C->next->prev = NPrev;
        else
            LChild.last = NPrev;
        deallocNodeChild(C);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent &LParent) {
    NodeParent P = LParent.first;
    int parentKe = 1;

    while (P != NULL) {
        cout << "=== Parent " << parentKe << " ===" << endl;
        cout << "ID Golongan   : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild C = P->L_Child.first;
            int childKe = 1;

            while (C != NULL) {
                cout << "  - Child " << childKe << " :" << endl;
                cout << "    ID Hewan   : " << C->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "    Habitat    : " << C->isidata.habitat << endl;
                cout << "    Ekor       : " << (C->isidata.ekor ? 1 : 0) << endl;
                cout << "    Bobot      : " << C->isidata.bobot << endl;

                C = C->next;
                childKe++;
            }
        }

        cout << "------------------------------" << endl;
        P = P->next;
        parentKe++;
    }
}


void searchHewanByEkor(listParent &LParent, bool tail) {
    NodeParent p = LParent.first;
    int posParent = 1;
    bool ditemukan = false;

    while (p != NULL) {
        NodeChild c = p->L_Child.first;
        int posChild = 1;

        while (c != NULL) {
            if (c->isidata.ekor == tail) {
                ditemukan = true;

                cout << "Data ditemukan pada list anak dari node parent "
                     << p->isidata.namaGolongan
                     << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << c->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << posChild << endl;
                cout << "Nama Hewan : " << c->isidata.namaHewan << endl;
                cout << "Habitat : " << c->isidata.habitat << endl;
                cout << "Ekor : " << c->isidata.ekor << endl;
                cout << "Bobot : " << c->isidata.bobot << endl;

                cout << "-------------------------" << endl;
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << p->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << posParent << endl;
                cout << "Nama golongan : " << p->isidata.namaGolongan << endl;
                cout << "-------------------------" << endl << endl;
            }

            c = c->next;
            posChild++;
        }

        p = p->next;
        posParent++;
    }

    if (!ditemukan) {
        cout << "Data hewan dengan ekor = " << tail << " tidak ditemukan!" << endl;
    }
}


```
file main.cpp
```C
#include <iostream>
#include "Multi.h"
using namespace std;

void inputData(listParent &LP) {
    NodeParent G1 = allocNodeParent("G001", "Aves");
    NodeParent G2 = allocNodeParent("G002", "Mamalia");
    NodeParent G3 = allocNodeParent("G003", "Pisces");
    NodeParent G4 = allocNodeParent("G004", "Amfibi");
    NodeParent G5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, G1);
    insertLastParent(LP, G2);
    insertLastParent(LP, G3);
    insertLastParent(LP, G4);
    insertLastParent(LP, G5);

    // Child G001
    insertLastChild(G1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    // Child G002
    insertLastChild(G2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(G2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    // Child G004
    insertLastChild(G4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));
}

int main() {
    listParent LP;
    createListParent(LP);

    int pilihan;
    bool dataSudahDiinput = false;

    do {
        cout << "\n===== MENU PRAKTIKUM MULTI LINKED LIST =====" << endl;
        cout << "1. Soal 1 - Insert & Print Data" << endl;
        cout << "2. Soal 2 - Search Hewan Ekor FALSE" << endl;
        cout << "3. Soal 3 - Delete Parent G004 & Print" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (!dataSudahDiinput) {
                    inputData(LP);
                    dataSudahDiinput = true;
                }
                cout << "\n=== OUTPUT SOAL 1 ===" << endl;
                printMLLStructure(LP);
                break;

            case 2:
                if (!dataSudahDiinput) {
                    cout << "Data belum diinput! Jalankan Soal 1 terlebih dahulu.\n";
                } else {
                    cout << "\n=== OUTPUT SOAL 2 (EKOR = FALSE) ===" << endl;
                    searchHewanByEkor(LP, false);
                }
                break;

            case 3:
                if (!dataSudahDiinput) {
                    cout << "Data belum diinput! Jalankan Soal 1 terlebih dahulu.\n";
                } else {
                    cout << "\n=== DELETE PARENT G004 (AMFIBI) ===" << endl;
                    // G004 berada setelah G003
                    deleteAfterParent(LP, LP.first->next->next);
                    printMLLStructure(LP);
                }
                break;

            case 0:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}


```

### Output Unguided 1 : 

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_11/foto/soal1.png)



penjelasan unguided 1 <br/>
pada kodingan di atas sudah termasuk jawaban soal 1 2 3 ,untuk memfasilitasinya menggunakan switch case ,dan untuk kesimpulan soal 1 adalah bahwa struktur data Multi Linked List berhasil digunakan untuk merepresentasikan hubungan antara golongan hewan (parent) dan data hewan (child). Setiap node parent mampu menyimpan lebih dari satu node child melalui list child yang dimilikinya. Proses insert data parent dan child berjalan dengan baik dan hasil print struktur Multi Linked List menunjukkan bahwa data tersimpan sesuai dengan urutan dan relasi yang telah ditentukan pada soal. Dengan demikian, penerapan ADT Multi Linked List pada studi kasus pengelompokan hewan dapat berfungsi secara benar dan efektif.





### 2.SOAL ”
Tambahkan prosedur searchHewanByEkor(input/output LParent :
listParent, input tail : Boolean) yang digunakan untuk melakukan operasi
SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan
menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil
prosedur tersebut pada main.cpp.
file multi.cpp
```C++
void searchHewanByEkor(listParent &LParent, bool tail) {
    NodeParent p = LParent.first;
    int posParent = 1;
    bool ditemukan = false;

    while (p != NULL) {
        NodeChild c = p->L_Child.first;
        int posChild = 1;

        while (c != NULL) {
            if (c->isidata.ekor == tail) {
                ditemukan = true;

                cout << "Data ditemukan pada list anak dari node parent "
                     << p->isidata.namaGolongan
                     << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << c->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << posChild << endl;
                cout << "Nama Hewan : " << c->isidata.namaHewan << endl;
                cout << "Habitat : " << c->isidata.habitat << endl;
                cout << "Ekor : " << c->isidata.ekor << endl;
                cout << "Bobot : " << c->isidata.bobot << endl;

                cout << "-------------------------" << endl;
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << p->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << posParent << endl;
                cout << "Nama golongan : " << p->isidata.namaGolongan << endl;
                cout << "-------------------------" << endl << endl;
            }

            c = c->next;
            posChild++;
        }

        p = p->next;
        posParent++;
    }

    if (!ditemukan) {
        cout << "Data hewan dengan ekor = " << tail << " tidak ditemukan!" << endl;
    }
}


```

file main.cpp
```C
#include <iostream>
#include "Multi.h"
using namespace std;

void inputData(listParent &LP) {
    NodeParent G1 = allocNodeParent("G001", "Aves");
    NodeParent G2 = allocNodeParent("G002", "Mamalia");
    NodeParent G3 = allocNodeParent("G003", "Pisces");
    NodeParent G4 = allocNodeParent("G004", "Amfibi");
    NodeParent G5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, G1);
    insertLastParent(LP, G2);
    insertLastParent(LP, G3);
    insertLastParent(LP, G4);
    insertLastParent(LP, G5);

    // Child G001
    insertLastChild(G1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    // Child G002
    insertLastChild(G2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(G2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    // Child G004
    insertLastChild(G4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));
}

int main() {
    listParent LP;
    createListParent(LP);

    int pilihan;
    bool dataSudahDiinput = false;

    do {
        cout << "\n===== MENU PRAKTIKUM MULTI LINKED LIST =====" << endl;
        cout << "1. Soal 1 - Insert & Print Data" << endl;
        cout << "2. Soal 2 - Search Hewan Ekor FALSE" << endl;
        cout << "3. Soal 3 - Delete Parent G004 & Print" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (!dataSudahDiinput) {
                    inputData(LP);
                    dataSudahDiinput = true;
                }
                cout << "\n=== OUTPUT SOAL 1 ===" << endl;
                printMLLStructure(LP);
                break;

            case 2:
                if (!dataSudahDiinput) {
                    cout << "Data belum diinput! Jalankan Soal 1 terlebih dahulu.\n";
                } else {
                    cout << "\n=== OUTPUT SOAL 2 (EKOR = FALSE) ===" << endl;
                    searchHewanByEkor(LP, false);
                }
                break;

            case 3:
                if (!dataSudahDiinput) {
                    cout << "Data belum diinput! Jalankan Soal 1 terlebih dahulu.\n";
                } else {
                    cout << "\n=== DELETE PARENT G004 (AMFIBI) ===" << endl;
                    // G004 berada setelah G003
                    deleteAfterParent(LP, LP.first->next->next);
                    printMLLStructure(LP);
                }
                break;

            case 0:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}

```
### dan untuk pemanggilannya pada :
``` c
 case 2:
                if (!dataSudahDiinput) {
                    cout << "Data belum diinput! Jalankan Soal 1 terlebih dahulu.\n";
                } else {
                    cout << "\n=== OUTPUT SOAL 2 (EKOR = FALSE) ===" << endl;
                    searchHewanByEkor(LP, false);
                }
                break;

```

### Output Unguided 2 : 

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_11/foto/soal2.png)



penjelasan unguided 2 <br/>
pada program pencarian data hewan yang tidak memiliki ekor (ekor = FALSE) dengan cara menelusuri seluruh list child pada setiap node parent di dalam struktur Multi Linked List. Hasil pencarian menampilkan data hewan yang sesuai dengan kriteria tanpa memengaruhi struktur data yang sudah ada.

### 3.SOAL ”
Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list
child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan
memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linked

## pengalan kode untuk menjalankan soal nomer 3 dimana LP.First ->next->next akan tepat menunjuk pada node G004
file main.h
```C++
case 3:
                if (!dataSudahDiinput) {
                    cout << "Data belum diinput! Jalankan Soal 1 terlebih dahulu.\n";
                } else {
                    cout << "\n=== DELETE PARENT G004 (AMFIBI) ===" << endl;
                    deleteAfterParent(LP, LP.first->next->next);
                    printMLLStructure(LP);
                }
                break;

```


### Output Unguided 3 : 

##### Output 3
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_11/foto/soal3.png)



penjelasan unguided 3 <br/>
Pada Soal Nomor 3 dilakukan operasi DELETE pada struktur data Multi Linked List, yaitu dengan menghapus node parent G004 (Amfibi) beserta seluruh node child yang dimilikinya. Proses penghapusan dilakukan menggunakan prosedur deleteAfterParent, dengan memberikan node parent sebelumnya (G003) sebagai acuan penghapusan.
Sebelum node parent G004 dihapus, sistem terlebih dahulu menjalankan prosedur deleteListChild untuk menghapus seluruh node child yang terhubung dengan parent tersebut. Hal ini bertujuan untuk mencegah terjadinya memory leak serta memastikan tidak ada data child yang masih tertinggal di memori.
Setelah node parent G004 berhasil dihapus, struktur Multi Linked List mengalami perubahan, di mana list parent kini hanya terdiri dari golongan Aves, Mamalia, Pisces, dan Reptil. Hasil dari pemanggilan kembali prosedur printMLLStructure menunjukkan bahwa data telah terhapus dengan benar dan relasi antar node parent dan child tetap terjaga dengan baik.


## Kesimpulan
Dari ketiga soal yang telah dikerjakan, dapat disimpulkan bahwa Multi Linked List sangat cocok digunakan untuk menyimpan data yang memiliki hubungan satu ke banyak, seperti golongan hewan dan data hewannya. Proses penambahan data, pencarian, dan penghapusan dapat dilakukan dengan baik tanpa merusak struktur data yang sudah ada. Setiap operasi berjalan sesuai dengan yang diharapkan, sehingga Multi Linked List terbukti efektif dan fleksibel untuk mengelola data yang saling berelasi.
## Referensi
[1] KAKIFIKOM — Implementasi Teknik Binary Search Tree Pada Pencarian Data Penduduk
https://ejournal.ust.ac.id/index.php/KAKIFIKOM/article/view/1794 
Ejournal UST<br/>
[2] Jurnal Ilmiah Universitas Satya Negara Indonesia — IMPLEMENTATION OF BINARY SEARCH TREE METHOD FOR ANDROID-BASED MORSE CODE DESCRIPTION
https://ejournal.usni.ac.id/index.php/jisni/article/view/27 <br/>
Rumah Jurnal USNI
[3] JRIIN : Jurnal Riset Informatika dan Inovasi — Pemanfaatan Pohon Biner Untuk Pemrosesan Data Efisien
https://jurnalmahasiswa.com/index.php/jriin/article/view/1264 <br/>