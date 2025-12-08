# <h1 align="center">Laporan Praktikum Modul 10 tree </h1>
<p align="center">M. Abdad mubarok - 103112400166</p>

## Dasar Teori
### A. tree<br/>
tree merupakan jenis struktur data yang tidak linear, digunakan untuk menampilkan data secara hierarkis melalui hubungan antara node utama dan node anak. Menurut penelitian yang dilakukan oleh Rahman (2023) dalam KAKIFIKOM [1], struktur pohon sering digunakan dalam proses pencarian data karena memiliki kemampuan untuk bercabang ke beberapa node anak, sehingga memudahkan dalam mengatur data yang rumit.


#### 
#### B.Operasi Dasar tree<br/>
Setiap tree memiliki beberapa operasi fundamental seperti insertion, searching, traversal, dan deletion. Dalam penelitian yang dijelaskan oleh Prasetyo (2022) [2], operasi-operasi tersebut sangat penting terutama untuk struktur data yang membutuhkan efisiensi pencarian, karena traversal seperti in-order dan pre-order dapat mempermudah pengolahan data secara sistematis.

###
#### C.Implementasi tree<br/>
Implementasi tree umumnya menggunakan node yang terdiri dari data dan pointer menuju anak kiri dan anak kanan. Seperti yang disebutkan dalam Jurnal Teknologi dan Sistem Informasi [3], metode implementasi tree dengan pointer memungkinkan pengelolaan memori yang fleksibel dan mendukung proses rekursif dalam fungsi-fungsi utama seperti pencarian dan penghapusan node.

###
#### D.Implementasi tree<br/>
Binary Search Tree adalah turunan dari struktur tree yang memiliki aturan bahwa child kiri < parent dan child kanan > parent. Dalam jurnal KAKIFIKOM [1], BST terbukti mempercepat proses pencarian data karena pengelompokan nilai secara terurut memungkinkan waktu pencarian mendekati O(log n) ketika tree berada dalam keadaan seimbang. Selain itu, BST banyak diterapkan pada aplikasi manajemen data dan sistem informasi yang memerlukan akses cepat terhadap data terurut.
###


## Guided 

###  guided 1
file bst.h 
```C++
 #ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

typedef int infotype;   
typedef struct Node* addrNode;
struct Node {
    infotype info;
    addrNode left;
    addrNode right;
};

bool isEmpty(addrNode root);
void createTree(addrNode &root);
addrNode newNode(infotype x);
addrNode insertNode(addrNode root, infotype x);
void preOrder(addrNode root);
void inOrder(addrNode root);
void postOrder(addrNode root);

int countNode(addrNode root);
int treeDepth(addrNode root);

#endif
```
bst.cpp
```C++
#include "BST.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(addrNode root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(addrNode &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
addrNode newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    addrNode temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

addrNode insertNode(addrNode root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(addrNode root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(addrNode root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(addrNode root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNode(addrNode root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNode(root->left) + countNode(root->right);
    }
}

int treeDepth(addrNode root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```
main.cpp
```C++
#include <iostream>
#include "BST.h"

using namespace std;

int main(){
    addrNode root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNode(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```


penjelasan singkat guided 1
Struktur data BST dibuat dengan pointer yang menunjuk ke setiap node, di mana tiap node punya tiga bagian: info, left, dan right. Fungsi createTree() dipakai buat mengawali tree dengan root = NULL, sedangkan newNode() dipakai untuk bikin node baru.
Untuk menambah data, program pakai fungsi insertNode() dengan aturan BST: kalau nilainya lebih kecil dari root, dia masuk ke kiri; kalau lebih besar, masuk ke kanan.
Program juga punya tiga metode traversal: preOrder, inOrder, dan postOrder, yang masing-masing nge-print urutan node dengan cara yang berbeda.
Selain itu, ada countNode() untuk ngitung berapa banyak node yang ada, dan treeDepth() untuk tahu kedalaman tree.
Di file main, datanya dimasukkan secara manual, lalu semua traversal dijalankan. Hasilnya ditampilkan bareng total node dan kedalaman tree.

