/**
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* Zaman Yapısı;
* Zaman ile alakalı değerleri ve fonksiyonları saklayan yapıdır.
* </p>
*/
#ifndef ZAMAN_H
#define ZAMAN_H

#include "stdio.h"
#include "stdlib.h"

struct ZAMAN;
typedef struct ZAMAN* Zaman;

struct ZAMAN{
    int saat;
    int gun;
    int ay;
    int yil;
    
    Zaman (*kopyala)(struct ZAMAN*);
    int (*saatFarkiHesapla)(struct ZAMAN*, struct ZAMAN*, int);
    char* (*toString)(struct ZAMAN*);
    void (*birSaatIlerle)(struct ZAMAN*, int);
    void (*yoket)(struct ZAMAN*);
};

Zaman zamanOlustur(int gun, int ay, int yil);
Zaman zamanOlusturSaatli(int saat, int gun, int ay, int yil);
Zaman zamanKopyala(const Zaman this);
int zamanSaatFarkiHesapla(const Zaman this, const Zaman tarih2, int gunSaatMiktari);
void zamanBirSaatIlerle(const Zaman this, int gunSaatMiktari);
int ayGunSayisi(int);
char* toString_Zaman(const Zaman);
void zamanYoket(const Zaman this);

#endif