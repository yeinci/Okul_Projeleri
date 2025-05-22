#include "Arac.h"

//Kurucu fonksiyon
Arac aracOlustur(char* isim, Gezegen cikisGezegeni, Gezegen varisGezegeni, Zaman cikisTarihi, int mesafe) {
    Arac this = (Arac)malloc(sizeof(struct ARAC));
    
    this->isim = strdup(isim);
    this->cikisGezegeni = cikisGezegeni;
    this->varisGezegeni = varisGezegeni;
    this->cikisTarihi = cikisTarihi;
    this->mesafe = mesafe;
    this->durum = strdup("Bekliyor");
    this->yolcuSayisi = 0;
    this->bulunduguGezegen = cikisGezegeni;
    this->kalkisaKalanSaat = kalkisaKalanSaatHesapla(this);
    this->hedefeKalanSaat = this->kalkisaKalanSaat + this->mesafe;
    this->hedefeVaracagiTarih = hedefeVaracagiTarihHesapla(this);

    this->yolcuSayisiGuncelle = &yolcuSayisiGuncelle;
    this->birSaatIlerle = &aracBirSaatIlerle;
    this->yoket = &aracYoket;

    return this;
}

// 1 saat simule eder, Aracın durumlarını kontrol eder.
void aracBirSaatIlerle(Arac this) {
    if (strcmp(this->durum, "Vardi") == 0 || strcmp(this->durum, "Imha") == 0) return;

    this->kalkisaKalanSaat--;
    this->hedefeKalanSaat--;
    
    if (strcmp(this->durum, "Bekliyor") == 0) {
        if (this->kalkisaKalanSaat <= 0) {
            aracKalkti(this);
        }
    } else {
        if (this->hedefeKalanSaat == 0) {
            aracVardi(this);
        }
    }
}

// Arac kalktğında çağırılan fonksiyon
void aracKalkti(const Arac this) {
	free(this->durum);
    this->durum = strdup("Yolda");

	this->bulunduguGezegen->nufus -= this->yolcuSayisi;
	this->bulunduguGezegen = NULL;
}

// Araç vardığında çağırılıan fonksiyon
void aracVardi(const Arac this) {
	free(this->durum);
    this->durum = strdup("Vardi");

	this->bulunduguGezegen = this->varisGezegeni;
	this->bulunduguGezegen->nufus += this->yolcuSayisi;
}

// YolcuSayisini dışarıdan gelen verilere göre düzenleyen fonksiyon, bulunduğu Gezegenin nufusunu da günceller
void yolcuSayisiGuncelle(const Arac this, int x) {
    this->yolcuSayisi += x;
    if (this->bulunduguGezegen != NULL) {
		this->bulunduguGezegen->nufus += x;
	}
    if (strcmp(this->durum, "Vardi") != 0 && this->yolcuSayisi == 0) {
		free(this->durum);
        this->durum = strdup("Imha");
	}
}

// Kalkışa kalan saati hesaplar döndürür
int kalkisaKalanSaatHesapla(const Arac this) {
    return this->cikisTarihi->saatFarkiHesapla(
        this->cikisTarihi,
        this->cikisGezegeni->tarih,
        this->cikisGezegeni->gunSaatMiktari
    );
}

// Hedefe Varacağı tarihi hesaplar oluşturur döndürür
Zaman hedefeVaracagiTarihHesapla(const Arac this) {
    Zaman hedefeVaracagiTarih = this->varisGezegeni->tarih->kopyala(this->varisGezegeni->tarih);
    for (int i = 0; i < this->hedefeKalanSaat; i++) {
        hedefeVaracagiTarih->birSaatIlerle(hedefeVaracagiTarih, this->varisGezegeni->gunSaatMiktari);
    }
    return hedefeVaracagiTarih;
}

// Yıkıcı fonksiyon
void aracYoket(const Arac this) {
    if (this == NULL) return;
    free(this->isim); /// isim kontrol
    free(this->durum);
    this->cikisTarihi->yoket(this->cikisTarihi);
    this->hedefeVaracagiTarih->yoket(this->hedefeVaracagiTarih);
    free(this);
}