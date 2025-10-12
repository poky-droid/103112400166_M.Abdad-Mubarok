#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void tukarElemenArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int *p1 = &arr1[baris][kolom];
    int *p2 = &arr2[baris][kolom];
    tukarPointer(p1, p2);
}

int main() {
    int array1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int array2[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    cout << "Array 1 sebelum ditukar:\n";
    tampilArray(array1);
    cout << "Array 2 sebelum ditukar:\n";
    tampilArray(array2);

    int baris = 1, kolom = 2; 
    tukarElemenArray(array1, array2, baris, kolom);

    cout << "Setelah menukar elemen posisi [" << baris << "][" << kolom << "]:\n";
    cout << "Array 1:\n";
    tampilArray(array1);
    cout << "Array 2:\n";
    tampilArray(array2);

    int a = 100, b = 200;
    int *pa = &a, *pb = &b;

    cout << "Sebelum tukar pointer: a = " << a << ", b = " << b << endl;
    tukarPointer(pa, pb);
    cout << "Setelah tukar pointer: a = " << a << ", b = " << b << endl;

    return 0;
}
