#ifndef SVM_H
#define SVM_H
#include "base.h"
#include "tree.h"

class svm {
private:
	node *root;
	kernel *ken;
	int vel_uz;

	double* get_array(std::string &str);
public :
	svm(kernel *k):ken(k){}
	svm(kernel *k,double ci):ken(k){}
	void train(PSamples samples, int num, double c);
	void train(std::istream &in,int vel,double c);
	int classify(std::string &pat);
	void save(std::ostream &out);
	void load(std::istream &in);
};
#endif