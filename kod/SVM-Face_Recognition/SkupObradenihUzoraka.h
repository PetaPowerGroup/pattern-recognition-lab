#pragma once
#include <vector>
class ObradeniUzorak;
class Baza;

class SkupObradenihUzoraka
{
public:
	SkupObradenihUzoraka(Baza);
	~SkupObradenihUzoraka(void);
	void izvuciKorisneZnacajke();
	void writeToFile();
private:
	std::vector<ObradeniUzorak> uzorci;
};
