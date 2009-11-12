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
	return out.str();
}
