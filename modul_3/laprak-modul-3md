# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
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

### 1. ...

```C++
#include <iostream>
using namespace std;
#include "mahasiswa.h"

void inputMhs(mahasiswa &m)
{
    cout << "Masukkan NIM: ";
    cin >> m.nim;
    cout << "Masukkan nilai 1: ";
    cin >> m.nilai1;
    cout << "Masukkan nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m)
{
    return (m.nilai1 + m.nilai2) / 2.0f;
}


```

```h
#ifndef MAHASISWA_H
#define MAHASISWA_H

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```

```C++
#include <iostream>
using namespace std;
#include "mahasiswa.h"
#include <cstdlib>

int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata: " << rata2(mhs) << endl;
    cout << "Data Mahasiswa:" << endl;
    cout << "NIM: " << mhs.nim << endl;
    cout << "Nilai 1: " << mhs.nilai1 << endl;
    cout << "Nilai 2: " << mhs.nilai2 << endl;
    system("pause");
    return 0;
}

```


penjelasan singkat guided 1
Program di atas menggunakan struktur mahasiswa untuk menyimpan data NIM dan nilai.
Fungsi inputMhs() digunakan untuk menerima input dari pengguna, sedangkan fungsi rata2() menghitung rata-rata dari dua nilai.
Konsep ini menunjukkan bagaimana ADT digunakan dalam pemrograman C++ untuk memisahkan antara data dan operasinya [4].


## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa maksimal 10 ke dalam sebuah array dengan field nama, nim, uts, uas, tugas dan nilai akhir. nilai akhir yang diperoleh dengan rumus 0.3uts + 0.4uas + 0.3*tugas. 

```C++
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa mhs[10];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> jumlah;
    cin.ignore(); 

    if (jumlah > 10) jumlah = 10;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;

        cout << "Nama  : ";
        getline(cin, mhs[i].nama);

        cout << "NIM   : ";
        getline(cin, mhs[i].nim);

        cout << "Nilai UTS  : ";
        cin >> mhs[i].uts;

        cout << "Nilai UAS  : ";
        cin >> mhs[i].uas;

        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);

        cin.ignore(); 
    }

    cout << "\n=============================================\n";
    cout << "Daftar Nilai Mahasiswa\n";
    cout << "=============================================\n";
    cout << "No\tNIM\t\tNama\t\tNilai Akhir\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << "\t" << mhs[i].nim << "\t" << mhs[i].nama 
             << "\t\t" << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}


```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_3/ss_soal_1.png)



penjelasan unguided 1 <br/>
Program ini menggunakan array of struct untuk menyimpan hingga 10 data mahasiswa.
Fungsi hitungNilaiAkhir() menghitung nilai akhir berdasarkan bobot tugas, UTS, dan UAS.
Konsep ini menunjukkan penggunaan struktur data terorganisir serta pengulangan untuk pemrosesan banyak data [3][5].


### 2. Buatlah ADT pelajaran dengan file "pelajaran.h" lalu buat implementasi ADT pelajran dalam file "pelajaran.cpp" lalu coba hasil implementasi ADT dalam file "main.cpp"

"pelajaran.h"

```h
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>
using std::string;

typedef struct {
   string namaMapel;
   string KodeMapel;
} Pelajaran;

Pelajaran Create_Pelajaran(const string &namaMapel, const string &KodeMapel);

void Tampilkan_Pelajaran(const Pelajaran &pelajaran);
#endif 
```

```C++
#include "pelajaran.h"
#include <iostream>
using std::cout;

Pelajaran Create_Pelajaran(const string &namaMapel, const string &KodeMapel) {
    Pelajaran pelajaran;
    pelajaran.namaMapel = namaMapel;
    pelajaran.KodeMapel = KodeMapel;
    return pelajaran;
}

void Tampilkan_Pelajaran(const Pelajaran &pelajaran) {
    cout << "Nama Pelajaran: " << pelajaran.namaMapel << "\n";
    cout << "Kode Pelajaran: " << pelajaran.KodeMapel << "\n";
}

int main() {
    string namapel = "Struktur Data";
    string kodepel = "std";
    Pelajaran pel = Create_Pelajaran(namapel, kodepel);
    Tampilkan_Pelajaran(pel);
    return 0;
}

```

### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_3/ss_soal_2.png)


penjelasan unguided 2 <br/>
Program ini menerapkan ADT (Abstract Data Type) dengan tiga file terpisah:

pelajaran.h berisi deklarasi struktur dan fungsi

pelajaran.cpp berisi implementasi fungsi

main.cpp untuk menjalankan program
Struktur pemisahan ini mencerminkan praktik modular programming dan meningkatkan keterbacaan serta pemeliharaan kode [6][7].

## Unguided 

### 3. 

```C++
#include <iostream>
using namespace std;

float nilai[10];

float nilaiAkhir(float nilaiTugas, float nilaiUts, float nilaiUas) {
    return (0.3 * nilaiTugas) + (0.3 * nilaiUts) + (0.4 * nilaiUas);
}

int main() {
    int banyak ;
    cout << "Masukkan banyak mahasiswa (maks 10): ";
    cin >> banyak;
    if (banyak > 10) {
        cout << "Maksimal mahasiswa adalah 10." << endl;
        return 1;
    }
    float nilaiTugas, nilaiUts, nilaiUas;

    for (int i = 0; i < banyak; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Masukkan nilai tugas: ";
        cin >> nilaiTugas;
        cout << "Masukkan nilai UTS: ";
        cin >> nilaiUts;
        cout << "Masukkan nilai UAS: ";
        cin >> nilaiUas;

        nilai[i] = nilaiAkhir(nilaiTugas, nilaiUts, nilaiUas);
        cout << endl;
    }

    cout << "\n=== Hasil Nilai Akhir ===\n";
    for (int i = 0; i < banyak; i++) {
        cout << "Nilai akhir mahasiswa ke-" << i + 1 << ": " << nilai[i] << endl;
    }

    return 0;
}

```
### Output Unguided 3 :

##### Output 3
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_3/ss_soal_3.png)



penjelasan unguided 3 <br/>
Program ini menghitung nilai akhir beberapa mahasiswa dengan menggunakan array bertipe float.
Pendekatan ini memperlihatkan dasar penggunaan fungsi dan array dalam bahasa C++ untuk melakukan perhitungan berulang [1][4].



## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa:

C++ memiliki struktur modular yang memungkinkan pemisahan antara logika program dan data melalui penggunaan ADT (Abstract Data Type).

Penggunaan struct, array, dan fungsi membantu dalam pengorganisasian data dan meningkatkan efisiensi program.

Penerapan ADT dan modularitas adalah fondasi penting dalam pengembangan perangkat lunak berskala besar [2][6][7].

## Referensi
[1] Berdi, Dasar Logika Pemrograman C++, Universitas Katolik Soegijapranata, 2025.<br>
[2] Bjarne Stroustrup, The C++ Programming Language, Addison-Wesley, 2013.<br>
[3] Deitel, H. & Deitel, P., C++ How to Program (10th Edition), Pearson, 2016.<br>
[4] Malik, D. S., C++ Programming: From Problem Analysis to Program Design, Cengage Learning, 2018.<br>
[5] Wirth, N., Algorithms + Data Structures = Programs, Prentice Hall, 1976.<br>
[6] Liang, Y. D., Introduction to Programming with C++, Pearson, 2022.<br>
[7] Lippman, S. B., Lajoie, J., & Moo, B. E., C++ Primer (5th Edition), Addison-Wesley, 2012.<br>