#ifndef GROUP_H
#define GROUP_H


#include "base.h"

class group {
public:
	virtual PElement get_center() = 0;
	virtual PDElementi get_elements() = 0;
	virtual bool has_single() = 0;
	virtual int get_number_elements() = 0;
	virtual bool add_element(PElement e) = 0;
	virtual int get_class() = 0;
};

/* razred koji predstavlja jednu grupu elemenata
 */
class l_group : public group {
private:
	PElement center;
	int number;
	PDElementi elements;
	int id;
public:
	l_group();
	l_group(int cid);
	~l_group();
    PElement get_center();
    PDElementi get_elements();
    bool has_single();
    int get_number_elements();
    bool add_element(PElement e);
	int get_class();
};

/* kompozit grupa 
 */
class c_group : public group {
private:
	PElement center;
	int number_groups;
	int number_elements;
	std::vector<group*> *groups;
public:
	c_group();
	~c_group();
	PElement get_center();
    PDElementi get_elements();
	std::vector<group*> *get_groups();
    bool has_single();
    int get_number_elements();
    bool add_element(Element *e);
	bool add_group(group *gr);
	int get_class();
};


/* algoritam grupiranja
 */
class algorithm {
public:
	virtual std::pair<c_group*,c_group*> grouping(std::vector<group*> *grps) = 0;
protected:
	double distance(PElement i, PElement j); 
};

/* algoritam grupiranja temeljen na euklidskoj udaljenosti izmedu grupa
 */
class alg1 : public algorithm {
public:
 std::pair<c_group*,c_group*> grouping(std::vector<group*> *grps);
};


#endif