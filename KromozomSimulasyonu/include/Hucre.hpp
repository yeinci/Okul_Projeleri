/**
* @file         Hucre.hpp / Hucre.cpp
* @description  Programın ana fonksiyonlarından sorumlu Hücre sınıfı
* @course       1. Öğretim A Grubu
* @assignment   1. Ödev
* @date         26.11.2024
* @author       Yunus Emre İNCİ yunus.inci1@ogr.sakarya.edu.tr
*/
#include <KromozomListe.hpp>

class Hucre { // Programın ana fonksiyonlarından sorumlu sınıf
    private:
    KromozomListe kromozomListe; // Kromozom Bağlı Listesi nesnesi
    void dnaTxtOku(); // Dna.txt'yi okuyan ve Bağlı Listeleri dolduran fonksiyon

    public:
    Hucre(); // Kurucu
    void caprazlama(int, int); // Çaprazlama
    void mutasyon(int, int); // Mutasyon
    void otomatikIslemler(); // Otomatik İşlemler
    void ekranaYaz(); // Ekrana Yaz
};