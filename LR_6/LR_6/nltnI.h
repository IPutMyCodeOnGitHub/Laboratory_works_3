#pragma once
#include"Intln.h"

class nltnI : public Intln {
private:
	bool mirror;
public:
	nltnI();
	nltnI(int e, char* m);
	nltnI(nltnI &n);

	~nltnI();

	void Show();
	friend ostream& operator<<(ostream& os, nltnI& numb);
	friend istream& operator >> (istream& is, nltnI& numb);
	void Invert(); //переворот числа
};
