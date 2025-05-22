/**
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* Liste Yapısı;
* Void pointer saklayan bir bağlı liste yapisidir.
* Bütün nesneler pointer olduğu için türünden bağımsız hepsini saklayabilir.
* </p>
*/
#ifndef LISTE_H
#define LISTE_H

#include "stdio.h"
#include "stdlib.h"

#include "Dugum.h"

struct LISTE{
    Dugum ilk;
    int uzunluk;
    
    void (*ekle)(struct LISTE*, void* veri, void (*veriYokEt)(void*));
    void* (*getir)(struct LISTE*, int index);
    void (*yoket)(struct LISTE*);
};
typedef struct LISTE* Liste;

Liste listeOlustur();
void listeEkle(Liste this, void* veri, void (*veriYoket)(void*));
void* listeGetir(Liste this, int index);
void listeYoket(const Liste this);

#endif