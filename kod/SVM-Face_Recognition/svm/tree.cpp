#include "tree.h"


void node::add_left(node *l) {
	left =l;
}

void node::add_right(node *r) {
	right = r;
}

bool node::is_leaf() {
	return leaf;
}
void node::set_class(int cl) {
	cla = cl;
}

int node::get_class() {
	return cla;
}

void linear_node::create(PLagrange alpha, PDElementi elements, PYpsilon ypsilon, double c){

	for (int i = 0; i <alpha->size(); i++) {
		if (alpha->at(i) !=0) {
			Element tmp  = *(elements->at(i));
		    tmp *= alpha->at(i)*ypsilon->at(i);
			*w += tmp;
		}
	}
	int cnt =0;
	for (int i =0; i<alpha->size(); i++) {
		if (alpha->at(i) !=0 && alpha->at(i)!=c) {
			cnt++;
			Element tmp = (*w)*(*elements->at(i));
			b = (*ypsilon)[i] - tmp.sum();
		}
	}
	b/=(double)cnt;
}




task::task(node *no, std::vector<group*> *gr) {
	n = no;
	groups = gr;
}

std::vector<group*>* tree::process_initail(PSamples samples, int num){
	std::vector<group*> *tmp = new std::vector<group*>(num);
	for (int i=0; i<num; i++) 
		tmp->at(i)= new l_group(i);
	for (int i = 0; i<samples->size(); i++) 
		tmp->at(samples->at(i).second-1)->add_element(samples->at(i).first);
	return tmp;
}

void tree::process_task(){
	task* tmp = tasks.front();
	tasks.pop();
	if (tmp->groups->size()>1) {
		std::pair<c_group*, c_group*> g = algo->grouping(tmp->groups);
		PDElementi el1 = g.first->get_elements();
		PDElementi el2 = g.second->get_elements();
		PYpsilon y = new Ypsilon(el1->size()+el2->size(),1);
		for (int i=el1->size(); i<el1->size()+el2->size(); i++) (*y)[i] =-1;
		el1->insert(el1->end(),el2->begin(),el2->end());
		PLagrange alpha = optimizer->optimize(el1,y,c,ken);
		node *n = tmp->n;
		n->create(alpha,el1,y,c);
		node* n1 = ken->create_node();
		node* n2 = ken->create_node();
		tmp->n->add_left(n1);
		tmp->n->add_right(n2);
		task *t1 = new task(n1,g.first->get_groups());
		task *t2 = new task(n2,g.second->get_groups());
		tasks.push(t1);
		tasks.push(t2);
	}else if (tmp->groups->size()==1) {
		tmp->n->set_class(tmp->groups->at(0)->get_class());
	}
	delete tmp;
}

node* tree::train(kernel* ker, algorithm *al, PSamples samp, double ci, int num){
	ken = ker;
	c =ci;
	algo = al;
	optimizer = new smo();
	node* n = ker->create_node();
	task *t = new task();
	t->n = n;
	t->groups = process_initail(samp,num);
	tasks.push(t);
	while (!tasks.empty()) 
		process_task();
	return n;
}