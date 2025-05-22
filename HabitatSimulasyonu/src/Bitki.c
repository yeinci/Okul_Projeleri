#include "Bitki.h"

Bitki BitkiOlustur(int sayi, Canli canli) {
	Bitki this;
	this = (Bitki)malloc(sizeof(struct BITKI));
	this->super = canli; // Bitkinin süperi Canlý
	this->super->tur = (void*)this; // Canlýnýn türü Bitki

	this->super->gorunum = &GorunumBitki; //Canlýnýn gorunum adresine GorunumBitki atýyor
	this->yoket = &BitkiYoket; // Canlýnýn yoket adresine BitkiYoket atýyor

	return this;
}

char *GorunumBitki(int yasiyorMu) {
	if (yasiyorMu == YASIYOR) { // Yaþýyorsa B, Ölüyse X döndürüyor
		return "B";
	}
	return "X";
}
void BitkiYoket(const Bitki this) {
	this->super->yoket(this->super); // Canlý sýnýfýný yokediyor
	if (this == NULL) return;
	free(this); // Kendisini yokediyor
}