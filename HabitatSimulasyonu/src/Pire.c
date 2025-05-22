#include "Pire.h"

Pire PireOlustur(int sayi, Bocek bocek) {
	Pire this;
	this = (Pire)malloc(sizeof(struct PIRE));
	this->super = bocek; // Pirenin s�peri B�cek
	bocek->super->tur = (void*)this; // Canl�n�n T�r� Pire

	this->super->super->gorunum = &GorunumPire; //Canl�n�n gorunum adresine GorunumPire at�yor
	this->yoket = &PireYoket; // Canl�n�n yoket adresine PireYoket at�yor

	return this;
}

char* GorunumPire(int yasiyorMu) {
	if (yasiyorMu == YASIYOR) { // Ya��yorsa B, �l�yse X d�nd�r�yor
		return "P";
	}
	return "X";
}

void PireYoket(const Pire this) {
	this->super->yoket(this->super); //B�cek S�n�f�n� yoket
	if (this == NULL) return; 
	free(this); //Kendisini yoket
}