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
	void train(PSamples samples, int num, double c);
	void train(std::istream &in,int vel);
	int clasify(std::string &pat);
};
#endif