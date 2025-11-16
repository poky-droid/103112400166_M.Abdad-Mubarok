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
        Infotype nilai = S.data[S.top];
        S.top--;
        return nilai;
    }
}
void printInfo(Stack S) {
    cout << "Isi Stack: ";
    while (!isEmpty(S)) {
        cout << S.data[S.top--] << " ";
    }
    cout << endl;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}
void balikStack(Stack &S) {
    Stack tempStack;
    createStack(tempStack);

    while (S.top != -1) {
        Infotype nilai = pop(S);
        tempStack.top++;
        tempStack.data[tempStack.top] = nilai;
    }
    S = tempStack;
    cout << "Stack telah dibalik." << endl;
    printInfo(S);
}
void getInputStream(Stack &S) {
    cout << "Masukkan input (tanpa spasi, tekan ENTER untuk selesai): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char c = cin.get();

    while (c != '\n') {
        if (c == ' ') {
            cout << "\nError: Input tidak boleh mengandung spasi!\n";
            return; 
        }
        push(S, c);
        c = cin.get();
    }
}


void push(Stack &S, Infotype x) {
    if (S.top == 19) {
        cout << "Stack penuh!" << endl;
        return;
    }
    S.top++;
    S.data[S.top] = x;
}

