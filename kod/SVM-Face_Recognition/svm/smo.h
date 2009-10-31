
// Sequential minimal optimization


#ifndef SMO_H
#define SMO_H

#include<vector>
#include<valarray>
#include<cmath>
#include<cstdio>


template<typename T>
class smo {
	typedef std::vector< std::valarray<T> > ELEMENTI;
	typedef std::valarray<int> YPSILON;
	private:
	
		std::vector<double>      *error_cache; // pogreske izracuna
		std::valarray<double>    *alpha;       // Lagrangeovi multiplikatori
		ELEMENTI				 *elem;
		YPSILON					 *ypsilon;
		double					 c;
		double					 tolerance;
		int examine(int i2);
		bool step(int i1,double e1,int i2);

	public:
		smo();
		smo(ELEMENTI* e, YPSILON *y);
		std::valarray<double>* find_alpha();
};

template<typename T>
smo<T>::smo() {
}

template<typename T>
smo<T>::smo(ELEMENTI *e, YPSILON *y) {
	elem = e;
	ypsilon = y;
	alpha = new valarray<double>(elem->size(),0);
	error_cache = new vector<double>(elem->size(),0);
}

template<typename T>
int smo<T>::examine(int i1){

	int y1 = (*elem)[i1];
	double alph1 = (*alpha)[i1];
	double e1 = (alph1 > 0 && alph1 < c)?(*error_cache)[i1]:function(i1) -y1;
	double r1 = y1*e1;
	if ((r<-tolerance && alph1<c) || (r> tolerance && alph1 >0)) {
		int i2=-1;
		double tmax=0;
		for (int k=0; k< alpha->size(); k++) {
			if ((*alpha)[k] >0 & (*alpha)[k] <c ) {
				double e2 = (*error_cache)[k];
				double tmp = fabs(e1-e2);
				if (tmp >tmax){
					tmax = tmp;
					i2 = k;
				}
			}
			if (i2>=0) {
				if (step(i1,i2));
				return 1;
			}
		}
		int k0 = (int)(rand()*alpha->size());
		for (int k=k0; k< alpha->size(); k++) {
			if ((*alpha)[k] >0 && (*alpha)[k] <c) {
				if (step(i1,k))
					return 1;
			}
		}
		for (int k=0; k<k0; k++) {
			if ((*alpha)[k]>0 && (*alpha)[k] <c) {
				if (step(i1,k))
					return 1;
			}
		}
		k0 = (int)(rand()*alpha->size());
		for (int k=k0; k< alpha->size(); k++) {
				if (step(i1,k))
					return 1;
		}
		for (int k=0; k<k0; k++) {
				if (step(i1,k))
					return 1;
		}
	}

}

template<typename T>
bool smo<T>::step(int i1, double e1, int i2){
	double a1, a2;
	double alph1 = (*alpha)[i1];
	double alph2 = (*alpha)[i2];
	int y1 = (*ypsilon)[i1];
	int y2 = (*ypsilon)[i2];
	double e2 = (alph2 > 0 && alph2 < c)?(*error_cache)[i2]:function(i2) -y2;
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
	std::valarray<T> x_1_2 = (*elem)[i1]*(*elem)[i2];
	std::valarray<T> x_1_1 = (*elem)[i1]*(*elem)[i1];
	std::valarray<T> x_2_2 = (*elem)[i2]*(*elem)[i2];
	double k12 = x_1_2.sum();
	double k11 = x_1_1.sum();
	double k22 = x_2_2.sum();
	double eta =(double)(2*k12 - k11 - k22);
	if (eta < 0) {
		a2 = alph2 +y2*(e2 - e1)/eta;
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
	if (fabs(a2 -alph2) < tolerance*(a2+alph2+eps))
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
	double b1, b2, bnew;
	if (a1 >0 && a1 <c) {
		bnew = b +e1+y1*(a1-alph1)*k11+y2*(a2-alph2)*k12;
	}else if (a2>0&& a2<c) {
		bnew = b+e2+y1*(a1-alph1)*k12+y2*(a2-alph2)*k22;
	}else {
		b1 = b +e1+y1*(a1-alph1)*k11+y2*(a2-alph2)*k12;
		b2 = b+e2+y1*(a1-alph1)*k12+y2*(a2-alph2)*k22;
		bnew = (b1+b2)/2;
	}
	delta_b = bnew - b;
	b = bnew;
	double t1 = y1*(a1-alph1);
	double t2 = y2*(a2-alph2);
	for (int i = 0; i <alpha->size(); i++) {
		if ((*alpha)[i] >0 && (*alpha)[i] < c){
			std::valarray<T> ko = (*elem)[i1]*(*elem)[i];
			std::valarray<T> no = (*elem)[i2]*(*elem)[i];
			(*error_cache)[i] += t1*ko.sum() +t2*no.sum() -delta_b;
		}
		(*error_cache)[i1] =0;
		(*error_cache)[i2] =0;

	}

	(*alpha)[i1] = a1;
	(*alpha)[i2] = a2;

	return 1;
}




#endif