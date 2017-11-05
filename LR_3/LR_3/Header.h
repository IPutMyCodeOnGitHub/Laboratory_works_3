#pragma once
#include<iostream>
#include<cmath>
#include<fstream>

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

	Intln& operator=(const Intln& n);

	Intln operator+(const Intln& right);
	friend Intln operator-(const Intln& left, const Intln& right);

	operator long();

	Intln& operator++(); //префиксная форма оператора
	Intln operator++(int); //постфиксная форма оператора

	friend ostream& operator<<(ostream& os, Intln& numb);//перегрузка оператора вывода в поток
	friend istream& operator >> (istream& is, Intln& numb); //перегрузка оператора ввода в поток

	friend ofstream& operator<<(ofstream& os, Intln& numb);//перегрузка оператора вывода в файловый поток
	friend ifstream& operator >> (ifstream& is, Intln& numb);//перегрузка оператора ввода в файловый поток

	void bin_read(ifstream& bin_f);
	void bin_write(ofstream& bin_f);
};
