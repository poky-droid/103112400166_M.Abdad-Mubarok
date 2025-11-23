#ifndef MODUL8_SOAL2_QUEUE_H
#define MODUL8_SOAL2_QUEUE_H
#include <iostream>

typedef int Infotype;
typedef struct Queue {
    int info[5];
    int head;
    int tail;

} Queue;

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, Infotype x);
Infotype dequeue(Queue &Q);
void printInfoQueue(Queue Q);
#endif