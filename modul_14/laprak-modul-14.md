# <h1 align="center">Laporan Praktikum Modul 14 graph </h1>
<p align="center">M. Abdad mubarok - 103112400166</p>

## Dasar Teori
### A. graph<br/>
Graph merupakan salah satu struktur data dan konsep dasar dalam matematika diskrit yang digunakan untuk merepresentasikan hubungan antar objek. Secara umum, graph terdiri dari himpunan simpul (vertex) dan sisi (edge) yang menghubungkan antar simpul tersebut. Graph banyak digunakan untuk memodelkan berbagai permasalahan nyata seperti jaringan komputer, jalur transportasi, dan struktur organisasi.
Menurut Mahardika (2019) dalam Jurnal Informatika [1], graph didefinisikan sebagai pasangan himpunan simpul dan himpunan sisi yang menghubungkan dua simpul, baik secara berarah maupun tidak berarah. Selain itu, Rizki (2020) dalam AKSIOMA [2] menjelaskan bahwa graph memiliki beberapa jenis, antara lain graph berarah, graph tidak berarah, graph berbobot, dan graph tidak berbobot yang masing-masing memiliki karakteristik dan kegunaan yang berbeda.
Graph juga dapat direpresentasikan dalam berbagai bentuk seperti matriks ketetanggaan (adjacency matrix) dan daftar ketetanggaan (adjacency list). Representasi ini sangat berpengaruh terhadap efisiensi penyimpanan dan proses pengolahan data graph dalam pemrograman komputer (Mahardika, 2019 dalam Jurnal Informatika [1]).

#### 
#### B.Operasi Dasar graph<br/>
Operasi dasar graph merupakan aktivitas fundamental yang dilakukan untuk mengelola dan memproses data graph. Operasi tersebut meliputi penambahan simpul (insert vertex), penambahan sisi (insert edge), penghapusan simpul dan sisi, serta penelusuran graph.
Penelusuran graph merupakan operasi penting yang bertujuan untuk mengunjungi seluruh simpul dalam graph. Metode penelusuran yang umum digunakan adalah Depth First Search (DFS) dan Breadth First Search (BFS). Rizki (2020) dalam AKSIOMA [2] menyatakan bahwa algoritma DFS dan BFS sangat efektif digunakan untuk pencarian jalur, analisis konektivitas, serta penyelesaian masalah optimasi seperti Minimum Spanning Tree.
Selain itu, Mahardika (2019) dalam Jurnal Informatika [1] menjelaskan bahwa operasi graph sering dikombinasikan dengan algoritma tertentu seperti Kruskal dan Prim untuk menyelesaikan permasalahan jaringan secara efisien, khususnya pada graph berbobot.

###
#### C.Implementasi graph<br/>
Implementasi graph dalam pemrograman biasanya dilakukan menggunakan struktur data tertentu, salah satunya adalah linked list. Representasi graph dengan adjacency list memanfaatkan linked list untuk menyimpan hubungan antar simpul sehingga lebih efisien dari sisi memori.
Menurut Wijoyo dkk. (2024) dalam JRIIN [3], struktur linked list dengan lebih dari satu referensi pointer sangat efektif digunakan dalam sistem yang membutuhkan fleksibilitas hubungan data, seperti sistem basis data sederhana dan struktur graph. Hal ini memungkinkan setiap simpul memiliki banyak relasi tanpa harus menggunakan memori yang besar seperti pada matriks.
Dalam bahasa pemrograman C++, implementasi graph sering menggunakan struktur struct atau class yang berisi informasi simpul, pointer ke simpul lain, serta atribut tambahan seperti status kunjungan (visited). Pendekatan ini mempermudah penerapan algoritma penelusuran graph seperti DFS dan BFS (Wijoyo dkk., 2024 dalam JRIIN [3]).
#### D.Implementasi graph lanjutan<br/>
Implementasi graph lanjutan mencakup penerapan algoritma-algoritma graph untuk menyelesaikan permasalahan nyata. Contoh penerapan tersebut adalah pencarian jalur terpendek, penentuan jalur minimum, dan optimasi jaringan.
Rizki (2020) dalam AKSIOMA [2] menjelaskan bahwa penerapan algoritma Minimum Spanning Tree pada graph berbobot dapat digunakan untuk merancang jaringan dengan biaya minimum, seperti jaringan listrik dan jaringan komputer. Implementasi ini biasanya dilakukan dengan memanfaatkan struktur data graph yang telah dibangun sebelumnya.
Selain itu, penggunaan graph dalam sistem komputer memungkinkan pengolahan data yang kompleks menjadi lebih terstruktur dan sistematis. Dengan demikian, pemahaman konsep graph dan implementasinya sangat penting dalam pengembangan perangkat lunak dan sistem informasi modern (Mahardika, 2019 dalam Jurnal Informatika [1]).

