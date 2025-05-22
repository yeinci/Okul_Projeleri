#include "Bitki.h"

Bitki BitkiOlustur(int sayi, Canli canli) {
	Bitki this;
	this = (Bitki)malloc(sizeof(struct BITKI));
	this->super = canli; // Bitkinin s�peri Canl�
	this->super->tur = (void*)this; // Canl�n�n t�r� Bitki

	this->super->gorunum = &GorunumBitki; //Canl�n�n gorunum adresine GorunumBitki at�yor
	this->yoket = &BitkiYoket; // Canl�n�n yoket adresine BitkiYoket at�yor

	return this;
}

char *GorunumBitki(int yasiyorMu) {
	if (yasiyorMu == YASIYOR) { // Ya��yorsa B, �l�yse X d�nd�r�yor
		return "B";
	}
	return "X";
}
void BitkiYoket(const Bitki this) {
	this->super->yoket(this->super); // Canl� s�n�f�n� yokediyor
	if (this == NULL) return;
	free(this); // Kendisini yokediyor
}