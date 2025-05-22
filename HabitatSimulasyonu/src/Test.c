#include "stdio.h"
#include "Habitat.h"

int main() {

	Habitat habitat = HabitatOlustur(); // Habitat oluştur

	habitat->Baslat(habitat); //Başlat
	habitat->yoket(habitat);


	return 0;
}