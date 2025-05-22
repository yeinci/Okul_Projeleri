/**
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* Kayac Yapısı;
* Gezegen alt yapisi
* </p>
*/
#ifndef KAYAC_H
#define KAYAC_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Gezegen.h"

struct KAYAC{
	struct GEZEGEN super;

    void (*yoket)(struct KAYAC*);
};
typedef struct KAYAC* Kayac;

Kayac kayacOlustur(char* isim, int gunSaatMiktari, Zaman tarih);
void kayacYoket(const Kayac this);

#endif