#include "SkupObradenihUzoraka.h"
#include "Baza.h"
#include "Uzorak.h"
#include "ObradeniUzorak.h"
#include "IzlucivanjeZnacajki.h"
#include "Greska.h"
#include "Ucitavanje.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

SkupObradenihUzoraka::SkupObradenihUzoraka(Baza baza, bool izluciHaarom, int sirina_okna, int visina_okna)
{
	uzorci=vector<ObradeniUzorak>();
	for (int i=0; i<baza.getBrojOsoba(); ++i){
		for (int j=0; j<baza.getBrojUzoraka(); ++j){
			ObradeniUzorak *uzorak=new ObradeniUzorak(i+1);
			std::vector<double> *skupZnacajki=uzorak->getSkupZnacajki();
			Uzorak trenutniUzorak=baza.getUzorak(i, j);

			//Matija-Haar metoda izlu�ivanja...
			//izvlacenje znacajki
			//Treba debuggirati sa breakpointom odavde
			if (izluciHaarom){
				std::vector<double> noveZnacajke= izlucivac.izluciZnacajke(trenutniUzorak, sirina_okna, visina_okna);
				skupZnacajki->insert(skupZnacajki->end(), noveZnacajke.begin(), noveZnacajke.end());
			} else {
				//Ili poznata Lucanin-samo_uzmi_sve metoda izlucivanja znacajki
				for (int k=0; k<trenutniUzorak.getVelicina(); k++)
				skupZnacajki->push_back((double)trenutniUzorak.getPixel(k));
			}

			uzorci.push_back(*uzorak);
			
		}
	}
}

SkupObradenihUzoraka::SkupObradenihUzoraka()
{
	Ucitavanje datoteka("naziv");
	datoteka.ucitajUzorak();

}

SkupObradenihUzoraka::~SkupObradenihUzoraka(void)
{
}

void SkupObradenihUzoraka::izvuciKorisneZnacajke(){//obavlja se u konstruktoru zapravo, tako je ispalo jednostavnije
}

void SkupObradenihUzoraka::writeToFile(){
	ofstream myfile ("vrijednostiZnacajkiUzoraka.txt");
	if (myfile.is_open()){
    for (vector<ObradeniUzorak>::iterator it = uzorci.begin(); it!=uzorci.end(); ++it) {
		myfile << it->toString() << endl;
	}
    myfile.close();
	}
	else throw Greska("GRESKA: Unable to open file");
/*
	ofstream File("vrijednostiZnacajkiUzoraka.txt");
	ofstream File(
	for (vector<ObradeniUzorak>::iterator it = uzorci.begin(); it!=uzorci.end(); ++it) {
		File<< it->toString() << endl;
	}
	File.close();*/
}
