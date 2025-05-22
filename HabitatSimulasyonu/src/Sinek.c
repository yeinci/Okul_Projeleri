#include "Sinek.h"

Sinek SinekOlustur(int sayi, Bocek bocek) {
	Sinek this;
	this = (Sinek)malloc(sizeof(struct SINEK));
	this->super = bocek; // Sineðin süperi Böcek
	bocek->super->tur = (void*)this; //Canlýnýn türü Sinek

	this->super->super->gorunum = &GorunumSinek; //Canlýnýn gorunum adresine GorunumSinek atýyor
	this->yoket = &SinekYoket; // Canlýnýn yoket adresine SinekYoket atýyor

	return this;
}

char* GorunumSinek(int yasiyorMu) {
	if (yasiyorMu == YASIYOR) { // Yaþýyorsa B, Ölüyse X döndürüyor
		return "S";
	}
	return "X";
}

void SinekYoket(const Sinek this) {
	this->super->yoket(this->super); //Böcek Sýnýfýný yoket
	if (this == NULL) return;
	free(this); //Kendisini yoket
}