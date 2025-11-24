# <h1 align="center">Laporan Praktikum Modul 8 Queue </h1>
<p align="center">M. Abdad mubarok - 103112400166</p>

## Dasar Teori
### A. Queue<br/>
Queue adalah struktur data linear yang mengikuti prinsip FIFO (First In First Out). Artinya elemen yang pertama masuk akan menjadi elemen pertama yang diproses atau keluar. Struktur queue secara umum digunakan pada sistem yang membutuhkan proses antrian seperti sistem kasir, proses pencetakan, penjadwalan proses, dan lainnya. Menurut jurnal Implementasi Struktur Data Queue pada manajemen antrian, konsep FIFO digunakan agar alur layanan menjadi adil dan teratur [1].

Pada queue, elemen ditambahkan melalui bagian belakang yang disebut tail, dan dihapus melalui bagian depan yang disebut head.


#### 
#### B.Operasi Dasar queue<br/>
Operasi dasar pada queue meliputi:
Enqueue
Menambahkan elemen pada bagian belakang (tail) antrian.
Dequeue
Menghapus elemen pada bagian depan (head) antrian.
IsEmpty
Mengecek apakah antrian kosong.
IsFull
Mengecek apakah antrian penuh (khusus queue berbasis array).
Display / PrintInfo
Menampilkan isi queue saat ini.

Konsep operasi seperti ini banyak digunakan dalam simulasi antrian bank dan pelayanan publik untuk memodelkan waktu tunggu dan pergerakan pelanggan [2].

###
#### C.Implementasi queue<br/>
Queue dapat diimplementasikan dengan dua cara:

Array (Static Queue)
Penyimpanan elemen menggunakan indeks tetap. Kekurangannya adalah ukuran queue terbatas.

Linked List (Dynamic Queue)
Penyimpanan elemen menggunakan node dinamis sehingga ukuran queue dapat fleksibel.

Implementasi berbasis linked list memudahkan proses enqueue dan dequeue karena tidak perlu menggeser data seperti pada array [3].

###
#### D.Implementasi Queue<br/>
Circular queue adalah modifikasi dari queue biasa, di mana indeks head dan tail dapat kembali ke posisi awal apabila sudah mencapai indeks maksimal. Teknik circular queue membuat penggunaan memori lebih efisien sehingga tidak ada ruang array terbuang.

###


## Guided 

