#include <iostream>
#include<fstream>
#include "svm.h"
using namespace std;
int main() {
	svm *moj = new svm(new linear_kernel());

	fstream dat("podaci.txt",ios::in);
	
	// dat - datoteka s uzorcima za ucenje
	// 2 - velicina uzorka ; ovaj podatak ce kasnije ici u konstruktor
	moj->train(dat,2);  // treniranje svm-a

	// klasifikacija uzorka 0.01 -0.01
	int raz = moj->clasify(string("1:0.01 2:-0.01"));
	cout<<"Razred je "<<raz<<endl;
	dat.close();
	return 0;
}