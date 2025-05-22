#include "Habitat.h"
#include "Canli.h"

Habitat HabitatOlustur() {
	Habitat this;
    this = (Habitat)malloc(sizeof(struct HABITAT));

    // Canl�lar dizisi i�in bellekte yer a�ar
    



    this->satir_sayisi = 1; // Sat�r say�s� 1 ba�lar
    this->sutun_sayisi = 1; // S�tun say�s� 1 ba�lar

    SatirSutunSayisiBul(this);

    // Canl�lar dizisi i�in bellekte yer a�ar
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
    FILE* dosya = fopen("Veri.txt", "r");//Dosya a�

    if (dosya == NULL) { //Dosya a��lmad� uyar� mesaj�
        printf("Dosya acma hatasi");
    }

    char karakter;

    // " " ve \n karakterlerine g�re sat�r s�tun say�s� bulur ve habitattaki de�i�kenlere atar
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
    FILE* dosya = fopen("Veri.txt", "r"); //Dosya a�
    int sayi;

    for (int i = 0; i < this->satir_sayisi; i++) { // Canl�lar dizisinin her eleman�na u�rar
        for (int j = 0; j < this->sutun_sayisi; j++) {
            fscanf(dosya, "%d", &sayi); //Veri.txt den say�y� okur
            Canli canli = CanliOlustur();
            canli->sayi = sayi; // Canl� olu�turur
            (this->canlilar)[i][j] = canli; // Canl�ya okudu�u say�y� verir
        }
    }
    fclose(dosya);//Dosya kapat
}

void CanliTurleriniBul(const Habitat this) { // Canl�lar dizisindeki Canl�lar�n say�lar�na g�re t�rlerini belirler
    for (int i = 0; i < this->satir_sayisi; i++) {
        for (int j = 0; j < this->sutun_sayisi; j++) {
            
            if ((this->canlilar)[i][j]->sayi < 1 || (this->canlilar)[i][j]->sayi > 99) {
                printf("Okunan deger [1 99] aras�nda degil"); // Say� 1-99 aras�nda de�ilse uyar� mesaj�
            }
            else if ((this->canlilar)[i][j]->sayi < 10) { // Say� 1-9 ise Bitki olu�turur(Parametre olarak Canl�y� verir)
                 Bitki bitki = BitkiOlustur((this->canlilar)[i][j]->sayi, (this->canlilar)[i][j]); 
            }
            else if ((this->canlilar)[i][j]->sayi < 21) { // Say� 10-20 ise B�cek olu�turur(Parametre olarak Canl�y� verir)
                Bocek bocek = BocekOlustur((this->canlilar)[i][j]->sayi, (this->canlilar)[i][j]);
            }
            else if ((this->canlilar)[i][j]->sayi < 51) { // Say� 21-50 ise B�cek olu�turur(Parametre olarak Canl�y� verir)
                                                          //                Sinek olu�turur(Parametre olarak B�ce�i verir)
                Bocek bocek = BocekOlustur((this->canlilar)[i][j]->sayi, (this->canlilar)[i][j]);
                Sinek sinek = SinekOlustur((this->canlilar)[i][j]->sayi, bocek);
            }
            else { // Say� 51-99 ise B�cek olu�turur(Parametre olarak Canl�y� verir)
                   //                Pire olu�turur(Parametre olarak B�ce�i verir)
                Bocek bocek = BocekOlustur((this->canlilar)[i][j]->sayi, (this->canlilar)[i][j]);
                Pire pire = PireOlustur((this->canlilar)[i][j]->sayi, bocek);
            }
        }
    }
}

void HabitatiGoster(const Habitat this) {
    
    for (int i = 0; i < this->satir_sayisi; i++) { //Canl�lar� Tablo olarak ekrana yazar
        for (int j = 0; j < this->sutun_sayisi; j++) {
            printf("%s ", (this->canlilar)[i][j]->gorunum((this->canlilar)[i][j]->yasiyorMu));
        }
        printf("\n");
    }

}

void Baslat(const Habitat this) {
    
    HabitatiGoster(this);//Tabloyu g�sterir
    
    getchar();
    system("cls");

    Canli Aktif = (this->canlilar)[0][0]; // Canl�lar dizisi 0,0 Canl�s� Aktif Canl� se�ilir
    int aktifSatir = 0, aktifSutun = 0;

    for (int i = 0; i < this->satir_sayisi; i++) { //Canl�lar dizisi elemanlar�n� dola��r
        for (int j = 0; j < this->sutun_sayisi; j++) {

            if (i == 0 && j == 0) // 0,0 Canl�s�n� atla
                continue;

            //Aktif canl�yla d�ng�deki s�radaki canl�y� kar��la�t�r�r
            //Aktif canl� kazan�rsa d�ng�deki canl� �l�r
            //Aktif canl� kaybederse �l�r, d�ng�deki canl� yeni aktif canl� olur

            if (Aktif->sayi < 10) { // Aktif Canl� Bitki ise
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
            else if (Aktif->sayi < 21) { // Aktif Canl� B�cek ise
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
            else if (Aktif->sayi < 51) { // Aktif Canl� Sinek ise
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
            else { // Aktif Canl� Pire ise
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
            HabitatiGoster(this); //Tablonun yeni halini g�ster
            getchar();
            system("cls");
        }
    }
    HabitatiGoster(this); // Kazanan� g�ster
    printf("Kazanan: %s : (%d,%d)", Aktif->gorunum(1), aktifSatir,aktifSutun);

}

void HabitatYoket(const Habitat this) {
    if (this == NULL) return;
    for (int i = this->satir_sayisi -1; i >= 0; i--) { // Dizi i�indeki b�t�n canlilari sat�r s�tun say�s�yla �a��r�r
        for (int j = this->sutun_sayisi - 1; j >= 0 ; j--) {

            if (this->canlilar[i][j]->sayi < 10) { // Bitki ise BitkiYoket
                BitkiYoket(this->canlilar[i][j]->tur);
            }
            else if (this->canlilar[i][j]->sayi < 21) { // B�cek ise BocekYoket
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