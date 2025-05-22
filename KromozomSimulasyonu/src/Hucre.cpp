#include <Hucre.hpp>
#include <fstream>

Hucre::Hucre() { // Kurucu
    dnaTxtOku();
}

void Hucre::dnaTxtOku() { // Dna.txt'yi okuyan ve Bağlı Listeleri dolduran fonksiyon
    ifstream dosyaOku;
    dosyaOku.open("Dna.txt"); // Dna.txt açılır
    if (!dosyaOku) {
        cout << "Dna.txt Dosyasi Acilamadi!";
    }

    GenListe* genListe = new GenListe(); // Boş Gen Listesi oluşturur
    char ch;
    while (dosyaOku.get(ch)) {
        if (ch == ' ') {} 
        else if (ch == '\n') { // Satır atladığında
            kromozomListe.ekle(genListe); // Gen Listesini Kromozom Listesine ekle
            genListe = new GenListe(); // Yeni boş Gen Listesi oluşturur
        }
        else { // Char karakterleri Gen Listesine ekler
            genListe->ekle(ch);
        }
    }
    kromozomListe.ekle(genListe); // Son Gen Listesini de Kromozom Listesine ekler

    dosyaOku.close(); // Dna.txt kapatılır
}

void Hucre::caprazlama(int indeks1, int indeks2) { // Çaprazlama
    Kromozom* kaynakKromozom1 = kromozomListe.getir(indeks1); // Kaynak Düğümler getirilir
    Kromozom* kaynakKromozom2 = kromozomListe.getir(indeks2);
    int uzunluk1 = kaynakKromozom1->genListe->uzunluk;
    int uzunluk2 = kaynakKromozom2->genListe->uzunluk;

    GenListe* olusacakKromozom1 = new GenListe(); // Oluşacak Düğümler
    GenListe* olusacakKromozom2 = new GenListe();

     // İşaretçi 1. Kaynak Kromozomum ilk Düğümünden başlar
    Gen* suanki = kaynakKromozom1->genListe->ilk;
    for (int i = 0; i < uzunluk1; i++) {
        if (i < uzunluk1 / 2) { // Kaynak Kromozomun ilk yarısı
            olusacakKromozom1->ekle(suanki->harf);
        } else { // Kaynak Kromozomun ikinci yarısı
            if (uzunluk1 % 2 == 0) { // Çiftse
                olusacakKromozom2->ekle(suanki->harf);
            } else if (i > uzunluk1 / 2) { // Tekse orta değer atlanır
                olusacakKromozom2->ekle(suanki->harf);
            }
        }
        suanki = suanki->sonraki;
    }
     // İşaretçi 2. Kaynak Kromozomum ilk Düğümünden başlar
    suanki = kaynakKromozom2->genListe->ilk;
    for (int i = 0; i < uzunluk2; i++) {
        if (i < uzunluk2 / 2) { // Kaynak Kromozomun ilk yarısı
            olusacakKromozom2->ekle(suanki->harf);
        } else { // Kaynak Kromozomun ikinci yarısı
            if (uzunluk2 % 2 == 0) { // Çiftse
                olusacakKromozom1->ekle(suanki->harf);
            } else if (i > uzunluk2 / 2) { // Tekse orta değer atlanır
                olusacakKromozom1->ekle(suanki->harf);
            }
        }
        suanki = suanki->sonraki;
    }

    kromozomListe.ekle(olusacakKromozom1); // Oluşan Kromozomları listeye ekler
    kromozomListe.ekle(olusacakKromozom2);
}

void Hucre::mutasyon(int satir, int sutun) { // Mutasyon
    Kromozom* kromozom = kromozomListe.getir(satir);
    Gen* gen = kromozom->genListe->getir(sutun); // İstenilen Gen Düğümü getirilir

    gen->harf = 'X'; // Değeri değiştirir
}

void Hucre::otomatikIslemler() { // Otomatik İşlemler
    ifstream dosyaOku;
    dosyaOku.open("Islemler.txt"); // Islemler.txt açılır
    if (!dosyaOku) {
        cout << "Islemler.txt Dosyasi Acilamadi!";
    }

    char islem;
    int parametre1, parametre2;
    while (dosyaOku.get(islem)) {
        if (islem == 'C') { // C karakteri okunursa caprazlama() çağrılır
            dosyaOku >> parametre1 >> parametre2;
            caprazlama(parametre1, parametre2);
        } else if (islem == 'M') { // M karakteri okunursa mutasyon() çağrılır
            dosyaOku >> parametre1 >> parametre2;
            mutasyon(parametre1, parametre2);
        }
    }

    dosyaOku.close(); // Islemler.txt kapatılır
}

void Hucre::ekranaYaz() { // Ekrana Yaz
    Kromozom* kromozom = kromozomListe.ilk; // İşaretçi ilk kromozomdan başlar

    while (kromozom != nullptr) {
        if (kromozom->genListe->ilk == nullptr) { // Kromozom boşsa
            std::cout << "bos ";
            kromozom = kromozom->sonraki;
            continue; // sonraki kromozoma geç
        }

        Gen* ilkGen = kromozom->genListe->ilk;
        Gen* gen = kromozom->genListe->son; // İşaretçi son genden başlar
        bool genYazildi = false;

        while (gen != nullptr) {
            if (gen->harf < ilkGen->harf) { // İşaretçinin geni ilk genden küçükse
                std::cout << gen->harf << " ";
                genYazildi = true;
                break;
            }
            gen = gen->onceki;
        }
        if (!genYazildi) { // Gen yazamadıysa ilk geni yazar
            std::cout << ilkGen->harf << " ";
        }
        kromozom = kromozom->sonraki;
    }
    cout << "\n";
}