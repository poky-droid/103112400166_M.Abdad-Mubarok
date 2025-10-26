#include "LinkedList.h"
#include "LinkedLish.h"

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "LINEAR SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: ";
    displayList(head);

    int key;

    key = 30;
    cout << "\nMencari nilai: " << key << endl;
    Node* found = linearSearch(head, key);

    if (found)
        cout << "\nHasil: Nilai " << key << " DITEMUKAN dalam linked list!"
             << "\nAlamat node: " << found << endl;
    else
        cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;

    key = 25;
    cout << "\n\nMencari nilai: " << key << endl;
    found = linearSearch(head, key);

    if (found)
        cout << "\nHasil: Nilai " << key << " DITEMUKAN dalam linked list!"
             << "\nAlamat node: " << found << endl;
    else
        cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;

    return 0;
}
