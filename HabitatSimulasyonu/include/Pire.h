#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE {
	Bocek super; // Pirenin s�peri olacak B�cek

	void (*yoket)(struct PIRE*); // Yokedecek fonksiyonun adresi
};
typedef struct PIRE* Pire;

Pire PireOlustur(int sayi, Bocek); // Pire olu�turma fonk.
char* GorunumPire(int); // Pire g�r�n�m fonk.
void PireYoket(const Pire); // Pire yoket fonk.

#endif