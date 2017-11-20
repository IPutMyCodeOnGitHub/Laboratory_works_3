#pragma once
#include<iostream>
using namespace std;

template <class T>
class Container
{
private:
	T** arr;
	int size;
public:
	Container();
	void Push();
	void Show();
	void Sort();
};


template<class T>
inline Container<T>::Container()
{
	arr = nullptr;
	size = 0;
}


template<>
inline void Container<char>::Push()
{
	char ch;
	cout << "Elements for array: ";
	while (ch = getchar())
	{
		if (ch == '\n')
			break;

		if (ch == ' ')
			continue;

		if (arr == nullptr)
		{

			arr = (char**)calloc(1, sizeof(char*));
			size = 1;
			arr[0] = (char*)calloc(1, sizeof(char));
			*(arr[0]) = ch;
			continue;
		}
		arr = (char**)realloc(arr, ++size * sizeof(char*));
		arr[size - 1] = (char*)calloc(1, sizeof(char));
		*(arr[size - 1]) = ch;
	}
}

template<class T>
inline void Container<T>::Push()
{
	cout << "Elements for array: ";
	T obj;
	while (cin >> obj)
	{
		if (arr == nullptr)
		{
			arr = (T**)calloc(1, sizeof(T*));
			size = 1;
			arr[0] = (T*)calloc(1, sizeof(T));
			*(arr[0]) = obj;
			continue;
		}
		arr = (T**)realloc(arr, ++size * sizeof(T*));
		arr[size - 1] = (T*)calloc(1, sizeof(T));
		*(arr[size - 1]) = obj;
	}
}

template<class T>
inline void Container<T>::Show()
{
	cout << "Elements of array: ";
	for (int i = 0; i < size; i++)
		cout << *arr[i] << ' ';
	cout << endl;
}

template<class T>
inline void Container<T>::Sort()
{
	T* str = new T[size];
	T c;
	int i, j, k;
	for (i = 0; i < size; i++)
		str[i] = *(arr[i]);
	
	for (i = size - 1; i >= 0; i--)
	{
		c = 0;
		for (j = 0; j < size; j++)
		{
			if (str[j] > c)
			{
				c = str[j];
				k = j;
			}
		}
		*(arr[i]) = c;
		str[k] = 0;
	}
}

