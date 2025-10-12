#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>
using std::string;

typedef struct {
   string namaMapel;
   string KodeMapel;
} Pelajaran;

Pelajaran Create_Pelajaran(const string &namaMapel, const string &KodeMapel);

void Tampilkan_Pelajaran(const Pelajaran &pelajaran);
#endif 