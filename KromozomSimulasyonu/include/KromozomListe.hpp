/**
* @file         KromozomListe.hpp / KromozomListe.cpp
* @description  Tek Yönlü Kromozom Bağlı Listesi Sınıfı
* @course       1. Öğretim A Grubu
* @assignment   1. Ödev
* @date         17.11.2024
* @author       Yunus Emre İNCİ yunus.inci1@ogr.sakarya.edu.tr
*/
#include <Kromozom.hpp>

class KromozomListe { // Tek Yönlü Kromozom Bağlı Listesi
    private:
    Kromozom* ilk;

    friend class Hucre;
    
    public:
    KromozomListe(); // Kurucu
    ~KromozomListe(); // Yıkıcı

    Kromozom* getir(int); // İstenilen indeksteki düğümü döndürür
    void ekle(GenListe*); // Yeni düğüm oluşturup listenin sonuna ekleyen fonksiyon
};