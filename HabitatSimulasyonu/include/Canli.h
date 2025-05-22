#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
extern const int YASIYOR, OLU;
	
struct CANLI{
	int sayi; // Okunan say�
	int yasiyorMu; // Ya��yor mu?

	void* tur; // Canl�n�n t�r�

	char* (*gorunum)(int); //Harf d�nd�recek fonksiyonun adresi

	void (*yoket)(struct CANLI*); // Yokedecek fonksiyonun adresi
};
typedef struct CANLI* Canli;

Canli CanliOlustur(); // Canl� olu�turma fonk.
void CanliYoket(const Canli); // Canl� yoketme fonk.

#endif