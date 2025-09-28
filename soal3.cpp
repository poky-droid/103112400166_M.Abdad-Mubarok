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