###  guided 1
file queue.h 
```C++
 #ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL
#include <iostream>
using namespace std;
typedef struct node *address;
struct node{
   int dataAngka;
   address next;
};
struct Queue {
    address head;
    address tail;
};
bool isEmpty(Queue Q);
void createQueue(Queue &Q);
address alokasi(int angka);
void dealokasi(Queue &node);
void enqueue(Queue &Q, address nodeBaru);
int dequeue(Queue &Q);
void updateQueue(Queue &Q, int posisi);
void viewQueue(Queue Q);
void searchData(Queue Q, int data);
#endif
```
queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(Queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(Queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enqueue(Queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

int dequeue(Queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(Queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(Queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(Queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}

```
main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enqueue(Q, nodeA);
    enqueue(Q, nodeB);
    enqueue(Q, nodeC);
    enqueue(Q, nodeD);
    enqueue(Q, nodeE);
    cout << endl;

    cout << "queue setelah dihapus " << endl;
    viewQueue(Q);
    cout << endl;

    dequeue(Q);
    dequeue(Q);
    cout << endl;

    cout << "queue setelah deque 2 kali" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "queue setelah diupdate " << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);
    return 0;
}
```


penjelasan singkat guided 1
Pada guided pertama, queue diimplementasikan menggunakan linked list. Tiap node menyimpan data dan pointer next. Struktur queue berisi head dan tail.

Operasi utama:
createQueue: menginisialisasi queue kosong
alokasi: membuat node baru
enqueue: menambah node ke bagian tail
dequeue: menghapus node dari head
updateQueue: memperbarui data berdasarkan posisi
searchData: mencari data dalam queue
viewQueue: menampilkan isi queue

Kelebihan implementasi ini adalah queue bersifat dinamis sehingga tidak ada batas ukuran, sesuai dengan teori queue berbasis linked list [3].


### 2......
file queue.h 
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
struct Queue
{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};
void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif


```
file queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```
file main.cpp
```C++
#include <iostream>
#include"queue.h"
using namespace std;
int main (){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueu 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    
    cout << "\n dequeue 1 elemen" << endl;
    cout << "elemen keluar : " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "enqueu 1 elemen " << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\n dequeue 2 elemen " << endl;
    cout << "elemen keluar : " << dequeue(Q) << endl;
    cout << "elemen keluar : " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```
Pada guided kedua, queue diimplementasikan menggunakan array berukuran tetap dengan mekanisme circular.
Ciri khas implementasi circular:
Index tail dan head bergerak dengan operasi modulus % MAX_QUEUE
Memori array digunakan secara penuh tanpa ruang kosong di awal
Operasi yang dilakukan:
Enqueue: menambah data pada tail secara melingkar
Dequeue: mengambil data dari head
printInfo: mencetak seluruh elemen queue sesuai posisi circular
Implementasi circular queue ini secara nyata digunakan pada sistem penjadwalan dan buffer data (misalnya keyboard buffer pada OS) [1].


## Unguided 

### 1.SOAL ”
Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file“queue.h”.Buatlah implementasi ADT Queue pada file“queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).


file Queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

typedef int Infotype;
typedef struct Queue {
    int info [5];
    int head;
    int tail;     

} Queue;

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, Infotype x);
Infotype dequeue(Queue &Q);
void printInfoQueue(Queue Q);
#endif
```
file Queue.cpp
```C
#include "Queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;

}

bool isEmptyQueue(Queue Q){
    return (Q.head == -1 && Q.tail == -1);
}
bool isFullQueue(Queue Q){
    return (Q.tail == 4);
}
void enqueue(Queue &Q, Infotype x){
    if(isFullQueue(Q)){
        cout << "queue penuh" << endl;

    }
    if (isEmptyQueue(Q)){
        Q.head = 1;
        Q.tail = 1;
        Q.info[0] = x;
    }else{
        Q.tail++;
        Q.info[Q.tail - 1] = x;
    }
    
}

Infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "queue kosong" << endl;
        return -1;
    }
    Infotype hasil = Q.info[0];
    for (int i = 0; i < Q.tail - 1; i++){
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;
    if (Q.tail == 0){
        Q.head = 0;
    }
    return hasil;
}
void printInfoQueue(Queue Q) {
    int H, T;

    if (isEmptyQueue(Q)) {
        H = -1;
        T = -1;
    } else {
        H = Q.head - 1;   
        T = Q.tail - 1;   
    }

    cout << H << "  -  " << T << "  |  ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = 0; i < Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}


```
file main.cpp
```C
#include "Queue.h"
using namespace std;
#include <iostream>

int main(){
    cout <<"Hello World!" << endl;
    Queue Q;
    CreateQueue(Q);

    cout<<"-------------------------"<<endl;
    cout<<"H - T \t | Queue info    "<< endl;
    cout<<"-------------------------"<<endl;
    printInfoQueue(Q);
    enqueue (Q, 5); printInfoQueue(Q);
    enqueue (Q, 2); printInfoQueue(Q);
    enqueue (Q, 7); printInfoQueue(Q);
    dequeue (Q); printInfoQueue(Q);
    enqueue (Q, 4); printInfoQueue(Q);
    dequeue (Q); printInfoQueue(Q);
    dequeue (Q); printInfoQueue(Q);

    return 0;
}

```

### Output Unguided 1 : 

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_8/foto/soal1.png)



penjelasan unguided 1 <br/>
Pada program ini, head berada pada posisi tetap (index 0), sedangkan tail bergerak ke kanan setiap kali elemen ditambahkan. Ketika dequeue dilakukan, semua elemen digeser ke kiri satu posisi agar elemen terdepan selalu di index ke-0.
Kelebihan: simple
Kekurangan: tidak efisien karena membutuhkan operasi shifting pada seluruh array setiap kali dequeue.
Model seperti ini hanya cocok untuk queue kecil karena kompleksitas dequeue adalah O(n).




### 2.SOAL ”
Buatlah implementasi ADT Queue pada file“queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

file Queue.h
```C++
#ifndef MODUL8_SOAL2_QUEUE_H
#define MODUL8_SOAL2_QUEUE_H
#include <iostream>

typedef int Infotype;
typedef struct Queue {
    int info[5];
    int head;
    int tail;

} Queue;

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, Infotype x);
Infotype dequeue(Queue &Q);
void printInfoQueue(Queue Q);
#endif

```
file Queue.cpp
```C
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;

}

bool isEmptyQueue(Queue Q){
    return (Q.head == -1 && Q.tail == -1);
}
bool isFullQueue(Queue Q){
    return (Q.tail == 4);
}
void enqueue(Queue &Q, Infotype x){
   if (!isFullQueue(Q)){
        if (isEmptyQueue(Q)){
            Q.head = 0;
            Q.tail = 0;
            Q.info[Q.tail] = x;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    } else {
        cout << "queue penuh \n";
    }

}
Infotype dequeue(Queue &Q){
    if (!isEmptyQueue(Q)) {
        int x = Q.info[Q.head];

        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head++;
        }
        return x;
    }
    cout << "Queue kosong!\n";
    return -1;

}

void printInfoQueue(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << "\n";
}
```
file main.cpp
```C
#include "queue.h"
using namespace std;
#include <iostream>

int main(){
    cout <<"Hello World!" << endl;
    Queue Q;
    CreateQueue(Q);

    cout<<"-------------------------"<<endl;
    cout<<"H - T \t | Queue info    "<< endl;
    cout<<"-------------------------"<<endl;
    printInfoQueue(Q);
    enqueue (Q, 5); printInfoQueue(Q);
    enqueue (Q, 2); printInfoQueue(Q);
    enqueue (Q, 7); printInfoQueue(Q);
    dequeue (Q); printInfoQueue(Q);
    enqueue (Q, 4); printInfoQueue(Q);
    dequeue (Q); printInfoQueue(Q);
    dequeue (Q); printInfoQueue(Q);

    return 0;
}
```

### Output Unguided 2 : 

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_8/foto/soal2.png)



penjelasan unguided 2 <br/>
Pada metode ini, baik head maupun tail bergerak maju seiring enqueue dan dequeue tanpa perlu menggeser elemen array.
Enqueue: tail bertambah
Dequeue: head bertambah
Jika head > tail → queue kosong



### 3.SOAL ”


file queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

#define MAX 5

typedef int Infotype;
typedef struct Queue {
    int info [MAX];
    int head;
    int tail;     

} Queue;

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, Infotype x);
Infotype dequeue(Queue &Q);
void printInfoQueue(Queue Q);
#endif
```
file queue.cpp
```C
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;

}

bool isEmptyQueue(Queue Q){
    return (Q.head == -1 && Q.tail == -1);
}
bool isFullQueue(Queue Q){
    return (Q.tail == MAX - 1);
}
void printInfoQueue(Queue Q){
    cout << " " << Q.head << " - " << Q.tail << "\t | ";

    if(isEmptyQueue(Q)){
        cout << "Queue kosong" << endl;
        return;
    }

    int i = Q.head;
    while(true){
        cout << Q.info[i] << " ";
        if(i == Q.tail) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}
void enqueue(Queue &Q, Infotype x){
    if (isFullQueue(Q)){
        cout << "queue penuh" << endl;
        return;
    }
    if(isEmptyQueue(Q)){
        Q.head = 0;
        Q.tail = 0;

    }else{
        Q.tail = (Q.tail + 1) % MAX;
    }
    Q.info[Q.tail] = x;
}
Infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        return -1;
    }
    Infotype temp = Q.info[Q.head];
    if(Q.head == Q.tail){
        Q.head = -1;
        Q.tail = -1;
    }else{
        Q.head = (Q.head + 1) % MAX;
    }
    return temp;
}


```
file main.cpp
```C
#include "queue.h"
using namespace std;
#include <iostream>

int main(){
    cout <<"Hello World!" << endl;
    Queue Q;
    CreateQueue(Q);

    cout<<"-------------------------"<<endl;
    cout<<"H - T \t | Queue info    "<< endl;
    cout<<"-------------------------"<<endl;
    printInfoQueue(Q);
    enqueue (Q, 5); printInfoQueue(Q);
    enqueue (Q, 2); printInfoQueue(Q);
    enqueue (Q, 7); printInfoQueue(Q);
    dequeue (Q); printInfoQueue(Q);
    enqueue (Q, 4); printInfoQueue(Q);
    dequeue (Q); printInfoQueue(Q);
    dequeue (Q); printInfoQueue(Q);

    return 0;
}
```

### Output Unguided 3 : 

##### Output 3
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_8/foto/soal3.png)



