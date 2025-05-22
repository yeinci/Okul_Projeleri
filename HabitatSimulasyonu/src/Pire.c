#include "Pire.h"

Pire PireOlustur(int sayi, Bocek bocek) {
	Pire this;
	this = (Pire)malloc(sizeof(struct PIRE));
	this->super = bocek; // Pirenin süperi Böcek
	bocek->super->tur = (void*)this; // Canlýnýn Türü Pire

	this->super->super->gorunum = &GorunumPire; //Canlýnýn gorunum adresine GorunumPire atýyor
	this->yoket = &PireYoket; // Canlýnýn yoket adresine PireYoket atýyor

	return this;
}

char* GorunumPire(int yasiyorMu) {
	if (yasiyorMu == YASIYOR) { // Yaþýyorsa B, Ölüyse X döndürüyor
		return "P";
	}
	return "X";
}

void PireYoket(const Pire this) {
	this->super->yoket(this->super); //Böcek Sýnýfýný yoket
	if (this == NULL) return; 
	free(this); //Kendisini yoket
}