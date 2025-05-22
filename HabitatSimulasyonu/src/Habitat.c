#include "Habitat.h"
#include "Canli.h"

Habitat HabitatOlustur() {
	Habitat this;
    this = (Habitat)malloc(sizeof(struct HABITAT));

    // Canlýlar dizisi için bellekte yer açar
    



    this->satir_sayisi = 1; // Satýr sayýsý 1 baþlar
    this->sutun_sayisi = 1; // Sütun sayýsý 1 baþlar

    SatirSutunSayisiBul(this);

    // Canlýlar dizisi için bellekte yer açar
    this->canlilar = (Canli**)malloc(this->satir_sayisi * sizeof(Canli*));
    for (int i = 0; i < this->satir_sayisi; i++) {
        (this->canlilar)[i] = (Canli*)malloc(this->sutun_sayisi * sizeof(Canli));
    }

    VeritxtOku(this);
    CanliTurleriniBul(this);
    
        this->Baslat = &Baslat;
	this->yoket = &HabitatYoket;

    return this;
}

void SatirSutunSayisiBul(const Habitat this) {
    FILE* dosya = fopen("Veri.txt", "r");//Dosya aç

    if (dosya == NULL) { //Dosya açýlmadý uyarý mesajý
        printf("Dosya acma hatasi");
    }

    char karakter;

    // " " ve \n karakterlerine göre satýr sütun sayýsý bulur ve habitattaki deðiþkenlere atar
    while ((karakter = fgetc(dosya)) != EOF) { 
        if (karakter == '\n') {
            (this->satir_sayisi)++;
            this->sutun_sayisi = 1;
        }
        else if (karakter == ' ') {
            (this->sutun_sayisi)++;
        }
    }
    fclose(dosya); //Dosya kapa
}

void VeritxtOku(const Habitat this) {
    FILE* dosya = fopen("Veri.txt", "r"); //Dosya aç
    int sayi;

    for (int i = 0; i < this->satir_sayisi; i++) { // Canlýlar dizisinin her elemanýna uðrar
        for (int j = 0; j < this->sutun_sayisi; j++) {
            fscanf(dosya, "%d", &sayi); //Veri.txt den sayýyý okur
            Canli canli = CanliOlustur();
            canli->sayi = sayi; // Canlý oluþturur
            (this->canlilar)[i][j] = canli; // Canlýya okuduðu sayýyý verir
        }
    }
    fclose(dosya);//Dosya kapat
}

void CanliTurleriniBul(const Habitat this) { // Canlýlar dizisindeki Canlýlarýn sayýlarýna göre türlerini belirler
    for (int i = 0; i < this->satir_sayisi; i++) {
        for (int j = 0; j < this->sutun_sayisi; j++) {
            
            if ((this->canlilar)[i][j]->sayi < 1 || (this->canlilar)[i][j]->sayi > 99) {
                printf("Okunan deger [1 99] arasýnda degil"); // Sayý 1-99 arasýnda deðilse uyarý mesajý
            }
            else if ((this->canlilar)[i][j]->sayi < 10) { // Sayý 1-9 ise Bitki oluþturur(Parametre olarak Canlýyý verir)
                 Bitki bitki = BitkiOlustur((this->canlilar)[i][j]->sayi, (this->canlilar)[i][j]); 
            }
            else if ((this->canlilar)[i][j]->sayi < 21) { // Sayý 10-20 ise Böcek oluþturur(Parametre olarak Canlýyý verir)
                Bocek bocek = BocekOlustur((this->canlilar)[i][j]->sayi, (this->canlilar)[i][j]);
            }
            else if ((this->canlilar)[i][j]->sayi < 51) { // Sayý 21-50 ise Böcek oluþturur(Parametre olarak Canlýyý verir)
                                                          //                Sinek oluþturur(Parametre olarak Böceði verir)
                Bocek bocek = BocekOlustur((this->canlilar)[i][j]->sayi, (this->canlilar)[i][j]);
                Sinek sinek = SinekOlustur((this->canlilar)[i][j]->sayi, bocek);
            }
            else { // Sayý 51-99 ise Böcek oluþturur(Parametre olarak Canlýyý verir)
                   //                Pire oluþturur(Parametre olarak Böceði verir)
                Bocek bocek = BocekOlustur((this->canlilar)[i][j]->sayi, (this->canlilar)[i][j]);
                Pire pire = PireOlustur((this->canlilar)[i][j]->sayi, bocek);
            }
        }
    }
}

