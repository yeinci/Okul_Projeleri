#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK {
	Canli super; // B�ce�in s�peri olacak Canl�

	void (*yoket)(struct BOCEK*); // Yokedecek fonksiyonun adresi
};
typedef struct BOCEK* Bocek;

Bocek BocekOlustur(int sayi, Canli); // B�cek olu�turma fonk.
char *GorunumBocek(int); // B�cek g�r�n�m fonk.
void BocekYoket(const Bocek); // B�cek yoket fonk.

#endif