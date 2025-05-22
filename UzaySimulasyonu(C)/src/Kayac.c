#include "Kayac.h"

// Kurucu fonksiyon
Kayac kayacOlustur(char* isim, int gunSaatMiktari, Zaman tarih) {
    Kayac this = (Kayac)malloc(sizeof(struct KAYAC));
    Gezegen superPtr = &this->super;

    gezegenDoldur(superPtr, isim, gunSaatMiktari, tarih);
    this->super.yaslanmaCarpani = 1.0f;
    this->super.tur = 0; // Ana sinifin tur degeri 0(Kayac) atanir

    this->yoket = &kayacYoket;

    return this;
}

// Yıkıcı fonksiyon
void kayacYoket(const Kayac this) {
    if (this == NULL) return;
    Gezegen superPtr = &this->super;
    superPtr->yoket(superPtr);
    free(this);
}