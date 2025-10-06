# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">M. Abdad mubarok - 103112400166</p>

## Dasar Teori
Bahasa C++ merupakan bahasa pemrograman tingkat tinggi pada umumnya banyak digunakan untuk pengembangan perangkat lunak[1].bahasa ini dapat digunakan untuk berbagai platfrom,mulai dari sistem oprasi ,aplikasi desktop ,perangkat tertanam (embedded system ), hingga pengembanagn game [1].

### A. Array <br/>
#### Array adalah struktur data statis yang digunakan untuk menyimpan sekumpulan nilai dengan tipe data yang sama dalam satu variabel. Elemen-elemen array diakses menggunakan indeks, dimulai dari 0.contoh
```C++
int angka[5] = {1, 2, 3, 4, 5};
cout << angka[0]; // Output: 1

```
### Array memudahkan penyimpanan dan pengolahan data dalam jumlah banyak seperti nilai siswa, daftar harga, atau elemen matriks [2].

### B. pointer <br/>
#### Pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Dengan pointer, kita dapat mengakses dan memanipulasi nilai secara langsung di memori.contoh
```C++
int a = 10;
int *ptr = &a;
cout << *ptr; // Output: 10

```


### B. prosedur <br/>
#### Prosedur atau fungsi void adalah bagian dari program yang memiliki tugas tertentu tetapi tidak mengembalikan nilai. Tujuannya adalah untuk membagi program menjadi bagian-bagian kecil (modular) agar lebih mudah dipahami dan dikelola.Contoh:
```C++
void tampilkanPesan() {
    cout << "Halo, Dunia!" << endl;
}

```
## Guided 

### 1. ...

```C++
#include <iostream>
using namespace std;

int main() {
    int arry[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan nilai ke-" << i + 1 << ": ";
        cin >> arry[i];
    }

    int j = 0;
    while (j < 5) {
        cout << "Nilai ke-" << j + 1 << ": " << arry[j] << endl;
        j++;
    }
    return 0;
}

```
penjelasan singkat guided 1
Program ini berfungsi untuk menyimpan serta menampilkan lima angka yang diberikan oleh pengguna melalui array. Pengisian dilakukan dengan menggunakan perulangan for, sedangkan untuk menampilkan hasilnya menggunakan while loop. Program ini mengenalkan ide tentang array dan kontrol perulangan dalam C++.

### 2. ...

```C++
#include <iostream>
using namespace std;

int cariMax(int arry[], int size) {
    int maxVal = arry[0];
    for (int i = 1; i < size; i++) {
        if (arry[i] > maxVal) {
            maxVal = arry[i];
        }
    }
    return maxVal;
}

void operasiAritmatika(int arry[],int size){
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arry[i];
    }
    int totalKali = 1;
    for (int i = 0; i < size; i++) {
    totalKali *= arry[i];
    }
    double avg = static_cast<double>(sum) / size;
    cout << "Jumlah: " << sum << endl;
    cout << "Rata-rata: " << avg << endl;
    cout << "Total Perkalian: " << totalKali << endl;

}

int main() {
    int arry[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan nilai ke-" << i + 1 << ": ";
        cin >> arry[i];
    }

    int j = 0;
    while (j < 5) {
        cout << "Nilai ke-" << j + 1 << ": " << arry[j] << endl;
        j++;
    }

    int maxVal = cariMax(arry, 5);
    cout << "Nilai maksimum: " << maxVal << endl;
    

    operasiAritmatika(arry, 5);

    return 0;
}
```
penjelasan singkat guided 2

Program ini mengukur nilai tertinggi, total, rata-rata, dan hasil dari perkalian semua elemen dalam array.

Fungsi cariMax() berfungsi untuk menemukan angka maksimum di dalam array.

Fungsi operasiAritmatika() melakukan perhitungan total, rata-rata, dan produk dari elemen-elemennya.
Program ini mengajarkan cara menggunakan fungsi (prosedur dan fungsi yang mengembalikan nilai) serta operasi pada array dalam C++.
### 3. ...

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,50};
    int*ptr = arr; 

    
    for(int i = 0; i<5; ++i){
        cout << " Elemen array ke-" << i+1 << " menggunakan pointer : " << *(ptr + i) << endl;
    }

    for (int i = 0; i < 5; ++i){
        cout << "elemen array ke-" << i + 1 << " menggunakan indeks: " << arr[i] << endl;
    }

    return 0;
}

