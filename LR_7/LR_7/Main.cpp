#include<iostream>
#include"Template_class.h"

using namespace std;

int main()
{
	Container<char> cont1;
	cont1.Push();
	cont1.Show();
	cout << endl;

	cont1.Sort();
	cout << "Sorted array2: " << endl;
	cont1.Show();

	Container<int> cont2;
	cont2.Push();
	cont2.Show();
	cout << endl;

	cont2.Sort();
	cout << "Sorted array1: " << endl;
	cont2.Show();
	cout << endl;


	system("pause");
	return 0;
}