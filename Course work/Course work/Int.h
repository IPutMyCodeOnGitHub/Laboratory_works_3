#pragma once
#include"Intln.h"

class Int : public object
{
private:
	int dat;
public:
	Int();
	Int(int);
	//Int(const Int &n);
	~Int();
	void show(); //вывод объекта классса, виртуальная ф
	void get();
	int indificate(); //получение уникального идентификатора класса
	char* class_name();//строка с именем класса
	int obj_cmp(object*, object*);//сравнение двух объектов 
	object* sum(object*, object*);//сложение двух объектов 
	void text_read(std::ifstream&);///чтение из текстового файла
	void text_write(std::ofstream&);//запись в текстовый файл
	void bin_read(std::ifstream&);//чтение из бинарного файла
	void bin_write(std::ofstream&);//запись в бинарный файл

	Int& operator=(const Int& n);
	Int operator+(const Int& right);
	friend Int operator-(const Int& left, const Int& right);

	Int& operator++();
	Int operator++(int);

	friend std::ostream& operator<<(std::ostream& os, Int& numb);
	friend std::istream& operator >> (std::istream& is, Int& numb);
	friend std::ofstream& operator<<(std::ofstream& os, Int& numb);
	friend std::ifstream& operator >> (std::ifstream& is, Int& numb);
};


Int::Int()
{
	dat = 0;
}

Int::Int(int n)
{
	dat = n;
}

Int::~Int()
{
	dat = 0;
}

void Int::show()
{
	std::cout << dat << " ";
	std::cout  << class_name() << " " << std::endl;
}

void Int::get()
{
	std::cin >> *this;
}

int Int::indificate()
{
	return 2;
}

char* Int::class_name()
{
	char* name = new char[4];
	name = "Int";
	return name;
}

void Int::text_read(std::ifstream& text_f)
{
	text_f >> *this;
}

void Int::text_write(std::ofstream& text_f)
{
	int identificator = indificate();
	text_f << " " << identificator << " ";
	text_f << *this;
}

void Int::bin_read(std::ifstream& bin_f)
{
	bin_f.read((char*)&dat, sizeof(int));
}

void Int::bin_write(std::ofstream& bin_f)
{
	int identificator = indificate();
	bin_f.write((char*)&identificator, sizeof(int));
	bin_f.write((char*)&dat, sizeof(int));
}

Int& Int::operator=(const Int& n)
{
	dat = n.dat;
	return *this;
}

Int Int::operator+(const Int & right)
{
	Int res;
	res.dat = this->dat + right.dat;
	return res;
}

Int& Int::operator++()
{
	this->dat = this->dat + 1;
	return *this;
}

Int Int::operator++(int)
{
	Int temp = *this;
	++*this;
	return temp;
}

int Int::obj_cmp(object* n1, object* n2)
{
	if (((Int*)n1)->dat > ((Int*)n2)->dat) return 1;
	if (((Int*)n1)->dat < ((Int*)n2)->dat) return -1;
	else return 0;
}

object* Int::sum(object* n1, object* n2)
{
	object* res = new Int(0);
	((Int*)res)->dat += ((Int*)n1)->dat;
	((Int*)res)->dat += ((Int*)n2)->dat;
	dat = ((Int*)res)->dat;
	return res;
}

Int operator-(const Int& left, const Int& right)
{
	Int res;
	res.dat = left.dat - right.dat;
	return res;
}

std::ostream& operator<<(std::ostream& os, Int& numb)
{
	os << numb.dat;
	return os;
}

std::istream& operator >> (std::istream& is, Int& numb)
{
	is >> numb.dat;
	return is;
}

std::ofstream& operator<<(std::ofstream& os, Int& numb)
{
	os << numb.dat;
	return os;
}

std::ifstream& operator >> (std::ifstream& is, Int& numb)
{
	is >> numb.dat;
	return is;
}

