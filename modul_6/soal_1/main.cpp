#include "Doublylist.h"

int main() {
    List L;
    createList(L);

    int n;
    cout << "Masukan banyak data : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        infotype x;
        cout << "\nmasukkan nomor polisi : ";
        cin >> x.nopol;

        if (isDuplicate(L, x.nopol)) {
            cout << "nomor polisi sudah terdaftar\n";
            continue;
        }

        cout << "masukkan warna kendaraan : ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan : ";
        cin >> x.thnBuat;

        ElmList* p = alokasi(x);
        insertLast(L, p);
    }

    cout << endl;
    printInfo(L);

    string cari;
    cout << "Masukan Nomor polisi yang dicari : ";
    cin >> cari;

    ElmList* found = findElm(L, cari);
    if (found != NULL) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan!\n";
    }

    string hapus;
    cout << "\nMasukkan nomor polisi yang akan dihapus : ";
    cin >> hapus;

    ElmList* del = findElm(L, hapus);
    if (del != NULL) {
        if (del == L.first) {
            deleteFirst(L, del);
        } else if (del == L.last) {
            deleteLast(L, del);
        } else {
            deleteAfter(L, del->prev, del);
        }
        cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus\n";
        dealokasi(del);
    } else {
        cout << "Data tidak ditemukan!\n";
    }

    printInfo(L);

    return 0;
}
