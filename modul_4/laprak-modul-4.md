# <h1 align="center">Laporan Praktikum Modul 4 </h1>
<p align="center">M. Abdad mubarok - 103112400166</p>

## Dasar Teori
Bahasa C++ merupakan bahasa pemrograman tingkat tinggi yang banyak digunakan dalam pengembangan perangkat lunak modern [1]. Bahasa ini mendukung paradigma pemrograman prosedural, berorientasi objek, dan generic programming, sehingga sangat fleksibel untuk berbagai kebutuhan [2].
C++ dapat dijalankan di berbagai platform seperti sistem operasi, aplikasi desktop, perangkat tertanam (embedded system), hingga pengembangan gim [1][3].

Selain itu, konsep dasar dalam C++ seperti Abstract Data Type (ADT) memungkinkan programmer untuk memisahkan definisi tipe data dari implementasinya, sehingga kode menjadi lebih modular dan mudah dikelola [4].

### A. Abstarct Data Type (ADT)<br/>
#### 
Abstract Data Type (ADT) merupakan model konseptual dari sebuah tipe data yang hanya mendefinisikan operasi yang dapat dilakukan tanpa menunjukkan implementasi detailnya [5].
Dengan ADT, pengembang dapat memisahkan antara interface (apa yang dapat dilakukan) dan implementation (bagaimana dilakukan). Hal ini mendukung prinsip enkapsulasi dan modularitas dalam pemrograman [6].


## Guided 

### 1.soal guided 1
file lish.h 
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};
typedef mahasiswa dataMahasiswa;
typedef struct node *address;
struct node{ 
    dataMahasiswa isidata;
    address next;
};
struct linkedlist{ 
    address first;
};
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```
list.cpp
```C++
#include "list.h"
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
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}
address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}
void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}
void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}
void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

```
main.cpp
```C++
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```


penjelasan singkat guided 1
Program pada guided 1 menerapkan konsep dasar pembuatan singly linked list dengan operasi insert (penyisipan) dan print (penampilan isi list).
Struktur mahasiswa digunakan sebagai tipe data yang disimpan dalam setiap node, dengan field nama, nim, dan umur.




### 1.soal guided 2
file lish.h 
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};
typedef mahasiswa dataMahasiswa;
typedef struct node *address;
struct node{ 
    dataMahasiswa isidata;
    address next;
};
struct linkedlist{ 
    address first;
};
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```
file list.cpp
```C++
#include "list.h"
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
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) { 
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```
file main.cpp 
```C
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}

```

penjelasan singkat guided 2
Pada guided 2, program sebelumnya dikembangkan dengan menambahkan fungsi penghapusan node dan penghitungan jumlah elemen.Program ini menunjukkan penerapan ADT yang lebih lengkap, mencakup operasi insert, delete, traverse, dan count, yang merupakan karakteristik dasar dari linked list. Dengan konsep modular,



## Unguided 

### 1.Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”
file singlyist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List &L);
void insertFirst(List &L, int nilai);
void insertAfter(Node* prevNode, int nilai);
void insertLast(List &L, int nilai);
void printList(List L);

#endif


```
file singlyist.cpp
```C
#include "singlylist.h"

void createList(List &L) {
    L.first = nullptr;
}

void insertFirst(List &L, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = L.first;
    L.first = newNode;
}