penjelasan unguided 3 <br/>
Pada metode ini, queue menggunakan array circular:
Jika tail mencapai index akhir, maka tail = (tail + 1) % MAX
Jika head mencapai index akhir, maka head = (head + 1) % MAX
Model ini jauh lebih efisien karena array digunakan sepenuhnya dan tidak ada shifting, sesuai konsep circular queue [2].



## Kesimpulan
Dalam praktikum modul ini, implementasi queue dilakukan dengan berbagai pendekatan:
Linked List Queue, bersifat dinamis dan tidak memiliki batas kapasitas.
Array Queue (Head Diam), sederhana tetapi tidak efisien karena memerlukan shifting.
Array Queue (Head Bergerak), lebih efisien karena tidak memindahkan data.
Circular Queue, penggunaan memori optimal dan sangat cocok untuk sistem nyata seperti buffer dan antrian proses.
Seluruh implementasi mendukung konsep dasar queue yaitu FIFO (First In First Out) sebagaimana dijelaskan dalam referensi [1][2][3].

## Referensi
[1] Jurnal Center — Implementasi Struktur Data Queue dan Stack dalam Sistem Antrian Kasir Cafe Berbasis Web
https://journalcenter.org/index.php/jupikom/article/view/5524<br/>
[2] USTJ — Simulasi Penerapan Multiple Queue Multiple Server Pada Antrian Bank Dengan Metode Discrete Event Simulation
[3] Global Scients — Implementasi Queue Berbasis Linked List Pada Aplikasi Web Manajemen Antrian Print Mahasiswa
https://jurnal.globalscients.com/index.php/jiki/article/view/709 <br/>
