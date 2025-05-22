/**
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* Simulasyon Yapısı;
* Her şeyi kontrol eden temel yapıdır.
* </p>
*/
#ifndef SIMULASYON_H
#define SIMULASYON_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Liste.h"
#include "DosyaOkuma.h"

struct SIMULASYON{
    Liste gezegenListesi; // Tüm nesnelerin tutulduğu listeler
    Liste aracListesi;
    Liste kisiListesi;

    void (*baslat)(struct SIMULASYON*);
	void (*yoket)(struct SIMULASYON*);
};
typedef struct SIMULASYON* Simulasyon;

Simulasyon simulasyonOlustur();
void dosyalariOku(const Simulasyon this);
void simulasyonBaslat(const Simulasyon this);
int programBittiMi(const Simulasyon this);
void simulasyonBirSaatIlerle(const Simulasyon this);
void simulasyonYazdir(const Simulasyon this);
void simulasyonYoket(const Simulasyon this);

#endif