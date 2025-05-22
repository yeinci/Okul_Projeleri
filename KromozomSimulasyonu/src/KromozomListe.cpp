#include <KromozomListe.hpp>

KromozomListe::KromozomListe() { // Kurucu
    ilk = nullptr;
}
KromozomListe::~KromozomListe() { // Yıkıcı

    Kromozom* silinecek = ilk;
    while (silinecek != nullptr) {
        Kromozom* sonraki = silinecek->sonraki;
        delete silinecek;
        silinecek = sonraki;
    }
}

Kromozom* KromozomListe::getir(int indeks) { // İstenilen indeksteki düğümü döndürür
    if (indeks < 0) {
        cout << "Hatali Indeks!";
    }
    Kromozom* getirilecek = ilk;
    for (int i = 0; i < indeks; i++) { // for döngüsüyle istenilen düğüme gider
        getirilecek = getirilecek->sonraki;
        if(getirilecek == nullptr) {
            cout << "Hatali Indeks!";
        }
    }
    return getirilecek;
}

void KromozomListe::ekle(GenListe* liste) { // Yeni düğüm oluşturup listenin sonuna ekleyen fonksiyon
    if (ilk == nullptr) { // Liste boşsa ilk düğüm olur
        ilk = new Kromozom(liste);
    }
    else { // Değilse listenin sonuna eklenir
        Kromozom* son = ilk;
        while (son->sonraki != nullptr) {
            son = son->sonraki;
        }
        son->sonraki = new Kromozom(liste);
    }
}