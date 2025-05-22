/**
* @file         Gen.hpp / Gen.cpp
* @description  Çift Yönlü Gen Düğümü Sınıfı
* @course       1. Öğretim A Grubu
* @assignment   1. Ödev
* @date         17.11.2024
* @author       Yunus Emre İNCİ yunus.inci1@ogr.sakarya.edu.tr
*/
#include <iostream>
using namespace std;

class Gen { // Çift yönlü Gen Düğümü
    private:
    char harf;
    Gen *onceki;
    Gen *sonraki;

    friend class GenListe;
    friend class Hucre;

    public:
    Gen(char); // Kurucu
};