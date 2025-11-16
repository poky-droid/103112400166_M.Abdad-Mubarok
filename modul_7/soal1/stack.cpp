#include "stack.h"
#include <iostream>
using namespace std;
void createStack(Stack &S) {
    S.top = -1;
}
void push(Stack &S) {
    if (S.top == 19) {
        cout << "Stack penuh!" << endl;
    } else {
        int nilai;
        cout << "Masukkan nilai yang akan dipush: ";
        cin >> nilai;
        S.top++;
        S.info[S.top] = nilai;
    }
}
Infotype pop(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        Infotype nilai = S.info[S.top];
        S.top--;
        return nilai;
    }
}
void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "Isi Stack: ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}
void balikStack(Stack &S) {
    Stack tempStack;
    createStack(tempStack);
    while (S.top != -1) {
        Infotype nilai = pop(S);
        tempStack.top++;
        tempStack.info[tempStack.top] = nilai;
    }
    S = tempStack;
}
