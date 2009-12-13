#ifndef SOLVER_H
#define SOLVER_H

#include "base.h"
#include "kernel.h"

class kernel;

class solver {
	
	private:
	
		std::vector<double>      *gradient;     // pogreske izracuna
		PLagrange			     alpha;       // Lagrangeovi multiplikatori
		PDElementi				 elem;
		PYpsilon				 ypsilon;
		double					  c;
		double					  eps;
		double					  tau;
		kernel					  *kern;
		double						*Q;  //kernel matrica
		bool					    *Qi;
		
		void select(int *i, int *j);
		inline double get_kernel(int i, int j);
		void	evaluate_kernel_matrix();
		void	free_kernel_matrix();
	public:
		solver(){eps = 10E-4;tau = 10E-12;};
		//smo(kernel *ken);
		PLagrange optimize(PDElementi e, PYpsilon y, double ci, kernel *ken);
};




#endif