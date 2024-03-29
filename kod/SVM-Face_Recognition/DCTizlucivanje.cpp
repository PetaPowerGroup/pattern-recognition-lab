/*	
	izlučivanje značajki DCT metodom
	dakle za svaki pojedini 8*8 blok se vadi SAMO
	osnovna frakvencija 2d diskretnog signala 
	to predstavlja element [1][1] u svakom 8x8 bloku
	transformirane matrice. Ovo je početna verzija
	i zasigurno uma hrpu grešaka budući dugo nisam radio sa c++ om
*/

//#include <vector>
//#include "Uzorak.h"
//#include "DCTIzlucivanje.h"
//#include <iostream>
//#include <math.h>
//
//using namespace std;
//
//
//std::vector<double> IzlucivanjeZnacajki::DCTznacajke(Uzorak uzorak){ //klasa za izlučivanje značajki
//	int okvir = 8;
//	vector <double> tvector = new vector <double> (sqr(uzorak.getSirina()/okvir));
//	//tvector je vektor veličine broja blokova po širini uzorka, on ujedno predstavlja skup značajki
//	for (int i=1; i<=uzorak.getSirina()/okvir; i++){
//		for (int j=1; j<=uzorak.getVisina()/okvir; j++){
//			int in[okvir][okvir]; //pomoćna 8x8 matrica za svaki blok
//			for (k=0; k < okvir; k++)
//				for (l=0; l < okvir; l++)
//					in[k][l] = uzorak.getPixel((i+k)*okvir + (j+l)); //punjenje matrice
//			tvector.at((i-1) * uzorak.getSirina()/okvir + j) = transformacija(in); //računanje značajke
//		}
//	}
//	DCTznacajke->push_back(tvector);
//
//
//	std::vector<double> transformacija(int& in){ //referenca? nisam siguran jel ovo dobro
//		double p[okvir][okvir];
//		double pom=0, prod=0; // prod je konačan rezultat tj. značajka pojedinog bloka
//		for (i=0; i < okvir; i++){
//			for (j=0; j < okvir; j++)
//				p[i][j] = cos(M_PI*(2*i+1)*j/2/okvir)/sqrt(okvir)*sqrt(2); //DCT formula
//			p[i][0] = cos(M_PI*(2*i+1)*j/2/okvir)/sqrt(okvir);
//		}
//		/* 
//		sljedeći blok naredbi se odnosi na transpoziciju matrice p
//		množenje iste sa matricom in, te nanovo množenje podrezultata 
//		sa matricom p čitav dio je bitno pojednostavljen budući da 
//		nama treba samo prvi element rezultantne matrice
//		*/
//		for (i=0; i < okvir; i++){
//			for (j=0; j < okvir; j++){
//				pom += in[i][j]*p[0][j];
//			}
//			prod += p[0][i]*pom;
//			pom = 0;
//		}
//		transformacija->push_back(prod);
//	}
//
//	return DCTznacajke; //vraćanje rezultata u .h file
//}
