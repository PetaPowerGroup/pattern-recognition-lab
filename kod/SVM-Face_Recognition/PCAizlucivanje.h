#pragma once
#include <vector>
#include "boost/shared_ptr.hpp"
#include "C:/Program Files/extern/include"
class Uzorak;

class IzlucivanjeZnacajki{
public:
	std::vector<double> PCA(Uzorak uzorak);
	std::vector<double> Covariance(Uzorak *uzorak);
	std::vector<double> Transpose(float m[], int M, int N);
	std::vector<double> Bubblesort(float x[], int m, int n);
};