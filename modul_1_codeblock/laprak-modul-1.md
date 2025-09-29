# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">M. Abdad mubarok - 103112400166</p>

## Dasar Teori
Bahasa C++ merupakan bahasa pemrograman tingkat tinggi pada umumnya banyak digunakan untuk pengembangan perangkat lunak[1].bahasa ini dapat digunakan untuk berbagai platfrom,mulai dari sistem oprasi ,aplikasi desktop ,perangkat tertanam (embedded system ), hingga pengembanagn game [1].

### A. pengenalan code block ide<br/>
#### 1. code block merupakan IDe open source yang sering di gunakan untuk pemrograman c dan c++
#### 2. IDE ini mendukung berbagai compiler ,seperti GCC ,clang , dan visual C++

### B. Structur kontrol <br/>
#### 1. for termasuk ke dalam struktur kontrol perulanagn yang berfungsi menjalankan sebuah block perintah secara berulang sampai kondisi berhenti terpenuhi [2].
#### 2. if akan mengeksekusi sepotong kode jika eksspresi yang jadi patokan terpenuhi [2]

## Guided 

### 1. ...

```C++
#include <iostream>

using namespace std;

int main() {
   float input1, input2;
   cout << "Masukkan dua angka: ";
   cin >> input1 >> input2;
    cout << "penjumlahan: " ;
    cout << input1 + input2 << endl;
    cout << "pengurangan: " ;
    cout << input1 - input2 << endl;
    cout << "perkalian: " ;
    cout << input1 * input2 << endl;
    cout << "pembagian: " ;
    cout << input1 / input2 << endl;
   return 0;
}

```
penjelasan singkat guided 1

program di atas digunakan untuk menghitung operasi aritmatika dasar dari 2 inputan yang dimasukan oleh user ,program di atas akan menampilkan penjumlajhan ,pengurangan , perkalian dan pembagian 

### 2. ...

```C++
#include <iostream>
using namespace std;
 string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
 string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
 string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};
int main() {
   int input ;
   string hasil = "";
   cout << "Masukkan angka yang mau dijadikan kalimat : ";
   cin >> input;
   
   if (input >= 100) {
      if(input == 100 ){
         cout << "seratus" << endl;
         return 0;
      };
     
   }
   if (input >= 10) {
      if (input >= 10 && input < 20) {
         hasil += belasan[input - 10] + " ";
         input = 0;
      } else {
         hasil += puluhan[input / 10] + " ";
         input %= 10;
      }
   }
   if (input > 0) {
      hasil += satuan[input] + " ";
   }
   cout << "Dalam kata: " << hasil << endl;
   return 0;
}
```
penjelasan singkat guided 2

program diatas bertujuan untuk mengubah inputan bentuk angka menjadi kalimat ,contoh inputa 11 akan memberikan output sebelas

### 3. ...

```C++
#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Masukkan angka: ";
    cin >> n;

    for (int i= n; i>=1; i--){
       
        for (int s = 0; s < n - i; s++) {
            cout << "  ";
        }
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "*" ;
        for (int j = 1; j <= i; j++) {
            cout << " " << j;
        }
        cout << endl;
   }

   for (int sb = 0; sb < n; sb++) {
        cout << "  ";
    }
    cout << "*" << endl;
   
   return 0;
}
```
penjelasan singkat guided 3


## Unguided 

### 1. (Buatlah program yang menerima input-an dua buah bilangan bertipe float ,kemudian memberikan output- an hasil penjumlahan ,pengurangan ,perkalian ,dan pembagian dari dua bilangan tersebut )

```C++
s#include <iostream>

using namespace std;

int main() {
   float input1, input2;
   cout << "Masukkan dua angka: ";
   cin >> input1 >> input2;
    cout << "penjumlahan: " ;
    cout << input1 + input2 << endl;
    cout << "pengurangan: " ;
    cout << input1 - input2 << endl;
    cout << "perkalian: " ;
    cout << input1 * input2 << endl;
    cout << "pembagian: " ;
    cout << input1 / input2 << endl;
   return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_1_codeblock/output-soal1.png)



penjelasan unguided 1 
program di atas digunakan untuk menghitung operasi aritmatika dasar dari 2 inputan yang dimasukan oleh user ,program di atas akan menampilkan penjumlajhan ,pengurangan , perkalian dan pembagian

### 2. (buatlah sebuah program yang menerima masukan angka dan mengeluarkan angka tersebut dalam bentuk tulisan .Angka yang akan di-input -kan user adalah bilangan bulat positif mulai dari 0 s.d 100)

```C++
#include <iostream>
using namespace std;
 string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
 string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
 string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};
int main() {
   int input ;
   string hasil = "";
   cout << "Masukkan angka yang mau dijadikan kalimat : ";
   cin >> input;
   
   if (input >= 100) {
      if(input == 100 ){
         cout << "seratus" << endl;
         return 0;
      };
     
   }
   if (input >= 10) {
      if (input >= 10 && input < 20) {
         hasil += belasan[input - 10] + " ";
         input = 0;
      } else {
         hasil += puluhan[input / 10] + " ";
         input %= 10;
      }
   }
   if (input > 0) {
      hasil += satuan[input] + " ";
   }
   cout << "Dalam kata: " << hasil << endl;
   return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_1_codeblock/output-soal2.png)


penjelasan unguided 2
program diatas bertujuan untuk mengubah inputan bentuk angka menjadi kalimat ,contoh inputa 11 akan memberikan output sebelas,mengguanakn array yang akan di panggil dengan kondiisi tertentu.

### 3. (buatlah program yang memberikan input output sbb)

```C++
#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Masukkan angka: ";
    cin >> n;

    for (int i= n; i>=1; i--){
       
        for (int s = 0; s < n - i; s++) {
            cout << "  ";
        }
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "*" ;
        for (int j = 1; j <= i; j++) {
            cout << " " << j;
        }
        cout << endl;
   }

   for (int sb = 0; sb < n; sb++) {
        cout << "  ";
    }
    cout << "*" << endl;
   
   return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/poky-droid/103112400166_M.Abdad-Mubarok/blob/main/modul_1_codeblock/output-soal3.png)

penjelasan unguided 3
membuat pola segitiga angka simetris dengan tanda * di tengah. Angka menurun di kiri, naik di kanan, dan spasi digunakan untuk membentuk segitiga. Baris terakhir hanya berisi * di tengah.

## Kesimpulan
praktikum  modul 1 mengenalkan dasar-dasar c++dan penggunnaan code blocks IDE,pembelajaran menggunakan struktur kontrol ,serta menerapkan program sederhana . latihan yang dilakukan meliputi operasi aritmatika ,konvensi angka menjadi kata, dan pembuatan pola segitiga angka ,yang dapat membantu meningkatkan logika pemrograman 

## Referensi
[1] Dasar Pemrograman Logika Dengan C++   https://www.unika.ac.id/wp-content/uploads/2025/02/ebook-Berdi-Dasar-Logika-Pemrograman-C.pdf
[2]https://code.tutsplus.com/id/php-control-structures-and-loops--cms-31999t
<br>
<br>...