void HabitatiGoster(const Habitat this) {
    
    for (int i = 0; i < this->satir_sayisi; i++) { //Canlýlarý Tablo olarak ekrana yazar
        for (int j = 0; j < this->sutun_sayisi; j++) {
            printf("%s ", (this->canlilar)[i][j]->gorunum((this->canlilar)[i][j]->yasiyorMu));
        }
        printf("\n");
    }

}

void Baslat(const Habitat this) {
    
    HabitatiGoster(this);//Tabloyu gösterir
    
    getchar();
    system("cls");

    Canli Aktif = (this->canlilar)[0][0]; // Canlýlar dizisi 0,0 Canlýsý Aktif Canlý seçilir
    int aktifSatir = 0, aktifSutun = 0;

    for (int i = 0; i < this->satir_sayisi; i++) { //Canlýlar dizisi elemanlarýný dolaþýr
        for (int j = 0; j < this->sutun_sayisi; j++) {

            if (i == 0 && j == 0) // 0,0 Canlýsýný atla
                continue;

            //Aktif canlýyla döngüdeki sýradaki canlýyý karþýlaþtýrýr
            //Aktif canlý kazanýrsa döngüdeki canlý ölür
            //Aktif canlý kaybederse ölür, döngüdeki canlý yeni aktif canlý olur

            if (Aktif->sayi < 10) { // Aktif Canlý Bitki ise
                if ((this->canlilar)[i][j]->sayi < 10) {
                    if (Aktif->sayi > (this->canlilar)[i][j]->sayi) {
                        (this->canlilar)[i][j]->yasiyorMu = OLU;
                    }
                    else if (Aktif->sayi == (this->canlilar)[i][j]->sayi) {
                        (this->canlilar)[i][j]->yasiyorMu = OLU;
                    }
                    else {
                        Aktif->yasiyorMu = OLU;
                        Aktif = (this->canlilar)[i][j];
                        aktifSatir = i;
                        aktifSutun = j;
                    }
                }
                else if ((this->canlilar)[i][j]->sayi < 21) {
                    Aktif->yasiyorMu = OLU;
                    Aktif = (this->canlilar)[i][j];
                    aktifSatir = i;
                    aktifSutun = j;
                }
                else if ((this->canlilar)[i][j]->sayi < 51) {
                    (this->canlilar)[i][j]->yasiyorMu = OLU;
                }
                else {
                    (this->canlilar)[i][j]->yasiyorMu = OLU;
                }
            }
            else if (Aktif->sayi < 21) { // Aktif Canlý Böcek ise
                if ((this->canlilar)[i][j]->sayi < 10) {
                    (this->canlilar)[i][j]->yasiyorMu = OLU;
                }
                else if ((this->canlilar)[i][j]->sayi < 21) {
                    if (Aktif->sayi > (this->canlilar)[i][j]->sayi) {
                        (this->canlilar)[i][j]->yasiyorMu = OLU;
                    }
                    else if (Aktif->sayi == (this->canlilar)[i][j]->sayi) {
                        (this->canlilar)[i][j]->yasiyorMu = OLU;
                    }
                    else {
                        Aktif->yasiyorMu = OLU;
                        Aktif = (this->canlilar)[i][j];
                        aktifSatir = i;
                        aktifSutun = j;
                    }
                }
                else if ((this->canlilar)[i][j]->sayi < 51) {
                    Aktif->yasiyorMu = OLU;
                    Aktif = (this->canlilar)[i][j];
                    aktifSatir = i;
                    aktifSutun = j;
                }
                else {
                    (this->canlilar)[i][j]->yasiyorMu = OLU;
                }
            }
            else if (Aktif->sayi < 51) { // Aktif Canlý Sinek ise
                if ((this->canlilar)[i][j]->sayi < 10) {
                    Aktif->yasiyorMu = OLU;
                    Aktif = (this->canlilar)[i][j];
                    aktifSatir = i;
                    aktifSutun = j;
                }
                else if ((this->canlilar)[i][j]->sayi < 21) {
                    (this->canlilar)[i][j]->yasiyorMu = OLU;
                }
                else if ((this->canlilar)[i][j]->sayi < 51) {
                    if (Aktif->sayi > (this->canlilar)[i][j]->sayi) {
                        (this->canlilar)[i][j]->yasiyorMu = OLU;
                    }
                    else if (Aktif->sayi == (this->canlilar)[i][j]->sayi) {
                        (this->canlilar)[i][j]->yasiyorMu = OLU;
                    }
                    else {
                        Aktif->yasiyorMu = OLU;
                        Aktif = (this->canlilar)[i][j];
                        aktifSatir = i;
                        aktifSutun = j;
                    }
                }
                else {
                    (this->canlilar)[i][j]->yasiyorMu = OLU;
                }
            }
            else { // Aktif Canlý Pire ise
                if ((this->canlilar)[i][j]->sayi < 10) {
                    Aktif->yasiyorMu = OLU;
                    Aktif = (this->canlilar)[i][j];
                    aktifSatir = i;
                    aktifSutun = j;
                }
                else if ((this->canlilar)[i][j]->sayi < 21) {
                    Aktif->yasiyorMu = OLU;
                    Aktif = (this->canlilar)[i][j];
                    aktifSatir = i;
                    aktifSutun = j;
                }
                else if ((this->canlilar)[i][j]->sayi < 51) {
                    Aktif->yasiyorMu = OLU;
                    Aktif = (this->canlilar)[i][j];
                    aktifSatir = i;
                    aktifSutun = j;
                }
                else {
                    if (Aktif->sayi > (this->canlilar)[i][j]->sayi) {
                        (this->canlilar)[i][j]->yasiyorMu = OLU;
                    }
                    else if (Aktif->sayi == (this->canlilar)[i][j]->sayi) {
                        (this->canlilar)[i][j]->yasiyorMu = OLU;
                    }
                    else {
                        Aktif->yasiyorMu = OLU;
                        Aktif = (this->canlilar)[i][j];
                        aktifSatir = i;
                        aktifSutun = j;
                    }
                }
            }
            HabitatiGoster(this); //Tablonun yeni halini göster
            getchar();
            system("cls");
        }
    }
    HabitatiGoster(this); // Kazananý göster
    printf("Kazanan: %s : (%d,%d)", Aktif->gorunum(1), aktifSatir,aktifSutun);

}

void HabitatYoket(const Habitat this) {
    if (this == NULL) return;
    for (int i = this->satir_sayisi -1; i >= 0; i--) { // Dizi içindeki bütün canlilari satýr sütun sayýsýyla çaðýrýr
        for (int j = this->sutun_sayisi - 1; j >= 0 ; j--) {

            if (this->canlilar[i][j]->sayi < 10) { // Bitki ise BitkiYoket
                BitkiYoket(this->canlilar[i][j]->tur);
            }
            else if (this->canlilar[i][j]->sayi < 21) { // Böcek ise BocekYoket
                BocekYoket(this->canlilar[i][j]->tur);
            }
            else if (this->canlilar[i][j]->sayi < 51) { // Sinek ise SinekYoket
                SinekYoket(this->canlilar[i][j]->tur);
            }
            else if (this->canlilar[i][j]->sayi > 50) { // Pire ise PireYoket
                PireYoket(this->canlilar[i][j]->tur);
            }
        }
    }
    free(this); // Kendisini yokeder
}