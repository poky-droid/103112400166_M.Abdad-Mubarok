#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

struct ElmList {
    infotype info;
    ElmList *next;
    ElmList *prev;
};

struct List {
    ElmList *first;
    ElmList *last;
};

// Fungsi dan prosedur
void createList(List &L);
ElmList* alokasi(infotype x);
void dealokasi(ElmList* p);
void insertLast(List &L, ElmList* p);
void printInfo(List L);

ElmList* findElm(List L, string x);
bool isDuplicate(List L, string nopol);

void deleteFirst(List &L, ElmList* &p);
void deleteLast(List &L, ElmList* &p);
void deleteAfter(List &L, ElmList* Prec, ElmList* &p);

#endif
