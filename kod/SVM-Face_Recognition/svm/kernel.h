#ifndef KERNEL_H
#define KERNEL_H

#include "base.h"

class kernel {

public:
	virtual double calculate(Element &i, Element &j) = 0;

};

class linear_kernel: public kernel{

public:
	double calculate(Element &i, Element &j);

};

#endif