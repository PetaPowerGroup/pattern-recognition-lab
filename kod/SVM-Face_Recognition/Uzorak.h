//#include <iostream>
#include <math.h>
//#include <vector>
#include <malloc.h>
#include <Greska.h>

using namespace std;

class Uzorak
{
public:
	Uzorak(int sirina, int visina);
	unsigned char getPixel(int red, int stupac);
	unsigned char getPixel(int pozicija);
	void setPixel(int red, int stupac, unsigned char nijansa);
	void setPixel(int pozicija, unsigned char nijansa);
	int getVelicina();
	int getSirina();
	int getVisina();

private:
	unsigned char* pixeli;
	int sirina;
	int visina;
};


Uzorak::Uzorak(int sirina, int visina)
{
	this->sirina = sirina;
	this->visina = visina;

	pixeli = (unsigned char *)malloc(sirina*visina*(sizeof(unsigned char)));

	for (int i=0; i<sirina*visina; i++)
	{
		pixeli[i]=0;
	}
}

unsigned char Uzorak::getPixel(int red, int stupac)
{
	if ( (red<1 || red>visina) && (stupac<1 || stupac>sirina) )
		throw Greska("GRESKA: Provjera raspona\n\tVrijednost red/stupac izvan raspona");
	
	return pixeli[red*sirina+stupac];
}

unsigned char Uzorak::getPixel(int pozicija)
{
	if ( pozicija<0 || pozicija>sirina*visina )
		throw Greska("GRESKA: Provjera raspona\n\tVrijednost izvan raspona");
	
	return pixeli[pozicija];
}

void Uzorak::setPixel(int red, int stupac, unsigned char nijansa)
{
	if (nijansa<0 || nijansa>255)
		throw Greska("GRESKA: Provjera raspona\n\tVrijednost Nijanse izvan raspona");

	if ( (red<1 || red>visina) && (stupac<1 || stupac>sirina) )
		throw Greska("GRESKA: Provjera raspona\n\tVrijednost red/stupac izvan raspona");

	pixeli[red*sirina+stupac] = nijansa;
}

void Uzorak::setPixel(int pozicija, unsigned char nijansa)
{
	if (nijansa<0 || nijansa>255)
		throw Greska("GRESKA: Provjera raspona\n\tVrijednost Nijanse izvan raspona");

	if (pozicija<0 || pozicija>sirina*visina)
		throw Greska("GRESKA: Provjera raspona\n\tVrijednost izvan raspona");

	pixeli[pozicija] = nijansa;
}

int Uzorak::getVelicina()
{
	return visina*sirina;
}

int Uzorak::getSirina()
{
	return sirina;
}

int Uzorak::getVisina()
{
	return visina;
}