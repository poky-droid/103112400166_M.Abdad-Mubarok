# <h1 align="center">Laporan Praktikum Modul 7 stack </h1>
<p align="center">M. Abdad mubarok - 103112400166</p>

## Dasar Teori
### A. stack<br/>
Stack adalah struktur data linear dengan akses yang hanya dapat dilakukan pada satu ujung, yaitu bagian atas atau top [1]. Elemen dapat ditambahkan dan dihapus melalui operasi yang terdefinisi, dan perilakunya diilustrasikan seperti tumpukan piring yang hanya dapat ditambah atau diambil dari bagian paling atas [1].
Stack dapat diimplementasikan menggunakan array (statis) maupun linked list (dinamis) [1].

#### 
#### B.Operasi Dasar Stack<br/>
Operasi yang umum dalam struktur data stack meliputi:
push → menambahkan elemen baru ke bagian atas stack [1]
pop → menghapus elemen teratas stack [1]
peek/top → melihat elemen teratas tanpa menghapus [3]
isEmpty → mengecek apakah stack kosong [1]
isFull (khusus array) → mengecek apakah stack penuh [2]
###
#### C.Implementasi Stack<br/>
Terdapat dua implementasi umum:
Array / Statis: ukuran tetap, sederhana secara implementasi namun kurang fleksibel [2].
Linked List / Dinamis: menggunakan node dan pointer, ukuran fleksibel mengikuti alokasi memori [1].
###
#### D.Implementasi Stack<br/>
Modul ini juga mencakup beberapa operasi tambahan:
Update → mengubah nilai node pada posisi tertentu (linked list)
Search → mencari data dalam stack
Balik Stack (Reverse) → membalik urutan elemen stack
pushAscending → memastikan elemen yang dimasukkan tetap terurut menaik
getInputStream → membaca input karakter satu per satu dan memasukkannya ke stack
###


## Guided 

###  guided 1
file stack.h 
```C++
 #ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node* address;

struct node{
    int dataAngka;
    address next;
};

struct stack {
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```
stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}

```
main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);
}
```


penjelasan singkat guided 1
Pada Guided 1, program membahas implementasi struktur data stack menggunakan linked list. Stack dibangun melalui node yang saling terhubung, di mana elemen baru selalu ditambahkan (push) di bagian atas (top). Program menyediakan beberapa operasi penting seperti push, pop, update, view, dan searchData.
Dalam contoh program, lima node pertama kali dialokasikan dan dimasukkan ke dalam stack sehingga susunan terakhir menjadi 5–4–3–2–1 mengikuti prinsip LIFO. Setelah itu dilakukan operasi pop sebanyak dua kali yang menghapus elemen teratas stack, diikuti proses update pada beberapa posisi tertentu untuk mengubah nilai node. Program juga menyediakan fungsi pencarian untuk memastikan apakah suatu data terdapat dalam stack dan pada posisi ke berapa.
Secara keseluruhan, Guided 1 menunjukkan bagaimana stack berbasis linked list bekerja secara dinamis, mulai dari penyisipan, penghapusan, hingga pengubahan data di posisi tertentu dalam tumpukan.



### 2......
file stack.h 
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; //Array untuk menyimpan eleman stack
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x); // Menambahkan elemen ke dalam stack
infotype pop(Stack &S); // Mengambil elemen teratas dari stack
void printInfo(Stack S);
void balikStack(Stack &S); // Membalik urutan elemen dalam stack

#endif

```
file stack.cpp
```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}

```
file main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```

penjelasan Guided 2
Guided 2 menjelaskan implementasi stack menggunakan array statis dengan kapasitas maksimum yang telah ditentukan. Pada stack ini, posisi teratas ditandai dengan variabel top, sedangkan data disimpan pada array info[]. Program menyediakan fungsi dasar seperti push, pop, pengecekan stack penuh atau kosong, hingga fungsi printInfo untuk menampilkan isi stack.
Selain operasi dasar, terdapat fitur tambahan yaitu balik stack, yang berfungsi membalik urutan elemen dengan memanfaatkan dua stack sementara. Proses pembalikan dilakukan dengan memindahkan data dari stack utama ke stack sementara secara berurut hingga mendapatkan urutan terbalik.
Dalam main program, beberapa nilai dimasukkan dan dihapus sehingga menghasilkan susunan akhir tertentu sebelum dibalik. Setelah fungsi balikStack dijalankan, urutan stack berubah total, menunjukkan bagaimana stack dapat digunakan untuk memanipulasi data secara terstruktur walaupun hanya menggunakan array.

## Unguided 

### 1.SOAL ”
Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”:
Type infotype : integer
Type Stack <
info : array [20] of integer
top : integer
>
procedure CreateStack( input/output S : Stack )
procedure push(input/output S : Stack,
input x : infotype)
function pop(input/output t S : Stack )
→ infotype
procedure printInfo( input S : Stack )
procedure balikStack(input/output S :
Stack )

