#include "SkupObradenihUzoraka.h"
#include "Baza.h"
#include "Uzorak.h"
#include "ObradeniUzorak.h"
#include "Greska.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

SkupObradenihUzoraka::SkupObradenihUzoraka(Baza baza)
{
	uzorci=vector<ObradeniUzorak>();
	for (int i=0; i<baza.getBrojOsoba(); ++i){
		for (int j=0; j<baza.getBrojUzoraka(); ++j){
			ObradeniUzorak *uzorak=new ObradeniUzorak(i+1);
			std::vector<double> *skupZnacajki=uzorak->getSkupZnacajki();
			Uzorak trenutniUzorak=baza.getUzorak(i, j);
			for (int k=0; k<trenutniUzorak.getVelicina(); k++)
				skupZnacajki->push_back((double)trenutniUzorak.getPixel(k));
			uzorci.push_back(*uzorak);
			
		}
	}
}

SkupObradenihUzoraka::~SkupObradenihUzoraka(void)
{
}

void SkupObradenihUzoraka::izvuciKorisneZnacajke(){//TODO
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
