#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK {
	Canli super; // Böceðin süperi olacak Canlý

	void (*yoket)(struct BOCEK*); // Yokedecek fonksiyonun adresi
};
typedef struct BOCEK* Bocek;

Bocek BocekOlustur(int sayi, Canli); // Böcek oluþturma fonk.
char *GorunumBocek(int); // Böcek görünüm fonk.
void BocekYoket(const Bocek); // Böcek yoket fonk.

#endif