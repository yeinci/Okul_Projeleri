#include "Canli.h"
const int YASIYOR = 1, OLU = 0;

Canli CanliOlustur() {
	Canli this;
	this = (Canli)malloc(sizeof(struct CANLI));

	this->yasiyorMu = YASIYOR; // Canlý "Yaþýyor" olarak oluþturuluyor
	this->tur = NULL;

	this->yoket = &CanliYoket; // CanliYoket fonksiyonunu Canlýnýn yoket adresine yazýyor
}

void CanliYoket(const Canli this) {
	if (this == NULL) return;
	free(this); // Kendisini yokediyor
}