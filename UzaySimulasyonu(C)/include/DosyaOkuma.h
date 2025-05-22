/**
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* DosyaOkuma Yapısı;
* 3 dosyayıda okuyup okunan değerleren nesneler oluşturur, nesneleri Liste'lerde saklar.
* Bu listeler Simulasyon yapısı tarafından çekilir.
* </p>
*/
#ifndef DOSYAOKUMA_H
#define DOSYAOKUMA_H

#include "stdio.h"
#include "stdlib.h"

#include "Zaman.h"
#include "Gezegen.h"
#include "Kayac.h"
#include "GazDevi.h"
#include "BuzDevi.h"
#include "Cuce.h"
#include "Arac.h"
#include "Kisi.h"
#include "Liste.h"

struct DOSYAOKUMA{
	Liste gezegenListesi;
	Liste aracListesi;
	Liste kisiListesi;

	void (*yoket)(struct DOSYAOKUMA*);
};
typedef struct DOSYAOKUMA* DosyaOkuma;

DosyaOkuma dosyaOkumaOlustur();
void gezegenleriOku(const DosyaOkuma this);
Gezegen gezegeniBul(Liste gezegenListesi, const char* isim);
void araclariOku(const DosyaOkuma this);
Arac araciBul(Liste aracListesi, const char* isim);
void kisileriOku(const DosyaOkuma this);
void dosyaOkumaYoket(const DosyaOkuma this);

#endif