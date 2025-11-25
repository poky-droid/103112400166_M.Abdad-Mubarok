#include "queuePengiriman.h"
#include <iostream>
using namespace std;
bool isEmpty(QueueEkspedisi &Q) {
    return (Q.front == -1 && Q.rear == -1);
}
bool isFull(QueueEkspedisi &Q) {
    return (Q.rear == MAX - 1);
}
void createQueue(QueueEkspedisi &Q) {
    Q.front = -1;
    Q.rear = -1;
}
void enqueue(QueueEkspedisi& Q, Paket p) {
    if (isFull(Q)) {
        cout << "Queue is full!" << endl;
    } else {
        if (Q.front == -1) {
            Q.front = 0; 
        }
        Q.rear++;
        Q.dataPaket[Q.rear] = p;
    }
}

void dequeue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        Paket paketDikeluarkan = Q.dataPaket[Q.front];
        cout << "Paket dengan Kode Resi " << paketDikeluarkan.KodeResi << " telah dikeluarkan dari queue." << endl;
        if (Q.front == Q.rear) {
            Q.front = -1;
            Q.rear = -1;
        } else {
            Q.front++;
        }
    }
}
void view(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Isi Queue Pengiriman:" << endl;
        for (int i = Q.front; i <= Q.rear; i++) {
            cout << "Kode Resi: " << Q.dataPaket[i].KodeResi
                    << ", Nama Pengirim: " << Q.dataPaket[i].NamaPengirim
                    << ", Berat Barang: " << Q.dataPaket[i].BeratBarang << " kg"
                    << ", Tujuan: " << Q.dataPaket[i].tujuan << endl;

        }
    }
}
int hitungBiayaTotal(QueueEkspedisi Q) {
    int totalBerat = 0;
    if (isEmpty(Q)) {
        return totalBerat;
    } else {
        for (int i = Q.front; i <= Q.rear; i++) {
            totalBerat += Q.dataPaket[i].BeratBarang;
        }
    }
    return totalBerat * 8250; 
    
}
