#pragma once
#include <vector>
#include <string>

class ObradeniUzorak
{
public:
	ObradeniUzorak(int oznakaRazreda);
	~ObradeniUzorak(void);
	int getOznakaRazreda();
	std::vector<double> *getSkupZnacajki();
	std::string toString();
private:
	int oznakaRazreda;//1,2,3 il 4 ...
	std::vector<double> skupZnacajki;//niz nekih brojeva -1.0 do 1.0 preporucljivo (ili 0.0 do 1.0)
};
