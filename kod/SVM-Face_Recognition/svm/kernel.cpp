#include "kernel.h"

double linear_kernel::calculate(PElement i, PElement j){
	Element tmp = (*i)*(*j);
	return tmp.sum();
}

node* linear_kernel::create_node(){
	return new linear_node();
}

double rbf_kernel::calculate(PElement i, PElement j){
	Element tmp = (*i)-(*j);
	tmp = pow(tmp,2.0);
	return exp(-gamma* tmp.sum());
}

node* rbf_kernel::create_node(){
	return new nonlinear_node(this);
}

double poly_kernel::calculate(PElement i, PElement j){
	Element tmp = (*i)*(*j);
	return pow(tmp.sum()+1,d);
}

node* poly_kernel::create_node(){
	return new nonlinear_node(this);
}
