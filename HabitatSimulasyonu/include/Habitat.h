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
	Canli** canlilar; // B�t�n canl�lar� tutan Canl� Dizisi
	int satir_sayisi; // Veri.txt sat�r say�s�
	int sutun_sayisi; // Veri.txt s�tun say�s�

	void (*Baslat)(); // Program� ba�latan fonksiyon

	void (*yoket)(struct HABITAT*); // Habitat yoket fonksiyonu adresi
};
typedef struct HABITAT* Habitat;

Habitat HabitatOlustur(); // Habitat olu�turan fonk.
void SatirSutunSayisiBul(const Habitat this); // Veri.txt verilerin sat�r, sut�n say�s�n� bulan fonk.
void VeritxtOku(const Habitat); // Say�lar� okuyup Canl�lar dizisine atayan fonk.
void CanliTurleriniBul(const Habitat); // Say�lar�na g�re canl�lar�n t�rlerini bulan fonk.
void HabitatiGoster(const Habitat); // Canl�lar� tablo �ekinde ekrana yans�tan fonk.
void Baslat(const Habitat); // Program� ba�latan fonk.
void HabitatYoket(const Habitat); // Habitat� yok eden fonk.

#endif