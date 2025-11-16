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