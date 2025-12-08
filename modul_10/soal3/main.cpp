#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6); 
    insertNode(root,7);

    printInOrder(root);
    cout << endl;

    printInOrder(root);
    cout << endl;

    cout << "Pre-order   : ";
    printPreOrder(root);
    cout << endl;

    cout << "Post-order  : ";
    printPostOrder(root);
    cout << endl;


    return 0;
}