file stack.h
```C++
#ifndef stack_h
#define stack_h
#include <iostream>
using namespace std;
typedef int Infotype;
typedef struct Stack {
    int info[20];
    int top;
} Node;

void createStack(Stack &S);
void push(Stack &S);
Infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
#endif
```
file stack.cpp
```C
#include "stack.h"
#include <iostream>
using namespace std;
void createStack(Stack &S) {
    S.top = -1;
}
void push(Stack &S) {
    if (S.top == 19) {
        cout << "Stack penuh!" << endl;
    } else {
        int nilai;
        cout << "Masukkan nilai yang akan dipush: ";
        cin >> nilai;
        S.top++;
        S.info[S.top] = nilai;
    }
}
Infotype pop(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        Infotype nilai = S.info[S.top];
        S.top--;
        return nilai;
    }
}
void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "Isi Stack: ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}
void balikStack(Stack &S) {
    Stack tempStack;
    createStack(tempStack);
    
    while (S.top != -1) {
        Infotype nilai = pop(S);
        tempStack.top++;
        tempStack.info[tempStack.top] = nilai;
    }
    
    S = tempStack;
    
    cout << "Stack telah dibalik." << endl;
    printInfo(S);
}

```
file main.cpp
```C
#include "stack.h"
#include <iostream>
using namespace std;
int main(){
    Stack S;
    createStack(S);
    int pilihan;
    do {
        cout << "Menu Stack:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print Stack" << endl;
        cout << "4. Balik Stack" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                push(S);
                break;
            case 2: {
                Infotype nilai = pop(S);
                if (nilai != -1) {
                    cout << "Nilai yang dipop: " << nilai << endl;
                }
                break;
            }
            case 3:
                printInfo(S);
                break;
            case 4:
                balikStack(S);
                cout << "Stack telah dibalik." << endl;
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        cout << endl;
    } while (pilihan != 5);
    return 0;
}

```

### Output Unguided 1 : 

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_7/foto/soal1.png)



penjelasan unguided 1 <br/>
Program pada Guided 1 membahas pembuatan ADT Stack menggunakan linked list dengan fungsi createStack, push, pop, update, view, dan searchData. Lima node pertama dimasukkan menggunakan push sehingga tersusun menjadi 5 – 4 – 3 – 2 – 1 sesuai prinsip LIFO. Setelah itu dilakukan pop dua kali untuk menghapus elemen teratas, diikuti proses update pada posisi tertentu dan pencarian data. Program ini menunjukkan cara kerja operasi dasar stack pada struktur linked list secara dinamis.



### 2.SOAL ”
Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)
int main()
{
STRUKTUR DATA 64
cout << "Hello world!" << endl;
Stack S;
createStack(S);
pushAscending(S,3);
pushAscending(S,4);
pushAscending(S,8);
pushAscending(S,2);
pushAscending(S,3);
pushAscending(S,9);
printInfo(S);
cout<<"balik stack"<<endl;
balikStack(S);
printInfo(S);
return 0;
}

file stack.h
```C++
#ifndef stack_h
#define stack_h
#include <iostream>
using namespace std;
typedef int Infotype;
typedef struct Stack {
    int info[20];
    int top;
} Node;

void createStack(Stack &S);
Infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, Infotype x);
#endif

```
file stack.cpp
```C
#include "stack.h"
#include <iostream>
using namespace std;
void createStack(Stack &S) {
    S.top = -1;
}
Infotype pop(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        Infotype nilai = S.info[S.top];
        S.top--;
        return nilai;
    }
}
void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "Isi Stack: ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}
void balikStack(Stack &S) {
    Stack tempStack;
    createStack(tempStack);
    
    while (S.top != -1) {
        Infotype nilai = pop(S);
        tempStack.top++;
        tempStack.info[tempStack.top] = nilai;
    }
    
    S = tempStack;
    
    cout << "Stack telah dibalik." << endl;
    printInfo(S);
}
void pushAscending(Stack &S, Infotype x) {
    
    Stack tempStack;
    createStack(tempStack);
    while (S.top != -1 && S.info[S.top] < x) {
        Infotype nilai = pop(S);
        tempStack.top++;
        tempStack.info[tempStack.top] = nilai;
    }
    S.top++;
    S.info[S.top] = x;
    while (tempStack.top != -1) {
        Infotype nilai = pop(tempStack);
        S.top++;
        S.info[S.top] = nilai;
    }

}


```
file main.cpp
```C
#include "stack.h"
#include <iostream>
using namespace std;

int main (){
    Stack S;
    createStack(S);
    int pilihan;

    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    
    do {
        cout << "Menu Stack Ascending:" << endl;
        cout << "1. Pop" << endl;
        cout << "2. Print Stack" << endl;
        cout << "3. Balik Stack" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;
        switch (pilihan) {
            
            case 1: {
                Infotype nilai = pop(S);
                if (nilai != -1) {
                    cout << "Nilai yang dipop: " << nilai << endl;
                }
                break;
            }
            case 2:
                printInfo(S);
                break;
            case 3:
                balikStack(S);
                cout << "Stack telah dibalik." << endl;
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        cout << endl;
    } while (pilihan != 4);
    return 0;
}
```

