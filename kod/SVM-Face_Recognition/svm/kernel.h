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

#endif