###


## Guided 

###  guided 1
file graph.h 
```C++
#ifndef Graph_h
#define Graph_h

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge{
    adrNode node;
    adrEdge next ;
};
struct Graph {
    adrNode first;
};

void createGraph(Graph &G );
adrNode findNode(Graph G , infoGraph X);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G ,infoGraph X);
void connectNode(Graph &G , infoGraph start ,infoGraph end);
void printGraph(Graph G);

#endif

 
```
graph.cpp
```C++
#include "graph.h"
#include <iostream>
using namespace std;

void printGraph(Graph G){
    adrNode P = G.first;
    while (P != NULL){
        cout << "Node: " << P->info << " terhubung ke " << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        P = P->next;
    }
}
void createGraph(Graph &G ){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void insertNode(Graph &G ,infoGraph X){
    adrNode P = allocateNode(X);
    if (G.first == NULL){
        G.first = P;
    } else {
        adrNode Q = G.first;    
        while (Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}
adrNode findNode(Graph G, infoGraph X ){
    adrNode P = G.first;
    while (P != NULL){ 
        if (P ->info == X) return P;
        P = P -> next;
    }
    return NULL;

}

void connectNode (Graph &G,infoGraph start ,infoGraph end){
    adrNode pStart = findNode(G,start);
    adrNode pEnd = findNode(G,end);

    if (pStart !=NULL && pEnd !=NULL){
        adrEdge newEdge = new ElmEdge;
        newEdge ->node = pEnd;
        newEdge->next = pStart -> firstEdge;
        pStart -> firstEdge = newEdge;
    }
}
```
main.cpp
```C++
#include "graph.h"
#include <iostream>
using namespace std;
int main(){
    Graph G;
    createGraph(G);

    insertNode (G,'A');
    insertNode (G,'B');
    insertNode (G,'C');
    insertNode (G,'D');

    connectNode (G,'A','B');
    connectNode (G,'A','C');
    connectNode (G,'B','D');
    connectNode (G,'C','D');
    cout<<"isi graph: "<<endl;
    printGraph(G);
    return 0;
}
```


penjelasan singkat guided 1
kode diatas merupakan untuk mengelola struktur data graph menggunakan linked list. Kode ini mencakup pembuatan graph, penambahan node, penghubungan node dengan edge, dan pencetakan isi graph. Fungsi-fungsi tersebut memungkinkan kita untuk membuat graph sederhana dan menampilkan hubungan antar node.



## Unguided 

### 1.SOAL ”
Buatlah implementasi ADT Graph pada file“graph.cpp” dan cobalah hasil implementasi ADT
pada file “main.cpp”.


file graph.h
```C++
#ifndef Graph_h
#define Graph_h
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode{
    infoGraph info;
    bool visited ;
    adrEdge firstEdge;
    adrNode next;

};

struct ElmEdge{
    adrNode Node;
    adrEdge next ;
};
struct Graph {
    adrNode first;
};

void createGraph(Graph &G );
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G ,infoGraph X);
void connectNode(Graph &G , infoGraph start ,infoGraph end);
void printGraph(Graph G);




#endif

```
file graph.cpp
```C
#include "graph.h"
#include <iostream>
void createGraph(Graph &G ){
    G.first = NULL;
}

adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G ,infoGraph X){
    adrNode P = allocateNode(X);
    if (G.first == NULL){
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}

void connectNode(Graph &G , infoGraph start ,infoGraph end){
    adrNode P = G.first;
    while (P != NULL && P->info != start){
        P = P->next;
    }
    if (P != NULL){
        adrNode Q = G.first;
        while (Q != NULL && Q->info != end){
            Q = Q->next;
        }
        if (Q != NULL){
            adrEdge E = new ElmEdge;
            E->Node = Q;
            E->next = NULL;
            if (P->firstEdge == NULL){
                P->firstEdge = E;
            } else {
                adrEdge F = P->firstEdge;
                while (F->next != NULL){
                    F = F->next;
                }
                F->next = E;
            }
        }
    }
}
void printGraph(Graph G){
    adrNode P = G.first;
    while (P != NULL){
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL){
            cout << E->Node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

```
file main.cpp
```C
#include "graph.h"
#include <iostream>

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'B', 'E');
    connectNode(G, 'C', 'F');
    connectNode(G, 'C', 'G');
    connectNode(G, 'D', 'H');
    connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H');
    connectNode(G, 'G', 'H');

    printGraph(G);

    return 0;
}
```

### Output Unguided 1 : 

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_14/foto/soal1.png)



