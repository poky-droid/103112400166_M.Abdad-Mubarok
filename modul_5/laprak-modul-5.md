# <h1 align="center">Laporan Praktikum Modul 5 Linear Search dan Binary Search </h1>
<p align="center">M. Abdad mubarok - 103112400166</p>

## Dasar Teori
### A. Binary Search<br/>
#### 
Binary Search adalah algoritma yang digunakan untuk mencari data dengan cara yang cepat, terutama ketika data sudah diurutkan. Cara kerjanya adalah dengan membagi dua bagian dari daerah pencarian secara berulang hingga data yang dicari ditemukan atau proses pencarian berakhir. Algoritma ini berbasis pada prinsip divide and conquer, yaitu memecah masalah besar menjadi beberapa masalah yang lebih kecil dan mudah ditangani.

Menurut Bhusari, Vaz, dan Jore [1], Binary Search memiliki kompleksitas waktu rata-rata sebesar O(log n), yang membuatnya jauh lebih efisien dibandingkan algoritma Linear Search yang memiliki kompleksitas O(n).
Meskipun demikian, Binary Search hanya bisa digunakan jika data dalam bentuk list atau array sudah terurut secara baik.

Selain itu, Parmar dan Kumbharana [2] menjelaskan bahwa Binary Search memiliki performa yang lebih baik terutama pada struktur data static array, karena akses langsung ke indeks memudahkan proses membagi data menjadi dua bagian secara berulang.
### B. Linear Search<br/>
#### 
Linear Search, juga disebut sebagai sequential search, adalah metode pencarian yang paling mudah. Cara kerjanya adalah dengan memeriksa setiap elemen satu persatu, mulai dari awal sampai akhir. Meskipun metode ini cukup sederhana, kelemahannya adalah kurang efisien terutama ketika data yang dicari berada di posisi terakhir atau bahkan tidak ada di dalam dataset.

Menurut Saha, Bhaumik, dan Das [3], Linear Search memiliki kompleksitas waktu O(n) dan tidak membutuhkan data yang sudah tersusun secara terurut.
Mereka juga mengusulkan versi yang dimodifikasi agar bisa mengurangi jumlah perbandingan dalam beberapa kasus tertentu dengan menggunakan pendekatan prediksi posisi data.

Zia [4] mengatakan bahwa Linear Search masih relevan digunakan untuk dataset yang ukurannya kecil atau struktur data yang sulit diurutkan, seperti linked list.
Selain itu, metode ini sering digunakan sebagai dasar untuk mempelajari konsep dasar pencarian sebelum memahami algoritma yang lebih rumit, seperti Binary Search atau Interpolation Search.

## Guided 

### 1.soal guided 1
file listBuah.h 
```C++
    #ifndef LISTBUAH_H
    #define LISTBUAH_H

    #define Nil NULL
    #include <iostream>
    using namespace std;

    struct buah {
        string nama;
        int jumlah;
        float harga;
    };

    typedef buah dataBuah;
    typedef struct node *address;

    struct node {
        dataBuah isidata;
        address next;
    };

    struct linkedlist {
        address first;
    };

    // ==== DEKLARASI / PROTOTYPE ====
    bool isEmpty(linkedlist List);
    void createList(linkedlist &List);

    address alokasi(string nama, int jumlah, float harga);
    void dealokasi(address &node);

    void insertFirst(linkedlist &List, address nodeBaru);
    void insertAfter(linkedlist &List, address nodeBaru, address Prev);
    void insertLast(linkedlist &List, address nodeBaru);

    void delFirst(linkedlist &List);
    void delLast(linkedlist &List);
    void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

    void printList(linkedlist List);
    int nbList(linkedlist List);
    void deleteList(linkedlist &List);

    // === Fungsi update data ===
    void updateFirst(linkedlist List);
    void updateLast(linkedlist List);
    void updateAfter(linkedlist List, address nodePrev);

    #endif
```
listBuah.cpp
```C++
#include "listbuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
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

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List) {
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List) {
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama Buah : " << nodeBantu->isidata.nama
            << ", Jumlah : " << nodeBantu->isidata.jumlah
            << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}

//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node "<< nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

```
main.cpp
```C++
#include "listBuah.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout <<"--- ISI LIST SETELAH DILAKUKAN INSERT---" << endl;
    printList(List);
    cout <<"jumlah node:" << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout <<"--- ISI LIST SETELAH DILAKUKAN UPDATE---" << endl;
    printList(List);
    cout << "jumlah node:" << nbList(List) << endl;
    cout << endl;

    return 0;
}

```


penjelasan singkat guided 1
Di bagian Guided 1, program menunjukkan cara membuat linked list yang sederhana menggunakan bahasa C++.
Struktur data node digunakan untuk menyimpan informasi buah, yaitu nama, jumlah, dan harga.

Beberapa fungsi penting telah diimplementasikan, antara lain:

- createList() untuk membuat list yang kosong,
- insertFirst(), insertLast(), dan insertAfter() untuk menambahkan data ke dalam list,
- delFirst(), delLast(), dan delAfter() untuk menghapus data dari list,
- updateFirst(), updateLast(), dan updateAfter() untuk mengubah data di dalam node tertentu.


