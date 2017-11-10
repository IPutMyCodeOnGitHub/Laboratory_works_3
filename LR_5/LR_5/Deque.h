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
	deque* pushFront(Intln*); //добавление в начало
	deque* delFront(); //удаление из начала
	deque* delBack(); //удаление из конца
	deque* numbPush(Intln*, int); //вставка по номеру
	deque* numbDel(int); //удаление по номеру
	void search(Intln*); //поиск
	void show(); //демонстрация дека
};
