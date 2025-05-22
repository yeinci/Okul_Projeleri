/**
* @file         Main.cpp
* @description  Main fonksiyonu
* @course       1. Öğretim A Grubu
* @assignment   1. Ödev
* @date         26.11.2024
* @author       Yunus Emre İNCİ yunus.inci1@ogr.sakarya.edu.tr
*/
#include <Menu.hpp>

int main() { // Main Fonksiyonu
    Menu menu;
    menu.baslat(); // Menu başlatılır

    cout << "\nProgram Kapandi"; // menu.baslat()'tan çıkıldığında program kapanır
    return 0;
}
