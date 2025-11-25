#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H
#include <iostream>
using namespace std;

typedef struct paket{
    string KodeResi;
    string NamaPengirim;
    int BeratBarang ; //dalam kg
    string tujuan;


} Paket;

const int MAX = 5;

typedef  struct QueueEkspedisi{
    Paket dataPaket[MAX];
    int front;
    int rear;
} QueueEkspedisi;


bool isEmpty(QueueEkspedisi &Q);
bool isFull(QueueEkspedisi &Q);
void createQueue(QueueEkspedisi &Q);
void enqueue(QueueEkspedisi &Q, Paket p);
void dequeue(QueueEkspedisi &Q);
void view(QueueEkspedisi Q);
int hitungBiayaTotal(QueueEkspedisi Q);

#endif





