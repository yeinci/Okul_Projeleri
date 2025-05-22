/**
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* Dugum Yapısı;
* Bağlı liste düğümü yapısı.
* Nesneleri ve yoketme fonksiyonlarını saklar.
* </p>
*/
#ifndef DUGUM_H
#define DUGUM_H

#include "stdio.h"
#include "stdlib.h"

struct DUGUM {
    void* veri;
    void (*veriYoket)(void*);
    struct DUGUM* sonraki;

    void (*yoket)(struct DUGUM*);
};
typedef struct DUGUM* Dugum;

Dugum dugumOlustur(void* veri, void (*veriYoket)(void*));
void dugumYoket(Dugum dugum);

#endif