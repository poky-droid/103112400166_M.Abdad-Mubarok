#include <iostream>
#include "Multi.h"
using namespace std;

void inputData(listParent &LP) {
    NodeParent G1 = allocNodeParent("G001", "Aves");
    NodeParent G2 = allocNodeParent("G002", "Mamalia");
    NodeParent G3 = allocNodeParent("G003", "Pisces");
    NodeParent G4 = allocNodeParent("G004", "Amfibi");
    NodeParent G5 = allocNodeParent("G005", "Reptil");

    insertLastParent(LP, G1);
    insertLastParent(LP, G2);
    insertLastParent(LP, G3);
    insertLastParent(LP, G4);
    insertLastParent(LP, G5);

    // Child G001
    insertLastChild(G1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    // Child G002
    insertLastChild(G2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(G2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    // Child G004
    insertLastChild(G4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));
}

int main() {
    listParent LP;
    createListParent(LP);

    int pilihan;
    bool dataSudahDiinput = false;

    do {
        cout << "\n===== MENU PRAKTIKUM MULTI LINKED LIST =====" << endl;
        cout << "1. Soal 1 - Insert & Print Data" << endl;
        cout << "2. Soal 2 - Search Hewan Ekor FALSE" << endl;
        cout << "3. Soal 3 - Delete Parent G004 & Print" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (!dataSudahDiinput) {
                    inputData(LP);
                    dataSudahDiinput = true;
                }
                cout << "\n=== OUTPUT SOAL 1 ===" << endl;
                printMLLStructure(LP);
                break;

            case 2:
                if (!dataSudahDiinput) {
                    cout << "Data belum diinput! Jalankan Soal 1 terlebih dahulu.\n";
                } else {
                    cout << "\n=== OUTPUT SOAL 2 (EKOR = FALSE) ===" << endl;
                    searchHewanByEkor(LP, false);
                }
                break;

            case 3:
                if (!dataSudahDiinput) {
                    cout << "Data belum diinput! Jalankan Soal 1 terlebih dahulu.\n";
                } else {
                    cout << "\n=== DELETE PARENT G004 (AMFIBI) ===" << endl;
                    // G004 berada setelah G003
                    deleteAfterParent(LP, LP.first->next->next);
                    printMLLStructure(LP);
                }
                break;

            case 0:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
