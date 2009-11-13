
#include "svm.h"


void svm::train(PSamples samples, int num, double c){
	tree *trainer = new tree();
	root = trainer->train(ken,new alg1(),samples,c,num);
}

double* svm::get_array(std::string &str) {
	double *niz = new double[vel_uz];
	std::stringstream s(str);
	std::string str2;
	while(s>>str2) {
		std::stringstream ss(str2);
		int i;
		ss>>i;
		char z;
		ss>>z;
		double f;
		ss>>f;
		niz[i-1]=f;
	}
	return niz;
}

void svm::train(std::istream &in,int vel){
	vel_uz = vel;
	PSamples sam = new Samples();
	std::string str;
	int x,max=-1;
	while(in>>x){
		if (x>max) max=x;
		getline(in,str);
		double *niz = get_array(str);
		PElement e = new Element(niz,vel);
		sam->push_back(std::make_pair<PElement,int>(e,x));
		delete [] niz;

	}
	train(sam,max,1);
}

int svm::clasify(std::string &pat){
	double *niz = get_array(pat);
	PElement e = new Element(niz,vel_uz);

	node *tmp = root;
	while(1) {
		if (tmp->is_leaf()) 
			return tmp->get_class();
		tmp = tmp->next(e);
		if (tmp==NULL) 
			return -1;
	}
	return 0;
}