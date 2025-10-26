#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value);
void append(Node*& head, int value);
void displayList(Node* head);
int getSize(Node* head);
Node* getNodeAt(Node* head, int index);
Node* binarySearch(Node* head, int key);

#endif
