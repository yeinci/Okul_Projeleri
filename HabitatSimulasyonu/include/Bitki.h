#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI {
	Canli super; // Bitkinin s�peri olacak Canl� s�n�f�

	void (*yoket)(struct BITKI*); // Yokedecek fonksiyonun adresi
};
typedef struct BITKI* Bitki;

Bitki BitkiOlustur(int sayi, Canli); // Bitki olu�turma fonk.
char *GorunumBitki(int); // Bitki g�r�n�m fonk.
void BitkiYoket(const Bitki);// Bitki Yoketme fonk.

#endif