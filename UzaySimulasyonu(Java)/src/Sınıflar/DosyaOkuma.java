/**
*
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 25.04.2025
* <p>
* DosyaOkuma Sınıfı;
* Kisi, Arac ve Gezegen nesneleri için, önce ilgili dosyaları okuyup satır sayısı bulur,
* satır sayısı elemanlı diziler oluşturur, sonra dosyaları tekrar okuyarak oluşturduğu
* nesneleri dizilerde saklar, dizileri döndürür.
* Bu işlemler için gerekli bir aç fonksiyonu barındırır.
*/

package Sınıflar;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class DosyaOkuma {
//	private String gezegenlerDosyası = "dist/Gezegenler.txt";
//	private String araclarDosyası = "dist/Araclar.txt";
//	private String kisilerDosyası = "dist/Kisiler.txt";
	private String gezegenlerDosyası = "Gezegenler.txt";
	private String araclarDosyası = "Araclar.txt";
	private String kisilerDosyası = "Kisiler.txt";

	Gezegen[] gezegenler;
	Arac[] araclar;
	
	 // Gezegenler.txt okuyup Gezegen nesnelerini olusturur, nesneleri diziye yerleştirip döndürür
	public Gezegen[] gezegenleriOku() {
		gezegenler = new Gezegen[diziElemanSayisiBul(gezegenlerDosyası)];
		
		String satir;
		int index = 0;
		
		try (BufferedReader br = new BufferedReader(new FileReader(gezegenlerDosyası))) {
		    while ((satir = br.readLine()) != null) {
		    	String[] degerler = satir.split("#");
		    	
		    	String isim = degerler[0];
		    	int gunSaatMiktari = Integer.parseInt(degerler[1]);
		    	Zaman tarih = tarihOku(degerler[2]);
		    	
		    	gezegenler[index] = new Gezegen(isim, gunSaatMiktari, tarih);
		    	index++;
		    }
		} catch (IOException hata) {
			System.out.println("Dosya Okuma Hatası!");
		}
		return gezegenler;
	}
	
	 // Araclar.txt okuyup Arac nesnelerini olusturur, nesneleri diziye yerleştirip döndürür
	public Arac[] araclariOku() {
		araclar = new Arac[diziElemanSayisiBul(araclarDosyası)];
		
		String satir;
		int index = 0;
		
		try (BufferedReader br = new BufferedReader(new FileReader(araclarDosyası))) {
		    while ((satir = br.readLine()) != null) {
		    	String[] degerler = satir.split("#");
		    	
		    	String isim = degerler[0];
		    	Gezegen cikisGezegeni = isimliGezegeniBul(degerler[1], gezegenler);
		    	Gezegen varisGezegeni = isimliGezegeniBul(degerler[2], gezegenler);
		    	Zaman cikisTarihi = tarihOku(degerler[3]);
		    	int mesafe = Integer.parseInt(degerler[4]);
		    	
		    	araclar[index] = new Arac(isim, cikisGezegeni, varisGezegeni, cikisTarihi, mesafe);
		    	index++;
		    }
		} catch (IOException hata) {
			System.out.println("Dosya Okuma Hatası!");
		}
		return araclar;
	}
	
	 // Kisiler.txt okuyup Kisi nesnelerini olusturur, nesneleri diziye yerleştirip döndürür
	public Kisi[] kisileriOku() {
		Kisi[] kisiler = new Kisi[diziElemanSayisiBul(kisilerDosyası)];
		
		String satir;
		int index = 0;
		
		try (BufferedReader br = new BufferedReader(new FileReader(kisilerDosyası))) {
		    while ((satir = br.readLine()) != null) {
		    	String[] degerler = satir.split("#");
		    	
		    	String isim = degerler[0];
		    	int yas = Integer.parseInt(degerler[1]);
		    	int kalanOmur = Integer.parseInt(degerler[2]);
		    	Arac bulunduguArac = isimliAraciBul(degerler[3], araclar);
		    	
		    	kisiler[index] = new Kisi(isim, yas, kalanOmur, bulunduguArac);
		    	index++;
		    }
		} catch (IOException hata) {
			System.out.println("Dosya Okuma Hatası!");
		}
		return kisiler;
	}
	
	 // Okunan değerlerde Zaman nesnesi oluşturup döndürür
	private Zaman tarihOku(String tarihString) {
		String[] degerler = tarihString.split("\\.");
    	
    	int gun = Integer.parseInt(degerler[0]) - 1;
    	int ay = Integer.parseInt(degerler[1]) - 1;
    	int yil = Integer.parseInt(degerler[2]);
    	
    	return new Zaman(gun, ay, yil);
	}
	 // İsmi verilen Gezegen nesnesini bulur ve döndürür
	private Gezegen isimliGezegeniBul(String isim, Gezegen[] dizi) {
		for (Gezegen gezegen : dizi) {
			if (gezegen.isimKontrol(isim)) return gezegen;
		}
		System.out.println("İlgili Gezegen Bulunamadı!");
		return null;
	}
	
	 // İsmi verilen Arac nesnesini bulur ve döndürür
	private Arac isimliAraciBul(String isim, Arac[] dizi) {
		for (Arac arac : dizi) {
			if (arac.isimKontrol(isim)) return arac;
		}
		System.out.println("İlgili Araç Bulunamadı!");
		return null;
	}
	
	 // Dosyayı okuyup oluşturulacak dizinin eleman sayısını bulur
	private int diziElemanSayisiBul(String dosyaAdi) {
		int elemanSayisi = 0;
		try (BufferedReader br = new BufferedReader(new FileReader(dosyaAdi))) {
		    while (br.readLine() != null) {
		    	elemanSayisi++;
		    }
		} catch (IOException hata) {
			System.out.println("Dosya Okuma Hatası!");
		}
		return elemanSayisi;
	}
}


