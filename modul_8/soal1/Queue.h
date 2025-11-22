#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

typedef int Infotype;
typedef struct Queue {
    int info [5];
    int head;
    int tail;     

};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, Infotype x);
Infotype dequeue(Queue &Q);
void printInfoQueue(Queue Q);
#endif