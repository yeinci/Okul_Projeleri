#include "stdio.h"
#include "Habitat.h"

int main() {

	Habitat habitat = HabitatOlustur(); // Habitat olu�tur

	habitat->Baslat(habitat); //Ba�lat
	habitat->yoket(habitat);


	return 0;
}