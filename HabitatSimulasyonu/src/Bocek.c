#include "Bocek.h"

Bocek BocekOlustur(int sayi, Canli canli) {
	Bocek this;
	this = (Bocek)malloc(sizeof(struct BOCEK));
	this->super = canli; // B�ce�in s�peri Canl�
	this->super->tur = (void*)this; // Canl�n�n t�r� B�cek

	this->super->gorunum = &GorunumBocek; //Canl�n�n gorunum adresine GorunumBocek at�yor
	this->yoket = &BocekYoket; // Canl�n�n yoket adresine BocekYoket at�yor

	return this;
}

char *GorunumBocek(int yasiyorMu) {
	if (yasiyorMu == YASIYOR) { // Ya��yorsa B, �l�yse X d�nd�r�yor
		return "C";
	}
	return "X";
}
void BocekYoket(const Bocek this) {
	this->super->yoket(this->super); // Canl� s�n�f�n� yokediyor
	if (this == NULL) return;
	free(this); // Kendisini yokediyor
}