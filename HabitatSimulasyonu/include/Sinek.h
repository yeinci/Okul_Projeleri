#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK {
	Bocek super; // Sineðin süperi olacak Böcek

	void (*yoket)(struct SINEK*); // Yokedecek fonksiyonun adresi
};
typedef struct SINEK* Sinek;

Sinek SinekOlustur(int sayi, Bocek); // Sinek oluþturma fonk.
char* GorunumSinek(int); // Sinek görünüm fonk.
void SinekYoket(const Sinek); // Sinek yokt fonk.

#endif