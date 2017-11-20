#pragma once
#include"Intln.h"

struct node
{
	node* next;
	node* prior;
	Intln* numb;
	node()
	{
		next = NULL;
		prior = NULL;
		numb = NULL;
	}
	node(Intln* n)
	{
		numb = new Intln(*n);
		next = NULL;
		prior = NULL;
	}
	~node()
	{
		next = NULL;
		prior = NULL;
		delete numb;
	}
};

class deque {
private:
	node* head;
	node* tail;
public:
	deque();
	void pushFront(Intln*); //добавление в начало
	void delFront(); //удаление из начала
	void delBack(); //удаление из конца
	void numbPush(Intln*, int); //вставка по номеру
	void numbDel(int); //удаление по номеру
	void search(Intln*); //поиск
	void show(); //демонстрация дека
};
