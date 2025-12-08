#include <iostream>
#include "bstree.h"
using namespace std;

// Alokasi node baru
address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

// Insert ke BST
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

// Mencari node
address findNode(infotype x, address root) {
    if (root == Nil) return Nil;
    if (x == root->info) return root;
    else if (x < root->info) return findNode(x, root->left);
    else return findNode(x, root->right);
}

// Traversal InOrder
void printInOrder(address root) {
    if (root != Nil) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}


// Menghitung jumlah node
int hitungJumlahNode(address root) {
    if (root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

// Menghitung total nilai info seluruh node
int hitungTotalInfo(address root, int start) {
    if (root == Nil) return start;
    start += root->info;
    start = hitungTotalInfo(root->left, start);
    start = hitungTotalInfo(root->right, start);
    return start;
}

// Menghitung kedalaman maksimal tree
int hitungKedalaman(address root, int start) {
    if (root == Nil) return start;

    int kiri  = hitungKedalaman(root->left,  start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);

    return (kiri > kanan) ? kiri : kanan;
}

