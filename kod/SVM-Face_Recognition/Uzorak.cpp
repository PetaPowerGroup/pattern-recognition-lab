
#include "Uzorak.h"
#include "Greska.h"

#include <malloc.h>


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
		throw Greska("GRESKA: Provjera raspona\n\tVrijednost parametra 'red'/'stupac' izvan raspona");
	
	return pixeli[red*sirina+stupac];
}

unsigned char Uzorak::getPixel(int pozicija)
{
	if ( pozicija<0 || pozicija>sirina*visina )
		throw Greska("GRESKA: Provjera raspona\n\tVrijednost parametra 'pozicija' izvan raspona");
	
	return pixeli[pozicija];
}

void Uzorak::setPixel(int red, int stupac, int nijansa)
{
	if (nijansa<0 || nijansa>255)
		throw Greska("GRESKA: Provjera raspona\n\tVrijednost parametra 'nijansa' izvan raspona");

	if ( (red<1 || red>visina) && (stupac<1 || stupac>sirina) )
		throw Greska("GRESKA: Provjera raspona\n\tVrijednost parametra 'red'/'stupac' izvan raspona");

	pixeli[red*sirina+stupac] = (unsigned char)nijansa;
}

void Uzorak::setPixel(int pozicija, int nijansa)
{
	if (nijansa<0 || nijansa>255)
		throw Greska("GRESKA: Provjera raspona\n\tVrijednost parametra 'nijansa' izvan raspona");

	if (pozicija<0 || pozicija>sirina*visina)
		throw Greska("GRESKA: Provjera raspona\n\tVrijednost parametra 'pozicija' izvan raspona");

	pixeli[pozicija] = (unsigned char)nijansa;
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

void Uzorak::print()
{//TODO ljepsi print - po retcima i stupcima
	for (int i=0; i<this->getVelicina(); ++i)
		printf("%d", this->getPixel(i));
	printf("\n");
}
