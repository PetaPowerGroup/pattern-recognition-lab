
#include "Uzorak.h"
#include "Greska.h"
#include "Ucitavanje.h"
#include "Baza.h"
#include "SkupObradenihUzoraka.h"

#include <iostream>

#define BROJ_LJUDI 294
#define BROJ_SLIKA_PO_COVJEKU 4
#define BROJ_VERZIJA_SLIKE 2

using namespace std;

string Ucitavanje::path="";//gdje se na disku nalazi kazalo sa slikama lica.

int main()
{
	Baza baza(BROJ_LJUDI, BROJ_SLIKA_PO_COVJEKU, BROJ_VERZIJA_SLIKE);
	try
	{	
		string noviPath("D:\\face");
		Ucitavanje::setPath(noviPath);
		cout<<"Unesite stazu do kazala sa slikama lica (raspakiranog) ili pritisnite enter ako se nalazi na D:\\face\n";
		
		getline(cin,noviPath);
		
		if (noviPath.compare("")!=0){
			Ucitavanje::setPath(noviPath);
		}
		cout<<"postavili ste stazu na: "<<Ucitavanje::getPath()<<endl;

		SkupObradenihUzoraka nasSkupUzoraka(baza); //stvara skup uzoraka u obliku prikladnom za obradu u memoriji
		nasSkupUzoraka.izvuciKorisneZnacajke(); //TODO actually napraviti ovo :D   ... Napomena: razmisliti da li æe ovo biti metoda koja æe na mjestu mijenjati klasu ili æe kreirati novu izmijenjenu i vratiti ju
		cout<<"Znacajke izlucene, pisem u datoteku"<<endl;
		nasSkupUzoraka.writeToFile();

		//testiranje baze
		/*
		baza.getUzorak(3,2).print();<-----ovako se od baze zatrazi uzorak 4. osobe i 3. slike
		*(indeksi u bazi poèinju od 0, kao i standardni niz tipa int[10])
		*/

		//Uzorak uzorak1(5,5);

		//cout<<"Pixel (1,1) ima nijansu: " << (int)uzorak1.getPixel(1,1) << endl;

		//uzorak1.setPixel(1,1,300);
		/*cout<<"Pixel (1,1) ima nijansu: " << (int)uzorak1.getPixel(1,1) << endl;

		Ucitavanje datoteka("000_2_1.nrm");
		Uzorak uzorak2 = datoteka.ucitajUzorak();
		uzorak2.print();*/

		/*for (int i=0; i<uzorak2.getVelicina(); i++)
		{
			cout<<(int)uzorak2.getPixel(i)<<" ";
		}*/

		//UzorakP uzorak3(&uzorak1);  kak se koriste ti pametni pokazivaci


		
		
	}

	catch (Greska g)
	{
		g.ispisGreske(Greska::KONZOLA);
		//g.ispisGreske();
	}
	catch (...)
	{
		cout<<"Greška uhvaæena, nepoznata"<<endl;
	}

	return 0;

}