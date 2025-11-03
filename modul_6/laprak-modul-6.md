# <h1 align="center">Laporan Praktikum Modul 6 Doubly Liked List (Bagian Pertama) </h1>
<p align="center">M. Abdad mubarok - 103112400166</p>

## Dasar Teori
### A. Doubly linked list<br/>
Doubly Linked List (DLL) adalah struktur data yang tersusun dari serangkaian node, di mana setiap node menyimpan dua pointer: satu menunjuk ke elemen berikutnya (next) dan yang lainnya menunjuk ke elemen sebelumnya (prev). Berkat desain ini, kita bisa melakukan traversal dua arah, maju maupun mundur, dalam daftar tersebut [1].

Keunggulan utama DLL dibandingkan dengan singly linked list adalah kemudahan dalam melakukan operasi seperti penghapusan dan penyisipan di tengah list tanpa perlu repot mencari elemen pendahulu secara eksplisit [2]. Namun, kelebihan ini datang dengan konsekuensi: DLL membutuhkan ruang memori ekstra untuk menyimpan pointer prev dan algoritma pengolahannya menjadi sedikit lebih kompleks karena kedua pointer (next dan prev) harus selalu diperbarui dengan benar [3].
#### 

## Guided 

### 1.soal guided 1
file listMakan.h 
```C++
    #ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```
listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}

```
main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);// sebelum node c
    updateAfter(List, nodeC);//setelah node c

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}

```


penjelasan singkat guided 1
program diatas membahas pembuatan ADT DLL dengan data makanan yang berupa fungsi createList, alokasi, insertFirst, insertLast, insertAfter, insertBefore, dan printList. Operasi dilakukan sesuai urutan penyisipan sehingga node tersusun menjadi D – A – C – E – B. Setelah itu dilakukan update terhadap node pertama, terakhir, sebelum, dan sesudah node C [4].

### 2......
file Doublylist.h 
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif
```
file Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```

file main.cpp 

```C++

#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}
```
penjelasan Guided 2

pada guide yang berikutnya struktur DLL digunakan untuk menyimpan data kendaraan. Fungsi yang digunakan adalah createList, insertLast, findElm, dan deleteByNopol untuk mencari serta menghapus node tertentu berdasarkan nomor polisi. Proses ini memperlihatkan kemampuan DLL dalam menghapus elemen di awal, tengah, maupun akhir dengan efisien [5].
## Unguided 

### 1.SOAL ”
Buatlah ADT Doubly Linked list sebagai berikut di dalam file“Doublylist.h”.Buatlah implementasi ADT Doubly Linked list pada file“Doublylist.cpp” dan coba hasil implementasi ADT pada file “main.cpp”.Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ): address.Hapus elemen dengan nomor polisi D003 dengan procedure delete.

procedure deleteFirst( input/output L : List ,P : address )
procedure deleteLast( input/output L : List ,P : address )
procedure deleteAfter( input Prec : address ,input/output P : address )

file Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

struct ElmList {
    infotype info;
    ElmList *next;
    ElmList *prev;
};

struct List {
    ElmList *first;
    ElmList *last;
};

void createList(List &L);
ElmList* alokasi(infotype x);
void dealokasi(ElmList* p);
void insertLast(List &L, ElmList* p);
void printInfo(List L);

ElmList* findElm(List L, string x);
bool isDuplicate(List L, string nopol);

void deleteFirst(List &L, ElmList* &p);
void deleteLast(List &L, ElmList* &p);
void deleteAfter(List &L, ElmList* Prec, ElmList* &p);

#endif

```
file Doublylist.cpp
```C
#include "Doublylist.h"

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