```
penjelasan singkat guided 3
Program ini memperlihatkan dua metode untuk mencapai elemen dalam array:

Dengan menerapkan pointer aritmatika ((ptr + i)), dan

Dengan memanfaatkan indeks array standar (arr[i]).
Fokusnya adalah untuk memahami bahwa pointer dapat berfungsi sebagai pilihan lain untuk mengakses elemen array secara langsung dari alamat memori.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. 

```C++
#include <iostream>
using namespace std;

void tampilMatriks(int matriks[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }
}

void penjumlahanMatriks(int matriksA[3][3], int matriksB[3][3]) {
    int hasil[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }
    cout << "Hasil Penjumlahan Matriks:" << endl;
    tampilMatriks(hasil);
}

void perkalianMatriks(int matriksA[3][3], int matriksB[3][3]) {
    int hasil[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                hasil[i][j] += matriksA[i][k] * matriksB[k][j];
            }
        }
    }
    cout << "Hasil Perkalian Matriks:" << endl;
    tampilMatriks(hasil);
}

void penguranganMatriks(int matriksA[3][3], int matriksB[3][3]) {
    int hasil[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = matriksA[i][j] - matriksB[i][j];
        }
    }
    cout << "Hasil Pengurangan Matriks:" << endl;
    tampilMatriks(hasil);
}



int main(){
    int pilih ;

    int matriksA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int matriksB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
for (;;){
     cout << "----Menu Program Matriks ---" << endl;
    cout << "1. Penjumlahan Matriks" << endl;
    cout << "2. Pengurangan Matriks" << endl;
    cout << "3. Perkalian Matriks" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> pilih;

    switch(pilih){
        case 1:
            penjumlahanMatriks(matriksA, matriksB);
            break;
        case 2:
            penguranganMatriks(matriksA, matriksB);
            break;
        case 3:
            perkalianMatriks(matriksA, matriksB);
            break;
            case 4:
            cout << "Keluar dari program." << endl;
            return 0;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
    }
}
   

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_1_codeblock/output-soal1.png)



penjelasan unguided 1 
Program ini digunakan untuk melaksanakan operasi penambahan, pengurangan, dan perkalian di antara dua matriks yang berukuran 3x3.

Setiap operasi dipisahkan ke dalam fungsi yang berbeda agar alur program menjadi lebih teratur.

Hasilnya dipresentasikan melalui fungsi tampilMatriks(). Program ini memperkenalkan ide mengenai array dua dimensi serta pemrograman modular.

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer

```C++
#include <iostream>
using namespace std;

int main(){
    int panjang = 10;
    int lebar = 5;
    int luas =0;

    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar  : " << lebar << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    int keliling = 2 * (*ptrPanjang + *ptrLebar);

    cout << "\n--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang    : " << luas << endl;
    cout << "Keliling Persegi Panjang: " << keliling << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru: " << panjang << endl;
    cout << "Lebar Baru  : " << lebar << endl;
    cout << "Luas Baru   : " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;


    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_1_codeblock/output-soal2.png)


penjelasan unguided 2
Program ini mengilustrasikan metode pemanfaatan pointer untuk menghitung ukuran dan perimeter dari suatu persegi panjang. Nilai dari panjang dan lebar dapat diakses melalui pointer (ptrPanjang, ptrLebar). Ketika nilai-nilai tersebut dimodifikasi melalui pointer, maka nilai-nilai dalam variabel asal turut berubah karena keduanya merujuk pada alamat memori yang identik. Program ini menunjukkan penerapan pointer dalam pengolahan data secara langsung.

## Kesimpulan
Praktikum Modul 1 memberikan pengenalan tentang dasar-dasar C++ dan penggunaan Code::Blocks IDE, yang mencakup:

Pengumuman variabel, array, dan pointer,

Struktur pengendali seperti for dan while,

Penyelesaian program melalui penggunaan fungsi dan prosedur,

Operasi matematis serta pengolahan data di dalam array dan matriks.

Dengan menguasai konsep tersebut, mahasiswa dapat membangun logika pemrograman fundamental serta meningkatkan kemampuan berpikir algoritma yang lebih baik.

## Referensi
[1] Berdi, Dasar Logika Pemrograman C++, Universitas Katolik Soegijapranata, 2025.<br>
[2] TutsPlus, Control Structures and Loops in PHP/C++, https://code.tutsplus.com/id/php-control-structures-and-loops--cms-31999t
<br>
[3] GeeksforGeeks, C++ Pointers – A Complete Guide, https://www.geeksforgeeks.org/pointers-in-cpp/
<br>
[4] Tutorialspoint, C++ Arrays, https://www.tutorialspoint.com/cplusplus/cpp_arrays.htm
<br>
[5] W3Schools, C++ Functions, https://www.w3schools.com/cpp/cpp_functions.asp
<br>
