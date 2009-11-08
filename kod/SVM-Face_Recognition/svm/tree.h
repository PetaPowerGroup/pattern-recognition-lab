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
	node *left;
	node *right;
	bool leaf;
	int  cla;
public:
    virtual bool is_leaf();
	//virtual node* next(PElement e) = 0;
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
	//node* next(PElement e);
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

class task {
public:
	task(){};
	task(node *no,std::vector<group*> *gr); 
	node* n;
	std::vector<group*> *groups;
};

class tree {
private:
	algorithm *algo;
	std::queue<task*> tasks;
	smo *optimizer;
	kernel *ken;
	double c;
public:
	std::vector<group*>* process_initail(PSamples samples, int num); // stvara poèetnu grupu
	void process_task(); //obradjuje pojedini zadatak iz reda
	node* train(kernel* ker, algorithm *al, PSamples samp, double ci, int num); // stvara stablo odluke i vraca cvor na korijen
};
#endif