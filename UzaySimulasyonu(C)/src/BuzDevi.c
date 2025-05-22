#include "BuzDevi.h"

// Kurucu fonksiyon
BuzDevi buzDeviOlustur(char* isim, int gunSaatMiktari, Zaman tarih) {
    BuzDevi this = (BuzDevi)malloc(sizeof(struct BUZDEVI));
    Gezegen superPtr = &this->super;

    gezegenDoldur(superPtr, isim, gunSaatMiktari, tarih);
    this->super.yaslanmaCarpani = 0.5f;
    this->super.tur = 2; // Ana sinifin tur degeri 2(Buz Devi) atanir

    this->yoket = &buzDeviYoket;
    return this;
}

// Yıkıcı fonksiyon
void buzDeviYoket(const BuzDevi this) {
    if (this == NULL) return;
    Gezegen superPtr = &this->super;
    superPtr->yoket(superPtr);
    free(this);
}