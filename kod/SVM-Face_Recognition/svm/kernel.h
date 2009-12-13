#ifndef KERNEL_H
#define KERNEL_H

#include "base.h"
#include "tree.h"
class node; 

class kernel {

public:
	virtual double calculate(PElement i, PElement j) = 0;
	virtual node* create_node() = 0;

};

class linear_kernel: public kernel{

public:
	double calculate(PElement i, PElement j);
	node* create_node();
};

class rbf_kernel: public kernel {
private:
		double gamma;
public:
	rbf_kernel():gamma(1){}
	rbf_kernel(double g):gamma(g){}
	double calculate(PElement i, PElement j);
	node* create_node();
};

class poly_kernel: public kernel {
private:
		double d;
public:
	poly_kernel():d(1){}
	poly_kernel(double p):d(p){}
	double calculate(PElement i, PElement j);
	node* create_node();
};

#endif