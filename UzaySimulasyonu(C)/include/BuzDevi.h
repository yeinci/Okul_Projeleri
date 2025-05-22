/**
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* BuzDevi Yapısı;
* Gezegen alt yapisi
* </p>
*/
#ifndef BUZDEVI_H
#define BUZDEVI_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Gezegen.h"

struct BUZDEVI{
    struct GEZEGEN super;
    void (*yoket)(struct BUZDEVI*);
};
typedef struct BUZDEVI* BuzDevi;

BuzDevi buzDeviOlustur(char* isim, int gunSaatMiktari, Zaman tarih);
void buzDeviYoket(const BuzDevi this);

#endif