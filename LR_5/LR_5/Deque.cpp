#include "Deque.h"

deque::deque()
{
	head = tail = NULL;
}


deque* deque::pushFront(Intln* n)
{
	if (head == NULL)
	{
		head = new node;
		head->numb = n;
		tail = head;
		return this;
	}

	head->prior = new node;
	head->prior->numb = n;
	head->prior->next = head;
	head = head->prior;
	return this;
}

deque* deque::delFront()
{
	if (head == NULL)
	{
		cout << "Deque is empty." << endl;
		return this;
	}
	if (head->next == NULL)
	{
		delete head;
		head = NULL;
		tail = NULL;
		cout << "The last node is deleted. The deque is empty." << endl;
		return this;
	}
	head = head->next;
	delete head->prior;
	head->prior = NULL;
	return this;
}

deque* deque::delBack()
{
	if (head == NULL)
	{
		cout << "Deque is empty." << endl;
		return this;
	}
	if (tail->prior == NULL)
	{
		delete tail;
		tail = NULL;
		head = NULL;
		cout << "The last node is deleted. The deque is empty." << endl;
		return this;
	}
	tail = tail->prior;
	delete tail->next;
	tail->next = NULL;
	return this;
}

deque* deque::numbPush(Intln *n, int pozition)
{
	if (pozition == 1)
	{
		pushFront(n);
		return this;
	}
	node* iterator;
	int k;
	for (iterator = head, k = 1; k < pozition && iterator != tail->next; iterator = iterator->next, k++);
	if (iterator == tail->next)
	{
		tail->next = new node;
		tail->next->numb = n;
		tail->next->prior = tail;
		tail = tail->next;
		return this;
	}
	node* new_node = new node;
	//new_node->numb = new Intln(*n);
	new_node->numb = n;
	new_node->prior = iterator->prior;
	iterator->prior->next = new_node;
	new_node->next = iterator;
	iterator->prior = new_node;
	return this;
}

deque * deque::numbDel(int pozition)
{
	if (pozition == 1)
	{
		delFront();
		return this;
	}
	node* iterator;
	int k;
	for (iterator = head, k = 1; k < pozition && iterator != tail; iterator = iterator->next, k++);
	if (iterator == tail)
	{
		delBack();
		return this;
	}
	iterator->prior->next = iterator->next;
	iterator->next->prior = iterator->prior;
	delete iterator;
	return this;
}

void deque::search(Intln* n)
{
	node* iterator;
	int k;
	for (iterator = head, k = 1; iterator != tail->next; iterator = iterator->next, k++)
		if (*(iterator->numb) == *(n))
		{
			cout << "The number is found in node #" << k << endl;
			return;
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
		iterator->numb->Show();
}
