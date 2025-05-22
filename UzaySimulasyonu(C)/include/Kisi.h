/**
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* Kisi Yapısı;
* Kisi ile alakalı değerleri ve fonksiyonları saklayan yapıdır.
* </p>
*/
#ifndef KISI_H
#define KISI_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Arac.h"

struct KISI{
	char* isim;
	int yas;
    float kalanOmur;
    Arac bulunduguArac;

	int yasiyorMu;

	void (*birSaatIlerle)(struct KISI*);
	void (*yoket)(struct KISI*);
};
typedef struct KISI* Kisi;

Kisi kisiOlustur(char* isim, int yas, float kalanOmur, Arac bulunduguArac);
void kisiBirSaatIlerle(const Kisi this);
void kisiYoket(const Kisi this);

#endif