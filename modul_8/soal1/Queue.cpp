#include "Queue.h"
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
    if (isEmptyQueue(Q)){
        Q.head = 0;
        Q.tail = 0;
        Q.info[Q.tail] = x;
    } else {
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}
Infotype dequeue(Queue &Q){
    Infotype x = Q.info[Q.head];
    if (Q.head == Q.tail){
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }
    return x;
}
void printInfoQueue(Queue Q){
    if (isEmptyQueue(Q)){
        cout << "Queue kosong" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
