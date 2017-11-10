#include<iostream>
#include <cmath>
#include<fstream>
#include"Deque.h"
#include"Intln.h"
#include"Ilnnt.h"
#include"nltnI.h"

using namespace std;

int main()
{
	cout << "Numbers for deque: " << endl;
	Intln* num1 = new Intln;
	cin >> *num1;
	Intln* num2 = new Ilnnt;
	cin >> *num2;
	Intln* num3 = new nltnI;
	cin >> *num3;
	cout << endl;

	deque* D = new deque;
	D->pushFront(num1);
	D->pushFront(num2);
	D->pushFront(num3);
	cout << "The deque: " << endl;
	D->show();
	cout << endl;

	cout << "Number for search: ";
	Intln* num4 = new Intln;
	cin >> *num4;
	D->search(num4);
	cout << endl;

	cout << "New number: ";
	Intln* num5 = new Ilnnt;
	cin >> *num5;
	cout << "And its pozition: ";
	int pozition;
	cin >> pozition;
	D->numbPush(num5, pozition);
	D->show();
	cout << endl;

	cout << "Delete number #";
	int poz_del;
	cin >> poz_del;
	D->numbDel(poz_del);
	D->show();
	cout << endl;

	cout << "Head-node is deleted." << endl;
	D->delFront();
	D->show();
	cout << endl;

	cout << "Tail-node is deleted." << endl;
	D->delBack();
	D->show();
	cout << endl;
	cout << "Tail-node is deleted." << endl;
	D->delBack();
	D->show();
	cout << endl;

	system("pause");
	return 0;
}
