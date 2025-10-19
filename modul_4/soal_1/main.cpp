#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    insertFirst(L, 2);
    insertFirst(L, 9);
    insertFirst(L, 12);
    insertAfter(L.first->next, 8); 

    cout << "Isi Linked List: ";
    printList(L);

    return 0;
}
