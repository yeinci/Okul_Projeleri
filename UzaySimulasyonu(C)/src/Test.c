/**
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* Main fonksiyonu
* </p>
*/
#include "stdio.h"
#include "stdlib.h"

#include "Simulasyon.h"

int main() {
    Simulasyon simulasyon = simulasyonOlustur();
    simulasyon->baslat(simulasyon);
    simulasyon->yoket(simulasyon);

    printf("Program Sonlandi.\n");
    return 0;
}