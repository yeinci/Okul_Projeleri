/**
*
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 25.04.2025
* <p>
* Simulasyon Sınıfı;
* Simülasyonu başlatan temel sınıftır, main fonksiyonu bu sınıf içerisindedir.
* Nesneleri dosyalardan okuyarak dizilerde saklar.
* Kullanıcıdan alınan girdilerle simülasyonu saat saat ilerletir ve konsola yazdırır.
* </p>
*/

package Sınıflar;

import java.util.Scanner;

public class Simulasyon {
	
	static Gezegen[] gezegenler; // Bütün nesnelerin tutulduğı diziler
	static Arac[] araclar;
	static Kisi[] kisiler;
	static int programMaxSaat; // Programın tamamlanması için gerekli saat miktarı
	
	public static void main(String[] args) { // Main fonksiyonu
		dosyalariOku();
		programMaxSaat = programMaxSaatHesapla();
		
		yazdir();
		programDongusu();
		
		System.out.println("\nProgram Sonlandı");
	}
	
	 // Program Döngüsü için fonksiyon
	private static void programDongusu() {
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		while (true) {
			System.out.printf("\n=> ");
		    String input = scanner.nextLine(); // Girdi Al
		    
		    if (input.equalsIgnoreCase("x")) { // X ise programı kapat
		        break;
		    }
		    
		    if (input.equalsIgnoreCase("z")) { // Z ise Programı direk tamamla
		        xSaatIlerle(programMaxSaat);
		        programMaxSaat = 0;
 		    } else if (input.isEmpty()) {      // Boş ise 1 saat ileri
		        xSaatIlerle(1);
		        programMaxSaat--;
		    } else {                           // Tam sayı ise tam sayı kadar saat ileri
		        try {
		            int saat = Integer.parseInt(input);
		            if (saat > programMaxSaat) {
		            	saat = programMaxSaat;
		            }
		            xSaatIlerle(saat);
		            programMaxSaat -= saat;
		        } catch (NumberFormatException e) {
		            System.out.println("Geçersiz girdi!");
		        }
		    }
		    if (programMaxSaat == 0) {          // Program tamamlandıysa programı kapat
		    	break;
		    }
		}
	}
	
	 // Her nesne için xSaatİlerle fonksiyonunu çağırır
	private static void xSaatIlerle(int x) {
		for (Kisi kisi : kisiler) {
			kisi.xSaatIlerle(x);
		}
		for (Arac arac : araclar) {
			arac.xSaatIlerle(x);
		}
		for (Gezegen gezegen : gezegenler) {
			gezegen.xSaatIlerle(x);
		}
		yazdir();
	}
	
	 // Programın tamamlanması için gerekli saat miktarını bulur
	private static int programMaxSaatHesapla() {
		int enBuyuk = 0;
		for (Arac arac : araclar) {
			int hedefeKalanSaat = Integer.parseInt(arac.hedefeKalanSaatGetir());
			if (hedefeKalanSaat > enBuyuk) {
				enBuyuk = hedefeKalanSaat;
			}
		}
		return enBuyuk;
	}
	
	 // Konsolu temizler
	private static void konsoluTemizle() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
	
	 // Dosyaları okur ve nesne dizilerini doldurur
	private static void dosyalariOku() {
		DosyaOkuma okuyucu = new DosyaOkuma();
		
		gezegenler = okuyucu.gezegenleriOku();
		araclar = okuyucu.araclariOku();
		kisiler = okuyucu.kisileriOku();
	}
	
	 // Konsola yazdırma fonksiyonu
	private static void yazdir() {
		konsoluTemizle();
		
		System.out.println("Gezegenler:");
		System.out.printf("%-20s","");
		for (Gezegen gezegen : gezegenler) {
			System.out.printf("%-20s","--- " + gezegen.isimGetir() + " ---");
		}
		System.out.println();
		System.out.printf("%-20s","Tarih");
		for (Gezegen gezegen : gezegenler) {
			System.out.printf("%-20s", gezegen.tarihGetir());
		}
		System.out.println();
		System.out.printf("%-20s","Nüfus");
		for (Gezegen gezegen : gezegenler) {
			System.out.printf("%-20s", "    " + gezegen.nufusGetir());
		}
		System.out.println("\n\n");
		System.out.println("Uzay Araçları:");
		System.out.printf("%-20s%-10s%-10s%-10s%-20s%-20s", "Araç adı", "Durum", "Çıkış",
				"Varış", "Hedefe Kalan Saat", "Hedefe Varacağı Tarih\n");
		for (Arac arac : araclar) {
			System.out.printf("%-20s%-10s%-10s%-10s%-20s%-20s", arac.isimGetir(), arac.durumGetir(),
					arac.cikisGezegeniIsimGetir(), arac.varisGezegeniIsimGetir(),
					arac.hedefeKalanSaatGetir(), arac.hedefeVaracagiTarihGetir());
			System.out.println();
		}
	}
}
