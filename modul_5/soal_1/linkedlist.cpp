#include "LinkedList.h"

// Membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Menambah node di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Menampilkan isi linked list
void displayList(Node* head) {
    cout << "Linked List yang dibuat: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Menghitung jumlah node
int getSize(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Mengambil node pada posisi tertentu
Node* getNodeAt(Node* head, int index) {
    for (int i = 0; head && i < index; i++)
        head = head->next;
    return head;
}

// Algoritma Binary Search untuk Linked List
Node* binarySearch(Node* head, int key) {
    cout << "\nMencari nilai: " << key << endl;
    cout << "\nProses Pencarian:" << endl;

    int left = 0;
    int right = getSize(head) - 1;
    int iterasi = 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(head, mid);

        cout << "Iterasi " << iterasi++ << ": Mid = " << midNode->data
             << " (indeks tengah)";

        if (midNode->data == key) {
            cout << " - DITEMUKAN!\n";
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << midNode << endl;
            cout << "Data node: " << midNode->data << endl;
            if (midNode->next)
                cout << "Node berikutnya: " << midNode->next->data << endl;
            else
                cout << "Node berikutnya: (tidak ada, ini node terakhir)\n";
            return midNode;
        } else if (midNode->data < key) {
            cout << " -> Cari di bagian kanan\n";
            left = mid + 1;
        } else {
            cout << " -> Cari di bagian kiri\n";
            right = mid - 1;
        }
    }

    cout << "Tidak ada elemen tersisa\n";
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}
