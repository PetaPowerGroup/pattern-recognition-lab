
#include "Uzorak.h"
#include "Greska.h"
#include "Ucitavanje.h"
#include "Baza.h"
#include "SkupObradenihUzoraka.h"

#include <iostream>
#include <conio.h>

#define BROJ_LJUDI 294
#define BROJ_SLIKA_PO_COVJEKU 4
#define BROJ_VERZIJA_SLIKE 2

using namespace std;

string Ucitavanje::path="";//gdje se na disku nalazi kazalo sa slikama lica.
bool izluciHaarom=true;
int sirina_okna=8;
int visina_okna=8;

int main(int argc, char* argv[])//prvi argument lokacija kazala sa slikama lica, a drugi 1 za izluèivanje znaèajki Haarom, a 0 za ne, zatim ide sirina okna pa visina okna za Haara
{
	Baza baza(BROJ_LJUDI, BROJ_SLIKA_PO_COVJEKU, BROJ_VERZIJA_SLIKE);
	try
	{	
		string noviPath("D:\\face");
		int izlucivanje=1;
		if (argc<2){
			Ucitavanje::setPath(noviPath);
			cout<<"Unesite stazu do kazala sa slikama lica (raspakiranog) ili pritisnite enter ako se nalazi na D:\\face\n";
			
			getline(cin,noviPath);
		} else {
			noviPath=argv[1];
			izlucivanje=atoi(argv[2]);
			if (izlucivanje) izluciHaarom=true;
			else izluciHaarom=false;
			cout<<"Izluci znacajke je: "<<izluciHaarom<<endl;
			if (argc==5){
				sirina_okna=atoi(argv[3]);
				visina_okna=atoi(argv[4]);
			}
		}
		if (noviPath.compare("")!=0){
			Ucitavanje::setPath(noviPath);
		}
		cout<<"postavili ste stazu na: "<<Ucitavanje::getPath()<<endl;

		SkupObradenihUzoraka nasSkupUzoraka(baza, izluciHaarom, sirina_okna, visina_okna); //stvara skup uzoraka u obliku prikladnom za obradu u memoriji
		//nasSkupUzoraka.izvuciKorisneZnacajke(); //TODO actually napraviti ovo :D   ... Napomena: razmisliti da li æe ovo biti metoda koja æe na mjestu mijenjati klasu ili æe kreirati novu izmijenjenu i vratiti ju
		cout<<"Znacajke izlucene, pisem u datoteku"<<endl;
		nasSkupUzoraka.writeToFile();
		cout<<"Gotovo."<<endl;
		//_getch();
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