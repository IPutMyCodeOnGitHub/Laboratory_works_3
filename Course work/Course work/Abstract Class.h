#include<fstream>
#include<iostream>
#include<cmath>

class object
{
public:
	object() {};
	virtual ~object() {};
	virtual void show() = 0;

	virtual void get() = 0;
	virtual int idetificate() { return(0); };
	virtual char* class_name() = 0;
	virtual int obj_cmp(object*, object*) = 0;
	virtual object* sum(object*, object*) = 0;
	virtual void bin_read(std::ifstream&) {};
	virtual void bin_write(std::ofstream&) {};
	virtual void text_read(std::ifstream&) {};
	virtual void text_write(std::ofstream&) {};
};


