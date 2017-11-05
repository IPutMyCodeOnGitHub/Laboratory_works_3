#include"Header.h"
#include<cmath>

Intln::Intln()
{
	exponent = 1;
	mantissa = new char;
	mantissa[0] = '0';
	mantissa[1] = '\0';
}

Intln::Intln(int e, char* m)
{
	exponent = e;
	mantissa = new char[e + 1];
	for (int i = 0; i < exponent; i++)
	{
		mantissa[i] = m[i];
	}
	mantissa[exponent] = '\0';
}

Intln::Intln(Intln &n)
{
	exponent = n.exponent;
	mantissa = new char[exponent + 1];
	for (int i = 0; i < exponent + 1; i++)
	{
		mantissa[i] = n.mantissa[i];
	}
}

Intln::~Intln()
{
	if (mantissa)
	{
		delete[] mantissa;
	}
}


char* Get_str_numb()
{
	char ch;
	int size = 2;
	char* num1 = (char*)calloc(size, sizeof(char));
	int index = 0;

	cout << "Number = ";
	while (ch = getchar())
	{
		if (ch == '\n')
			break;

		num1[index] = ch;
		index++;

		if (index >= size)
		{
			char* ptr;
			if ((ptr = (char*)realloc(num1, (size * 2) + 1)) != NULL)
			{

				size += 1;
				num1 = ptr;
			}
		}
	}
	num1[index] = '\0';

	return num1;
}


void Intln::Show()
{
	for (int i = 0; i < exponent; i++)
		cout << mantissa[i];
	cout << endl;
}


Intln& Intln::operator=(const Intln& n)
{
	exponent = n.exponent;
	mantissa = new char(exponent + 1);
	for (int i = 0; i < exponent + 1; i++)
	{
		mantissa[i] = n.mantissa[i];
	}
	return *this;
}


Intln Intln::operator+(const Intln& right)
{
	Intln result;
	bool reg = false;
	int position;
	if (this->exponent >= right.exponent)
	{
		position = this->exponent - 1;
		result.exponent = this->exponent;
	}
	else
	{
		position = right.exponent - 1;
		result.exponent = right.exponent;
	}

	char* ptr;
	if ((ptr = (char*)realloc(result.mantissa, position + 2)) != NULL)
		result.mantissa = ptr;

	int i, j;
	for (i = this->exponent - 1, j = right.exponent - 1; position >= 0; i--, j--, position--)
	{
		if (i < 0)
			while (j >= 0)
			{
				result.mantissa[position] = right.mantissa[j] + reg;
				reg = false;
				if (result.mantissa[position] > '9')
				{
					reg = true;
					result.mantissa[position] -= 10;
				}
				j--;
				position--;
			}
		if (j < 0)
			while (i >= 0)
			{
				result.mantissa[position] = this->mantissa[i] + reg;
				reg = false;
				if (result.mantissa[position] > '9')
				{
					reg = true;
					result.mantissa[position] -= 10;
				}
				i--;
				position--;
			}
		if (i >= 0 && j >= 0)
		{
			result.mantissa[position] = this->mantissa[i] + right.mantissa[j] - '0' + reg;
			reg = false;
			if (result.mantissa[position] > '9')
			{
				reg = true;
				result.mantissa[position] -= 10;
			}
		}
	}
	if (reg)
	{
		if ((ptr = (char*)realloc(result.mantissa, result.exponent * 2 + 1)) != NULL)
			result.mantissa = ptr;

		for (int k = result.exponent - 1; k >= 0; k--)
			result.mantissa[k + 1] = result.mantissa[k];
		result.mantissa[0] = '1';
		result.exponent++;
	}

	result.mantissa[result.exponent] = '\0';

	//*this = result;

	return result;
}


Intln operator-(const Intln& left, const Intln& right)
{
	Intln result;
	bool reg = false;

	int position;
	if (left.exponent >= right.exponent)
	{
		position = left.exponent - 1;
		result.exponent = left.exponent;
	}
	else
	{
		position = right.exponent - 1;
		result.exponent = right.exponent;
	}

	char* ptr;
	if ((ptr = (char*)realloc(result.mantissa, position + 2)) != NULL)
		result.mantissa = ptr;

	int i, j;
	for (i = left.exponent - 1, j = right.exponent - 1; position >= 0; i--, j--, position--)
	{
		if (i < 0)
			while (j >= 0)
			{
				result.mantissa[position] = right.mantissa[j] - reg;
				reg = false;
				if (result.mantissa[position] < '0')
				{
					reg = true;
					result.mantissa[position] += 10;
				}
				j--;
				position--;
			}
		if (j < 0)
			while (i >= 0)
			{
				result.mantissa[position] = left.mantissa[i] - reg;
				reg = false;
				if (result.mantissa[position] < '0')
				{
					reg = true;
					result.mantissa[position] += 10;
				}
				i--;
				position--;
			}
		if (i >= 0 && j >= 0)
		{
			result.mantissa[position] = left.mantissa[i] - right.mantissa[j] + '0' - reg;
			reg = false;
			if (result.mantissa[position] < '0')
			{
				reg = true;
				result.mantissa[position] += 10;
			}
		}
	}

	int nnull = 0;
	int k = 0;
	while (result.mantissa[k] == '0')
	{
		nnull++;
		k++;
	}
	for (k = 0; k < result.exponent - nnull; k++)
	{
		result.mantissa[k] = result.mantissa[k + nnull];
	}

	result.exponent -= nnull;

	result.mantissa[result.exponent] = '\0';

	return result;
}

Intln::operator long()
{
	long a = 0;
	int e = exponent;
	for (int k = 0; k < exponent; k++, e--)
		a += (mantissa[k] - '0') * pow(10, e - 1);
	return a;
}


Intln& Intln::operator++()
{
	int i;
	bool reg = true;

	for (i = exponent - 1; i >= 0; i--)
	{
		mantissa[i] += reg;

		reg = false;
		if (mantissa[i] > '9')
		{
			reg = true;
			mantissa[i] -= 10;
		}

	}
	if (reg)
	{
		char* ptr;
		if ((ptr = (char*)realloc(mantissa, exponent * 2 + 1)) != NULL)
			mantissa = ptr;

		for (i = exponent - 1; i >= 0; i--)
			mantissa[i + 1] = mantissa[i];
		mantissa[0] = '1';
		exponent++;
	}
	mantissa[exponent] = '\0';

	return *this;
}


Intln Intln::operator++(int)
{
	Intln temp = *this;
	++*this;
	return temp;
}
