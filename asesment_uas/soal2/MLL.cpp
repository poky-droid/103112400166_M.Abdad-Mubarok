#include "MLL.h"
void createListParent(ListParent &L) {
    L.first = NULL;
    L.last = NULL;
}
void createListChild(ListChild &L) {
    L.first = NULL;
    L.last = NULL;
}
NodeParent* allocateParent(string IDGenre, string namaGenre) {
    NodeParent *P = new NodeParent;
    P->IDGenre = IDGenre;
    P->namaGenre = namaGenre;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->childs);
    return P;
}
NodeChild* allocateChild(string IDFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm) {
    NodeChild *C = new NodeChild;
    C->IDFilm = IDFilm;
    C->judulFilm = judulFilm;
    C->durasiFilm = durasiFilm;
    C->tahunTayang = tahunTayang;
    C->ratingFilm = ratingFilm;
    C->next = NULL;
    C->prev = NULL;
    return C;
}


void deallocateParent(NodeParent *P) {
    delete P;
}
void deallocateChild(NodeChild *C) {
    delete C;
}
void insertFirstParent(ListParent &L, NodeParent *P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}
void insertLastChild(ListChild &L, NodeChild *C) {
    if (L.first == NULL) {
        L.first = C;
        L.last = C;
    } else {
        L.last->next = C;
        C->prev = L.last;
        L.last = C;
    }
}
void insertFirstChild(ListChild &L, NodeChild *C) {
    if (L.first == NULL) {
        L.first = C;
        L.last = C;
    } else {
        C->next = L.first;
        L.first->prev = C;
        L.first = C;
    }
}
void deleteAfterParent(ListParent &L, NodeParent *P) {
    if (P != NULL) {
        if (P == L.first && P == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else if (P == L.first) {
            L.first = P->next;
            L.first->prev = NULL;
        } else if (P == L.last) {
            L.last = P->prev;
            L.last->next = NULL;
        } else {
            P->prev->next = P->next;
            P->next->prev = P->prev;
        }
        deallocateParent(P);
    }
}
void hapusListChild(ListChild &L) {
    NodeChild *C = L.first;
    while (C != NULL) {
        NodeChild *temp = C;
        C = C->next;
        deallocateChild(temp);
    }
    L.first = NULL;
    L.last = NULL;
}
void searchFilmByRatingRange(ListChild L, float minR, float maxR) {
    NodeChild *C = L.first;
    int cPos = 1;
    bool found = false;
    while (C != nullptr) {
        if (C->ratingFilm >= minR && C->ratingFilm <= maxR) {
            cout << "Data Film ditemukan pada list child pada posisi ke-" << cPos << "!" << endl;
            cout << "--- Data Film (Child) ---\nJudul Film : " << C->judulFilm << "\nPosisi dalam list child : posisi ke-" << cPos << endl;
            cout << "    ID Film : " << C->IDFilm << "\n    Durasi Film : " << C->durasiFilm << " menit\n    Tahun Tayang : " << C->tahunTayang << "\n    Rating Film : " << C->ratingFilm << endl;
            cout << "========================================" << endl;
            found = true;
        }
        C = C->next; cPos++;
    }
    if (!found) {
        cout << "Tidak ada film dengan rating dalam range tersebut." << endl;
    }
}
void printAll(ListParent L) {
    NodeParent *P = L.first;
    int pIdx = 1;
    while (P != nullptr) {
        cout << "=== Parent " << pIdx++ << " ===" << endl;
        cout << "ID Genre : " << P->IDGenre << "\nNama Genre : " << P->namaGenre << endl;
        NodeChild *C = P->childs.first;
        int cIdx = 1;
        while (C != nullptr) {
            cout << "  - Child " << cIdx++ << " :\n    ID Film : " << C->IDFilm << "\n    Judul Film : " << C->judulFilm 
                 << "\n    Durasi Film : " << C->durasiFilm << " menit\n    Tahun Tayang : " << C->tahunTayang 
                 << "\n    Rating Film : " << C->ratingFilm << endl;
            C = C->next;
        }
        cout << "--------------------------" << endl;
        P = P->next;
    }
}