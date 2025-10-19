#include "singlylist.h"

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

void printList(List L) {
    Node* temp = L.first;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
