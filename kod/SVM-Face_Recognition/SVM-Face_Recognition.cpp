
#include "Uzorak.h"
#include "Greska.h"
#include "Ucitavanje.h"

#include <iostream>

using namespace std;

string Ucitavanje::path = "";

int main()
{
	char c;
	try
	{
		cout<<"Hello"<<endl;

		//gdje se na disku nalazi kazalo sa slikama lica.
		string noviPath;
		cout<<"Unesite stazu do kazala sa slikama lica (raspakiranog)";
		cin>>noviPath;
		Ucitavanje::setPath(noviPath);
		cout<<"postavili ste stazu na: "<<Ucitavanje::getPath()<<endl;

		Uzorak uzorak1(5,5);

		//cout<<"Pixel (1,1) ima nijansu: " << (int)uzorak1.getPixel(1,1) << endl;

		//uzorak1.setPixel(1,1,300);
		cout<<"Pixel (1,1) ima nijansu: " << (int)uzorak1.getPixel(1,1) << endl;

		Ucitavanje datoteka("000_2_1.nrm");
		Uzorak uzorak2 = datoteka.ucitajUzorak();
		uzorak2.print();

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
		cout<<"Gre�ka uhva�ena, nepoznata"<<endl;
	}

	cin>>c;
	return 0;

}