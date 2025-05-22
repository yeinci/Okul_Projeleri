#include <Menu.hpp>

void Menu::yazdir() { // Menüyü ekrana yazar
    cout << "\nSecmek istediginiz secenegin rakamini girin" << endl;
    cout << "1. Caprazlama" << endl;
    cout << "2. Mutasyon" << endl;
    cout << "3. Otomatik Islemler" << endl;
    cout << "4. Ekrana yaz" << endl;
    cout << "5. Programi kapat" << endl << endl;
    cout << "=> ";
}

void Menu::baslat() { // Menü başlatılır
    int secim;
    while (secim != 5) {
        yazdir();
        cin >> secim; // Kullanıcıdan seçim alınır

        switch (secim) // Seçilen seçime göre ilgili fonksiyon çalıştırılır
        {
        case 1:
            caprazlamaSecilirse();
            break;
        case 2:
            mutasyonSecilirse();
            break;
        case 3:
            hucre.otomatikIslemler();
            break;
        case 4:
            hucre.ekranaYaz();
            break;
        case 5: // Döngüden çıkar, program kapanır
            break;
        default:
        cout << "Gecersiz Secenek!\n";
            break;
        }
    }
}

void Menu::caprazlamaSecilirse() { // Çaprazlama parametrelerini kullanıcıdan alır
    int ilk, ikinci;
    cout << "\nSirasiyla caprazlama yapilacak kromozomlarin satir numaralarini girin\n\n";
    cout << "ilk kromozom: ";
    cin >> ilk;
    cout << "ikinci kromozom: ";
    cin >> ikinci;

    hucre.caprazlama(ilk, ikinci); 
}

void Menu::mutasyonSecilirse() { // Mutasyon parametrelerini kullanıcıdan alır
    int satir, sutun;
    cout << "\nSirasiyla mutasyon yapilacak kromozomun sira numarasini ve genin sira numarasini girin\n\n";
    cout << "Kromozom numarasi: ";
    cin >> satir;
    cout << "Gen numarasi: ";
    cin >> sutun;

    hucre.mutasyon(satir, sutun);
}