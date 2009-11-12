#include "Baza.h"
#include "Ucitavanje.h"
#include "Uzorak.h"

#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include "Greska.h"
using namespace std;

Baza::Baza(int brojOsoba, int brojSnimanja, int brojSlika){
	this->brojOsoba=brojOsoba;
	this->brojSnimanja=brojSnimanja;
	this->brojSlika=brojSlika;
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