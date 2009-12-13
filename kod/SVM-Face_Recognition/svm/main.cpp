#include <iostream>
#include<fstream>
#include "svm.h"
using namespace std;
int main() {
	svm *moj = new svm(new rbf_kernel(5));
	
	// dat - datoteka s uzorcima za ucenje
	fstream dat("lica-sva.txt",ios::in);
	
	// 2 - velicina uzorka ; c=1.0 - ovo je zasada hardkodirano
	long int t1 = time(NULL);
	moj->train(dat,64,1.0);  // treniranje svm-a
	long int t2 = time(NULL);
	std::cout<<"vrijeme treniranja "<<t2-t1<<" sekundi\n";
	dat.close();
	fstream dat2 ("svm.txt",ios::out);
	//moj->save(dat2);
	dat2.close();
	dat.close();

	string str;
	cout<<"Treniranje zavrseno.\nDecizijske funkcije pohranjene u svm.txt\n"<<endl;
	cout<<"Otvaram datoteku test.txt za testiranje\n\n"<<endl;
	fstream dat3("test.txt",ios::in);
	while(getline(dat3,str)){
		int raz = moj->classify(string(str)); //klasifikacija uzorka
		cout<<"Uzorak  pripada razredu "<<raz<<endl;
	}
	dat3.close();
	system("pause");
	return 0;
}