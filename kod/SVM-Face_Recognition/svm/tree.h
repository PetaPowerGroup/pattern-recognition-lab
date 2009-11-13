#ifndef TREE_H
#define TREE_H

//#include "group.h"
#include "classifier.h"

class kernel;
/*
class group;
class l_group;
class c_group;
class algorithm;
*/
class smo;
class node {
protected:
	node *left; //lijevo dijete
	node *right; //desno dijete
	bool leaf; // je li cvor list
	int  cla;  // roj klase 
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
};

/*
class nonlinear_node : public node {
private:
	nonlinear_node *left;
	nonlinear_node *right;
public:
	bool is_leaf();
	node* next();
	void create(std::vector<double>* alpha, Elementi* suports);
};

*/


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
	smo *optimizer;
	kernel *ken;
	double c;
public:
	std::vector<group*>* process_initail(PSamples samples, int num); 
	void process_task(); 
	node* train(kernel* ker, algorithm *al, PSamples samp, double ci, int num); 
};
#endif