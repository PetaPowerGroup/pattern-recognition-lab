#include <iostream>
#include <string>

using namespace std;

class Greska
{
public:
	Greska(char* poruka);
	void ispisGreske();

private:
	char porukaGreske[100];
};

Greska::Greska(char* poruka)
{
	strcpy(porukaGreske,poruka);
}

void Greska::ispisGreske()
{
	cout << porukaGreske << endl;
}