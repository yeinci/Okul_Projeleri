/**
*
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 25.04.2025
* <p>
* Arac Sınıfı;
* Arac nesnelerinin değişkenlerini ve araç ile ilgili tüm fonksiyonları barındırır.
* </p>
*/

package Sınıflar;

public class Arac {
	private String isim;
	private Gezegen cikisGezegeni;
	private Gezegen varisGezegeni;
	private Zaman cikisTarihi;
	private int mesafe;
	
	private String durum;            // Gerekli değişkenler
	private int kalkisaKalanSaat;
	private int hedefeKalanSaat;
	private Zaman hedefeVaracagiTarih;
	private int yolcuSayisi;
	private Gezegen bulunduguGezegen;
	
	// Kurucu fonksiyon
	public Arac(String isim, Gezegen cikisGezegeni, Gezegen varisGezegeni, Zaman cikisTarihi, int mesafe) {
		this.isim = isim;
		this.cikisGezegeni = cikisGezegeni;
		this.varisGezegeni = varisGezegeni;
		this.cikisTarihi = cikisTarihi;
		this.mesafe = mesafe;
		
		durum = "Bekliyor";
		kalkisaKalanSaat = kalkisaKalanSaatHesapla();
		hedefeKalanSaat = hedefeKalanSaatHesapla();
		hedefeVaracagiTarih = hedefeVaracagiTarihHesapla();
		yolcuSayisi = 0;
		bulunduguGezegen = cikisGezegeni;
	}
	
	// Getir fonksiyonları
	public String isimGetir() { return isim; }
	public String durumGetir() { return durum; }
	public String cikisGezegeniIsimGetir() { return cikisGezegeni.isimGetir(); }
	public String varisGezegeniIsimGetir() { return varisGezegeni.isimGetir(); }
	public String hedefeKalanSaatGetir() { 
		if (durum.equals("İmha") ) {
			return "--";
		}
		return String.valueOf(hedefeKalanSaat);
	}
	public String hedefeVaracagiTarihGetir() {
		if (durum.equals("İmha") ) {
			return "--";
		}
		return hedefeVaracagiTarih.toString();
	}
	
	// x saat ilerle fonksiyonu
	public void xSaatIlerle(int x) {
		if (durum.equals("Vardı") || durum.equals("İmha")) return;
		
		hedefeKalanSaat -= x;           
		
		if (durum.equals("Bekliyor")) {
			if (x > kalkisaKalanSaat) {
				x -= kalkisaKalanSaat;
				aracKalti();                // kalkisaKalanSaat sıfırlanırsa araç kalkar
			} else {
				kalkisaKalanSaat -= x;     
				if (kalkisaKalanSaat == 0) {
					aracKalti();
				}
				return;
			}
		}
		if (hedefeKalanSaat <= 0) {         // hedefeKalanSaat sıfırlanırsa araç varır
			aracVardi();
			hedefeKalanSaat = 0;
		}
	}
	
	private void aracKalti() { // Araç kalktı
		durum = "Yolda";       // Durum Yolda
		bulunduguGezegen.nufusGuncelle(-yolcuSayisi); // Bulunduğu Gezegenin nüfusunu güncelle
		bulunduguGezegen = null;
	}
	
	private void aracVardi() { // Araç vardı
		durum = "Vardı";       // Durum Vardı
		bulunduguGezegen = varisGezegeni;
		bulunduguGezegen.nufusGuncelle(+yolcuSayisi); // Bulunduğu Gezegenin nüfusunu güncelle
	}
	
	// yolcuSayisi değişkenini parametreye göre günceller
	public void yolcuSayisiGuncelle(int x) {
		yolcuSayisi += x;
		if (bulunduguGezegen != null) {                   // Bulunduğu Gezegenin nüfusunu güncelle
			bulunduguGezegen.nufusGuncelle(x);
		}
		if (!durum.equals("Vardı") && yolcuSayisi == 0) { // Yolcu Sayısı sıfırlandıysa İmha
			durum = "İmha";
		}
	}
	
	private int kalkisaKalanSaatHesapla() { // Kalkışa kalan saati hesaplayan fonksiyon
		Zaman tarih = cikisGezegeni.tarihGetir();
		int gunSaatMiktari = cikisGezegeni.gunSaatMiktariGetir();
		return tarih.saatFarkiHesapla(gunSaatMiktari, cikisTarihi);
	}
	
	private int hedefeKalanSaatHesapla() { // Hedefe kalan saati hesaplayan fonksiyon
		return mesafe + kalkisaKalanSaat;
	}
	
	private Zaman hedefeVaracagiTarihHesapla() { // Hedefe varacağı tarihi hesaplayan fonksiyon
		Zaman tarih = varisGezegeni.tarihGetir();
		int gunSaatMiktari = varisGezegeni.gunSaatMiktariGetir();
		return tarih.xSaatIlerideTarihKac(gunSaatMiktari, hedefeKalanSaat);
	}
	
	public boolean isimKontrol(String isim) { // Parametre ile isim ayn mı diye kontrol eder
		return this.isim.equals(isim);        // DosyaOkuma için gerekli
	}
}
