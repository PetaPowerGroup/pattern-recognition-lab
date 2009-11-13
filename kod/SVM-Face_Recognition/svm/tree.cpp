#include "tree.h"

node::~node() {
	delete left;
	delete right;
}

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
	leaf = true;
	cla = cl;
}

int node::get_class() {
	return cla;
}

linear_node::~linear_node() {
	delete left;
	delete right;
	delete w;
}

/* cvor se puni podacima i ovisno o tipu cvora pohranjuje odredene podatke
 */
void linear_node::create(PLagrange alpha, PDElementi elements, PYpsilon ypsilon, double c){

	// w = sum (alpha(i)*y()*x(i))
	w = new Element(elements->at(0)->size());
	for (int i = 0; i <alpha->size(); i++) {
		if (alpha->at(i)!=0) {
			Element tmp  = *(elements->at(i));
		    tmp *= alpha->at(i)*ypsilon->at(i);
			*w += tmp;
		}
	}

	// b = (1/cnt) * sum(y(i)-w*x(i))
	int cnt =0;
	for (int i =0; i<alpha->size(); i++) {
		if (alpha->at(i) !=0 && alpha->at(i)!=c) {
			cnt++;
			Element tmp = (*w)*(*elements->at(i));
			b = (*ypsilon)[i] - tmp.sum();
		}
	}
	if (cnt==0)
		b = 0;
	else
		b/=(double)cnt;
}

/* funkcjia radi klasifikaciju i vraca odredeni cvor dijete
 */
node* linear_node::next(PElement e){
	if (leaf)
		return NULL;
	Element tmp = (*w)*(*e);
	double dx = tmp.sum() + b;
	if (dx > 0) 
		return left;
	else if (dx < 0) 
		return right;
	else 
		return NULL;
}


task::task(node *no, std::vector<group*> *gr) {
	n = no;
	groups = gr;
}

/* funkcija koja prima uzorke i broj razreda i stvara 
   toliki broj grupa</br>
   <i>samples</i> - uzorci </br>
   <i>num</i> - broj razreda
 */
std::vector<group*>* tree::process_initail(PSamples samples, int num){
	std::vector<group*> *tmp = new std::vector<group*>(num);

	for (int i=0; i<num; i++) 
		tmp->at(i)= new l_group(i+1);
	// dodavanje uzoraka u odredene grupe
	for (int i = 0; i<samples->size(); i++) 
		tmp->at(samples->at(i).second-1)->add_element(samples->at(i).first);
	return tmp;
}
/*	funkcija za obradu pojedinog zadataka iz reda
 */
void tree::process_task(){
	// dohvati zadatak
	task* tmp = tasks.front();
	tasks.pop();


	if (tmp->groups->size()>1) {
		
		// grupiranje
		std::pair<c_group*, c_group*> g = algo->grouping(tmp->groups);
		
		// dohvacanje elemenat prve i druge grupe
		// i stvaranje niza ypsilon
		PDElementi el1 = g.first->get_elements();
		PDElementi el2 = g.second->get_elements();
		PYpsilon y = new Ypsilon(el1->size()+el2->size(),1);
		for (int i=el1->size(); i<el1->size()+el2->size(); i++) (*y)[i] =-1;
		el1->insert(el1->end(),el2->begin(),el2->end());

		// optimzacija
		PLagrange alpha = optimizer->optimize(el1,y,c,ken);
		node *n = tmp->n;

		// predavanje izracunatih podataka cvoru
		// i stvaranej dva cvora djeteta
		n->create(alpha,el1,y,c);
		node* n1 = ken->create_node();
		node* n2 = ken->create_node();
		tmp->n->add_left(n1);
		tmp->n->add_right(n2);

		// stvaranje dva nova zadatka za optimizaciju i 
		// njihovo dodavanje u red
		task *t1 = new task(n1,g.first->get_groups());
		task *t2 = new task(n2,g.second->get_groups());
		tasks.push(t1);
		tasks.push(t2);

		delete el1;
		delete el2;
		delete alpha;
		delete y;

	}else if (tmp->groups->size()==1) {
		// u nizu grupa je samo jedna grupa pa nije potrebno grupiranje i optimizacija
		// nego taj cvor nosi oznaku te odredene grupe
		tmp->n->set_class(tmp->groups->at(0)->get_class());
		delete tmp->groups->at(0);
	}
	delete tmp;
}

/* funkcija za treniranje 
   vraca korijen stabla odluke
 */
node* tree::train(kernel* ker, algorithm *al, PSamples samp, double ci, int num){
	
	// inicijalizacija kernel-a , konstante C i algoritma grupiranja
	// stvaranje optimizatora
	ken = ker;
	c =ci;
	algo = al;
	optimizer = new smo();

	// korijen stabla i pocetni zadatak
	node* n = ker->create_node();
	task *t = new task();
	t->n = n;
	t->groups = process_initail(samp,num);
	tasks.push(t);

	// procesiranje zadataka koji se nalaze u redu na cekanju
	// mogucnost paralenog rjesenja
	while (!tasks.empty()) 
		process_task();

	delete optimizer;
	
	return n;
}