Selain itu, ada fungsi printList() yang digunakan untuk menampilkan semua data dalam list, sedangkan nbList() berfungsi menghitung jumlah node yang ada dalam list.

Program ini membantu memahami cara kerja dasar dari linked list sebelum digunakan dalam algoritma pencarian seperti Linear Search atau Binary Search.





### 2......
file binary.h 
```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara binary
Node* binarySearch(Node* head, int key) { //Node* ini pointer (kembalian) // head ini pointer ke node pertama //key ini data yang dicari
    int size = 0; //var size disi 0
    for (Node* current = head; current;current = current->next)size++; //current adalah pointer yan digunakan untuk menyusuri linked linked list
    Node *start = head; //start adalah pointer yang menunjuk ke node pertama
    Node *end = nullptr; //end adalah pointer yang menunjuk ke node terakhir (null karena linked list tidak memiliki pointer ke node terakhir yang pasti)

    while(size > 0) { //selama masih ada elemen > 0
        int mid = size / 2; //bagi size jadi 2
        Node* midNode = start; //midNode adalah pointer yang menunjuk ke node tengah
        for (int i = 0 ; i< mid;i++)midNode = midNode->next; //pindah ke node tengah

        if(midNode->data == key)return midNode; //jika ditemukan data yang cocok, kembalikan node
        if(midNode->data < key) { //jika data midNode lebih kecil dari key, kita cari dibagian kanan
            start = midNode->next; //Mulai pencarian dari node setelah midNode
        }
        else { //jika data midNode lebih besar dari key, kita cari dibagian kiri
            end = midNode; //Akhiri pencarian di midNode
        }
        size -= mid; //kita mengurangi size dengan mid
    }
    return nullptr; //jika key tidak ditemukan
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode; // node terakhir dihubungkan ke node baru
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30);
    append(head, 40);
    append(head, 50); //menambah node

    //mencari data 40  menggunakan binarysearch
    Node* result = binarySearch(head, 40); //result ini pointer untuk mencari data 40
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
file linear.cpp
```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara linear
Node* linearSearch(Node* head, int key) {//head adalah pointer ke node pertama, key adalah nilai yang dicari
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //selama current tidak null
        if (current->data == key)//jika data pada node saat ini sama dengan key
        return current; //kembalikan pointer ke node yang ditemukan
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //jika tidak ditemukan, kembalikan null
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
penjelasan singkat guided 2

Di Guided 2, terdapat dua cara untuk mencari data menggunakan algoritma, yaitu Binary Search dan Linear Search, keduanya menggunakan struktur data Linked List.

Cara Linear Search bekerja dengan memeriksa setiap node satu per satu mulai dari awal sampai akhir.
Jika data yang dicari ditemukan, maka program akan mengembalikan alamat node tersebut. Metode ini mudah dipahami, tetapi tidak efisien ketika data yang dicari banyak.

Sementara itu, Binary Search bekerja dengan membagi area pencarian menjadi dua bagian setiap kali proses dilakukan.
Oleh karena itu, data harus sudah teratur sebelum digunakan. Algoritma ini lebih cepat dibandingkan Linear Search, karena kompleksitas waktu rata-ratanya adalah O(log n) dibandingkan O(n) [1][2].

Tujuan dari program ini adalah menunjukkan perbedaan kecepatan dan cara kerja kedua metode pencarian tersebut saat diterapkan dalam linked list.


## Unguided 

### 1.binary search”
file linkedlist.h
```C++
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value);
void append(Node*& head, int value);
void displayList(Node* head);
int getSize(Node* head);
Node* getNodeAt(Node* head, int index);
Node* binarySearch(Node* head, int key);

#endif

```
file linkedlist.cpp
```C
#include "LinkedList.h"

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void append(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    cout << "Linked List yang dibuat: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int getSize(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getNodeAt(Node* head, int index) {
    for (int i = 0; head && i < index; i++)
        head = head->next;
    return head;
}

Node* binarySearch(Node* head, int key) {
    cout << "\nMencari nilai: " << key << endl;
    cout << "\nProses Pencarian:" << endl;

    int left = 0;
    int right = getSize(head) - 1;
    int iterasi = 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(head, mid);

        cout << "Iterasi " << iterasi++ << ": Mid = " << midNode->data
             << " (indeks tengah)";

        if (midNode->data == key) {
            cout << " - DITEMUKAN!\n";
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << midNode << endl;
            cout << "Data node: " << midNode->data << endl;
            if (midNode->next)
                cout << "Node berikutnya: " << midNode->next->data << endl;
            else
                cout << "Node berikutnya: (tidak ada, ini node terakhir)\n";
            return midNode;
        } else if (midNode->data < key) {
            cout << " -> Cari di bagian kanan\n";
            left = mid + 1;
        } else {
            cout << " -> Cari di bagian kiri\n";
            right = mid - 1;
        }
    }

    cout << "Tidak ada elemen tersisa\n";
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}

```
file main.cpp
```C
#include "linkedlist.h"

int main() {
    cout << "BINARY SEARCH PADA LINKED LIST\n\n";

    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    displayList(head);

    int key1,key2;
    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> key1;
    binarySearch(head, key1);

    cout << "\nMasukkan nilai kedua yang ingin dicari: ";
    cin >> key2;
    binarySearch(head, key2);

    return 0;
}


```

### Output Unguided 1 : 

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_5/foto/soal_1.png)



