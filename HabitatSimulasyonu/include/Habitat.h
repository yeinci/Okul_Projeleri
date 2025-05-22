#ifndef HABITAT_H
#define HABITAT_H

#include "stdio.h"
#include "stdlib.h"
#include "Bitki.h"
#include "Canli.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"


struct HABITAT {
	Canli** canlilar; // Bütün canlýlarý tutan Canlý Dizisi
	int satir_sayisi; // Veri.txt satýr sayýsý
	int sutun_sayisi; // Veri.txt sütun sayýsý

	void (*Baslat)(); // Programý baþlatan fonksiyon

	void (*yoket)(struct HABITAT*); // Habitat yoket fonksiyonu adresi
};
typedef struct HABITAT* Habitat;

Habitat HabitatOlustur(); // Habitat oluþturan fonk.
void SatirSutunSayisiBul(const Habitat this); // Veri.txt verilerin satýr, sutün sayýsýný bulan fonk.
void VeritxtOku(const Habitat); // Sayýlarý okuyup Canlýlar dizisine atayan fonk.
void CanliTurleriniBul(const Habitat); // Sayýlarýna göre canlýlarýn türlerini bulan fonk.
void HabitatiGoster(const Habitat); // Canlýlarý tablo þekinde ekrana yansýtan fonk.
void Baslat(const Habitat); // Programý baþlatan fonk.
void HabitatYoket(const Habitat); // Habitatý yok eden fonk.

#endif