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