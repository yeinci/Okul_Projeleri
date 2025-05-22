#include "Liste.h"

// Kurucu fonksiyon
Liste listeOlustur() {
    Liste this = (Liste)malloc(sizeof(struct LISTE));

    this->ilk = NULL;
    this->uzunluk = 0;

    this->ekle = &listeEkle;
    this->getir = &listeGetir;
    this->yoket = &listeYoket;

    return this;
}

// listeye eleman ekleyen fonksiyon
void listeEkle(Liste this, void* veri, void (*veriYoket)(void*)) {
    Dugum dugum = dugumOlustur(veri, veriYoket);

    if (this->ilk == NULL) {
        this->ilk = dugum;
    } else {
        Dugum gecici = this->ilk;
        while (gecici->sonraki != NULL) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = dugum;
    }
    this->uzunluk++;
}

// listenin indexindeki elemanı döndüren fonksiyon
void* listeGetir(Liste this, int index) {
    Dugum gecici = this->ilk;
    int i = 0;

    for (int i = 0; gecici != NULL && i < index; i++) {
        gecici = gecici->sonraki;
    }
    return gecici->veri;
}

// Yıkıcı fonksiyon
void listeYoket(Liste this) {
    Dugum gecici = this->ilk;

    while (gecici != NULL) { // Bütün düğümler silinir
        Dugum silinecek = gecici;
        gecici = gecici->sonraki;
        silinecek->yoket(silinecek);
    }
    free(this);
}