ElmList* alokasi(infotype x) {
    ElmList* p = new ElmList;
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void dealokasi(ElmList* p) {
    delete p;
}

void insertLast(List &L, ElmList* p) {
    if (L.first == NULL) {
        L.first = p;
        L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

void printInfo(List L) {
    ElmList* p = L.first;
    int i = 1;
    cout << "DATA LIST 1" << endl;
    while (p != NULL) {
        cout << "no polisi : " << p->info.nopol << endl;
        cout << "warna     : " << p->info.warna << endl;
        cout << "tahun     : " << p->info.thnBuat << endl;
        cout << endl;
        p = p->next;
        i++;
    }
}

ElmList* findElm(List L, string x) {
    ElmList* p = L.first;
    while (p != NULL) {
        if (p->info.nopol == x) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

bool isDuplicate(List L, string nopol) {
    return findElm(L, nopol) != NULL;
}

void deleteFirst(List &L, ElmList* &p) {
    if (L.first != NULL) {
        p = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = p->next;
            L.first->prev = NULL;
            p->next = NULL;
        }
    }
}

void deleteLast(List &L, ElmList* &p) {
    if (L.last != NULL) {
        p = L.last;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.last = p->prev;
            L.last->next = NULL;
            p->prev = NULL;
        }
    }
}

void deleteAfter(List &L, ElmList* Prec, ElmList* &p) {
    if (Prec != NULL && Prec->next != NULL) {
        p = Prec->next;
        Prec->next = p->next;
        if (p->next != NULL) {
            p->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        p->next = NULL;
        p->prev = NULL;
    }
}

```
file main.cpp
```C
#include "Doublylist.h"

int main() {
    List L;
    createList(L);

    int n;
    cout << "Masukan banyak data : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        infotype x;
        cout << "\nmasukkan nomor polisi : ";
        cin >> x.nopol;

        if (isDuplicate(L, x.nopol)) {
            cout << "nomor polisi sudah terdaftar\n";
            continue;
        }

        cout << "masukkan warna kendaraan : ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan : ";
        cin >> x.thnBuat;

        ElmList* p = alokasi(x);
        insertLast(L, p);
    }

    cout << endl;
    printInfo(L);

    string cari;
    cout << "Masukan Nomor polisi yang dicari : ";
    cin >> cari;

    ElmList* found = findElm(L, cari);
    if (found != NULL) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan!\n";
    }

    string hapus;
    cout << "\nMasukkan nomor polisi yang akan dihapus : ";
    cin >> hapus;

    ElmList* del = findElm(L, hapus);
    if (del != NULL) {
        if (del == L.first) {
            deleteFirst(L, del);
        } else if (del == L.last) {
            deleteLast(L, del);
        } else {
            deleteAfter(L, del->prev, del);
        }
        cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus\n";
        dealokasi(del);
    } else {
        cout << "Data tidak ditemukan!\n";
    }

    printInfo(L);

    return 0;
}

```

### Output Unguided 1 : 

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_6/foto/soal1.png)



penjelasan unguided 1 <br/>
Bagian ini hanya menambahkan fungsi deleteFirst, deleteLast, dan deleteAfter pada ADT DLL. Operasi-operasi tersebut memperlihatkan bagaimana pointer next dan prev diperbarui agar integritas struktur list tetap terjaga setelah penghapusan node [6].





## Kesimpulan
Doubly Linked List (DLL) merupakan salah satu struktur data yang mudahan dalam proses traversal dua arah serta penyisipan dan penghapusan elemen di berbagai posisi [1]. Keunggulan ini menjadikan DLL lebih fleksibel dibandingkan struktur data sejenis, meskipun di sisi lain implementasinya memerlukan ketelitian yang tinggi dalam memperbarui setiap pointer agar tidak menimbulkan kesalahan seperti dangling pointer [3]. Berdasarkan percobaan yang telah dilakukan, dapat dibuktikan bahwa DLL dapat diterapkan secara efektif pada berbagai jenis data, misalnya untuk menyimpan informasi makanan maupun data kendaraan [4][5]. Selain itu, operasi dasar seperti penyisipan (insert), penghapusan (delete), dan pencarian (search) juga berhasil diimplementasikan dengan baik menggunakan konsep pointer dinamis yang menjadi inti dari struktur data ini [6].




## Referensi
[1] Wikipedia. Doubly Linked List. [Online]. Available: https://en.wikipedia.org/wiki/Doubly_linked_list
 <br>

[2] D. T. H. Ng and B. J. Oommen, “Generalizing Singly-Linked List Reorganizing Heuristics for Doubly-Linked Lists,” Mathematical Foundations of Computer Science (MFCS), 1989. [Online]. Available: https://people.scs.carleton.ca/~oommen/papers/NgOommenMFCS89.pdf
 <br>

[3] R. S. Valiveti, “Self-Organizing Doubly Linked Lists,” Science Direct, 1983. [Online]. Available: https://www.sciencedirect.com/science/article/pii/S0196677483710059
 <br>

[4] N. Garg, E. Zhu, and F. C. Botelho, “Highly-Concurrent Doubly-Linked Lists,” arXiv Preprint, 2011. [Online]. Available: https://arxiv.org/abs/1112.1141
 <br>

[5] D. Racordon, “Who Owns the Contents of a Doubly-Linked List?,” Programming 2025, Dagstuhl, 2025. [Online]. Available: https://drops.dagstuhl.de/storage/01oasics/oasics-vol134-programming2025/OASIcs.Programming.2025.25/OASIcs.Programming.2025.25.pdf
 <br>

[6] RIP Linked List: Empirical Study to Discourage You from Using Linked Lists Any Further, arXiv, 2023. [Online]. Available: https://arxiv.org/html/2306.06942v2
 <br>
