#include "Deque.h"

exception ex;

deque::deque()
{
	head = tail = NULL;
}


void deque::pushFront(Intln* n)
{
	try {
		if (head == NULL)
		{
			head = new node(n);
			tail = head;
			return;
		}
		head->prior = new node(n);
		head->prior->next = head;
		head = head->prior;
		return;
	}
	catch (runtime_error)
	{
		cerr << "Uninitializated number." << endl;
	}
}



void deque::delFront()
{
	if (head == NULL)
	{
		cout << "Deque is empty." << endl;
		return;
	}
	if (head->next == NULL)
	{
		delete head;
		head = NULL;
		tail = NULL;
		cout << "The last node is deleted. The deque is empty." << endl;
		return;
	}
	head = head->next;
	delete head->prior;
	head->prior = NULL;
	return;
}

void deque::delBack()
{
	if (head == NULL)
	{
		cout << "Deque is empty." << endl;
		return;
	}
	if (tail->prior == NULL)
	{
		delete tail;
		tail = NULL;
		head = NULL;
		cout << "The last node is deleted. The deque is empty." << endl;
		return;
	}
	tail = tail->prior;
	delete tail->next;
	tail->next = NULL;
	return;
}

void deque::numbPush(Intln *n, int pozition)
{
	if (pozition == 1)
	{
		pushFront(n);
		return;
	}
	node* iterator;
	int k;
	for (iterator = head, k = 1; k < pozition && iterator != tail->next; iterator = iterator->next, k++);
	try
	{
		if (iterator == tail->next)
		{
			tail->next = new node(n);
			tail->next->prior = tail;
			tail = tail->next;
			cerr << "Pozition of new number is out of deque. The number is pushed in the tail." << endl;
			return;
		}
		node* new_node = new node(n);
		new_node->prior = iterator->prior;
		iterator->prior->next = new_node;
		new_node->next = iterator;
		iterator->prior = new_node;
		return;
	}
	catch(runtime_error)
	{
		cerr << "Uninitializated number." << endl;
	}
}

void deque::numbDel(int pozition)
{
	if (pozition == 1)
	{
		delFront();
		return;
	}
	node* iterator;
	int k;
	for (iterator = head, k = 1; k < pozition && iterator != tail; iterator = iterator->next, k++);
	try
	{
		if (iterator == tail) throw ex;
		iterator->prior->next = iterator->next;
		iterator->next->prior = iterator->prior;
		delete iterator;
		return;
	}
	catch (exception ex)
	{
		cerr << "Pozition of deleting number is out of deque. The tail is deleted." << endl;
		delBack();
		return;
	}
}

void deque::search(Intln* n)
{
	node* iterator;
	int k;
	for (iterator = head, k = 1; iterator != tail->next; iterator = iterator->next, k++)
	{
		try
		{
			if (*(iterator->numb) == *(n))
			{
				cout << "The number is found in node #" << k << endl;
				return;
			}
		}
		catch (runtime_error)
		{
			cerr << "Uninitializated number." << endl;
			return;
		}
	}
	cout << "The number is not in the deque." << endl;
	return;
}

void deque::show()
{
	if (head == NULL)
	{
		cout << "The deque is empty." << endl;
		return;
	}
	node* iterator;
	for (iterator = head; iterator != tail->next; iterator = iterator->next)
	{
		if (iterator == NULL) throw runtime_error("Uninitializated number.");
		iterator->numb->Show();
	}

}
