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
    if(isFullQueue(Q)){
        cout << "queue penuh" << endl;

    }
    if (isEmptyQueue(Q)){
        Q.head = 1;
        Q.tail = 1;
        Q.info[0] = x;
    }else{
        Q.tail++;
        Q.info[Q.tail - 1] = x;
    }
    
}

Infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "queue kosong" << endl;
        return -1;
    }
    Infotype hasil = Q.info[0];
    for (int i = 0; i < Q.tail - 1; i++){
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;
    if (Q.tail == 0){
        Q.head = 0;
    }
    return hasil;
}
void printInfoQueue(Queue Q) {
    int H, T;

    if (isEmptyQueue(Q)) {
        H = -1;
        T = -1;
    } else {
        H = Q.head - 1;   
        T = Q.tail - 1;   
    }

    cout << H << "  -  " << T << "  |  ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = 0; i < Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}