### Output Unguided 2 : 

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_7/foto/soal2.png)



penjelasan unguided 2 <br/>
Program pada Guided 2 mengimplementasikan ADT Stack yang digunakan untuk membalik urutan karakter dalam sebuah string. Pengguna memasukkan satu kata atau kalimat tanpa spasi, kemudian setiap karakter dimasukkan ke dalam stack satu per satu. Setelah seluruh karakter berhasil dipush, stack dicetak sehingga urutan tampil terbalik sesuai prinsip LIFO. Program ini memperlihatkan bagaimana operasi push dan pop dapat dimanfaatkan untuk membalik data secara efisien menggunakan struktur stack berbasis linked list.


### 3.SOAL ”
Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan
menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan
tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

file stack.h
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
const int MAX = 20;
typedef char Infotype;
struct Stack {
    char data[MAX];
    int top;
};

void createStack(Stack &S);
Infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void getInputStream(Stack &S);
void push(Stack &S, Infotype x);
bool isEmpty(Stack S);
#endif
```
file stack.cpp
```C
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}
Infotype pop(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        Infotype nilai = S.data[S.top];
        S.top--;
        return nilai;
    }
}
void printInfo(Stack S) {
    cout << "Isi Stack: ";
    while (!isEmpty(S)) {
        cout << S.data[S.top--] << " ";
    }
    cout << endl;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}
void balikStack(Stack &S) {
    Stack tempStack;
    createStack(tempStack);

    while (S.top != -1) {
        Infotype nilai = pop(S);
        tempStack.top++;
        tempStack.data[tempStack.top] = nilai;
    }
    S = tempStack;
    cout << "Stack telah dibalik." << endl;
    printInfo(S);
}
void getInputStream(Stack &S) {
    cout << "Masukkan input (tanpa spasi, tekan ENTER untuk selesai): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char c = cin.get();

    while (c != '\n') {
        if (c == ' ') {
            cout << "\nError: Input tidak boleh mengandung spasi!\n";
            return; 
        }
        push(S, c);
        c = cin.get();
    }
}


void push(Stack &S, Infotype x) {
    if (S.top == 19) {
        cout << "Stack penuh!" << endl;
        return;
    }
    S.top++;
    S.data[S.top] = x;
}


```
file main.cpp
```C
#include "stack.h"
#include <iostream>
using namespace std;


int main(){
    Stack S;
    createStack(S);
    int pilihan;
    do {
        cout << "Menu Stack:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print Stack" << endl;
        cout << "4. Balik Stack" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                getInputStream(S);
                break;
            case 2: {
                Infotype nilai = pop(S);
                if (nilai != -1) {
                    cout << "Nilai yang dipop: " << nilai << endl;
                }
                break;
            }
            case 3:
                printInfo(S);
                break;
            case 4:
                balikStack(S);
                cout << "Stack telah dibalik." << endl;
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        cout << endl;
    } while (pilihan != 5);
    return 0;
}
```

### Output Unguided 3 : 

##### Output 3
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_7/foto/soal3.png)



penjelasan unguided 3 <br/>
Program pada Guided 3 menggunakan dua stack untuk memisahkan angka genap dan ganjil. Setiap angka yang dimasukkan pengguna akan dicek terlebih dahulu, kemudian disimpan ke stack genap atau stack ganjil sesuai kategorinya. Setelah seluruh data dimasukkan, kedua stack dapat ditampilkan sehingga proses pengelompokan terlihat jelas.
Pada program ini juga digunakan cin.get() untuk menangani input agar tidak terjadi masalah pembacaan karakter, terutama setelah penggunaan cin >> angka. Fungsi cin.get() berfungsi membersihkan karakter newline (\n) yang tertinggal di buffer, sehingga input berikutnya dapat diterima dengan benar.
Program ini memperlihatkan bagaimana dua stack dapat digunakan untuk memilah data sekaligus menunjukkan pemanfaatan fungsi input seperti cin.get() untuk memastikan alur program berjalan tanpa gangguan.


## Kesimpulan
Dari seluruh percobaan pada modul stack, dapat disimpulkan bahwa stack merupakan struktur data yang bekerja dengan prinsip LIFO, di mana data terakhir yang masuk akan menjadi data pertama yang keluar. Melalui guided dan unguided, mahasiswa dapat memahami cara kerja operasi dasar seperti push, pop, update, view, serta variasi penerapannya pada kasus berbeda. Praktikum ini memberikan gambaran jelas bahwa stack sangat fleksibel dan dapat digunakan untuk memproses data secara terstruktur dan efisien.

## Referensi
[1]GeeksforGeeks — Stack Data Structure  https://www.geeksforgeeks.org/dsa/stack-data-structure/<br/>
[2]Tutorialspoint — Stack Data Structure  https://www.programiz.com/dsa/stack <br/>
[3]Programiz — Stack  https://ocw.mit.edu <br/>
