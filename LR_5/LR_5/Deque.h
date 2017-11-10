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
	deque* pushFront(Intln*); //���������� � ������
	deque* delFront(); //�������� �� ������
	deque* delBack(); //�������� �� �����
	deque* numbPush(Intln*, int); //������� �� ������
	deque* numbDel(int); //�������� �� ������
	void search(Intln*); //�����
	void show(); //������������ ����
};
