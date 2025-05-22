#include "DosyaOkuma.h"

// Kurucu fonksiyon, listeleri oluşturur ve doldurur.
DosyaOkuma dosyaOkumaOlustur() {
    DosyaOkuma this = (DosyaOkuma)malloc(sizeof(struct DOSYAOKUMA));
    this->gezegenListesi = listeOlustur();
    gezegenleriOku(this);
    this->aracListesi = listeOlustur();
    araclariOku(this);
    this->kisiListesi = listeOlustur();
    kisileriOku(this);
    printf("buradym");
    this->yoket = &dosyaOkumaYoket;
    return this;
}

// "Gezegenler.txt" dosyasını okur, Gezegen Listesini doldurur
void gezegenleriOku(const DosyaOkuma this) {
    FILE* dosyaOku = fopen("Gezegenler.txt", "r");
    if (dosyaOku == NULL) {
        printf("Dosya acilamadi: %s\n", "Gezegenler.txt");
    }

    char satir[128];

    while (fgets(satir, sizeof(satir), dosyaOku)) {
        char isim[32];
        int tur, gunSaatMiktari, gun, ay, yil;

        if (sscanf(satir, "%31[^#]#%d#%d#%d.%d.%d", isim, &tur, &gunSaatMiktari, &gun, &ay, &yil) == 6) {
            Zaman tarih = zamanOlustur(gun, ay, yil);
            Gezegen gezegen;
            
            switch (tur)
            {
            case 0: {
                Kayac kayac = kayacOlustur(isim, gunSaatMiktari, tarih);
                this->gezegenListesi->ekle(this->gezegenListesi, kayac, (void (*)(void*))kayac->yoket);
                break;
            }
            case 1: {
                GazDevi gazDevi = gazDeviOlustur(isim, gunSaatMiktari, tarih);
                this->gezegenListesi->ekle(this->gezegenListesi, gazDevi, (void (*)(void*))gazDevi->yoket);
                break;
            }
            case 2: {
                BuzDevi buzDevi = buzDeviOlustur(isim, gunSaatMiktari, tarih);
                this->gezegenListesi->ekle(this->gezegenListesi, buzDevi, (void (*)(void*))buzDevi->yoket);
                break;
            }
            case 3: {
                Cuce cuce = cuceOlustur(isim, gunSaatMiktari, tarih);
                this->gezegenListesi->ekle(this->gezegenListesi, cuce, (void (*)(void*))cuce->yoket);
                break;
            }
            default: {
                printf("Gezegen turu algilanamadi: %s\n", satir);
                break;
            }
            }
        } else {
            printf("Gezegen formati algilanamadi: %s\n", satir);
        }
    }

    fclose(dosyaOku);
}

// İsmi verilen gezegeni bulur, Gezegen olarak cast eder ve döndürür.
Gezegen gezegeniBul(Liste gezegenListesi, const char* isim) {
    int uzunluk = gezegenListesi->uzunluk;

    for (int i = 0; i < uzunluk; i++) {
        Gezegen gezegen = (Gezegen)gezegenListesi->getir(gezegenListesi, i);
        if (strcmp(gezegen->isim, isim) == 0) {
            return gezegen;
        }
    }   
    return NULL;
}

// "Araclar.txt" dosyasını okur, Arac Listesini doldurur
void araclariOku(const DosyaOkuma this) {
    FILE* dosyaOku = fopen("Araclar.txt", "r");
    if (dosyaOku == NULL) {
        printf("Dosya acilamadi: %s\n", "Araclar.txt");
    }

    char satir[128];

    while (fgets(satir, sizeof(satir), dosyaOku)) {
        char isim[32], CGIsim[32], VGIsim [32];
        int mesafe, gun, ay, yil;

        if (sscanf(satir, "%31[^#]#%31[^#]#%31[^#]#%d.%d.%d#%d",isim, CGIsim, VGIsim, &gun, &ay, &yil, &mesafe) == 7) {
            Zaman cikisTarihi = zamanOlustur(gun, ay, yil);
            Gezegen cikisGezegeni = gezegeniBul(this->gezegenListesi, CGIsim);
            Gezegen varisGezegeni = gezegeniBul(this->gezegenListesi, VGIsim);

            Arac arac = aracOlustur(isim, cikisGezegeni, varisGezegeni, cikisTarihi, mesafe);
            this->aracListesi->ekle(this->aracListesi, arac, (void (*)(void*))arac->yoket);
        } else {
            printf("Arac formati algilanamadi: %s\n", satir);
        }
    }

    fclose(dosyaOku);
}

// İsmi verilen aracı bulur ve döndürür.
Arac araciBul(Liste aracListesi, const char* isim) {
    int uzunluk = aracListesi->uzunluk;
    
    for (int i = 0; i < uzunluk; i++) {
        Arac arac = (Arac)aracListesi->getir(aracListesi, i);
        if (strcmp(arac->isim, isim) == 0) {
            return arac;
        }
    }
    return NULL;
}

// "Kisiler.txt" dosyasını okur, Kisi Listesini doldurur
void kisileriOku(const DosyaOkuma this) {
    FILE* dosyaOku = fopen("Kisiler.txt", "r");
    if (dosyaOku == NULL) {
        printf("Dosya acilamadi: %s\n", "Kisiler.txt");
    }
    char satir[128];

    while (fgets(satir, sizeof(satir), dosyaOku)) {
        char isim[32], aracIsmi[32];
        int yas;
        float kalanOmur;
        if (sscanf(satir, "%31[^#]#%d#%f#%31s", isim, &yas, &kalanOmur, aracIsmi) == 4) {
            Arac bulunduguArac = araciBul(this->aracListesi, aracIsmi);
            Kisi kisi = kisiOlustur(isim, yas, kalanOmur, bulunduguArac);
            this->kisiListesi->ekle(this->kisiListesi, kisi, (void (*)(void*))kisi->yoket);
        } else {
            printf("Kisi formati algilanamadi: %s\n", satir);
        }
    }

    fclose(dosyaOku);
}

// Yıkıcı fonksiyon
void dosyaOkumaYoket(const DosyaOkuma this) {
    if (this == NULL) return;

    this->gezegenListesi = NULL; // * bunlar artık Simulasyon elemanları o yüzden burada silinmemeli
    this->aracListesi = NULL;    // *
    this->kisiListesi = NULL;    // *

    free(this);
}