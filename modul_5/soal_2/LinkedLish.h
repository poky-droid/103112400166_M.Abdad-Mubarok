#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value);

Node* linearSearch(Node* head, int key);

void displayList(Node* head);

#endif
