#ifndef GROUP_H
#define GROUP_H

#include "base.h"

class group {
public:
	virtual Element* get_center() = 0;
	virtual Elementi* get_elements() = 0;
	virtual bool has_single() = 0;
	virtual int get_number_elements() = 0;
	virtual bool add_element(Element *e) = 0;
	virtual int get_class() = 0;
};

class l_group : public group {
private:
	Element* center;
	int number;
	Elementi* elements;
	int id;
public:
	l_group();
	l_group(int cid);
	~l_group();
    Element* get_center();
    Elementi* get_elements();
    bool has_single();
    int get_number_elements();
    bool add_element(Element *e);
	int get_class();
};

class c_group : public group {
private:
	Element* center;
	int number_groups;
	int number_elements;
	std::vector<group*> groups;
public:
	c_group();
	Element* get_center();
    Elementi* get_elements();
    bool has_single();
    int get_number_elements();
    bool add_element(Element *e);
	bool add_group(group *gr);
	int get_class();
};


class algorithm {
public:
	virtual std::pair<c_group*, c_group*> group(std::vector<group*> *grps) = 0;
private:
	double distance(Element& i, Element& j); 
};

class alg1 : public algorithm {
public:
	std::pair<c_group*, c_group*> group(std::vector<group*> *grps) ;
};


#endif