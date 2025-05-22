#include <GenListe.hpp>

GenListe::GenListe() { // Kurucu
    ilk = nullptr;
    son = nullptr;
    uzunluk = 0;
}
GenListe::~GenListe() { // Yıkıcı
    Gen* silinecek = ilk;
    while (silinecek != nullptr) {
        Gen* sonraki = silinecek->sonraki;
        delete silinecek;
        silinecek = sonraki;
    }
}

Gen* GenListe::getir(int indeks) { // İstenilen indeksteki düğümü döndürür
    if (indeks < 0 || indeks >= uzunluk) {
        cout << "Hatali Indeks!";
    }

    Gen* getirilecek;
    if (indeks < uzunluk / 2) { // İndeks ilk yarıdaysa arama baştan başlar
        getirilecek = ilk;
        for (int i = 0; i < indeks; i++) { // for döngüsüyle istenilen düğüme gider
            getirilecek = getirilecek->sonraki;
        }
    } else { // İndeks ikinci yarıdaysa arama sondan başlar
        getirilecek = son;
        for (int i = uzunluk-1; i > indeks; i--) { // for döngüsüyle istenilen düğüme gider
            getirilecek = getirilecek->onceki;
        }
    }
    return getirilecek;
}

void GenListe::ekle(char harf) { // Yeni düğüm oluşturup listenin sonuna ekleyen fonksiyon
    if (ilk == nullptr) { // Liste boşsa ilk ve son düğüm olur
        ilk = new Gen(harf);
        son = ilk;
    }
    else { // Değilse yeni son düğüm olur
        son->sonraki = new Gen(harf);
        son->sonraki->onceki = son;
        son = son->sonraki;
    }
    uzunluk++; // Uzunluk bir artar
}