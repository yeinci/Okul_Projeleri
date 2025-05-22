#include "Dugum.h"

// Kurucu fonksiyon
Dugum dugumOlustur(void* veri, void (*veriYoket)(void*)) { // nesneyi ve yoketme fonksiyonunu alır
    Dugum this = (Dugum)malloc(sizeof(struct DUGUM));

    this->veri = veri;
    this->veriYoket=veriYoket;
    this->sonraki = NULL;

    this->yoket = &dugumYoket;

    return this;
}

// Yıkıcı fonksiyon
void dugumYoket(Dugum this) {
    this->veriYoket(this->veri); // nesneyi siler
    free(this);
}