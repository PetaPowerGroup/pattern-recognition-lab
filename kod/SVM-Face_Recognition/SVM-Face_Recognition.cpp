#include <iostream>
#include <Uzorak.h>
//#include <Greska.h>
#include <Ucitavanje.h>

using namespace std;

int main()
{
	try
	{
		cout<<"Hello"<<endl;

		Uzorak uzorak1(5,5);

		cout<<"Pixel (1,1) ima nijansu: " << (int)uzorak1.getPixel(1,1) << endl;

		/*uzorak1.setPixel(1,1,300);
		cout<<"Pixel (1,1) ima nijansu: " << (int)uzorak1.getPixel(1,1) << endl;*/

		Ucitavanje datoteka("000_1_1.nrm");
		Uzorak uzorak2 = datoteka.ucitajUzorak();

		/*for (int i=0; i<uzorak2.getVelicina(); i++)
		{
			cout<<(int)uzorak2.getPixel(i)<<" ";
		}*/
		
	}

	catch (Greska g)
	{
		g.ispisGreske();
	}
	catch (...)
	{
		cout<<"Gre�ka uhva�ena, nepoznata"<<endl;
	}



}