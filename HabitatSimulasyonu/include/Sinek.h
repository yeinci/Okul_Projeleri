#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK {
	Bocek super; // Sine�in s�peri olacak B�cek

	void (*yoket)(struct SINEK*); // Yokedecek fonksiyonun adresi
};
typedef struct SINEK* Sinek;

Sinek SinekOlustur(int sayi, Bocek); // Sinek olu�turma fonk.
char* GorunumSinek(int); // Sinek g�r�n�m fonk.
void SinekYoket(const Sinek); // Sinek yokt fonk.

#endif