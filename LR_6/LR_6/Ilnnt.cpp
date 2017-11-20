#include "Ilnnt.h"


Ilnnt::Ilnnt() :Intln()
{
	order = 0;
}

Ilnnt::Ilnnt(int e, char* m) : Intln(e, m) {}

Ilnnt::Ilnnt(Ilnnt & n) : Intln(n) {}

Ilnnt::~Ilnnt()
{}

void Ilnnt::Show()
{
	if (order == 1)
		cout << "Well-ordered ";
	else
		cout << "Unordered ";
	Intln::Show();
}

ostream& operator<<(ostream& os, Ilnnt& numb)
{
	for (int i = 0; i < numb.exponent; i++)
		os << numb.mantissa[i];
	return os;
}

istream& operator >> (istream& is, Ilnnt& numb)
{
	char ch;
	int size = 2;
	char* num = (char*)calloc(size, sizeof(char));
	int index = 0;

	while (ch = getchar())
	{
		if (ch == '\n')
			break;

		num[index] = ch;
		index++;

		if (index >= size)
		{
			char* ptr;
			if ((ptr = (char*)realloc(num, (size * 2) + 1)) != NULL)
			{

				size += 1;
				num = ptr;
			}
		}
	}
	num[index] = '\0';

	numb.exponent = strlen(num);
	numb.mantissa = new char[numb.exponent + 1];
	for (int i = 0; i <= numb.exponent; i++)
	{
		numb.mantissa[i] = num[i];
	}
	return is;
}

void Ilnnt::Sort()
{
	char* str = new char[exponent + 1];
	int i, j, k;
	for (i = 0; i < exponent + 1; i++)
		str[i] = mantissa[i];
	for (i = 0; i < exponent; i++)
	{
		char c = '9' + 1;
		for (j = 0; j < exponent; j++)
		{
			if (str[j] < c)
			{
				c = str[j];
				k = j;
			}
		}
		mantissa[i] = c;
		str[k] = '9' + 1;
	}
	order = 1;
}
