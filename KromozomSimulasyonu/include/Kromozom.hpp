/**
* @file         Kromozom.hpp / Kromozom.cpp
* @description  Tek Yönlü Kromozom Düğümü Sınıfı
* @course       1. Öğretim A Grubu
* @assignment   1. Ödev
* @date         17.11.2024
* @author       Yunus Emre İNCİ yunus.inci1@ogr.sakarya.edu.tr
*/
#include <GenListe.hpp>

class Kromozom { // Tek Yönlü Kromozom Düğümü
    private:
    GenListe *genListe; // Gen Bağlı Listesi nesnesi
    Kromozom *sonraki;

    friend class KromozomListe;
    friend class Hucre;

    public:
    Kromozom(GenListe*); // Kurucu
    ~Kromozom(); // Yıkıcı
};