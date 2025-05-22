/**
* @file         GenListe.hpp / GenListe.cpp
* @description  Çift Yönlü Gen Bağlı Listesi Sınıfı
* @course       1. Öğretim A Grubu
* @assignment   1. Ödev
* @date         17.11.2024
* @author       Yunus Emre İNCİ yunus.inci1@ogr.sakarya.edu.tr
*/
#include <Gen.hpp>

class GenListe { // Çift Yönlü Gen Bağlı Listesi
    private:
    Gen* ilk;
    Gen* son;
    int uzunluk; // Listenin uzunluğu

    friend class Kromozom;
    friend class Hucre;

    public:
    GenListe(); // Kurucu
    ~GenListe(); // Yıkıcı
    Gen* getir(int); // İstenilen indeksteki düğümü döndürür
    void ekle(char); // Yeni düğüm oluşturup listenin sonuna ekleyen fonksiyon
};