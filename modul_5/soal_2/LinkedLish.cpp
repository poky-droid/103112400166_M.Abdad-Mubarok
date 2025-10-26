#include "LinkedList.h"

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

Node* linearSearch(Node* head, int key) {
    Node* temp = head;
    int step = 1;

    cout << "\nProses Pencarian:\n";
    while (temp) {
        cout << "Memeriksa node ke-" << step 
             << ": " << temp->data;

        if (temp->data == key) {
            cout << " (SAMA) -> DITEMUKAN!\n";
            return temp;
        } else {
            cout << " (tidak sama)\n";
        }

        temp = temp->next;
        step++;
    }

    cout << "Tidak ada node lagi yang tersisa.\n";
    return nullptr;
}
