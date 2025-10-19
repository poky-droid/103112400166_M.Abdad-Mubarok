#include "Singlylist.h"
int main() {
    while (true) {
        List L;
        createList(L);

        insertFirst(L, 2);
        insertFirst(L, 8);
        insertFirst(L, 9);
        insertFirst(L, 12);

        cout << "Linked List Awal: ";
        printList(L);

        deleteFirst(L);

        deleteLast(L);

        deleteAfter(L.first);

        cout << "\nSetelah Penghapusan: ";
        printList(L);

        cout << "\nJumlah node : " << nbList(L) << endl;

        deleteList(L);

        cout << "\n- List Berhasil Terhapus -" << endl;
        cout << "Jumlah node : " << nbList(L) << endl;

        cout << endl;
    }

    return 0;
}
