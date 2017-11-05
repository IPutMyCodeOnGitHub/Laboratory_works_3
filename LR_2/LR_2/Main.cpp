#include<iostream>
#include <cmath>
#include"Header.h"

using namespace std;

int main()
{
	char* num1 = Get_str_numb();
	Intln number1(strlen(num1), num1);

	char* num2 = Get_str_numb();
	Intln number2(strlen(num2), num2);

	Intln number3 = number1 - number2;
	cout << "By operator-: Number1 - Number2 = ";
	number3.Show();

	Intln number4 = number1 + number2;
	cout << "By operator+: Number1 + Number2 = ";
	number4.Show();
	cout << endl;

	//(number1.operator+(number2)).Show();

	cout << "Number1 = ";
	number1.Show();
	cout << "(++number1).Show(): ";
	(++number1).Show();
	cout << "Number1 = ";
	number1.Show();

	cout << "Number2 = ";
	number2.Show();
	cout << "(number1++).Show(): ";
	(number2++).Show();
	cout << "Number2 = ";
	number2.Show();

	long long_num = long(number2);
	cout << "Number4 of long = " << long_num << endl;

	Intln* del_number = new Intln(number2);
	delete del_number;

	system("pause");
	return 0;
}
