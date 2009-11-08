#ifndef SVM_H
#define SVM_H
#include "base.h"
#include "tree.h"

class svm {
private:
	node *root;
	kernel *ken;
public :
	svm(kernel *k):ken(k){}
	void train(PSamples samples, int num, double c);
};
#endif