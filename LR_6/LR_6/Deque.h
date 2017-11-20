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
	void pushFront(Intln*); //���������� � ������
	void delFront(); //�������� �� ������
	void delBack(); //�������� �� �����
	void numbPush(Intln*, int); //������� �� ������
	void numbDel(int); //�������� �� ������
	void search(Intln*); //�����
	void show(); //������������ ����
};