void insertAfter(Node* prevNode, int nilai) {
    if (prevNode == nullptr) return;
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertLast(List &L, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = nullptr;

    if (L.first == nullptr) {
        L.first = newNode;
    } else {
        Node* temp = L.first;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void printList(List L) {
    Node* temp = L.first;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

```
file main.cpp
```C
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    insertFirst(L, 2);
    insertFirst(L, 9);
    insertFirst(L, 12);
    insertAfter(L.first->next, 8); 

    cout << "Isi Linked List: ";
    printList(L);

    return 0;
}


```

### Output Unguided 1 : 

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_3/ss_soal_1.png)



penjelasan unguided 1 <br/>
Tiga operasi penyisipan yang diimplementasikan adalah:

insertFirst() → menambah node di awal list.

insertAfter() → menambah node setelah node tertentu.

insertLast() → menambah node di akhir list.

Fungsi printList() menampilkan seluruh isi list secara berurutan.
Melalui program ini, konsep dynamic memory allocation pada linked list terlihat jelas: node dibuat secara dinamis menggunakan operator new, dan hubungan antar-node dibentuk menggunakan pointer next.

### 2. lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList()

"Singleylist.h"

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List &L);
void insertFirst(List &L, int nilai);
void insertAfter(Node* prevNode, int nilai);
void insertLast(List &L, int nilai);

void deleteFirst(List &L);
void deleteAfter(Node* prevNode);
void deleteLast(List &L);

void printList(List L);
int nbList(List L);
void deleteList(List &L);

#endif

```
"Singleylist.cpp"
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.first = nullptr;
}

void insertFirst(List &L, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = L.first;
    L.first = newNode;
}

void insertAfter(Node* prevNode, int nilai) {
    if (prevNode == nullptr) return;
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertLast(List &L, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = nullptr;

    if (L.first == nullptr) {
        L.first = newNode;
    } else {
        Node* temp = L.first;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteFirst(List &L) {
    if (L.first != nullptr) {
        Node* hapus = L.first;
        L.first = L.first->next;
        delete hapus;
    }
}

void deleteAfter(Node* prevNode) {
    if (prevNode != nullptr && prevNode->next != nullptr) {
        Node* hapus = prevNode->next;
        prevNode->next = hapus->next;
        delete hapus;
    }
}

void deleteLast(List &L) {
    if (L.first != nullptr) {
        if (L.first->next == nullptr) {
            delete L.first;
            L.first = nullptr;
        } else {
            Node* temp = L.first;
            while (temp->next->next != nullptr)
                temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
    }
}

void printList(List L) {
    Node* temp = L.first;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int nbList(List L) {
    int count = 0;
    Node* temp = L.first;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.first != nullptr) {
        deleteFirst(L);
    }
}


```
main.cpp

```C++
#include <iostream>
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    insertFirst(L, 2);
    insertFirst(L, 8);
    insertFirst(L, 9);
    insertFirst(L, 12);

    cout << "Linked List Awal: ";
    printList(L);

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L.first);

    cout << "\nSetelah Penghapusan: ";
    printList(L);

    cout << "\nJumlah node : " << nbList(L) << endl;

    deleteList(L);

    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}


```

### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_3/ss_soal_2.png)


penjelasan unguided 2 <br/>
Program ini merupakan lanjutan dari Unguided 1 dengan penambahan beberapa operasi baru, yaitu penghapusan dan perhitungan jumlah node dalam list.
Fungsi deleteFirst() digunakan untuk menghapus node yang berada di posisi paling awal, sedangkan deleteLast() berfungsi menghapus node terakhir dalam list.
Fungsi deleteAfter() digunakan untuk menghapus node yang berada setelah node tertentu. Selain itu, nbList() menghitung berapa banyak node yang tersimpan, dan deleteList() berfungsi untuk menghapus seluruh node sehingga list menjadi kosong.



## Kesimpulan
Dari percobaan pada modul ini, bisa disimpulkan bahwa penggunaan ADT (Abstract Data Type) dalam bahasa C++ sangat membantu dalam membuat program yang terorganisasi dan lebih mudah dikelola.
Dengan menerapkan Singly Linked List, mahasiswa memahami cara kerja penyimpanan data secara dinamis menggunakan pointer, mulai dari proses menambahkan, menghapus, hingga menghitung jumlah node.


Selain itu, percobaan ini juga menunjukkan betapa pentingnya mengelola memori secara manual dalam C++, karena setiap node harus dialokasikan dan dihapus dengan tepat agar tidak terjadi kebocoran memori.

Secara umum, konsep ADT dan struktur data linked list memberikan dasar yang baik untuk memahami bagaimana data bisa diatur dan diolah secara efisien dalam pemrograman lanjutan.


## Referensi
[1] Berdi, Dasar Logika Pemrograman C++, Universitas Katolik Soegijapranata, 2025.<br>
[2] Bjarne Stroustrup, The C++ Programming Language, Addison-Wesley, 2013.<br>
[3] Deitel, H. & Deitel, P., C++ How to Program (10th Edition), Pearson, 2016.<br>
[4] Malik, D. S., C++ Programming: From Problem Analysis to Program Design, Cengage Learning, 2018.<br>
[5] Wirth, N., Algorithms + Data Structures = Programs, Prentice Hall, 1976.<br>
[6] Liang, Y. D., Introduction to Programming with C++, Pearson, 2022.<br>