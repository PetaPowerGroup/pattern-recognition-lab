#pragma once
#include <vector>
#include "IzlucivanjeZnacajki.h"
class ObradeniUzorak;
class Baza;

class SkupObradenihUzoraka
{
public:
	SkupObradenihUzoraka(Baza, bool izluciHaarom, int sirina_okna, int visina_okna);
	SkupObradenihUzoraka();
	~SkupObradenihUzoraka(void);
	void izvuciKorisneZnacajke();
	void writeToFile();
private:
	std::vector<ObradeniUzorak> uzorci;
	IzlucivanjeZnacajki izlucivac;
};
