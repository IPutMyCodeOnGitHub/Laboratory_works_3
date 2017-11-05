#include "nltnI.h"

nltnI::nltnI() :Intln()
{
	mirror = 0;
}

nltnI::nltnI(int e, char* m) : Intln(e, m) {}

nltnI::nltnI(nltnI & n) : Intln(n) {}

nltnI::~nltnI()
{}

void nltnI::Show()
{
	Intln::Show();
	if (mirror == 1)
		cout << ", reflected.";
	else
		cout << ", unreflected.";

	cout << endl;
}

ostream& operator<<(ostream& os, nltnI& numb)
{
	for (int i = 0; i < numb.exponent; i++)
		os << numb.mantissa[i];
	return os;
}

istream& operator >> (istream& is, nltnI& numb)
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

void nltnI::Invert()
{
	char* str = new char[exponent + 1];
	int i, j;
	for (i = 0; i < exponent + 1; i++)
		str[i] = mantissa[i];
	for (i = 0, j = exponent - 1; i < exponent; i++, j--)
		mantissa[i] = str[j];
	mirror = 1;
}

