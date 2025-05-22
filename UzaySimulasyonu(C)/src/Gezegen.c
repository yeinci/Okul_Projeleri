#include "Gezegen.h"


// Kurucu fonksiyon
Gezegen gezegenOlustur(char* isim, int gunSaatMiktari, Zaman tarih) {
    Gezegen this = (Gezegen)malloc(sizeof(struct GEZEGEN));
    
    this->isim = strdup(isim);
    this->gunSaatMiktari = gunSaatMiktari;
    this->tarih = tarih;
    this->nufus = 0;

    this->birSaatIlerle = &gezegenBirSaatIlerle;
    this->yoket = &gezegenYoket;

    return this;
}

// Zaten oluşturulmuş Gezegen için kurucu fonksiyon;
void gezegenDoldur(Gezegen this, char* isim, int gunSaatMiktari, Zaman tarih) {
    this->isim = strdup(isim);
    this->gunSaatMiktari = gunSaatMiktari;
    this->tarih = tarih;
    this->nufus = 0;

    this->birSaatIlerle = &gezegenBirSaatIlerle;
    this->yoket = &gezegenYoket;
}

// 1 saat simule eder
void gezegenBirSaatIlerle(Gezegen this) {
    this->tarih->birSaatIlerle(this->tarih, this->gunSaatMiktari);
}
// Yıkıcı fonksiyon
void gezegenYoket(const Gezegen this) {
    if (this == NULL) return;

    free(this->isim);
    this->tarih->yoket(this->tarih);
    // free(this); soyut sınıf olduğu için serbest bırakmıyor, alt sınıf serbest bırakacak
}