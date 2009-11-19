// koristit æemo Haarove znaèajke 

/*  mg
Osnovni algoritam:
	- šetat se "oknom" -> prozorom po slici 
	- za svako okno na slici izraèunati razliku tamnog i svijetlog dijela
	- tu razliku spremiti u novi vektor znaèajki

Na ovaj naèin dobit æemo puno znaèajki, no uz kotrolu velièine okna i to se može smanjiti. 
Naravno rezultat æe ovisiti o izboru broja znaèajki, za ovo ne znam u kolikoj mjeri. Vidjet æemo testiranjem.

*/
#include <vector>
#include "Uzorak.h"


std::vector<double> izluciZnacajke(Uzorak uzorak) {//ova povratna vrijednost bi mi pasala, za pozivanje od tamo od kud sam mislio

	// integralna slika - kako bi manje puta pristupal slici i na taj naèin ubrzali ovaj postupak
	Uzorak integralna_slika(uzorak.getSirina(), uzorak.getVisina());
	int zbroj = 0;
	
	for (int i = 1; i <= uzorak.getSirina(); i++)
	{
		zbroj += uzorak.getPixel(i); 
		integralna_slika.setPixel(i, zbroj);
	}
	for (int i = 2; i <= uzorak.getVisina(); i++)   // poèinjemo od 2, zato jer smo prvi red veæ obradili  
	{
		zbroj = 0;
		for (int j = 1; j <= uzorak.getSirina(); j++) 
		{
			zbroj += uzorak.getPixel(i*uzorak.getSirina() + j);
			integralna_slika.setPixel(i*uzorak.getSirina() + j, integralna_slika.getPixel((i-1)*uzorak.getSirina()+zbroj));
		}
	}



	std::vector<double> izracunateZnacajke;//=std::vector<double>();//u ovu listu trpaš vrijednosti znaèajki, kako ih izraèunavaš

	int sirina_okna = 8;  
	int visina_okna = 8;  // ako je slika velika 64x64 imamo 64 znaèajke, može se poveæavati ili smanjivati ovisno o rezultatima 

	double tamni, svijetli;
	double prva_tocka, druga_tocka, treca_tocka, cetvrta_tocka, peta_tocka, sesta_tocka;

	for (int i = 1; i <= (integralna_slika.getVisina() - visina_okna); i += visina_okna)  
		{
		for (int j = 1; j <= (integralna_slika.getSirina() - sirina_okna); j += sirina_okna) 
			{
				if (i == 1)  
				{
					prva_tocka = 0;
					cetvrta_tocka = 0;
				}
				else 
				{
					prva_tocka = integralna_slika.getPixel(i * integralna_slika.getSirina() + j - 1);
					cetvrta_tocka = integralna_slika.getPixel((i + visina_okna - 1) * integralna_slika.getSirina() + j - 1);
				}
				if (j == 1)
				{
					prva_tocka = 0;
					druga_tocka = 0;
					treca_tocka = 0;
				} 
				else
				{
					if (i != 1) prva_tocka = integralna_slika.getPixel(i * integralna_slika.getSirina() + j - 1);
					druga_tocka = integralna_slika.getPixel(i * integralna_slika.getSirina() + j + sirina_okna/2 - 1);
					treca_tocka = integralna_slika.getPixel(i * integralna_slika.getSirina() + j + sirina_okna - 1);
				}
				peta_tocka = integralna_slika.getPixel((i + visina_okna - 1) * integralna_slika.getSirina() + j + sirina_okna/2 - 1);
				sesta_tocka = integralna_slika.getPixel((i + visina_okna - 1) * integralna_slika.getSirina() + j + sirina_okna - 1);
			
				tamni = peta_tocka - cetvrta_tocka - druga_tocka + prva_tocka;
				svijetli = sesta_tocka - peta_tocka - treca_tocka + druga_tocka;
			
				izracunateZnacajke.push_back(tamni - svijetli); // i dobili smo znaèajku
			} 
		}
	// Uzorak integralna_slika potrebno je izbrisati, ali u klasi uzorak nema destruktora. 

	return izracunateZnacajke;
}
