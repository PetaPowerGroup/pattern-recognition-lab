
#include "svm.h"


void svm::train(PSamples samples, int num, double c){
	tree *trainer = new tree();
	root = trainer->train(ken,new alg1(),samples,c,num);
}
