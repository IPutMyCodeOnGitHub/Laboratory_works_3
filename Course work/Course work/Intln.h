#pragma once
#include"Abstract Class.h"

class Intln : public object
{
protected:
	int exponent;
	char* mantissa;

public:
	Intln();
	Intln(int e, char* m);
	Intln(const Intln &n);
	~Intln();
	void show(); //вывод объекта классса, виртуальная ф
	void get();
	int indificate(); //получение уникального идентификатора класса
	char* class_name();//строка с именем класса
	int obj_cmp(object*, object*);//сравнение двух объектов 
	object* sum(object*, object*);//сложение двух объектов 
	void text_read(std::ifstream&);///чтение из текстового файла
	void text_write(std::ofstream&);//запись в текстовый файл
	void bin_read(std::ifstream&);//чтение из бинарного файла
	void bin_write(std::ofstream&);//запись в бинарный файл

	Intln& operator=(const Intln&);
	Intln operator+(const Intln&);
	friend Intln operator-(const Intln&, const Intln&);

	Intln& operator++();
	Intln operator++(int);

	friend std::ostream& operator<<(std::ostream&, Intln&);
	friend std::istream& operator >> (std::istream&, Intln&);
	friend std::ofstream& operator<<(std::ofstream&, Intln&);
	friend std::ifstream& operator >> (std::ifstream&, Intln&);
};



Intln::Intln()
{
	exponent = 1;
	mantissa = NULL;
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


Intln::Intln(const Intln &n)
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
		delete[] mantissa;
}


void Intln::show()
{
	for (int i = 0; i < exponent; i++)
		std::cout << mantissa[i];
	std::cout << " ";
	std::cout << class_name() << " " << std::endl;
}


void Intln::get()
{
	std::cin >> *this;
	
}


int Intln::indificate()
{
	return 1;
}


inline char* Intln::class_name()
{
	char* name = new char[6];
	name = "Intln";
	return name;
}


int Intln::obj_cmp(object* n1, object* n2)
{
	//object::obj_cmp(object* n1, object* n2);
	return strcmp(((Intln*)n1)->mantissa, ((Intln*)n2)->mantissa);
}


object* Intln::sum(object* n1, object* n2)
{
	//object::sum(object*, object*);
	object* res = new Intln;
	*((Intln*)res) = *((Intln*)n1) + *((Intln*)n2);
	return res;
}


inline void Intln::text_read(std::ifstream& text_f)
{
	text_f >> *this;
}

inline void Intln::text_write(std::ofstream& text_f)
{
	int identificator = indificate();
	text_f << " " << identificator << " ";
	text_f << *this;
}

void Intln::bin_read(std::ifstream& bin_f)
{
	if (mantissa)
		delete[] mantissa;
	bin_f.read((char*)&exponent, sizeof(int));
	mantissa = new char[exponent + 1];
	bin_f.read(mantissa, exponent + 1);

}


void Intln::bin_write(std::ofstream& bin_f)
{
	int identificator = indificate();
	bin_f.write((char*)&identificator, sizeof(int));
	bin_f.write((char*)&exponent, sizeof(int));
	bin_f.write(mantissa, exponent + 1);
	bin_f.flush();
}

Intln& Intln::operator=(const Intln& n)
{
	exponent = n.exponent;

	if (mantissa) {
		delete[] mantissa;
	}
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


std::ostream& operator<<(std::ostream& os, Intln& numb)
{
	for (int i = 0; i < numb.exponent; i++)
		os << numb.mantissa[i];
	return os;
}


std::istream& operator>> (std::istream& is, Intln& numb)
{
	char ch;
	int size = 2;
	char* num = (char*)calloc(size, sizeof(char));
	int index = 0;
	ch = getchar();
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

std::ofstream& operator<<(std::ofstream& os, Intln& numb)
{
	os << numb.exponent << " " << numb.mantissa;

	return os;
}

std::ifstream& operator >> (std::ifstream& is, Intln& numb)
{
	if (numb.mantissa)
		delete[] numb.mantissa;
	is.get();
	numb.exponent = is.get() - '0';
	is.get();
	numb.mantissa = new char[numb.exponent + 1];
	int i;
	for (i = 0; i < numb.exponent + 1; i++)
		numb.mantissa[i] = is.get();
	numb.mantissa[i - 1] = '\0';

	return is;
}



