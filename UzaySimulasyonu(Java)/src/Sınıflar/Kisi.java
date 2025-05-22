/**
*
* @author Yunus Emre İnci yunus.inci1@ogr.sakarya.edu.tr
* @since 25.04.2025
* <p>
* Kisi Sınıfı;
* Kisi nesnelerinin değişkenlerini ve saat ilerleme fonksiyonunu barındırır.
* </p>
*/

package Sınıflar;

public class Kisi {
	@SuppressWarnings("unused")
	private String isim;
	@SuppressWarnings("unused")
	private int yas;
	private int kalanOmur;
	private Arac bulunduguArac;
	
	public Kisi(String isim, int yas, int kalanOmur, Arac bulunduguArac) { // Kurucu fonksiyon
		this.isim = isim;
		this.yas = yas;
		this.kalanOmur = kalanOmur;
		this.bulunduguArac = bulunduguArac;
		
		bulunduguArac.yolcuSayisiGuncelle(+1); // Arac yolcu sayısı +1
	}
	
	public void xSaatIlerle(int x) { // x saat ilerle fonksiyonu
		if (kalanOmur <= 0) return;
		kalanOmur -=x;                             // Ömrü x saat azaldı
		if (kalanOmur <= 0) {
			bulunduguArac.yolcuSayisiGuncelle(-1); // Öldüyse arac yolcu sayısı -1
		}
	}
}
