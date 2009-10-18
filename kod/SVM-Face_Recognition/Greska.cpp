
#include "Greska.h"

#include <iostream>
#include <string>

using namespace std;

Greska::Greska(char* poruka)
{
	strcpy(porukaGreske,poruka);
}

void Greska::ispisGreske()
{
	cout << porukaGreske << endl;
}