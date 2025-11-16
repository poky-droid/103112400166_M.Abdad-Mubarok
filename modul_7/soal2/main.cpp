#include "stack.cpp"
#include <iostream>
using namespace std;

int main (){
    Stack S;
    createStack(S);
    int pilihan;
    int n;
    do {
        cout << "Menu Stack Ascending:" << endl;
        cout << "1. Push Ascending" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print Stack" << endl;
        cout << "4. Balik Stack" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: {
                Infotype nilai;
                cout << "Masukkan jumlah nilai yang akan dipush secara ascending: ";
                cin >> n;
                for (int i = 0; i < n; i++){
                cout << "Masukkan nilai yang akan dipush secara ascending: ";
                cin >> nilai;
                pushAscending(S, nilai);
                }
                
            }
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