#ifndef TREE_H
#define TREE_H


#include "classifier.h"
#include "solver.h"

class kernel;
class solver;

class node {
protected:
	node *left; //lijevo dijete
	node *right; //desno dijete
	bool leaf; // je li cvor list
	int  cla;  // broj klase 
public:
	node() : left(NULL), right(NULL),leaf(false) {}
   ~node(); 
    virtual bool is_leaf();
	virtual node* next(PElement e) = 0;
	virtual void add_left(node* l);
	virtual void add_right(node* r);
	virtual void create(PLagrange alpha, PDElementi elements, PYpsilon ypsilon, double c) = 0;
	virtual void set_class(int cl);
	virtual int get_class();
	virtual void save(std::ostream &out, std::queue<node*> &q) = 0;
	virtual void load(std::istream& in, std::queue<node*> &q) = 0;
};


class linear_node: public node{
private:
	double b;
	PElement w;
public:
	linear_node():node(){}
	~linear_node();
	node* next(PElement e);
	void create(PLagrange alpha, PDElementi elements, PYpsilon ypsilon, double c);
	void save(std::ostream &out, std::queue<node*> &q);
	void load(std::istream& in, std::queue<node*> &q) ;
};



class nonlinear_node : public node {
private:
	PLagrange lag;   // spremnik za LAgrangeove multiplikatore mnozene s y
	PDElementi sv;   // spremnik za potpornje vektore
	kernel *ken;     // koristeni kernel
	double b;

	double calculate(PElement e);
public:
	nonlinear_node():node(){}
	nonlinear_node(kernel* k):ken(k),node(){}
	~nonlinear_node();
	node* next(PElement e);
	void create(PLagrange alpha, PDElementi elements, PYpsilon ypsilon, double c);
	void save(std::ostream &out, std::queue<node*> &q);
	void load(std::istream& in, std::queue<node*> &q);
};



/* zadatak koji se koristi prilikom izgradnje stabla odluke
 */
class task {
public:
	task(){};
	task(node *no,std::vector<group*> *gr); 
	node* n;
	std::vector<group*> *groups;
};

/* razred koji se brine za izgradnju stabla odluke, ne predstavlja samo stablo 
   nego prilikom njegove izgradnje vraca pokazivac na korijen
 */
class tree {
private:
	algorithm *algo;
	std::queue<task*> tasks;
	solver *optimizer;
	kernel *ken;
	double c;
public:
	std::vector<group*>* process_initail(PSamples samples, int num); 
	void process_task(); 
	node* train(kernel* ker, algorithm *al, PSamples samp, double ci, int num); 
};
#endif