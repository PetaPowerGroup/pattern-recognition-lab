#include <string>
#include <vector>
using namespace std;
class Uzorak;

class Baza{
	public:
		Baza(int brojOsoba, int brojSnimanja, int brojSlika);
		int getdir (std::string dir, std::vector<string> &files);
		std::vector<Uzorak> ucitajCijelu();
		Uzorak getUzorak(int osoba, int uzorak);
			/*
			*osoba: 0<=indeks osobe<brojOsoba
			*uzorak: 0<=indeks uzorka<brojSnimanja*brojSlika (0-7 u našem sluèaju !!!)
			*/
		int getBrojOsoba();
		int getBrojUzoraka();
			
	private:
		int brojOsoba, brojSnimanja, brojSlika;
		bool sanity_check(int osoba, int snimanje, int slika);
		string oblikujNaziv(int osoba, int snimanje, int slika);

};