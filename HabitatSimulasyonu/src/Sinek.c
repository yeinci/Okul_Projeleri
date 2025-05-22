#include "Sinek.h"

Sinek SinekOlustur(int sayi, Bocek bocek) {
	Sinek this;
	this = (Sinek)malloc(sizeof(struct SINEK));
	this->super = bocek; // Sine�in s�peri B�cek
	bocek->super->tur = (void*)this; //Canl�n�n t�r� Sinek

	this->super->super->gorunum = &GorunumSinek; //Canl�n�n gorunum adresine GorunumSinek at�yor
	this->yoket = &SinekYoket; // Canl�n�n yoket adresine SinekYoket at�yor

	return this;
}

char* GorunumSinek(int yasiyorMu) {
	if (yasiyorMu == YASIYOR) { // Ya��yorsa B, �l�yse X d�nd�r�yor
		return "S";
	}
	return "X";
}

void SinekYoket(const Sinek this) {
	this->super->yoket(this->super); //B�cek S�n�f�n� yoket
	if (this == NULL) return;
	free(this); //Kendisini yoket
}