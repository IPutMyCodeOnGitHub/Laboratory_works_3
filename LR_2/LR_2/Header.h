#pragma once
#include<iostream>
#include <cmath>

using namespace std;

class Intln {
private:
	int exponent;
	char* mantissa;

public:
	Intln();

	Intln(int e, char* m);

	Intln(Intln &n);

	~Intln();

	friend char* Get_str_numb();

	void Show();

	Intln& operator=(const Intln& n);

	Intln operator+(const Intln& right);

	friend Intln operator-(const Intln& left, const Intln& right);

	operator long();

	Intln& operator++(); //префиксная форма оператора

	Intln operator++(int); //постфиксная форма оператора
};
