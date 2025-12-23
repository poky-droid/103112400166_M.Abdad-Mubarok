#ifndef MLL_H
#define MLL_H
#include <iostream>
#include <string>

using namespace std;

struct NodeChild;

struct NodeChild {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    NodeChild *next;
    NodeChild *prev;
};

struct ListChild {
    NodeChild *first;
    NodeChild *last;
};

struct NodeParent {
    string IDGenre;
    string namaGenre;
    NodeParent *next;
    NodeParent *prev;
    ListChild childs; 
};

struct ListParent {
    NodeParent *first;
    NodeParent *last;
};

void createListParent(ListParent &L);
void createListChild(ListChild &L);
NodeParent* allocateParent(string IDGenre, string namaGenre);
NodeChild* allocateChild(string IDFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm);
void deallocateParent(NodeParent *P);
void deallocateChild(NodeChild *C);
void insertFirstParent(ListParent &L, NodeParent *P);
void insertLastChild(ListChild &L, NodeChild *C);
void insertFirstChild(ListChild &L, NodeChild *C);
void deleteAfterParent(ListParent &L, NodeParent *P);
void hapusListChild(ListChild &L);
void searchFilmByRatingRange(ListChild L, float ratingmin, float ratingmax);
void printAll(ListParent L);
#endif