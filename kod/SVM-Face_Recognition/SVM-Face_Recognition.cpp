
#include "Uzorak.h"
#include "Greska.h"
#include "Ucitavanje.h"
#include "Baza.h"
#include "SkupObradenihUzoraka.h"

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "engine.h" // ovo je include fajl za MATLABov engine

#include <direct.h>

#include <string>
#include <sstream>

#define  BUFSIZE 256

#define BROJ_LJUDI 294
#define BROJ_SLIKA_PO_COVJEKU 4
#define BROJ_VERZIJA_SLIKE 2

using namespace std;

string Ucitavanje::path="";//gdje se na disku nalazi kazalo sa slikama lica.
bool izluciHaarom=true;
int sirina_okna=8;
int visina_okna=8;
int konacniBrojZnacajkiZaPCA=20;
int brojOsoba=294;

int pozoviPCA(int brojUzoraka, int brojZnacajki, int konacniBrojZnacajki){

	//dobavi kazalo
	char *path = NULL;
	path = _getcwd(NULL, 0); // or _getcwd
	if ( path != NULL)
		printf("%s\n", path);

	Engine *ep; // pointer na MATLAB-ov engine
	char buffer[BUFSIZE];

	// pokretanje MATLAB engine-a, uz standardne provjere ispravnosti
	if (!(ep = engOpen("\0"))) {
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		return EXIT_FAILURE;
	}

	engOutputBuffer(ep, buffer, BUFSIZE); // definiramo string varijablu za MATLABov output
	
	
	string promjeniKazalo("cd('");
	promjeniKazalo.append(path);
	promjeniKazalo.append("')");
	engEvalString(ep, promjeniKazalo.c_str());
	printf("%s", buffer+2); // ispisujemo dobiveni rezultat

	stringstream ss;
	ss<<"PCA("<<brojUzoraka<<","<<brojZnacajki<<","<<konacniBrojZnacajki<<")";
	string naredba=ss.str();
	printf("Naredba za pozivanje PCA je: %s\n", naredba.c_str());
	//system("pause");
	engEvalString(ep, naredba.c_str()); // saljemo string na izracunavanje

	printf("%s", buffer+2); // ispisujemo dobiveni rezultat

    //fgetc(stdin);
	
	engClose(ep); // gasimo engine
	printf("Odradio matlab poziv PCA funkcije\n");
	return EXIT_SUCCESS;
}

int main(int argc, char* argv[])//prvi argument lokacija kazala sa slikama lica
	//drugi 0 za PCA, 1 za izluèivanje znaèajki Haarom, 2 za oboje, a 3 za ništa
	//zatim ide sirina okna
	//pa visina okna za Haara
	//broj konacnih znacajki za PCA
	//broj osoba (maksimum 294)
{
	if (argc==7 && atoi(argv[6])<=BROJ_LJUDI) brojOsoba=atoi(argv[6]);
	cout<<"Broj ljudi je: "<<brojOsoba<<endl;
	Baza baza(brojOsoba, BROJ_SLIKA_PO_COVJEKU, BROJ_VERZIJA_SLIKE);
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
			if (izlucivanje==1 || izlucivanje==2) izluciHaarom=true;
			else izluciHaarom=false;
			cout<<"Izluci znacajke je: "<<izlucivanje<<endl;
			if (argc==7){
				sirina_okna=atoi(argv[3]);
				visina_okna=atoi(argv[4]);
				konacniBrojZnacajkiZaPCA=atoi(argv[5]);
				cout<<"Sirina, visina, konacni broj znacajki su "<<sirina_okna<<", "<<visina_okna<<", "<<konacniBrojZnacajkiZaPCA<<", "<<endl;
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
		if (izlucivanje==0 || izlucivanje==2)//1 je samo za Haara, a 3 je za ništa pa tada ne koristimo PCA
			pozoviPCA(baza.getBrojOsoba()*baza.getBrojUzoraka(),nasSkupUzoraka.getBrojZnacajki(),konacniBrojZnacajkiZaPCA);
		cout<<"Gotovo. Pritisnite enter..."<<endl;
		//system("pause");
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