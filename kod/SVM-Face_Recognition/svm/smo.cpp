
#include "smo.h"




/*
smo::smo() {
	elem = e;
	ypsilon = y;
	alpha = new Lagrange(elem->size(),0);
	f_cache = new vector<double>(elem->size(),0);
}
*/

double smo::function(int i) {
	double tmp=0;
	for (int j=0; j<elem->size(); j++) 
		tmp += alpha->at(i)*ypsilon->at(i)*kern->calculate(elem->at(i),elem->at(j));
	return tmp;
}


int smo::examine(int i1){

	int y1 = (*ypsilon)[i1];
	double alph1 = (*alpha)[i1];
	double f1 = (alph1 > 0 && alph1 < c)?(*f_cache)[i1]:function(i1) -y1;
	(*f_cache)[i1] = f1;
	int i2;
	bool optimal = true;

	// ako element pripada skupu I_1 ili I_2  i nije zadovoljen uvijet optimalnosti
	// izracunaj b_up i i_up
	// inace ako element pripada skupu I_3 ili I_4 i nije zadovoljen uvijet optimalnosti
	// izracunaj b_low i i_low
	if (((y1==1 && alph1 ==0) || (y1==-1 && alph1 ==c)) && f1 < b_up) {
		b_up = f1;
		i_up = i1;
	}else if (((y1==1 && alph1 ==c) || (y1==-1 && alph1 ==0)) && f1 > b_low){
		b_low = f1;
		i_low = i1;
	}

	// provjera optimalnosti uz b_low i b_up i ako je prekrsena 
	// pronadi index i2 za zdruzenu optimmizacijus
	if (((y1==1 && alph1 ==0) || (y1==-1 && alph1 ==c))) {
		// provjera zadovoljenja optimalnosti
		if (b_low - f1>2*tol) {
			optimal = false;
			i2 = i_low;
		}
	}else if (((y1==1 && alph1 ==c) || (y1==-1 && alph1 ==0))){
		//provjera zadovoljenja optimalnosti
		if (f1 -b_up>2*tol) {
			optimal = false;
			i2 = i_up;
		}
	}
	// ako se element nalazi u skupu I_0 uzmi najbolji element 
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



bool smo::step(int i1, double f1, int i2){
	
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
			L = gamma - c;
			H = c;
		}else{
			L = 0;
			H = gamma;
		}
	}else {
		double gamma = alph1 - alph2;
		if (gamma > 0) {
			L = 0;
			H = c - gamma;
		}else{
			L = -gamma;
			H = c;
		}
	}
	if ( L == H ) 
		return false;
	double k12 = kern->calculate(elem->at(i1),elem->at(i2));
	double k11 = kern->calculate(elem->at(i1),elem->at(i1));
	double k22 = kern->calculate(elem->at(i2),elem->at(i2));
	double eta =(double)(2*k12 - k11 - k22);
	if (eta < 0) {
		a2 = alph2 +y2*(f2 - f1)/eta;
		if (a2<L) 
			a2 =L;
		else if (a2>H) 
			a2 =H;
	}else {
		double c1 = eta/2;
		double c2 = y2*(f1-f2) -eta*alph2;
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


	double t1 = y1*(a1-alph1);
	double t2 = y2*(a2-alph2);
	for (int i = 0; i <alpha->size(); i++) {
		if ((*alpha)[i] >0 && (*alpha)[i] < c){
			(*f_cache)[i] += t1*kern->calculate(elem->at(i1),elem->at(i))+t2*kern->calculate(elem->at(i2),elem->at(i));
		}
		(*f_cache)[i1] = f1 +t1*k11 + t2*k12;
		(*f_cache)[i2] = f2 +t1*k12 + t2*k22;

	}

	(*alpha)[i1] = a1;
	(*alpha)[i2] = a2;

	return 1;
}


PLagrange smo::optimize(PDElementi e, PYpsilon y, double ci, kernel *ken){
	kern = ken;
	elem = e;
	c = ci;
	ypsilon = y;
	i_up = i_low = -1;
	
	// inicijalizacija Lagrangeovih multiplikatora na sve 0
	// inicijalizacija f_cache
	// inicijalizacija i_up_i_low,b_up i b_low
	alpha = new Lagrange(elem->size(),0);
	f_cache = new std::vector<double>(elem->size());
	for (int i =0; i <ypsilon->size(); i++){ 
		(*f_cache)[i] = -(*ypsilon)[i];
		if ((*ypsilon)[i]==1 && i_up ==-1) i_up =i;
		if ((*ypsilon)[i]==-1 && i_low ==-1) i_low =i;
	}
	b_up =-1;
	b_low = 1;


	int number = 0;
	bool all = true;

	// trazenje elemenata za optimiranje
	while (number > 0 || all) {
		number = 0;
		if (all) {
			// prolazak po svima
			for(int i=0; i <alpha->size(); i++) 
				number += examine(i);
		}else {
			// prolazak po elementima kod koji pripadajuci multiplikator nije rubni (0 ili C)
			for(int i=0; i <alpha->size(); i++){
				if ((*alpha)[i] > 0 && (*alpha)[i]< c)
					number += examine(i);
				// provjera uspjesnosti optimizacije
				if (b_up > b_low - 2*tol) {
					number = 0;
					break;
				}
			}
		}
		if (all) 
			all = false;
		else if (number ==0) 
			all = true;
	}
	return alpha;
}
