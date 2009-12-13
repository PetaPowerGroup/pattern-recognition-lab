
#include "solver.h"



void solver::evaluate_kernel_matrix() {
	int size = elem->size();
	Q = new double[size*size];
	Qi = new bool[size*size];
	for (int i=0; i<size; i++) {
		for (int j=i; j<size; j++) {
			Qi[i*size+j] = false;
			Qi[j*size+i] = false;
		}
	}
}

void solver::free_kernel_matrix() {
	delete [] Q;
	delete [] Qi;

}

double solver::get_kernel(int i, int j){
	if (!Qi[i*elem->size()+j]){
		double tmp = kern->calculate(elem->at(i),elem->at(j));
		Q[i*elem->size()+j] = tmp;
		Q[j*elem->size()+i] = tmp;
		Qi[i*elem->size()+j] = true;
		Qi[j*elem->size()+i] = true;
	}
		return Q[i*elem->size()+j];
}

void solver::select(int *i, int *j){

	*i = -1;
	double G_max = -std::numeric_limits<double>::infinity();
	double G_min = std::numeric_limits<double>::infinity();
	for (int t = 0; t<gradient->size(); t++) {
		if(((*ypsilon)[t] == 1 && (*alpha)[t] <c) || ((*ypsilon)[t] == -1 && (*alpha)[t]>10E-12)){
			if (-(*ypsilon)[t]*(*gradient)[t] >= G_max) {
				*i = t;
				G_max = -(*ypsilon)[t]*(*gradient)[t];
			}
		}
	}

	*j = -1;
	double obj_min = std::numeric_limits<double>::infinity();
	for (int t = 0; t<gradient->size(); t++) {
		if(((*ypsilon)[t] == 1 && (*alpha)[t] >10E-12) || ((*ypsilon)[t] == -1 && (*alpha)[t]<c)){
			double b = G_max +(*ypsilon)[t]*(*gradient)[t];
			if (-(*ypsilon)[t]*(*gradient)[t] <= G_min) {
				G_min = -(*ypsilon)[t]*(*gradient)[t];
			}
			if (b>0) {
				double kii = get_kernel(*i,*i);//kern->calculate(elem->at(*i),elem->at(*i));
				double ktt = get_kernel(t,t);//kern->calculate(elem->at(t),elem->at(t));
				double kit = get_kernel(*i,t);//kern->calculate(elem->at(*i),elem->at(t));
				double a = kii +ktt - 2*(*ypsilon)[*i]*(*ypsilon)[t]*kit;
				if (a<=0) 
					a = tau;
				if (-(b*b)/a <= obj_min) {
					*j =t;
					obj_min = -(b*b)/a;
				}
			}
		}
	}

	if (G_max - G_min < eps) {
		*i =-1;
		*j =-1;
	}
}

PLagrange solver::optimize(PDElementi e, PYpsilon y, double ci, kernel *ken){
	kern = ken;
	elem = e;
	c = ci;
	ypsilon = y;
	std::cout<<"Generiram kernel matricu\n";
	evaluate_kernel_matrix();
	std::cout<<"Matrica generirana\n";
	// inicijalizacija Lagrangeovih multiplikatora na sve 0
	// inicijalizacija gradienta na -1
	alpha = new Lagrange(elem->size(),0);
	gradient = new std::vector<double>(elem->size(),-1);
	int i,j;
	while(1) {
		long int t1 = time(NULL);
		select(&i, &j);
		long int t2 = time(NULL);
		//std::cout<<i<<" "<<j<<"vrijeme "<<t2-t1<<" milisekundi\n";
		if (j==-1) break;

		//ovo bi moglo biti sporo
		double kii = get_kernel(i,i);//kern->calculate(elem->at(i),elem->at(i));
		double kjj = get_kernel(j,j);//kern->calculate(elem->at(j),elem->at(j));
		double kij = get_kernel(i,j);//kern->calculate(elem->at(i),elem->at(j));
		double a =kii + kjj - 2*(*ypsilon)[i]*(*ypsilon)[j]*kij;
		
		if (a < tau) 
			a = tau;
		double b = -(*ypsilon)[i]*(*gradient)[i] +(*ypsilon)[j]*(*gradient)[j];

		//update Lagrangea
		double oldAi = (*alpha)[i];
		double oldAj = (*alpha)[j];
		(*alpha)[i] += (*ypsilon)[i]*b/a;
		(*alpha)[j] -= (*ypsilon)[j]*b/a;

		// dozvoljeno podrucje 0<= alpha <= c
		double sum = (*ypsilon)[i]*oldAi + (*ypsilon)[j]*oldAj;
		if ((*alpha)[i]>c) 
			(*alpha)[i] = c;
		if ((*alpha)[i]<0) 
			(*alpha)[i] = 0;
		(*alpha)[j] = (*ypsilon)[j]*(sum-(*ypsilon)[i]*(*alpha)[i]);
		if ((*alpha)[j]>c) 
			(*alpha)[j] = c;
		if ((*alpha)[j]<0) 
			(*alpha)[j] = 0;
		(*alpha)[i] = (*ypsilon)[i]*(sum-(*ypsilon)[j]*(*alpha)[j]);

		//update gradient
		double deltaAi = (*alpha)[i] - oldAi;
		double deltaAj = (*alpha)[j] - oldAj;

		for (int t=0; t<gradient->size(); t++){
			double kti = (*ypsilon)[t]*(*ypsilon)[i]*get_kernel(t,i);//(*ypsilon)[t]*(*ypsilon)[i]*kern->calculate(elem->at(t),elem->at(i));
			double ktj = (*ypsilon)[t]*(*ypsilon)[j]*get_kernel(t,j);//(*ypsilon)[t]*(*ypsilon)[j]*kern->calculate(elem->at(t),elem->at(j));
			(*gradient)[t] += kti*deltaAi +ktj*deltaAj;
		}
	}
	free_kernel_matrix();
	return alpha;
}