penjelasan unguided 1 <br/>
kode diatas merupakan implementasi dasar dari struktur data graph menggunakan linked list. Kode ini mencakup pembuatan graph, penambahan node, penghubungan node dengan edge, dan pencetakan isi graph. Fungsi-fungsi tersebut memungkinkan kita untuk membuat graph sederhana dan menampilkan hubungan antar node.dan juga menampilkan hasil koneksi antar node pada graph yang telah dibuat.





### 2.SOAL ”
Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
file graph.h
```C++
#ifndef Graph_h
#define Graph_h
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode{
    infoGraph info;
    bool visited ;
    adrEdge firstEdge;
    adrNode next;

};

struct ElmEdge{
    adrNode Node;
    adrEdge next ;
};
struct Graph {
    adrNode first;
};

void createGraph(Graph &G );
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G ,infoGraph X);
void connectNode(Graph &G , infoGraph start ,infoGraph end);
void printGraph(Graph G);
void penulusuranDFS(Graph &G, adrNode P);
void resetVisited(Graph &G);



#endif

```
file graph.cpp
```C
#include "graph.h"
#include <iostream>
void createGraph(Graph &G ){
    G.first = NULL;
}

adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G ,infoGraph X){
    adrNode P = allocateNode(X);
    if (G.first == NULL){
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}

void connectNode(Graph &G , infoGraph start ,infoGraph end){
    adrNode P = G.first;
    while (P != NULL && P->info != start){
        P = P->next;
    }
    if (P != NULL){
        adrNode Q = G.first;
        while (Q != NULL && Q->info != end){
            Q = Q->next;
        }
        if (Q != NULL){
            adrEdge E = new ElmEdge;
            E->Node = Q;
            E->next = NULL;
            if (P->firstEdge == NULL){
                P->firstEdge = E;
            } else {
                adrEdge F = P->firstEdge;
                while (F->next != NULL){
                    F = F->next;
                }
                F->next = E;
            }
        }
    }
}
void printGraph(Graph G){
    adrNode P = G.first;
    while (P != NULL){
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL){
            cout << E->Node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void penulusuranDFS(Graph &G, adrNode P){
    if (P == NULL) return;
    P->visited = true;
    cout << P->info << " ";
    adrEdge E = P->firstEdge;
    while (E != NULL){
        if (!E->Node->visited){
            penulusuranDFS(G, E->Node);
        }
        E = E->next;
    }
}


void resetVisited(Graph &G){
    adrNode P = G.first;
    while(P != NULL){
        P->visited = false;
        P = P->next;
    }
}



```
file main.cpp
```C
#include "graph.h"
#include <iostream>

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'B', 'E');
    connectNode(G, 'C', 'F');
    connectNode(G, 'C', 'G');
    connectNode(G, 'D', 'H');
    connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H');
    connectNode(G, 'G', 'H');
    cout << "Graph conection list:" << endl;
    printGraph(G);

    cout << "\nDFS Traversal mulai node A:" << endl;
    adrNode startNode = G.first; // Node A
    penulusuranDFS(G, startNode);
    cout << endl;

    resetVisited(G); 
    cout << "\nDFS Traversal mulai node C:" << endl;
    startNode = G.first->next->next; // Node C
    penulusuranDFS(G, startNode);
    cout << endl;

    return 0;
}
```

### Output Unguided 2 : 

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_14/foto/soal2.png)



penjelasan unguided 2 <br/>
kode diatas merupakan implementasi algoritma Depth First Search (DFS) pada struktur data graph yang diimplementasikan menggunakan linked list. Kode ini mencakup pembuatan graph, penambahan node, penghubungan node dengan edge, serta prosedur untuk melakukan penelusuran DFS dan mereset status kunjungan node. Fungsi-fungsi tersebut memungkinkan kita untuk menelusuri graph secara mendalam mulai dari node tertentu dan menampilkan urutan kunjungan node selama penelusuran DFS.

### 3.SOAL ”
Buatlah prosedur untuk menampilkanhasil penelusuran BFS.
prosedur PrintBFS (Graph G, adrNode N);

