#include "Doublylist.h"

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

ElmList* alokasi(infotype x) {
    ElmList* p = new ElmList;
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void dealokasi(ElmList* p) {
    delete p;
}

void insertLast(List &L, ElmList* p) {
    if (L.first == NULL) {
        L.first = p;
        L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

void printInfo(List L) {
    ElmList* p = L.first;
    int i = 1;
    cout << "DATA LIST 1" << endl;
    while (p != NULL) {
        cout << "no polisi : " << p->info.nopol << endl;
        cout << "warna     : " << p->info.warna << endl;
        cout << "tahun     : " << p->info.thnBuat << endl;
        cout << endl;
        p = p->next;
        i++;
    }
}

ElmList* findElm(List L, string x) {
    ElmList* p = L.first;
    while (p != NULL) {
        if (p->info.nopol == x) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

bool isDuplicate(List L, string nopol) {
    return findElm(L, nopol) != NULL;
}

void deleteFirst(List &L, ElmList* &p) {
    if (L.first != NULL) {
        p = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = p->next;
            L.first->prev = NULL;
            p->next = NULL;
        }
    }
}

void deleteLast(List &L, ElmList* &p) {
    if (L.last != NULL) {
        p = L.last;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.last = p->prev;
            L.last->next = NULL;
            p->prev = NULL;
        }
    }
}

void deleteAfter(List &L, ElmList* Prec, ElmList* &p) {
    if (Prec != NULL && Prec->next != NULL) {
        p = Prec->next;
        Prec->next = p->next;
        if (p->next != NULL) {
            p->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        p->next = NULL;
        p->prev = NULL;
    }
}
