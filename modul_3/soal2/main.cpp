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
