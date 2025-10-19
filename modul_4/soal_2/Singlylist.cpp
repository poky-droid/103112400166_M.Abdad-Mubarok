#include "Singlylist.h"

void createList(List &L) {
    L.first = nullptr;
}

void insertFirst(List &L, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = L.first;
    L.first = newNode;
}

void insertAfter(Node* prevNode, int nilai) {
    if (prevNode == nullptr) return;
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertLast(List &L, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = nullptr;

    if (L.first == nullptr) {
        L.first = newNode;
    } else {
        Node* temp = L.first;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteFirst(List &L) {
    if (L.first != nullptr) {
        Node* hapus = L.first;
        L.first = L.first->next;
        delete hapus;
    }
}

void deleteAfter(Node* prevNode) {
    if (prevNode != nullptr && prevNode->next != nullptr) {
        Node* hapus = prevNode->next;
        prevNode->next = hapus->next;
        delete hapus;
    }
}

void deleteLast(List &L) {
    if (L.first != nullptr) {
        if (L.first->next == nullptr) {
            delete L.first;
            L.first = nullptr;
        } else {
            Node* temp = L.first;
            while (temp->next->next != nullptr)
                temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
    }
}

void printList(List L) {
    Node* temp = L.first;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int nbList(List L) {
    int count = 0;
    Node* temp = L.first;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.first != nullptr) {
        deleteFirst(L);
    }
}
