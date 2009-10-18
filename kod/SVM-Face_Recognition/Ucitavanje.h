//#include <Uzorak.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class Ucitavanje
{
public:
	Ucitavanje(char* dat);
	Uzorak ucitajUzorak();


private:
	char imeDatoteke[40];

};

Ucitavanje::Ucitavanje(char* dat)
{
	strcpy(imeDatoteke, dat);
}

Uzorak Ucitavanje::ucitajUzorak()
{
	ifstream datoteka;
	Uzorak uzorak(64,64);

	datoteka.open(imeDatoteke,ios::in|ios::binary);
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
		
