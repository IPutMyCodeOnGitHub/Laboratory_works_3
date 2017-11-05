#pragma once
#include<iostream>
#include<cmath>
#include<fstream>
#include"Intln.h"

class Ilnnt : public Intln {
private:
	bool order;
public:
	Ilnnt();
	Ilnnt(int e, char* m);
	Ilnnt(Ilnnt &n);

	~Ilnnt();

	void Show();
	friend ostream& operator<<(ostream& os, Ilnnt& numb);
	friend istream& operator >> (istream& is, Ilnnt& numb);
	void Sort(); //сортировка по возрастанию
};
