#ifndef MULTI_H
#define MULTI_H
#include <iostream>
using namespace std;

typedef struct nodeParent* NodeParent;
typedef struct nodeChild* NodeChild;

struct nodeChild
{
string idMakanan;
string namaMakanan;
NodeChild next;
NodeChild prev;
};

struct listAnak
{
    NodeChild first;
    NodeChild last;
};

struct nodeParent { //node parent
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk
{
    NodeParent first;
    NodeParent last;
    /* data */
};

void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);
NodeParent alokasiNodeParent(string idkategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruInduk);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodeprev);

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodeprev);
void findChildById(listInduk LInduk, string idCari);

void printStructurMLL(listInduk LInduk);





#endif