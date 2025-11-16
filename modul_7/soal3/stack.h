#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
const int MAX = 20;
typedef char Infotype;
struct Stack {
    char data[MAX];
    int top;
};

void createStack(Stack &S);
Infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void getInputStream(Stack &S);
void push(Stack &S, Infotype x);
bool isEmpty(Stack S);
#endif