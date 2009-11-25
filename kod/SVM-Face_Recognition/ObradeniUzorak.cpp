#include "ObradeniUzorak.h"
#include <string>
#include <sstream>

ObradeniUzorak::ObradeniUzorak(int oznakaRazreda)
{
	this->oznakaRazreda=oznakaRazreda;
	this->skupZnacajki=std::vector<double>();
}

ObradeniUzorak::~ObradeniUzorak(void)
{
}

int ObradeniUzorak::getOznakaRazreda(void){
	return oznakaRazreda;
}
std::vector<double> *ObradeniUzorak::getSkupZnacajki(){
	return &skupZnacajki;
}

std::string ObradeniUzorak::toString(){
	std::stringstream out;
	out<<this->getOznakaRazreda();
	int i=1;
	for (std::vector<double>::iterator it = skupZnacajki.begin(); it!=skupZnacajki.end();++it) {
		if (*it!=0.0)
			out << " " << i << ":" << *it;
		++i;
	}
	return out.str();
}
