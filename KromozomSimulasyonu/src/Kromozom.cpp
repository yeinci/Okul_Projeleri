#include <Kromozom.hpp>

Kromozom::Kromozom(GenListe* genListe) { // Kurucu
    this->genListe = genListe;
    sonraki = nullptr;
}
Kromozom::~Kromozom() { // Yıkıcı
    delete genListe;
}