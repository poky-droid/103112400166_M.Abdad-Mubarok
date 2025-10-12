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
