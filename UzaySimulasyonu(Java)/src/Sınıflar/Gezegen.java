/**
*
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 25.04.2025
* <p>
* Gezegen Sınıfı;
* Gezegen nesnelerinin değişkenlerini ve gezegen ile ilgili tüm fonksiyonları barındırır.
* </p>
*/

package Sınıflar;

public class Gezegen {
	private String isim;
	private int gunSaatMiktari;
	private Zaman tarih;
	
	private int nufus;
	
	// kurucu fonksiyon
	public Gezegen(String isim, int gunSaatMiktari, Zaman tarih) {
		this.isim = isim;
		this.gunSaatMiktari = gunSaatMiktari;
		this.tarih = tarih;
		
		nufus = 0;
	}
	
	public boolean isimKontrol(String isim) { // Parametre ile isim aynı mı diye kontrol eder
		return this.isim.equals(isim);        // DosyaOkuma için gerekli
	}
	
	// Getir fonksiyonları
	public String isimGetir() { return isim; }
	public Zaman tarihGetir() { return tarih; }
	public int nufusGetir() { return nufus; }
	public int gunSaatMiktariGetir() { return gunSaatMiktari; }
	
	public void xSaatIlerle(int x) { // x saat ilerle
		tarih.xSaatIlerle(gunSaatMiktari, x);
	}
	
	public void nufusGuncelle(int x) { // Nüfusu parametreye göre günceller
		nufus += x;
	}
}
