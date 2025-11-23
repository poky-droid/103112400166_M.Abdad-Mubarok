#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;

}

bool isEmptyQueue(Queue Q){
    return (Q.head == -1 && Q.tail == -1);
}
bool isFullQueue(Queue Q){
    return (Q.tail == 4);
}
void enqueue(Queue &Q, Infotype x){
   if (!isFullQueue(Q)){
        if (isEmptyQueue(Q)){
            // first element
            Q.head = 0;
            Q.tail = 0;
            Q.info[Q.tail] = x;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    } else {
        cout << "queue penuh \n";
    }

}
Infotype dequeue(Queue &Q){
    if (!isEmptyQueue(Q)) {
        int x = Q.info[Q.head];

        // if removing last element, reset queue to empty state
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head++;
        }
        return x;
    }
    cout << "Queue kosong!\n";
    return -1;

}

void printInfoQueue(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << "\n";
}