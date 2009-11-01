#include "Ucitavanje.h"
#include "Uzorak.h"
#include "Greska.h"

#include <fstream>
#include <string>

using namespace std;

Ucitavanje::Ucitavanje(char* dat)
{
	strcpy_s(imeDatoteke, dat);
}

Uzorak Ucitavanje::ucitajUzorak()
{
	ifstream datoteka;
	Uzorak uzorak(64,64);
	string ime(imeDatoteke);
	if(path.substr(path.size()-1, 1).compare("\\")!=0)
		path.append("\\");
	ime=path+ime;
	printf("%s\n", ime.c_str());

	datoteka.open(ime.c_str(),ios::in|ios::binary);
	if (!datoteka.is_open())
		throw Greska("GRESKA: Provjera pristupa\n\tDatoteka nije otvorena.");

	char nijansa;
	int i=0;

	while (!datoteka.eof())
	{
		datoteka.read(&nijansa,sizeof(unsigned char));

		if (i>uzorak.getVelicina())
			throw Greska("GRESKA: Provjera raspona\nPristupanje izvan raspona");
		uzorak.setPixel(i++, (unsigned char)nijansa);
	}

	return uzorak;
}

void Ucitavanje::setPath(string newPath)
{
	Ucitavanje::path=newPath;
}
		
string Ucitavanje::getPath()
{
	return Ucitavanje::path;
}