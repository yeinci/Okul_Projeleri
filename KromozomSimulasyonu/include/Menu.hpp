/**
* @file         Menu.hpp / Menu.cpp
* @description  Menü sınıfı
* @course       1. Öğretim A Grubu
* @assignment   1. Ödev
* @date         26.11.2024
* @author       Yunus Emre İNCİ yunus.inci1@ogr.sakarya.edu.tr
*/
#include <Hucre.hpp>

class Menu {
    private:
    Hucre hucre;
    void yazdir(); // Menüyü ekrana yazar
    void caprazlamaSecilirse(); // Çaprazlama parametrelerini kullanıcıdan alır
    void mutasyonSecilirse(); // Mutasyon parametrelerini kullanıcıdan alır

    public:
    void baslat(); // Menü başlatılır
};