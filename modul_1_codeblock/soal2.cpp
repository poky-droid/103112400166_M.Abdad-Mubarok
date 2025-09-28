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
      if(input / 10 == 1) hasil += "sepuluh ";
      else hasil += puluhan[input / 10] + " ";
      input %= 10;
   }
   if (input > 0) {
      hasil += satuan[input] + " ";
   }
   cout << "Dalam kata: " << hasil << endl;
   return 0;
}