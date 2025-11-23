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
    return (Q.tail == MAX - 1);
}
void printInfoQueue(Queue Q){
    cout << " " << Q.head << " - " << Q.tail << "\t | ";

    if(isEmptyQueue(Q)){
        cout << "Queue kosong" << endl;
        return;
    }

    int i = Q.head;
    while(true){
        cout << Q.info[i] << " ";
        if(i == Q.tail) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}
void enqueue(Queue &Q, Infotype x){
    if (isFullQueue(Q)){
        cout << "queue penuh" << endl;
        return;
    }
    if(isEmptyQueue(Q)){
        Q.head = 0;
        Q.tail = 0;

    }else{
        Q.tail = (Q.tail + 1) % MAX;
    }
    Q.info[Q.tail] = x;
}
Infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        return -1;
    }
    Infotype temp = Q.info[Q.head];
    if(Q.head == Q.tail){
        Q.head = -1;
        Q.tail = -1;
    }else{
        Q.head = (Q.head + 1) % MAX;
    }
    return temp;
}
