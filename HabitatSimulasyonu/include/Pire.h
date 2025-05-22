#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE {
	Bocek super; // Pirenin süperi olacak Böcek

	void (*yoket)(struct PIRE*); // Yokedecek fonksiyonun adresi
};
typedef struct PIRE* Pire;

Pire PireOlustur(int sayi, Bocek); // Pire oluþturma fonk.
char* GorunumPire(int); // Pire görünüm fonk.
void PireYoket(const Pire); // Pire yoket fonk.

#endif