/**
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* Arac Yapısı;
* Arac ile alakalı değerleri ve fonksiyonları saklayan yapıdır.
* </p>
*/
#ifndef ARAC_H
#define ARAC_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Zaman.h"
#include "Gezegen.h"

struct ARAC{
	char* isim;
	Gezegen cikisGezegeni;
    Gezegen varisGezegeni;
    Zaman cikisTarihi;
    int mesafe;
    char* durum;
    int yolcuSayisi;
    Gezegen bulunduguGezegen;
    int kalkisaKalanSaat;
    int hedefeKalanSaat;
    Zaman hedefeVaracagiTarih;

    void (*yolcuSayisiGuncelle)(struct ARAC*, int);
    void (*birSaatIlerle)(struct ARAC*);
	void (*yoket)(struct ARAC*);
};
typedef struct ARAC* Arac;

Arac aracOlustur(char* isim, Gezegen cikisGezegeni, Gezegen varisGezegeni, Zaman cikisTarihi, int mesafe);
void aracBirSaatIlerle(Arac this);
void aracKalkti(const Arac this);
void aracVardi(const Arac this);
void yolcuSayisiGuncelle(const Arac this, int x);
int kalkisaKalanSaatHesapla(const Arac this);
Zaman hedefeVaracagiTarihHesapla(const Arac this);
void aracYoket(const Arac this);

#endif