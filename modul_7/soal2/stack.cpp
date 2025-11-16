#include "stack.h"
#include <iostream>
using namespace std;
void createStack(Stack &S) {
    S.top = -1;
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
    
    cout << "Stack telah dibalik." << endl;
    printInfo(S);
}
void pushAscending(Stack &S, Infotype x) {
    
    Stack tempStack;
    createStack(tempStack);
    while (S.top != -1 && S.info[S.top] < x) {
        Infotype nilai = pop(S);
        tempStack.top++;
        tempStack.info[tempStack.top] = nilai;
    }
    S.top++;
    S.info[S.top] = x;
    while (tempStack.top != -1) {
        Infotype nilai = pop(tempStack);
        S.top++;
        S.info[S.top] = nilai;
    }

}
