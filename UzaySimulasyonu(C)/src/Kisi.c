#include "Kisi.h"

// Kurucu fonksiyon
Kisi kisiOlustur(char* isim, int yas, float kalanOmur, Arac bulunduguArac) {
    Kisi this = (Kisi)malloc(sizeof(struct KISI));
    
    this->isim = strdup(isim);
    this->yas = yas;
    this->kalanOmur = kalanOmur;
    this->bulunduguArac = bulunduguArac;
    this->yasiyorMu = 1;

    this->bulunduguArac->yolcuSayisiGuncelle(this->bulunduguArac, +1); // bulunduğu aracın yolcu sayısı +1

    this->birSaatIlerle = &kisiBirSaatIlerle;
    this->yoket = &kisiYoket;

    return this;
}

// 1 saat simule eder. ömrü biterse ölür
void kisiBirSaatIlerle(const Kisi this) {
    if (this->bulunduguArac->bulunduguGezegen != NULL) {
        this->kalanOmur -= this->bulunduguArac->bulunduguGezegen->yaslanmaCarpani;
    } else {
        this->kalanOmur -= 1;
    }
    if (this->kalanOmur <= 0 && this->yasiyorMu == 1) {
        this->bulunduguArac->yolcuSayisiGuncelle(this->bulunduguArac, -1);
        this->yasiyorMu = 0;
    }
}

// Yıkıcı fonksiyon
void kisiYoket(const Kisi this) {
    if (this == NULL) return;
    free(this->isim);
    free(this);
}