#include "Queue.h"
using namespace std;
#include <iostream>

int main(){
    cout <<"Hello World!" << endl;
    Queue Q;
    CreateQueue(Q);

    cout<<"-------------------------"<<endl;
    cout<<"H - T \t | Queue info    "<< endl;
    cout<<"-------------------------"<<endl;
    printInfoQueue(Q);
    enqueue (Q, 5); printInfoQueue(Q);
    enqueue (Q, 2); printInfoQueue(Q);
    enqueue (Q, 7); printInfoQueue(Q);
    dequeue (Q); printInfoQueue(Q);
    enqueue (Q, 4); printInfoQueue(Q);
    dequeue (Q); printInfoQueue(Q);
    dequeue (Q); printInfoQueue(Q);

    return 0;
}