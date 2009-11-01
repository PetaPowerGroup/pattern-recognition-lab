#include <string>
using namespace std;
class Uzorak;

class Baza{
	public:
		Baza(int brojOsoba, int brojSnimanja, int brojSlika);
		Uzorak getUzorak(int osoba, int slika);
			/*
			*osoba: 0<=indeks osobe<brojOsoba
			*slika: 0<=indeks slike<brojSnimanja*brojSlika (0-7 u našem sluèaju !!!)
			*/
			
	private:
		int brojOsoba, brojSnimanja, brojSlika;
		bool sanity_check(int osoba, int snimanje, int slika);
		string oblikujNaziv(int osoba, int snimanje, int slika);

};