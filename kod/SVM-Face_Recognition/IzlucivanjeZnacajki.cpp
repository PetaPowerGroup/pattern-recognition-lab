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
#include "IzlucivanjeZnacajki.h"
#include <iostream>

using namespace std;


std::vector<double> IzlucivanjeZnacajki::izluciZnacajke(Uzorak uzorak, int sirina_okna, int visina_okna) {//ova povratna vrijednost bi mi pasala, za pozivanje od tamo od kud sam mislio
/*
	// integralna slika - kako bi manje puta pristupal slici i na taj naèin ubrzali ovaj postupak
	vector< vector<int> > integrirana_slika(uzorak.getVisina()+1);
	//Uzorak integralna_slika(uzorak.getSirina(), uzorak.getVisina());
	int zbroj = 0;
	
	vector<int> *redak_integralne_slike=new vector<int>(uzorak.getSirina()+1);
	vector<int> *pomocni=new vector<int>(uzorak.getSirina()+1);
	for (int i = 1; i <= uzorak.getSirina(); i++)
	{
		zbroj += uzorak.getPixel(i-1); 
		//integralna_slika.setPixel(i, zbroj);
		//redak_integralne_slike->push_back(zbroj);
		redak_integralne_slike->at(i-1) = zbroj;
		pomocni->at(i-1) = uzorak.getPixel(i-1);
		//cout << "i je: " << i<<endl;
	}
	integrirana_slika.at(1)=*redak_integralne_slike;


	for (int i = 2; i <= uzorak.getVisina(); i++)   // poèinjemo od 2, zato jer smo prvi red veæ obradili  
	{
		redak_integralne_slike=new vector<int>(uzorak.getSirina()+1);
		integrirana_slika.at(i)=*redak_integralne_slike;
		zbroj = 0;
		for (int j = 1; j <= uzorak.getSirina(); j++) 
		{
			zbroj += uzorak.getPixel((i-1)*uzorak.getSirina() + (j-1));
			integrirana_slika.at(i).at(j)=integrirana_slika.at(i-1).at(j)+zbroj;
			//redak_integralne_slike.at(i).at(j)=zbroj;
			//integralna_slika.setPixel(i, j, integralna_slika.getPixel((i-1), j)+zbroj));
		}
	}



	std::vector<double> izracunateZnacajke;//=std::vector<double>();//u ovu listu trpaš vrijednosti znaèajki, kako ih izraèunavaš

	int sirina_okna = 4;  
	int visina_okna = 4;  // ako je slika velika 64x64 imamo 64 znaèajke, može se poveæavati ili smanjivati ovisno o rezultatima 

	double tamni, svijetli;
	double prva_tocka, druga_tocka, treca_tocka, cetvrta_tocka, peta_tocka, sesta_tocka;

	for (int i = 1; i <= (int)(integrirana_slika.size() - visina_okna); i += visina_okna)  
		{
		for (int j = 1; j <= (int)(integrirana_slika.size() - sirina_okna); j += sirina_okna) 
			{
				if (i == 1)  
				{
					prva_tocka = 0;
					cetvrta_tocka = 0;
				}
				else 
				{
					prva_tocka = integrirana_slika.at(i).at(j - 1);
					cetvrta_tocka = integrirana_slika.at(i + visina_okna - 1).at(j - 1);
				}
				if (j == 1)
				{
					prva_tocka = 0;
					druga_tocka = 0;
					treca_tocka = 0;
				} 
				else
				{
					if (i != 1) prva_tocka = integrirana_slika.at(i).at(j - 1); 
					druga_tocka = integrirana_slika.at(i + visina_okna - 1).at(j + sirina_okna/2 - 1);
					treca_tocka = integrirana_slika.at(i).at(j + sirina_okna - 1);
				}
				peta_tocka = integrirana_slika.at(i + visina_okna - 1).at(j + sirina_okna/2 - 1);
				sesta_tocka = integrirana_slika.at(i + visina_okna - 1).at(j + sirina_okna - 1);
			
				tamni = peta_tocka - cetvrta_tocka - druga_tocka + prva_tocka;
				svijetli = sesta_tocka - peta_tocka - treca_tocka + druga_tocka;
			
				double rezultat=(svijetli-tamni)/(sirina_okna*visina_okna/2*255);
				izracunateZnacajke.push_back(rezultat); // i dobili smo znaèajku
				assert (rezultat<=1.0 && rezultat>=0.0);
			} 
		}
	// Uzorak integralna_slika potrebno je izbrisati, ali u klasi uzorak nema destruktora. 

	//praznjenje memorije
	for(int i=0; i<(int)integrirana_slika.size(); ++i) 
		integrirana_slika.at(i).~vector();
	integrirana_slika.~vector();

	return izracunateZnacajke;
*/
	std::vector<double> izracunateZnacajke;//=std::vector<double>();//u ovu listu trpaš vrijednosti znaèajki, kako ih izraèunavaš

	//int sirina_okna = 8;  
	//int visina_okna = 8;  // ako je slika velika 64x64 imamo 64 znaèajke, može se poveæavati ili smanjivati ovisno o rezultatima 

	double tamni, svijetli;

	for (int i = 0; i < (int)(uzorak.getVisina() - visina_okna); i += visina_okna)  
		{
			for (int j = 0; j < (int)(uzorak.getSirina() - sirina_okna); j += sirina_okna) 
			{
				tamni = 0;
				svijetli = 0;
				for (int x = i; x < i + visina_okna; x++)
				{
					for (int y = j; y < j + sirina_okna; y++) 
					{
						if (y < (j + sirina_okna/2)) 
						{
							tamni += uzorak.getPixel(x,y);
						}
						else 
						{
							svijetli += uzorak.getPixel(x,y);
						}
					}
				}
			
				double rezultat=(svijetli-tamni+sirina_okna*visina_okna/2*255)/(sirina_okna*visina_okna*255);
				izracunateZnacajke.push_back(rezultat); // i dobili smo znaèajku
				assert (rezultat<=1.0 && rezultat>=0.0);
			} 
		} 

	

	return izracunateZnacajke;
}
