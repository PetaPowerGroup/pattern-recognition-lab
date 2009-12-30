#pragma once
#include <vector>
class Uzorak;

class IzlucivanjeZnacajki{
public:
	std::vector<double> IzlucivanjeZnacajki::PCA(Uzorak uzorak);
	std::vector<double> Covariance(Uzorak *uzorak);
	std::vector<double> Transpose(float m[], int M, int N);
	std::vector<double> Bubblesort(float x[], int m, int n);
};