file graph.h
```C++
#ifndef Graph_h
#define Graph_h
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode{
    infoGraph info;
    bool visited ;
    adrEdge firstEdge;
    adrNode next;

};

struct ElmEdge{
    adrNode Node;
    adrEdge next ;
};
struct Graph {
    adrNode first;
};

void createGraph(Graph &G );
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G ,infoGraph X);
void connectNode(Graph &G , infoGraph start ,infoGraph end);
void printGraph(Graph G);
void penulusuranBFS(Graph &G, adrNode P);
void resetVisited(Graph &G);



#endif


```
file graph.cpp
```C
#include "graph.h"
#include <iostream>
void createGraph(Graph &G ){
    G.first = NULL;
}

adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G ,infoGraph X){
    adrNode P = allocateNode(X);
    if (G.first == NULL){
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}

void connectNode(Graph &G , infoGraph start ,infoGraph end){
    adrNode P = G.first;
    while (P != NULL && P->info != start){
        P = P->next;
    }
    if (P != NULL){
        adrNode Q = G.first;
        while (Q != NULL && Q->info != end){
            Q = Q->next;
        }
        if (Q != NULL){
            adrEdge E = new ElmEdge;
            E->Node = Q;
            E->next = NULL;
            if (P->firstEdge == NULL){
                P->firstEdge = E;
            } else {
                adrEdge F = P->firstEdge;
                while (F->next != NULL){
                    F = F->next;
                }
                F->next = E;
            }
        }
    }
}
void printGraph(Graph G){
    adrNode P = G.first;
    while (P != NULL){
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL){
            cout << E->Node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void penulusuranBFS(Graph &G, adrNode P){
    if (P == NULL) return;

    queue<adrNode> Q;

    P->visited = true;
    Q.push(P);

    while (!Q.empty()) {
        adrNode current = Q.front();
        Q.pop();

        cout << current->info << " ";

        adrEdge E = current->firstEdge;
        while (E != NULL) {
            adrNode nextNode = E->Node;
            if (!nextNode->visited) {
                nextNode->visited = true;
                Q.push(nextNode);
            }
            E = E->next;
        }
    }
}


void resetVisited(Graph &G){
    adrNode P = G.first;
    while(P != NULL){
        P->visited = false;
        P = P->next;
    }
}


```
file main.cpp
```C
#include "graph.h"
#include <iostream>

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'B', 'E');
    connectNode(G, 'C', 'F');
    connectNode(G, 'C', 'G');
    connectNode(G, 'D', 'H');
    connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H');
    connectNode(G, 'G', 'H');
    cout << "Graph conection list:" << endl;
    printGraph(G);

    cout << "\nBFS Traversal mulai node A:" << endl;
    adrNode startNode = G.first; // Node A
    penulusuranBFS(G, startNode);
    cout << endl;


    resetVisited(G);
    cout << "\nBFS Traversal mulai node C:" << endl;
    startNode = G.first->next->next; // Node C
    penulusuranBFS(G, startNode);
    cout << endl;

    return 0;
}


```

### Output Unguided 3 : 

##### Output 3
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_14/foto/soal3.png)



penjelasan unguided 3 <br/>
kode diatas merupakan implementasi algoritma Breadth First Search (BFS) pada struktur data graph yang diimplementasikan menggunakan linked list. Kode ini mencakup pembuatan graph, penambahan node, penghubungan node dengan edge, serta prosedur untuk melakukan penelusuran BFS dan mereset status kunjungan node. Fungsi-fungsi tersebut memungkinkan kita untuk menelusuri graph secara menyeluruh mulai dari node tertentu dan menampilkan urutan kunjungan node selama penelusuran BFS.dimana pola penelusuran BFS mengunjungi node perlevel sebelum melanjutkan ke level berikutnya.




## Kesimpulan
dari semua kode diatas dapat disimpulkan bahwa struktur data graph sangat penting dalam pemrograman komputer untuk merepresentasikan hubungan antar objek. Implementasi graph menggunakan linked list memungkinkan efisiensi memori dan fleksibilitas dalam mengelola hubungan antar node. Algoritma penelusuran seperti DFS dan BFS sangat berguna untuk menjelajahi graph, dengan DFS menelusuri secara mendalam dan BFS menelusuri secara menyeluruh per level. Pemahaman dan penerapan konsep graph sangat krusial dalam pengembangan sistem informasi dan aplikasi yang kompleks.

## Referensi
[1] Jurnal Informatika
Penerapan Teori Graf pada Jaringan Komputer dengan Algoritma Kruskal
https://ejournal.poltekharber.ac.id/index.php/informatika/article/view/1032
E-Journal Politeknik Harapan Bersama
<br/>
[2] AKSIOMA: Jurnal Pendidikan Matematika
Penerapan Teori Graf untuk Menyelesaikan Minimum Spanning Tree (MST)
https://ojs.fkip.ummetro.ac.id/index.php/matematika/article/view/68
E-Journal FKIP Universitas Muhammadiyah Metro
<br/>
[3] JRIIN : Jurnal Riset Informatika dan Inovasi
Implementasi Struktur Data Linked List dalam Sistem Graf
https://jurnalmahasiswa.com/index.php/jriin/article/view/1264
Rumah Jurnal Mahasiswa – JRIIN
<br/>>