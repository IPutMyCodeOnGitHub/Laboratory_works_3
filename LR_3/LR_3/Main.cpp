#include<iostream>
#include <cmath>
#include<fstream>
#include"Header.h"

using namespace std;

int main()
{
	Intln number1;

	cout << "Number for istream: ";
	cin >> number1;
	cout << "Number from ostream: " << number1 << endl;

	Intln number2;
	Intln number3;

	cout << "Number for ofstream, file \"New_file.txt\": ";
	cin >> number2;
	ofstream f("New_file.txt", ios::out);
	f << number2;
	f.close();

	ifstream fl("New_file.txt", ios::in);
	fl >> number3;
	cout << "Number from ifstream, file \"New_file.txt\": ";
	cout << number3 << endl;
	f.close();

	cout << "Number for ofstream, file \"New_bin_file.bin\": ";
	cout << number2 << endl;
	ofstream bin_f("New_bin_file.bin", ios_base::binary);
	number2.bin_write(bin_f);

	Intln number4;
	ifstream bin_fl("New_bin_file.bin", ios_base::binary);
	number4.bin_read(bin_fl);
	cout << "Number from ifstream, file \"New_bin_file.bin\": ";
	cout << number4 << endl;

	system("pause");
	return 0;
}
