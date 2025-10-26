#include "linkedlist.h"

int main() {
    cout << "BINARY SEARCH PADA LINKED LIST\n\n";

    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    displayList(head);

    int key1,key2;
    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> key1;
    binarySearch(head, key1);

    cout << "\nMasukkan nilai kedua yang ingin dicari: ";
    cin >> key2;
    binarySearch(head, key2);

    return 0;
}
