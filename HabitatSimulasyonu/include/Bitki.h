#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI {
	Canli super; // Bitkinin süperi olacak Canlý sýnýfý

	void (*yoket)(struct BITKI*); // Yokedecek fonksiyonun adresi
};
typedef struct BITKI* Bitki;

Bitki BitkiOlustur(int sayi, Canli); // Bitki oluþturma fonk.
char *GorunumBitki(int); // Bitki görünüm fonk.
void BitkiYoket(const Bitki);// Bitki Yoketme fonk.

#endif