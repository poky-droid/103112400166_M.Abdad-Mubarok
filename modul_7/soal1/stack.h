#ifndef stack_h
#define stack_h
#include <iostream>
using namespace std;
typedef int Infotype;
typedef struct Stack {
    int info[20];
    int top;
} Node;

void createStack(Stack &S);
void push(Stack &S);
Infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
#endif