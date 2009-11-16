#include "Baza.h"
#include "Ucitavanje.h"
#include "Uzorak.h"
#include "Greska.h"

#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <sys/types.h>
#include <errno.h>
#include <vector>
using namespace std;

Baza::Baza(int brojOsoba, int brojSnimanja, int brojSlika){
	this->brojOsoba=brojOsoba;
	this->brojSnimanja=brojSnimanja;
	this->brojSlika=brojSlika;
}

int Baza::getdir (string dir, vector<string> &files)
{
/*    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);*/
    return 0;
}

vector<Uzorak> Baza::ucitajCijelu(){
	vector<Uzorak> uzorci=vector<Uzorak>();
	vector<string> files = vector<string>();


	return uzorci;
}
Uzorak Baza::getUzorak(int osoba, int uzorak){
	int snimanje=uzorak/2;
	int slika=uzorak%2;
	if (sanity_check(osoba, snimanje, slika)){
		Ucitavanje datoteka(oblikujNaziv(osoba, snimanje, slika));
		return datoteka.ucitajUzorak();
	} else
		throw Greska("GRESKA: Pristupa se podatku iz baze koji ne postoji.");
}
bool Baza::sanity_check(int osoba, int snimanje, int slika){
	return (osoba>=0 && osoba<this->brojOsoba
		&& snimanje>=0 && snimanje<this->brojSnimanja
		&& slika>=0 && slika<brojSlika);
}

string Baza::oblikujNaziv(int osoba, int snimanje, int slika){
	string naziv="";

	//nazivi datoteka sadrze indekse slika i snimanja od 1 na gore
	++snimanje;
	++slika;

	stringstream out;
	out<< setw( 3 ) << setfill( '0' ) << osoba << "_" << snimanje << "_" << slika << ".nrm";
	naziv=out.str();

	return naziv;
}

int Baza::getBrojOsoba(){
	return brojOsoba;
}
int Baza::getBrojUzoraka(){
	return brojSnimanja*brojSlika;
}