#include "Zaman.h"

// Kurucu fonksiyon
Zaman zamanOlustur(int gun, int ay, int yil) {
    Zaman this = (Zaman)malloc(sizeof(struct ZAMAN));

    this->saat = 0;
    this->gun = gun;
    this->ay = ay;
    this->yil = yil;

    this->saatFarkiHesapla = &zamanSaatFarkiHesapla;
    this->kopyala = &zamanKopyala;
    this->toString = &toString_Zaman;
    this->birSaatIlerle = &zamanBirSaatIlerle;
    this->yoket = &zamanYoket;

    return this;
}

// Saatli Kurucu fonksiyon
Zaman zamanOlusturSaatli(int saat, int gun, int ay, int yil) {
    Zaman this = (Zaman)malloc(sizeof(struct ZAMAN));

    this->saat = saat;
    this->gun = gun;
    this->ay = ay;
    this->yil = yil;

    this->saatFarkiHesapla = &zamanSaatFarkiHesapla;
    this->kopyala = &zamanKopyala;
    this->toString = &toString_Zaman;
    this->birSaatIlerle = &zamanBirSaatIlerle;
    this->yoket = &zamanYoket;

    return this;
}

// İki Zaman arasında saat cinsinden farkı bulur döndürür
int zamanSaatFarkiHesapla(const Zaman this, const Zaman tarih2, int gunSaatMiktari) {
    int toplamSaat1 = this->saat +
        (this->gun - 1) * gunSaatMiktari +
        (this->yil - 1) * 365 * gunSaatMiktari;

    for (int a = 1; a < this->ay; a++) {
        toplamSaat1 += ayGunSayisi(a) * gunSaatMiktari;
    }

    int toplamSaat2 = tarih2->saat +
        (tarih2->gun - 1) * gunSaatMiktari +
        (tarih2->yil - 1) * 365 * gunSaatMiktari;

    for (int a = 1; a < tarih2->ay; a++) {
        toplamSaat2 += ayGunSayisi(a) * gunSaatMiktari;
    }

    return abs(toplamSaat2 - toplamSaat1);
}

// Kopyasını oluşturur ve döndürür
Zaman zamanKopyala(const Zaman this) {
    return zamanOlusturSaatli(this->saat, this->gun, this->ay, this->yil);
}

// toString fonksiyonu
char* toString_Zaman(const Zaman this) {
    char* string = (char*)malloc(11 * sizeof(char));
    if (string == NULL) return NULL;

    snprintf(string, 11, "%02d.%02d.%04d", this->gun, this->ay, this->yil);

    return string;
}

// 1 saat simule eder
void zamanBirSaatIlerle(const Zaman this, int gunSaatMiktari) {
    if (this == NULL) return;

    this->saat++;
    if (this->saat == gunSaatMiktari) {
        this->saat = 0;

        this->gun++;
        if (this->gun == ayGunSayisi(this->ay) + 1) {
            this->gun = 1;

            this->ay++;
            if (this->ay == 13) {
                this->ay = 1;

                this->yil++;
            }
        }
    }
}

// Ay gün sayısı döndürür
int ayGunSayisi(int ay) {
    switch (ay) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return 28;
    }
}

// Yıkıcı fonksiyon
void zamanYoket(const Zaman this) {
    if (this == NULL) return;
    free(this);
}