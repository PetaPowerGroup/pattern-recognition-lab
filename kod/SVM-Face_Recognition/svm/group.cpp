
#include "group.h"


/* konstruktor
 */
l_group::l_group() {
	number = 0;
}

/* konstruktor
 */
l_group::l_group(int cid) {
	//elements = new std::vector<Element*>();
	number = 0;
	id = cid;
}

/* destruktor
 */
l_group::~l_group() {
	delete elements;
	delete center;
}

bool l_group::add_element(PElement e){
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

c_group::~c_group() {
	delete center;
	delete groups;
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
	throw new std::string("Ne mogu dohvatiti id grupe ovo je kompozit");
	return 0;
}

int c_group::get_number_elements(){
	return number_elements;
}

int c_group::get_number_groups() {
	return number_groups;
}

/* u kompozit se nemoze dodati pojedini element
 */
bool c_group::add_element(Element *e){
	return false;
}

bool c_group::add_group(group *gr){
	if (number_groups == 0) {
		groups = new std::vector<group*>();
		center = new Element();
		*center = *(gr->get_center());
		number_elements = gr->get_number_elements();
		number_groups = 1;
	}else {
		(*center)*=number_groups;
		(*center)+=(*gr->get_center());
		number_groups++;
		number_elements +=gr->get_number_elements();
		(*center)/=number_groups;
	}
	groups->push_back(gr);
	return true;
}

PDElementi c_group::get_elements() {
	PDElementi tmp = new PPElementi(number_elements);
	PPElementi::iterator cpy = tmp->begin();
	std::vector<group*>::iterator it;
	for (it = groups->begin(); it!=groups->end(); it++) 
		cpy = std::copy((*it)->get_elements()->begin(),(*it)->get_elements()->end(),cpy);
	return tmp;
}

std::vector<group*> * c_group::get_groups() {
	std::vector<group*> *tmp = new std::vector<group*>(groups->size());
	std::copy(groups->begin(),groups->end(),tmp->begin());
	return tmp;
}


/* euklidska udaljenost izmedu dva elementa
 */
double algorithm::distance(PElement i, PElement j){
	Element tmp = *i - *j;
	tmp = pow(tmp,2.);
	double d = tmp.sum();
	return sqrt(d);
}

/* algoritam grupiranja
 */
std::pair<c_group*,c_group*> alg1::grouping(std::vector<group*> *grps){
	int a;
	int b;
	double tmp = -1;
	c_group* first = new c_group();
	c_group* second = new c_group();


	// trazenje dvije grupe koje su najudaljenije
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

	// dodavanje ostalih grupa u blizi cluster
	for (int i=0; i<grps->size(); i++) {
		if (i ==a || i == b) continue;

		// racunanje udaljenosti
		double dist1 = distance(grps->at(i)->get_center(),first->get_center());
		double dist2 = distance(grps->at(i)->get_center(),second->get_center());

		// ako je grupa bliza clusteru 2 dodaj grupu u cluster 2 inace u cluster 1
		if (dist1>dist2) 
			second->add_group(grps->at(i));
		else 
			first->add_group(grps->at(i));
	}
	return std::make_pair<c_group*,c_group*>(first,second);
}
