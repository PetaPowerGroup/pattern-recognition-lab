
#include "Uzorak.h"
#include "Greska.h"
#include "Ucitavanje.h"

#include <iostream>

using namespace std;

int main()
{
	try
	{
		cout<<"Hello"<<endl;

		Uzorak uzorak1(5,5);

		//cout<<"Pixel (1,1) ima nijansu: " << (int)uzorak1.getPixel(1,1) << endl;

		//uzorak1.setPixel(1,1,300);
		cout<<"Pixel (1,1) ima nijansu: " << (int)uzorak1.getPixel(1,1) << endl;

		Ucitavanje datoteka("000_1_1.nrm");
		Uzorak uzorak2 = datoteka.ucitajUzorak();

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



}