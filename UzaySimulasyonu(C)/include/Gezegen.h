/**
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* Gezegen Yapısı;
* Gezegen ile alakalı değerleri ve fonksiyonları saklayan soyut sınıf benzeri yapıdır.
* </p>
*/
#ifndef GEZEGEN_H
#define GEZEGEN_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Zaman.h"

struct KAYAC;
struct GAZDEVI;
struct BUZDEVI;
struct CUCE;

struct GEZEGEN{
	char* isim;
	int gunSaatMiktari;
    Zaman tarih;
	int tur;
	int nufus;
	float yaslanmaCarpani;

	void (*birSaatIlerle)(struct GEZEGEN*);
	void (*yoket)(struct GEZEGEN*);
};
typedef struct GEZEGEN* Gezegen;

Gezegen gezegenOlustur(char* isim, int gunSaatMiktari, Zaman tarih);
void gezegenDoldur(Gezegen this, char* isim, int gunSaatMiktari, Zaman tarih);
void gezegenBirSaatIlerle(Gezegen this);
void gezegenYoket(const Gezegen this);

#endif