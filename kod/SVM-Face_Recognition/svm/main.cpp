#include <iostream>
#include<fstream>
#include "svm.h"
using namespace std;
int main() {
	svm *moj = new svm(new linear_kernel());

	fstream dat("heart_scale.txt",ios::in);
	
	// dat - datoteka s uzorcima za ucenje
	// 2 - velicina uzorka ; ovaj podatak ce kasnije ici u konstruktor
	moj->train(dat,13);  // treniranje svm-a

	//klasifikacija uzorka 
	int raz = moj->classify(string("1:0.208333 2:1 3:1 4:-0.358491 5:-0.392694 6:2 7:1 8:-0.0992366 9:1 10:-0.0322581 12:0.333333 13:1"));
	cout<<"Razred je "<<raz<<endl;
	dat.close();
	return 0;
}