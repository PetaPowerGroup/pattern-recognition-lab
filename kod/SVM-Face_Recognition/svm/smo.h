// Optimizator za SVM. Temelji se na SMO metodi predloženoj od Platt. 
// Implementirano je takoðer i podoljsanje predloženo od ...

#ifndef SMO_H
#define SMO_H



#include "kernel.h"

class kernel;

class smo {
	
	private:
	
		std::vector<double>      *f_cache;     // pogreske izracuna
		PLagrange			     alpha;       // Lagrangeovi multiplikatori
		PDElementi				 elem;
		PYpsilon					 ypsilon;
		double					  c;
		double					  eps;
		double					  b_up;
		double					  b_low;
		int						i_up;
		int						i_low;
		double						*Q;  //kernel matrica
		bool					    *Qi;
		double tol;
		int examine(int i2);
		bool step(int i1,int i2);
		kernel *kern;
		double function(int i);
		inline double get_kernel(int i, int j);
		void	evaluate_kernel_matrix();
		void	free_kernel_matrix();

	public:
		smo(){eps = tol = 10E-3;};
		//smo(kernel *ken);
		PLagrange optimize(PDElementi e, PYpsilon y, double ci, kernel *ken);
};




#endif