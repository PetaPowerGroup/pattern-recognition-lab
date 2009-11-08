
#include "group.h"


l_group::l_group() {
	number = 0;
}

l_group::l_group(int cid) {
	//elements = new std::vector<Element*>();
	number = 0;
	id = cid;
}

l_group::~l_group() {
	delete elements;
}

bool l_group::add_element(Element *e){
	if (number == 0) {
		center = new Element(e->size());
		elements = new PPElementi();
		*center = *e;
		number++;
	}else {
		(*center)*= number;
		(*center)+= (*e);
		 number++;
		(*center)/=number;
	}
	elements->push_back(e);
	return true;
}

int l_group::get_class(){
	return id;
}

bool l_group::has_single(){
	return true;
}

int l_group::get_number_elements(){
	return number;
}

PElement l_group::get_center(){
	return center;
}

PDElementi l_group::get_elements() {
	return elements;
}





c_group::c_group() {
	number_elements =0;
	number_groups =0;
}

PElement c_group::get_center(){
	return center;
}

bool c_group::has_single(){
	if (number_groups==1) 
		return true;
	return false;
}

int c_group::get_class() {
	throw new std::string("Ne mogu dohvatiti id grupe");
	return 0;
}

int c_group::get_number_elements(){
	return number_elements;
}


bool c_group::add_element(Element *e){
	return false;
}
bool c_group::add_group(group *gr){
	if (number_groups == 0) {
		center = new Element();
		*center = *(gr->get_center());
		number_elements = gr->get_number_elements();
		number_groups = 1;
	}else {
		(*center)*=number_groups;
		(*center)+=(*gr->get_center());
		number_groups++;
		(*center)/=number_groups;
	}
	groups.push_back(gr);
	return true;
}

PDElementi c_group::get_elements() {
	PDElementi tmp = new PPElementi(number_elements);
	PPElementi::iterator cpy = tmp->begin();
	std::vector<group*>::iterator it;
	for (it = groups.begin(); it!=groups.end(); it++) 
		cpy = std::copy((*it)->get_elements()->begin(),(*it)->get_elements()->end(),cpy);
	return tmp;
}

std::vector<group*> * c_group::get_groups() {
	std::vector<group*> *tmp = new std::vector<group*>(groups.size());
	std::copy(groups.begin(),groups.end(),tmp->begin());
	return tmp;
}



double algorithm::distance(PElement i, PElement j){
	Element tmp = *i - *j;
	tmp = pow(tmp,2.);
	double d = tmp.sum();
	return sqrt(d);
}

std::pair<c_group*,c_group*> alg1::grouping(std::vector<group*> *grps){
	int a;
	int b;
	double tmp = 0;
	c_group* first = new c_group();
	c_group* second = new c_group();


//trazenje dvije grupe koje su najudaljenije
	for (int i=0; i<grps->size()-1; i++) {
		for (int j=i+1; j<grps->size(); j++) {
			double dist = distance(grps->at(i)->get_center(),grps->at(j)->get_center());
			if (dist>tmp) {
				tmp = dist;
				a = i;
				b = j;
			}
		}
	}
	first->add_group(grps->at(a));
	second->add_group(grps->at(b));
	for (int i=0; i<grps->size(); i++) {
		if (i ==a || i == b) continue;
		double dist1 = distance(grps->at(i)->get_center(),first->get_center());
		double dist2 = distance(grps->at(i)->get_center(),second->get_center());
		if (dist1>dist2) 
			second->add_group(grps->at(i));
		else 
			first->add_group(grps->at(i));
	}
	return std::make_pair<c_group*,c_group*>(first,second);
}