### 2......
file bst.h 
```C++
#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

typedef int infotype;   
typedef struct Node* addrNode;
struct Node {
    infotype info;
    addrNode left;
    addrNode right;
};

bool isEmpty(addrNode root);
void createTree(addrNode &root);
addrNode newNode(infotype x);
addrNode insertNode(addrNode root, infotype x);
void preOrder(addrNode root);
void inOrder(addrNode root);
void postOrder(addrNode root);

int countNode(addrNode root);
int treeDepth(addrNode root);
void searchByData(addrNode root, infotype x);
addrNode mostLeft(addrNode root);
addrNode mostRight(addrNode root);
bool deleteNode(addrNode &root, infotype x);
void deleteTree(addrNode &root);


#endif
```
file bst.cpp
```C++
#include "bst.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(addrNode root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(addrNode &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
addrNode newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    addrNode temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

addrNode insertNode(addrNode root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(addrNode root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(addrNode root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(addrNode root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNode(addrNode root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNode(root->left) + countNode(root->right);
    }
}

int treeDepth(addrNode root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(addrNode root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        addrNode nodeBantu = root;
        addrNode parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            addrNode sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
addrNode mostLeft(addrNode root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

addrNode mostRight(addrNode root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(addrNode &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                addrNode temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                addrNode temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                addrNode temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                addrNode successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(addrNode &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```
file main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main(){
    addrNode root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNode(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```
penjelasan 
fitur BST dikembangkan lebih lengkap. Ada tambahan fungsi untuk mencari data, mengambil nilai paling kiri dan paling kanan, menghapus node tertentu, sampai menghapus seluruh tree.
Fungsi searchByData() dipakai buat nyari data di dalam BST, sekaligus nunjukkin hubungan node tersebut—mulai dari siapa parent-nya, ada sibling atau nggak, sampai child-nya siapa saja.
Fungsi mostLeft() dan mostRight() berfungsi untuk ngambil node dengan nilai paling kecil dan paling besar.



## Unguided 

### 1.SOAL ”
Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file
“bstree.h”:


file bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;

typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);

void insertNode(address &root, infotype x);

address findNode(infotype x, address root);

void printInOrder(address root);

#endif

```
file bstree.cpp
```C
#include <iostream>
#include "bstree.h"
using namespace std;

// Alokasi node baru
address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

// Insert ke BST
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

// Mencari node
address findNode(infotype x, address root) {
    if (root == Nil) return Nil;
    if (x == root->info) return root;
    else if (x < root->info) return findNode(x, root->left);
    else return findNode(x, root->right);
}

// Traversal InOrder
void printInOrder(address root) {
    if (root != Nil) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}


```
file main.cpp
```C
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;

    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);   
    insertNode(root,7);

    printInOrder(root);
    return 0;
}

```

### Output Unguided 1 : 

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_10/foto/soal1.png)



penjelasan unguided 1 <br/>
Pada unguided 1, ADT Binary Search Tree dibuat dengan struktur yang sederhana memakai file header bstree.h dan implementasinya di bstree.cpp. Fungsi alokasi() dipakai untuk membuat node baru. Proses menambah data ke BST dilakukan lewat insertNode(), dengan aturan: nilai yang lebih kecil masuk ke subtree kiri, sedangkan nilai yang lebih besar masuk ke subtree kanan.
Untuk mencari data, digunakan fungsi findNode() yang bekerja secara rekursif. Sementara itu, penampilan data pada tree dilakukan menggunakan traversal in-order lewat printInOrder(), sehingga hasilnya otomatis tampil dalam keadaan terurut.
Di file main, beberapa data dimasukkan ke BST, lalu hasil traversal in-order ditampilkan sesuai output yang diminta.




### 2.SOAL ”
Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
➢ fungsi hitungJumlahNode( root:address ) : integer
/* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
➢ fungsi hitungTotalInfo( root:address, start:integer ) : integer
/* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
➢ fungsi hitungKedalaman( root:address, start:integer ) : integer

file bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;

typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);

void insertNode(address &root, infotype x);

address findNode(infotype x, address root);

void printInOrder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);


#endif


```
file bstree.cpp
```C
#include <iostream>
#include "bstree.h"
using namespace std;

// Alokasi node baru
address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

// Insert ke BST
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

// Mencari node
address findNode(infotype x, address root) {
    if (root == Nil) return Nil;
    if (x == root->info) return root;
    else if (x < root->info) return findNode(x, root->left);
    else return findNode(x, root->right);
}

// Traversal InOrder
void printInOrder(address root) {
    if (root != Nil) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}


// Menghitung jumlah node
int hitungJumlahNode(address root) {
    if (root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

// Menghitung total nilai info seluruh node
int hitungTotalInfo(address root, int start) {
    if (root == Nil) return start;
    start += root->info;
    start = hitungTotalInfo(root->left, start);
    start = hitungTotalInfo(root->right, start);
    return start;
}

// Menghitung kedalaman maksimal tree
int hitungKedalaman(address root, int start) {
    if (root == Nil) return start;

    int kiri  = hitungKedalaman(root->left,  start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);

    return (kiri > kanan) ? kiri : kanan;
}


```
file main.cpp
```C
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6); 
    insertNode(root,7);

    printInOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;

    return 0;
}

```

### Output Unguided 2 : 

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_10/foto/soal2.png)



penjelasan unguided 2 <br/>
Di file bstree.h, didefinisikan struktur node yang berisi nilai dan dua pointer yang menunjuk ke anak kiri dan kanan. Di bagian ini juga disiapkan deklarasi fungsi-fungsi penting seperti alokasi, insertNode, findNode, sampai fungsi traversal.
Masuk ke bstree.cpp, fungsi alokasi() bertugas membuat node baru setiap kali ada data yang ingin dimasukkan. Fungsi insertNode() melakukan proses penyisipan data secara rekursif sesuai aturan BST: angka yang lebih kecil dimasukkan ke kiri, dan angka yang lebih besar dimasukkan ke kanan. Lalu ada findNode() yang dipakai untuk mencari suatu nilai di dalam tree, juga dengan cara rekursif. Selain itu, disediakan tiga fungsi traversal: printInOrder, printPreOrder, dan printPostOrder, yang menampilkan data sesuai urutan kunjungannya masing-masing.
Sementara itu, di main.cpp, program membuat tree kosong, lalu mengisinya dengan beberapa angka. Setelah tree jadi, program menampilkan hasil traversal InOrder, PreOrder, dan PostOrder. Dari hasilnya terlihat kalau BST sudah terbentuk dengan benar dan fungsi traversal berjalan sesuai harapan. Untuk data yang sama seperti angka 6, program secara otomatis mengabaikannya karena fungsi insertNode hanya akan menambahkan nilai jika belum ada di dalam tree.




### 3.SOAL ”


file bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInOrder(address root);
void printPreOrder(address root);
void printPostOrder(address root);

#endif

```
file bstree.cpp
```C
#include <iostream>
#include "bstree.h"
using namespace std;

// Alokasi node baru
address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

// Insert
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

// Find
address findNode(infotype x, address root) {
    if (root == Nil) return Nil;
    if (x == root->info) return root;
    else if (x < root->info) return findNode(x, root->left);
    else return findNode(x, root->right);
}

// InOrder
void printInOrder(address root) {
    if (root != Nil) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}

// PreOrder
void printPreOrder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// PostOrder
void printPostOrder(address root) {
    if (root != Nil) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " - ";
    }
}

```
file main.cpp
```C
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6); 
    insertNode(root,7);

    printInOrder(root);
    cout << endl;

    printInOrder(root);
    cout << endl;

    cout << "Pre-order   : ";
    printPreOrder(root);
    cout << endl;

    cout << "Post-order  : ";
    printPostOrder(root);
    cout << endl;


    return 0;
}

```

### Output Unguided 3 : 

##### Output 3
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_10/foto/soal3.png)



penjelasan unguided 3 <br/>
program yang dibuat sudah diuji untuk memastikan semua fungsi BST berjalan dengan benar. Data dimasukkan sesuai urutan pada soal, jadi tree terbentuk mulai dari node 1 sebagai root dan seterusnya mengikuti aturan Binary Search Tree.
Hasil traversal InOrder menampilkan data dari yang terkecil sampai terbesar, jadi bisa dipastikan struktur tree yang terbentuk sudah sesuai. Traversal PreOrder dan PostOrder juga berhasil dijalankan untuk melihat bentuk tree dari sudut pandang yang berbeda.
Dari output yang muncul, fungsi-fungsi seperti insert, pencarian node, dan traversal semuanya bekerja seperti yang diharapkan. Program juga bisa menampilkan struktur tree secara lengkap. Secara keseluruhan, implementasi BST di bagian unguided ini sudah berjalan dengan baik dan sesuai konsep dasarnya.



## Kesimpulan
Berdasarkan praktikum yang sudah dilakukan, bisa disimpulkan bahwa Binary Search Tree (BST) adalah struktur data yang cukup efektif untuk menyimpan dan mencari data secara teratur. Dari percobaan membuat fungsi-fungsi dasar seperti alokasi node, insert, search, dan traversal, terlihat bahwa tree bisa dibangun dan dijalankan sesuai konsep BST.
Baik pada bagian guided maupun unguided, tree berhasil terbentuk dengan benar dan proses traversal juga dapat menampilkan data dalam urutan yang sesuai. Secara keseluruhan, praktikum ini membantu memberikan gambaran yang jelas tentang cara kerja BST dan bagaimana struktur ini bisa digunakan untuk mengelola data secara efisien.
## Referensi
[1] KAKIFIKOM — Implementasi Teknik Binary Search Tree Pada Pencarian Data Penduduk
https://ejournal.ust.ac.id/index.php/KAKIFIKOM/article/view/1794 
Ejournal UST<br/>
[2] Jurnal Ilmiah Universitas Satya Negara Indonesia — IMPLEMENTATION OF BINARY SEARCH TREE METHOD FOR ANDROID-BASED MORSE CODE DESCRIPTION
https://ejournal.usni.ac.id/index.php/jisni/article/view/27 <br/>
Rumah Jurnal USNI
[3] JRIIN : Jurnal Riset Informatika dan Inovasi — Pemanfaatan Pohon Biner Untuk Pemrosesan Data Efisien
https://jurnalmahasiswa.com/index.php/jriin/article/view/1264 <br/>