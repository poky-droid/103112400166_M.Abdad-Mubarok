
#include <iostream>
#include "Multi.h"
using namespace std;

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL && LParent.last == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL && LChild.last == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        deleteListChild(P->L_Child);
        if (LParent.first == LParent.last) {
            LParent.first = LParent.last = NULL;
        } else {
            LParent.first = P->next;
            LParent.first->prev = NULL;
        }
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent P = NPrev->next;
        deleteListChild(P->L_Child);
        NPrev->next = P->next;
        if (P->next != NULL)
            P->next->prev = NPrev;
        else
            LParent.last = NPrev;
        deallocNodeParent(P);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild C = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = LChild.last = NULL;
        } else {
            LChild.first = C->next;
            LChild.first->prev = NULL;
        }
        deallocNodeChild(C);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild C = NPrev->next;
        NPrev->next = C->next;
        if (C->next != NULL)
            C->next->prev = NPrev;
        else
            LChild.last = NPrev;
        deallocNodeChild(C);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent &LParent) {
    NodeParent P = LParent.first;
    int parentKe = 1;

    while (P != NULL) {
        cout << "=== Parent " << parentKe << " ===" << endl;
        cout << "ID Golongan   : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        if (isEmptyChild(P->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild C = P->L_Child.first;
            int childKe = 1;

            while (C != NULL) {
                cout << "  - Child " << childKe << " :" << endl;
                cout << "    ID Hewan   : " << C->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "    Habitat    : " << C->isidata.habitat << endl;
                cout << "    Ekor       : " << (C->isidata.ekor ? 1 : 0) << endl;
                cout << "    Bobot      : " << C->isidata.bobot << endl;

                C = C->next;
                childKe++;
            }
        }

        cout << "------------------------------" << endl;
        P = P->next;
        parentKe++;
    }
}


void searchHewanByEkor(listParent &LParent, bool tail) {
    NodeParent p = LParent.first;
    int posParent = 1;
    bool ditemukan = false;

    while (p != NULL) {
        NodeChild c = p->L_Child.first;
        int posChild = 1;

        while (c != NULL) {
            if (c->isidata.ekor == tail) {
                ditemukan = true;

                cout << "Data ditemukan pada list anak dari node parent "
                     << p->isidata.namaGolongan
                     << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << c->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << posChild << endl;
                cout << "Nama Hewan : " << c->isidata.namaHewan << endl;
                cout << "Habitat : " << c->isidata.habitat << endl;
                cout << "Ekor : " << c->isidata.ekor << endl;
                cout << "Bobot : " << c->isidata.bobot << endl;

                cout << "-------------------------" << endl;
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << p->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << posParent << endl;
                cout << "Nama golongan : " << p->isidata.namaGolongan << endl;
                cout << "-------------------------" << endl << endl;
            }

            c = c->next;
            posChild++;
        }

        p = p->next;
        posParent++;
    }

    if (!ditemukan) {
        cout << "Data hewan dengan ekor = " << tail << " tidak ditemukan!" << endl;
    }
}