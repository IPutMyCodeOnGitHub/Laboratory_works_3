#include<iostream>
#include <cmath>
#include<fstream>
#include"Intln.h"
#include"Ilnnt.h"
#include"nltnI.h"

using namespace std;

int main()
{
	Intln* n;
	Ilnnt number1;
	cout << "Ilnnt object: ";
	cin >> number1;
	number1.Sort();
	n = &number1;
	n->Show();

	nltnI number2;
	cout << "nltnI object: ";
	cin >> number2;
	number2.Invert();
	n = &number2;
	n->Show();


	system("pause");
	return 0;
}


