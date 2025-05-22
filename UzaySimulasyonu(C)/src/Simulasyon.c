#include "Simulasyon.h"

// Kurucu fonksiyon
Simulasyon simulasyonOlustur() {
    Simulasyon this = (Simulasyon)malloc(sizeof(struct SIMULASYON));

    dosyalariOku(this);

    this->baslat = &simulasyonBaslat;
    this->yoket = &simulasyonYoket;

    return this;
}

// Dosyaları okur ve listeleri doldurur.
void dosyalariOku(const Simulasyon this) {
	DosyaOkuma dosyaOkuma = dosyaOkumaOlustur();
    
    this->gezegenListesi = dosyaOkuma->gezegenListesi;
    this->aracListesi = dosyaOkuma->aracListesi;
    this->kisiListesi = dosyaOkuma->kisiListesi;

    dosyaOkuma->yoket(dosyaOkuma);
}

// Simulasyonuu başlatır, program bitene kadar döner
void simulasyonBaslat(const Simulasyon this) {
    simulasyonYazdir(this);
    while (!programBittiMi(this)) {
        simulasyonBirSaatIlerle(this);
        simulasyonYazdir(this);
    }
    simulasyonYazdir(this);
}

// Programın bitip bitmediğini bulur, Bütün araçlar imha yada vardıysa bitmiştir.
int programBittiMi(const Simulasyon this) {
    for (int i = 0; i < this->aracListesi->uzunluk; i++) {
        Arac arac = (Arac)this->aracListesi->getir(this->aracListesi, i);
        if (strcmp(arac->durum, "Imha") != 0 && strcmp(arac->durum, "Vardi") != 0) {
            return 0;
        }
    }
    return 1;
}

// Tüm simulasyonu bir saat sonrasına simule eder, bütün nesneler için birSaatIlerle fonksiyonlarını çağırır
void simulasyonBirSaatIlerle(const Simulasyon this) {
    int uzunluk = this->kisiListesi->uzunluk;
    for (int i = 0; i < uzunluk; i++) {
        Kisi kisi = (Kisi)this->kisiListesi->getir(this->kisiListesi, i);
        kisi->birSaatIlerle(kisi);
    }
    uzunluk = this->aracListesi->uzunluk;
    for (int i = 0; i < uzunluk; i++) {
        Arac arac = (Arac)this->aracListesi->getir(this->aracListesi, i);
        arac->birSaatIlerle(arac);
    }
    uzunluk = this->gezegenListesi->uzunluk;
    for (int i = 0; i < uzunluk; i++) {
        Gezegen gezegen = (Gezegen)this->gezegenListesi->getir(this->gezegenListesi, i);
        gezegen->birSaatIlerle(gezegen);
    }
}

// Konsol çıktısını yazan fonksiyon
void simulasyonYazdir(const Simulasyon this) {
    system("cls");

    printf("Gezegenler:\n");
    printf("%-20s", "");
    int uzunluk = this->gezegenListesi->uzunluk;
    for (int i = 0; i < uzunluk; i++) {
        Gezegen gezegen = (Gezegen)this->gezegenListesi->getir(this->gezegenListesi, i);
        char isim[20];
        snprintf(isim, sizeof(isim), "--- %s ---", gezegen->isim);
        printf("%-20s", isim);
    }
    printf("\n");

    printf("%-20s", "Tarih");
    for (int i = 0; i < uzunluk; i++) {
        Gezegen gezegen = (Gezegen)this->gezegenListesi->getir(this->gezegenListesi, i);
        char* tarihStr = gezegen->tarih->toString(gezegen->tarih);
        printf("%-20s", tarihStr);
        free(tarihStr);
    }
    printf("\n");

    printf("%-20s", "Nufus");
    for (int i = 0; i < uzunluk; i++) {
        Gezegen gezegen = (Gezegen)this->gezegenListesi->getir(this->gezegenListesi, i);
        printf("%-20d", gezegen->nufus);
    }
    printf("\n\n");
    printf("Uzay Araclari:\n");
    printf("%-20s%-10s%-10s%-10s%-20s%-20s\n",
           "Arac adi", "Durum", "Cikis", "Varis", "Hedefe Kalan Saat", "Hedefe Varacagi Tarih");

    for (int i = 0; i < this->aracListesi->uzunluk; i++) {
        Arac arac = (Arac)this->aracListesi->getir(this->aracListesi, i);

        char hedefeKalanSaat[20];
        char* hedefeVaracagiTarih;

        if (strcmp(arac->durum, "Imha") == 0) {
            strcpy(hedefeKalanSaat, "---");
            hedefeVaracagiTarih = strdup("---");
        } else {
            sprintf(hedefeKalanSaat, "%d", arac->hedefeKalanSaat);
            hedefeVaracagiTarih = arac->hedefeVaracagiTarih->toString(arac->hedefeVaracagiTarih);
        }
        printf("%-20s%-10s%-10s%-10s%-20s%-20s\n",
               arac->isim,
               arac->durum,
               arac->cikisGezegeni->isim,
               arac->varisGezegeni->isim,
               hedefeKalanSaat,
               hedefeVaracagiTarih);
        
        free(hedefeVaracagiTarih);
    }
}

// Yıkıcı fonksiyon, listeler elemanlarıyla birlikte silinir.
void simulasyonYoket(const Simulasyon this) {
    if (this == NULL) return;
    this->gezegenListesi->yoket(this->gezegenListesi);
    this->aracListesi->yoket(this->aracListesi);
    this->kisiListesi->yoket(this->kisiListesi);
    free(this);
}