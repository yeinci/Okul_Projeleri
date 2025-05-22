#include "Cuce.h"

// Kurucu fonksiyon
Cuce cuceOlustur(char* isim, int gunSaatMiktari, Zaman tarih) {
    Cuce this = (Cuce)malloc(sizeof(struct CUCE));
    Gezegen superPtr = &this->super;

    gezegenDoldur(superPtr, isim, gunSaatMiktari, tarih);
    this->super.yaslanmaCarpani = 0.01f;
    this->super.tur = 3; // Ana sinifin tur degeri 3(Cuce) atanir

    this->yoket = &cuceYoket;
    return this;
}

// Yıkıcı fonksiyon
void cuceYoket(const Cuce this) {
    if (this == NULL) return;
    Gezegen superPtr = &this->super;
    superPtr->yoket(superPtr);
    free(this);
}