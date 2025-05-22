/**
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* Cuce Yapısı;
* Gezegen alt yapisi
* </p>
*/
#ifndef CUCE_H
#define CUCE_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Gezegen.h"

struct CUCE{
    struct GEZEGEN super;
    void (*yoket)(struct CUCE*);
};
typedef struct CUCE* Cuce;

Cuce cuceOlustur(char* isim, int gunSaatMiktari, Zaman tarih);
void cuceYoket(const Cuce this);

#endif