#include "Canli.h"
const int YASIYOR = 1, OLU = 0;

Canli CanliOlustur() {
	Canli this;
	this = (Canli)malloc(sizeof(struct CANLI));

	this->yasiyorMu = YASIYOR; // Canl� "Ya��yor" olarak olu�turuluyor
	this->tur = NULL;

	this->yoket = &CanliYoket; // CanliYoket fonksiyonunu Canl�n�n yoket adresine yaz�yor
}

void CanliYoket(const Canli this) {
	if (this == NULL) return;
	free(this); // Kendisini yokediyor
}