
#include "Greska.h"

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

Greska::Greska(char* poruka)
{
	strcpy(porukaGreske,poruka);
}

void Greska::ispisGreske()
{
	cout<<porukaGreske<<endl;
}

void Greska::ispisGreske(streamEnum stream)
{
	if (stream == Greska::KONZOLA)
	{
		cout<<porukaGreske<<endl;
	}
	else
	{
		ofstream datoteka;
		
		datoteka.open("errorlog.txt",ios::out | ios::app);
		if (!datoteka.is_open())
		{
			cout<<"GRESKA: Provjera pristupa\n\tDatoteka \"errorlog.txt\" nije otvorena."<<endl;
		}
		else
		{
			time_t vrijeme;
			time (&vrijeme);
			datoteka<<asctime(localtime(&vrijeme))<<" "<<porukaGreske<<endl;
		}
		datoteka.close();
	}

}