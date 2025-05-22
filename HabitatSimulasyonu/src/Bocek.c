#include "Bocek.h"

Bocek BocekOlustur(int sayi, Canli canli) {
	Bocek this;
	this = (Bocek)malloc(sizeof(struct BOCEK));
	this->super = canli; // Böceðin süperi Canlý
	this->super->tur = (void*)this; // Canlýnýn türü Böcek

	this->super->gorunum = &GorunumBocek; //Canlýnýn gorunum adresine GorunumBocek atýyor
	this->yoket = &BocekYoket; // Canlýnýn yoket adresine BocekYoket atýyor

	return this;
}

char *GorunumBocek(int yasiyorMu) {
	if (yasiyorMu == YASIYOR) { // Yaþýyorsa B, Ölüyse X döndürüyor
		return "C";
	}
	return "X";
}
void BocekYoket(const Bocek this) {
	this->super->yoket(this->super); // Canlý sýnýfýný yokediyor
	if (this == NULL) return;
	free(this); // Kendisini yokediyor
}