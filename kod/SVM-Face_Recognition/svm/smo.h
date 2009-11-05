
// Sequential minimal optimization

//todo
// promijeniti još step funkciju
// dodati moguænost kernela
//

#ifndef SMO_H
#define SMO_H

#include<vector>
#include<valarray>
#include<cmath>
#include<cstdio>

#include "base.h"

template<typename T>
class smo {
	
	private:
	
		std::vector<double>      *f_cache;     // pogreske izracuna
		std::valarray<double>    *alpha;       // Lagrangeovi multiplikatori
		ELEMENTI				 *elem;
		YPSILON					 *ypsilon;
		double					  c;
		double					  eps;
		double					  b_up;
		double					  b_low;
		int						i_up;
		int						i_low;
		int examine(int i2);
		bool step(int i1,double f1,int i2);
		T &kernel;

	public:
		smo();
		smo(T &ken);
		std::valarray<double>* operator()(ELEMENTI* e, YPSILON *y);
};

template<typename T>
smo<T>::smo() {
}

template<typename T>
smo<T>::smo() {
	elem = e;
	ypsilon = y;
	alpha = new valarray<double>(elem->size(),0);
	f_cache = new vector<double>(elem->size(),0);
}


template<typename T>
int smo<T>::examine(int i1){

	int y1 = (*elem)[i1];
	double alph1 = (*alpha)[i1];
	double f1 = (alph1 > 0 && alph1 < c)?(*f_cache)[i1]:function(i1) -y1;
	bool optimal = true;
	if (((y1==1 && alph1 ==0) || (y1==-1 && alph1 ==c)) && f1 < b_up) {
		b_up = f1;
		i_up = i1;
		if (b_low - f1>2*tol) {
			optimal = false;
			i2 = i_low;
		}
	} else if (((y1==1 && alph1 ==c) || (y1==-1 && alph1 ==0)) && f1 > b_low){
		b_low = f1;
		i_low = i1;
		if (f1 -b_up>2*tol) {
			optimal = false;
			i2 = i_up;
		}
	}
	if (alph1 >0 && alph1 <c) {
		optimal = false;
		if (b_low - f1 > f1 -b_up)
			i2 = i_low;
		else 
			i2 = i_up;
	}
	if (optimal) return 0;
	if (step(i1,f1,i2))
		return 1;
	else 
		return 0;
}


template<typename T>
bool smo<T>::step(int i1, double f1, int i2){
	
	if (i1==i2 ) return 0;
	
	double a1, a2;
	double alph1 = (*alpha)[i1];
	double alph2 = (*alpha)[i2];
	int y1 = (*ypsilon)[i1];
	int y2 = (*ypsilon)[i2];
	double f2 = (alph2 > 0 && alph2 < c)?(*f_cache)[i2]:function(i2) -y2;
	int s = y1*y2;
	double L,H,Lobj,Hobj;
	if (y1==y2) {
		double gamma = alph1 + alph2;
		if (gamma > c) {
			L = gamma - C;
			H = C;
		}else{
			L = 0;
			H = gamma;
		}
	}else {
		double gamma = alph1 - alph2;
		if (gamma > 0) {
			L = 0;
			H = C - gamma;
		}else{
			L = -gamma;
			H = C;
		}
	}
	if ( L == H ) 
		return false;
	std::valarray<T> x_1_2 = (*elem)[i1]*(*elem)[i2];//potrebno dodat za kernel
	std::valarray<T> x_1_1 = (*elem)[i1]*(*elem)[i1];
	std::valarray<T> x_2_2 = (*elem)[i2]*(*elem)[i2];
	double k12 = x_1_2.sum();//kernel
	double k11 = x_1_1.sum();// kernel
	double k22 = x_2_2.sum();// kernel
	double eta =(double)(2*k12 - k11 - k22);
	if (eta < 0) {
		a2 = alph2 +y2*(f2 - f1)/eta;
		if (a2<L) 
			a2 =L;
		else if (a2>H) 
			a2 =H;
	}else {
		double c1 = eta/2;
		double c2 = y2*(e1-e2) -eta*alph2;
		Lobj = c1*L*L+c2*L;
		Hobj = c1*H*H*c2*H;
		if (Lobj>Hobj) 
			a2 = L;
		else if (Lobj < Hobj) 
			a2 = H;
		else 
			a2 = alph2;
	}
	if (fabs(a2 -alph2) < eps*(a2+alph2+eps))
		return 0;
	a1 = alph1 - s*(a2 - alph2);
	if (a1 < 0) {
		a2 += s*a1;
		a1 =0;
	}else if (a1 > c) {
		double t = a1-c;
		a2+=s*t;
		a1=c;
	}

	//ovo se mijenja

	double t1 = y1*(a1-alph1);
	double t2 = y2*(a2-alph2);
	for (int i = 0; i <alpha->size(); i++) {
		if ((*alpha)[i] >0 && (*alpha)[i] < c){
			std::valarray<T> ko = (*elem)[i1]*(*elem)[i];//kernel 
			std::valarray<T> no = (*elem)[i2]*(*elem)[i];//kernel
			(*f_cache)[i] += t1*ko.sum() +t2*no.sum();
		}
		(*f_cache)[i1] = f1 +t1*k11 + t2*k12;
		(*f_cache)[i2] = f2 +t1*k12 + t2*k22;

	}

	(*alpha)[i1] = a1;
	(*alpha)[i2] = a2;
//do tute
	return 1;
}

template<typename T>
std::valarray<double>* smo<T>::operator ()(ELEMENTI *e, YPSILON *y) {
	elem = e;
	ypsilon = y;
	i_up = i_low = -1;
	alpha = new valarray<double>(elem->size(),0);
	f_cache = new vector<double>(elem->size());
	for (int i =0; i <ypsilon->size(); i++){ 
		(*f_cache)[i] = -(*ypsilon)[i];
		if ((*ypsilon)[i]==1 && i_up ==-1) i_up =i;
		if ((*ypsilon)[i]==-1 && i_low ==-1) i_low =i;
	}
	b_up =-1;
	b_low = 1;
	int number = 0;
	bool all = true;
	while (number > 0 || all) {
		number = 0;
		if (all) {
			for(int i=0; i <alpha->size(); i++) 
				number += examine(i);
		}else {
			for(int i=0; i <alpha->size(); i++){
				if ((*alpha)[i] > 0 && (*alpha)[i]< c)
					number += examine(i);
				if (b_up > b_low - 2*tol) {
					number = 0;
					break;
				}
			}
		}
		if (all) all = false;
		else if (number ==0) all = true;
	}
}



#endif