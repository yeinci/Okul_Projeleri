/**
*
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 25.04.2025
* <p>
* Zaman Sınıfı;
* Zaman nesnelerinin değişkenlerini ve zaman ile iilgili tüm fonksiyonları barındırır.
* İşlem kolaylığı açısından zamanı saat cinsine, saati zaman cinsine dçnüştüren 2 static fonksiyona sahiptir
* </p>
*/

package Sınıflar;

public class Zaman {
	private int saat;
	private int gun;
	private int ay;
	private int yil;
	
	// Kurucu fonksiyon
	public Zaman(int gun, int ay, int yil) {
		saat = 0;
		this.gun = gun;
		this.ay = ay;
		this.yil = yil;
	}
	
	// Saatli kurcu fonksiyon
	public Zaman(int saat, int gun, int ay, int yil) {
		this.saat = saat;
		this.gun = gun;
		this.ay = ay;
		this.yil = yil;
	}
	
	// toString fonksiyonu
	public String toString() {
		return (gun + 1) + "." + (ay + 1) + "." + yil;
	}
	
	// x saat ilerle fonksiyonu
	public void xSaatIlerle(int gunSaatMiktari, int x) {
		Zaman yeniTarih = xSaatIlerideTarihKac(gunSaatMiktari, x);
		this.saat = yeniTarih.saat;
		this.gun = yeniTarih.gun;
		this.ay = yeniTarih.ay;
		this.yil = yeniTarih.yil;
	}
	
	// x saat ilerideki tarihi döndürür, hedefeVaracagiTarihHesapla() fonksiyonu için
	public Zaman xSaatIlerideTarihKac(int gunSaatMiktari, int x) {   
		int toplamSaatThis = zamanDonusturSaat(gunSaatMiktari, this);
		return saatDonusturZaman(gunSaatMiktari, toplamSaatThis + x);
	}
	
	// parametre ile this arasındaki saat farkını hesaplar, kalkisaKalanSaatHesapla() fonksiyonu için
	public int saatFarkiHesapla(int gunSaatMiktari, Zaman tarih) {   
		int toplamSaatThis = zamanDonusturSaat(gunSaatMiktari, this);// 
		int toplamSaatTarih = zamanDonusturSaat(gunSaatMiktari, tarih);
		return Math.abs(toplamSaatTarih - toplamSaatThis);
	}
	
	// saati Zaman cinsine dönüştürür, işlem kolaylığı için
	private static Zaman saatDonusturZaman(int gunSaatMiktari, int toplamSaat) {
	    int yil = toplamSaat / (12 * 30 * gunSaatMiktari);
	    toplamSaat = toplamSaat % (12 * 30 * gunSaatMiktari);
	    int ay = toplamSaat / (30 * gunSaatMiktari);
	    toplamSaat = toplamSaat % (30 * gunSaatMiktari);
	    int gun = toplamSaat / gunSaatMiktari;
	    toplamSaat = toplamSaat % gunSaatMiktari;
	    return new Zaman(toplamSaat, gun, ay, yil);
	}
	
	// Zamanı saat cinsine dönüştürür, işlem kolaylığı için
	private static int zamanDonusturSaat(int gunSaatMiktari, Zaman tarih) {
	    return tarih.yil * 12 * 30 * gunSaatMiktari + tarih.ay * 30 * gunSaatMiktari +
	    		tarih.gun * gunSaatMiktari + tarih.saat;
	}
}
