///*	
//	izlučivanje značajki PCA metodom
//	još je potrebno uključit matlab biblioteku
//	smanjenje dimenzionalnosti M na n
//	gdje se n penje do stupnja uspješnosti od 90%
//	do otprilike vrijednosti 130
//	(ako je za vjerovat g. Ribariću)
//*/
//
//#include <vector>
//#include "Uzorak.h"
//#include "PCAizlucivanje.h"
//#include <iostream>
//#include <math.h>
//#include <malloc.h>
//
//using namespace std;
//
//
//std::vector <double> IzlucivanjeZnacajki::PCA(Uzorak uzorak){
//	int M = uzorak.getVisina();
//	int N = uzorak.getSirina(), n=0;
//	double R[M][M], I[M][M], x[M], lambda, *k;
//	vector <double> transformacijska_matrica = new vector <double> (M*n);
//	R = Covariance(&uzorak);
//	for (int i=0; i<M;i++)
//		for (int j=0; j<N;j++)
//			I[i][j] = (i==j)?1:0;
//	/*računanje determinante*/
//	do{
//		l = (void *)realloc(l, sizeof(float)*(++n));
//		/*ponovo matlab funkcija*/
//		//x = solve(det(R-lambda.*I)=0, lambda);
//		k = Bubblesort(x, M, n);
//		for (int i=0; i<n; i++)
//			*(l+i)=*(k+i);
//	}while(postotak<0.9);//:)
//	vector <double> A = new vector <double> (M*n);
//	/*i ponovo matlab funkcija, no ovaj put matrična jednadžba*/
//	for (i=0;i<n;i++)
//	//transformacijska_matrica(i,:) = solve((R-*(l+i).*I)*((A(i,:))')=0, A(i,:));  ?ovo je upitno, jer je l pokazivač
//	PCA->push_back(transformacijska_matrica);
//	free(l);
//	return PCA;
//	
//}
//
//std::vector <double> Covariance(Uzorak *uzorak){
//	float mean = 0, m[uzorak->getVisina()][uzorak->getSirina()], cov[uzorak->getVisina()][uzorak->getVisina()];
//	for (int i=0; i<uzorak->getVisina();i++)
//		for (int j=0; j<uzorak->getSirina();j++)
//		mean += uzorak->getPixel(i*uzorak->getSirina() + j);
//
//	mean /= uzorak->getVisina()/uzorak->getSirina();
//	for (int i=0; i<uzorak->getVisina();i++)
//		for (int j=0; j<uzorak->getSirina();j++)
//		m[i][j] = uzirak->getPixel(i*uzorak->getSirina() + j) - mean;
//	/*matlab library
//	-matrično množenje i transpozicija*/
//	//cov = m*transpose(m[0], uzorak->getVisina(), uzorak->getSirina());
//	Covariance->push_back(cov);
//	
//}
//
//std::vector <double> Transpose(float m[], int M, int N){
//	vector <double> tr = new vector <double> (M*N);
//	for (int i=0; i<N;i++)
//		for (int j=0; j<M;j++)
//			tr(i*M+j) = m[j][i];
//	Transpose->push_back(tr);
//}
//
//
////bubblesort se pokazao najbržim za ovaj algoritam
//
//std::vector <double *> Bubblesort(float x[], int m, int n){
//	int i, j;
//	for (i = 0; i < n-1; i++) {
//		for (j = 0; j < m-1-i; j++) {
//			if (x[j+1] < x[j]) {
//				float pom = x[j];
//				x[j] = x[j+1];
//				x[j+1] = pom;
//			}
//		}
//	}
//	Bubblesort->push_back(x[]);
//}
//
////pražnjenje memorije
//A.~vector();
//tr.~vector();
//
