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

	Intln& operator++(); //���������� ����� ���������
	Intln operator++(int); //����������� ����� ���������

	friend ostream& operator<<(ostream& os, Intln& numb);//���������� ��������� ������ � �����
	friend istream& operator >> (istream& is, Intln& numb); //���������� ��������� ����� � �����

	friend ofstream& operator<<(ofstream& os, Intln& numb);//���������� ��������� ������ � �������� �����
	friend ifstream& operator >> (ifstream& is, Intln& numb);//���������� ��������� ����� � �������� �����

	void bin_read(ifstream& bin_f);
	void bin_write(ofstream& bin_f);
};
