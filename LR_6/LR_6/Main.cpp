/*Вариант 6.
Постpоить класс для pаботы с целыми произвольной точности. Класс должен включать соответствующие поля:
длину и динамический массив – само число. Класс должен обеспечивать пpостейшие функции для pаботы с данными класса:
сложение, вычитание, умножение, деление, вывод числа в удобной форме в разных системах счисления и т.д.*/


#include"Deque.h"
#include"Intln.h"
#include"Ilnnt.h"
#include"nltnI.h"

using namespace std;

int main()
{
	cout << "Number = " << endl;
	Intln* num1 = new Intln;
	try
	{
		cout << "++Number = ";
		cout << ++(*num1) << endl;
	}
	catch (runtime_error) {
		cerr << endl << "Uninitializated number" << endl;
	};
	cout << endl;

	
	cout << "Numbers for deque:" << endl;
	Intln* num2 = new Ilnnt;
	cout << "Number1 = ";
	cin >> *num2;
	Intln* num3 = new nltnI;
	cout << "Number2 = ";
	cin >> *num3;
	Intln* num4 = new Intln;
	cout << "Number3 = " << endl;

	deque* D = new deque;
	D->pushFront(num2);
	D->pushFront(num3);
	D->pushFront(num4);
	cout << "The deque: " << endl;
	D->show();
	cout << endl;

	Intln* num5 = new Intln;
	cout << "Number for search = " << endl;
	D->search(num5);
	cout << endl;

	cout << "New number = " << endl;
	Intln* num6 = new Ilnnt;
	cout << "And its pozition = ";
	int pozition;
	cin >> pozition;
	D->numbPush(num5, pozition);
	cout << "The deque: " << endl;
	D->show();
	cout << endl;

	cout << "Delete number #";
	int poz_del;
	cin >> poz_del;
	D->numbDel(poz_del);
	cout << "The deque: " << endl;
	D->show();
	cout << endl;

	system("pause");
	return 0;
}