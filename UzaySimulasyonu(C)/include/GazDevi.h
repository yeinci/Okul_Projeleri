/**
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* GazDevi Yapısı;
* Gezegen alt yapisi
* </p>
*/
#ifndef GAZDEVI_H
#define GAZDEVI_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Gezegen.h"

struct GAZDEVI{
    struct GEZEGEN super;
    void (*yoket)(struct GAZDEVI*);
};
typedef struct GAZDEVI* GazDevi;

GazDevi gazDeviOlustur(char* isim, int gunSaatMiktari, Zaman tarih);
void gazDeviYoket(const GazDevi this);

#endif