penjelasan unguided 1 <br/>
Bagian Unguided 1 menunjukkan cara menerapkan Binary Search pada linked list.
Program tersebut menambahkan beberapa node yang berisi data berupa bilangan bulat yang telah diurutkan, lalu melakukan pencarian berdasarkan input yang dimasukkan oleh pengguna.


Pencarian dilakukan secara bertahap, dengan menampilkan nilai tengah (mid) dan arah pencarian (ke kiri atau ke kanan).

Jika data yang dicari ditemukan, program akan menampilkan node yang berisi data tersebut beserta alamat memori tempat data tersebut disimpan.

Metode ini efektif untuk mencari data dalam struktur linked list yang sudah terurut, sesuai dengan hasil penelitian Bhusari dkk.
[1] dan Parmar & Kumbharana [2].


### 2. linear search

"LinkedLish.h"

```C++
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value);

Node* linearSearch(Node* head, int key);

void displayList(Node* head);

#endif


```
"LinkedLish.cpp"
```C++
#include "LinkedLish.h"

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

Node* linearSearch(Node* head, int key) {
    Node* temp = head;
    int step = 1;

    cout << "\nProses Pencarian:\n";
    while (temp) {
        cout << "Memeriksa node ke-" << step 
             << ": " << temp->data;

        if (temp->data == key) {
            cout << " (SAMA) -> DITEMUKAN!\n";
            return temp;
        } else {
            cout << " (tidak sama)\n";
        }

        temp = temp->next;
        step++;
    }

    cout << "Tidak ada node lagi yang tersisa.\n";
    return nullptr;
}

```
main.cpp

```C++
#include "LinkedLish.h"
#include "LinkedLish.h"

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "LINEAR SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: ";
    displayList(head);

    int key;

    key = 30;
    cout << "\nMencari nilai: " << key << endl;
    Node* found = linearSearch(head, key);

    if (found)
        cout << "\nHasil: Nilai " << key << " DITEMUKAN dalam linked list!"
             << "\nAlamat node: " << found << endl;
    else
        cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;

    key = 25;
    cout << "\n\nMencari nilai: " << key << endl;
    found = linearSearch(head, key);

    if (found)
        cout << "\nHasil: Nilai " << key << " DITEMUKAN dalam linked list!"
             << "\nAlamat node: " << found << endl;
    else
        cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;

    return 0;
}

```

### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_5/foto/soal_2.png)


penjelasan unguided 2 <br/>

Bagian Unguided 2 menerapkan pencarian linear pada linked list.
Program menambahkan beberapa node, lalu mencari nilai tertentu secara berurutan mulai dari awal hingga akhir list.


Setiap tahap pencarian ditampilkan dengan jelas, menunjukkan cara program memeriksa setiap node satu persatu.

Bila data ditemukan, alamat memori node tersebut akan ditampilkan.


Metode ini sederhana dan efektif untuk dataset yang ukurannya kecil, seperti yang dijelaskan oleh Saha dkk.
[3] dan Zia [4], namun kurang efisien untuk dataset besar karena waktu yang dibutuhkan untuk mencari meningkat secara linear sesuai dengan ukuran data.


## Kesimpulan
Dari hasil percobaan di atas dapat disimpulkan bahwa:

Linear Search mudah diaplikasikan dan tidak memerlukan data yang sudah terurut, tetapi kurang efisien ketika jumlah datanya besar karena kompleksitasnya mencapai O(n).


Binary Search jauh lebih cepat dengan kompleksitas O(log n) karena membagi area pencarian secara teratur, tetapi hanya bisa digunakan jika data sudah diurutkan.


Pemilihan algoritma tergantung pada ukuran data dan cara penyimpanannya.


Berdasarkan referensi [1][2][3][4], Binary Search lebih unggul dalam hal efisiensi waktu, sedangkan Linear Search lebih fleksibel dalam berbagai kondisi data.




## Referensi
[1] Bhusari, C., Vaz, S., & Jore, Y. (2020). Comparison between Linear Search and Binary Search. International Journal of Trend in Research and Development (IJTRD).<br>
[2] Parmar, V. P., & Kumbharana, C. K. (2015). Comparing Linear Search and Binary Search Algorithms to Search an Element from a Linear List Implemented through Static Array, Dynamic Array and Linked List. International Journal of Computer Applications (IJCA).<br>
[3] Saha, S., Bhaumik, M. K., & Das, S. (2019). A New Modified Linear Search Algorithm. International Journal of Mathematics Trends and Technology (IJMTT). DOI: 10.14445/22315373/IJMTT-V65I12P516.<br>
[4] Zia, A. S. (2020). A Survey on Different Searching Algorithms. International Research Journal of Engineering and Technology (IRJET).<br>
