#ifndef TREE_H
#define TREE_H

#include "base.h"

class node {
public:
	virtual bool is_leaf() = 0;
	virtual node* next() = 0;
	virtual void create(std::vector<double>* alpha, Elementi* suports) = 0;
};

class linear_node: public node{
private:
	linear_node *left;
	linear_node *right;
public:
	bool is_leaf();
	node* next();
	void create(std::vector<double>* alpha, Elementi* suports);
};

class nonlinear_node : public node {
private:
	nonlinear_node *left;
	nonlinear_node *right;
public:
	bool is_leaf();
	node* next();
	void create(std::vector<double>* alpha, Elementi* suports);
};


class tree {
}
#endif