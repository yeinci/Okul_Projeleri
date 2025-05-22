#include "GazDevi.h"

// Kurucu fonksiyon
GazDevi gazDeviOlustur(char* isim, int gunSaatMiktari, Zaman tarih) {
    GazDevi this = (GazDevi)malloc(sizeof(struct GAZDEVI));
    Gezegen superPtr = &this->super;

    gezegenDoldur(superPtr, isim, gunSaatMiktari, tarih);
    this->super.yaslanmaCarpani = 0.1f;
    this->super.tur = 1; // Ana sinifin tur degeri 1(Gaz Devi) atanir

    this->yoket = &gazDeviYoket;
    return this;
}

// Yıkıcı fonksiyon
void gazDeviYoket(const GazDevi this) {
    if (this == NULL) return;
    Gezegen superPtr = &this->super;
    superPtr->yoket(superPtr);
    free(this);
}