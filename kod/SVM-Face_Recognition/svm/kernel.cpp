#include "kernel.h"

double linear_kernel::calculate(PElement i, PElement j){
	Element tmp = (*i)*(*j);
	return tmp.sum();
}

node* linear_kernel::create_node(){
	return new linear_node();
}
