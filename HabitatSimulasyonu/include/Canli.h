#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
extern const int YASIYOR, OLU;
	
struct CANLI{
	int sayi; // Okunan sayý
	int yasiyorMu; // Yaþýyor mu?

	void* tur; // Canlýnýn türü

	char* (*gorunum)(int); //Harf döndürecek fonksiyonun adresi

	void (*yoket)(struct CANLI*); // Yokedecek fonksiyonun adresi
};
typedef struct CANLI* Canli;

Canli CanliOlustur(); // Canlý oluþturma fonk.
void CanliYoket(const Canli); // Canlý yoketme fonk.

#endif