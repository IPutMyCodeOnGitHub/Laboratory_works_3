#include"Int.h"

class List 
{
private:
	object* obj;
	List* next;
	List* prior;
public:
	List();
	~List();
	void show();
	void push();
	void edition();
	List* deleting();
	void summation();
	void comparing();
	void text_read();
	void text_write();
	void bin_read();
	void bin_write();
};


List::List()
{
	obj = nullptr;
	next = nullptr;
	prior = nullptr;
}

List::~List()
{
	List* iterator;
	iterator = this;

	while (iterator->next != nullptr)
	{
		delete obj;
		iterator->prior->next = nullptr;
		iterator->prior = nullptr;
		iterator = iterator->next;
	}
}

void List::show()
{
	std::cout << "--List:" << std::endl;
	if (this->obj == nullptr)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	List* iterator;
	iterator = this;
	int i = 1;
	while (iterator != nullptr)
	{
		std::cout << i++ << ". ";
		iterator->obj->show();
		iterator = iterator->next;
	}
}

void List::push()
{
	char type[10];
	std::cout << "Type of new object: ";
	std::cin >> type;

	if (obj == nullptr)
	{
		if (strcmp("Intln", type) == 0)
			obj = new Intln;
		if (strcmp("Int", type) == 0)
			obj = new Int;
		if (obj == nullptr)
		{
			std::cout << "Wrong type" << std::endl;
			return;
		}
		std::cout << "New object: ";
		obj->get();
		return;
	}

	List* iterator = this;
	while (iterator->next!= nullptr)
		iterator = iterator->next;
	iterator->next = new List;
	iterator->next->prior = iterator;
	iterator = iterator->next;

	if (strcmp("Intln", type) == 0)
		iterator->obj = new Intln;
	if (strcmp("Int", type) == 0)
		iterator->obj = new Int;
	if (iterator->obj == nullptr)
	{
		std::cout << "Wrong type" << std::endl;
		return;
	}
	std::cout << "New object: ";
	iterator->obj->get();
}

void List::edition()
{
	int position;
	std::cout << "Position of list's element that needs edition: ";
	std::cin >> position;

	List* iterator;
	iterator = this;
	for (int i = 1; i < position; i++, iterator = iterator->next);
	if (iterator == nullptr)
	{
		std::cout << "Off-list position" << std::endl;
		return;
	}

	std::cout << "Old object: ";
	iterator->obj->show();

	char type[10];
	std::cout << "Type of new object: ";
	std::cin >> type;
	if (strcmp(iterator->obj->class_name(), type) != 0)
	{
		std::cout << "Different types" << std::endl;
		return;
	}
	if (strcmp("Intln", type) == 0)
		iterator->obj = new Intln;
	if (strcmp("Int", type) == 0)
		iterator->obj = new Int;
	std::cout << "New object: ";
	iterator->obj->get();
}

List* List::deleting()
{
	int position;
	std::cout << "Position of list's element that needs deleting: ";
	std::cin >> position;

	List* iterator;
	iterator = this;
	int i = 1;
	for (; i < position; ++i, iterator = iterator->next);

	if (iterator == nullptr)
	{
		std::cout << "Off-list position" << std::endl;
		return this;
	}
	if (iterator->prior == nullptr && iterator->next == nullptr)
	{
		delete iterator->obj;
		iterator->obj = nullptr;
		iterator = nullptr;
		return this;
	}
	if (iterator->prior == nullptr)
	{
		delete this->obj;
		this->obj = nullptr;
		this->next->prior = nullptr;
		return this->next;
	}
	if (iterator->next == nullptr)
	{
		iterator = iterator->prior;
		delete iterator->next->obj;
		iterator->next->obj = nullptr;
		iterator->next = nullptr;
		return this;
	}
	iterator->prior->next = iterator->next;
	iterator->next->prior = iterator->prior;
	delete iterator->obj;
	iterator->obj = nullptr;
	iterator = nullptr;
	return this;
}

void List::summation()
{
	int pos1, pos2;
	std::cout << "Positions of compared elements: ";
	std::cin >> pos1;
	std::cin >> pos2;

	List* iterator1;
	iterator1 = this;
	for (int i = 1; i < pos1; i++, iterator1 = iterator1->next);
	List* iterator2;
	iterator2 = this;
	for (int i = 1; i < pos2; i++, iterator2 = iterator2->next);
	int eq = strcmp(iterator1->obj->class_name(), iterator2->obj->class_name());
	if (eq != 0)
	{
		std::cout << "Elements are diferent types" <<std::endl;
		return;
	}

	List* iterator = this;
	while (iterator->next != nullptr)
		iterator = iterator->next;
	iterator->next = new List;
	iterator->next->prior = iterator;
	iterator = iterator->next;

	if (strcmp("Intln", iterator1->obj->class_name()) == 0)
		iterator->obj = new Intln;
	if (strcmp("Int", iterator1->obj->class_name()) == 0)
		iterator->obj = new Int;
	iterator->obj = iterator->obj->sum(iterator1->obj, iterator2->obj);
}


void List::comparing()
{
	int pos1, pos2;
	std::cout << "Positions of compared objects: ";
	std::cin >> pos1;
	std::cin >> pos2;
	List* iterator1;
	iterator1 = this;
	for (int i = 1; i < pos1; i++, iterator1 = iterator1->next);
	List* iterator2;
	iterator2 = this;
	for (int i = 1; i < pos2; i++, iterator2 = iterator2->next);
	int eq = strcmp(iterator1->obj->class_name(), iterator2->obj->class_name());
	if (eq != 0)
	{
		std::cout << "Elements are diferent types" <<std::endl;
		return;
	}
	int result;
	result = iterator1->obj->obj_cmp(iterator1->obj, iterator2->obj);
	if (result > 0)
		std::cout << "Element #" << pos1 << " is bigger than element #" << pos2 << std::endl;
	if (result < 0)
		std::cout << "Element #" << pos2 << " is bigger than element #" << pos1 << std::endl;
	if (result == 0)
		std::cout << "Element #" << pos2 << " and element #" << pos1 << " are equal" << std::endl;
}

void List::text_read()
{
	std::ifstream text_f("List.txt");
	List* iterator = this;
	while (!text_f.eof())
	{
		int identificator;
		text_f >> identificator;
		if (identificator == 0)
			break;
		if (obj == nullptr)
		{
			if (identificator == 1)
				iterator->obj = new Intln;
			if (identificator == 2)
				iterator->obj = new Int;
			iterator->obj->text_read(text_f);
			identificator = 0;
			continue;
		}
		iterator->next = new List;
		iterator->next->prior = iterator;
		iterator = iterator->next;
		if (identificator == 1)
			iterator->obj = new Intln;
		if (identificator == 2)
			iterator->obj = new Int;
		iterator->obj->text_read(text_f);
		identificator = 0;
	}
	text_f.close();
}

void List::text_write()
{
	std::ofstream text_f("List.txt");
	List* iterator = this;
	while (iterator != nullptr)
	{
		iterator->obj->text_write(text_f); 
		text_f << "\n";
		iterator = iterator->next;
	}
	text_f.close();
}


void List::bin_read()
{
	std::ifstream bin_f("List.bin", std::ios_base::binary);
	List* iterator = this;
	bin_f.seekg(0, std::ios::end);
	std::streampos eof = bin_f.tellg();
	bin_f.seekg(0, std::ios::beg);
	while (bin_f.tellg() != eof) {
		int identificator;
		bin_f.read((char*)&identificator, sizeof(int));
		if (obj == nullptr)
		{
			if (identificator == 1)
				iterator->obj = new Intln;
			if (identificator == 2)
				iterator->obj = new Int;
			identificator = 0;
			iterator->obj->bin_read(bin_f);
			continue;
		}
		iterator->next = new List;
		iterator->next->prior = iterator;
		iterator = iterator->next;
		if (identificator == 1)
			iterator->obj = new Intln;
		if (identificator == 2)
			iterator->obj = new Int;
		identificator = 0;
		iterator->obj->bin_read(bin_f);
	}
}

void List::bin_write()
{
	std::ofstream bin_f("List.bin", std::ios_base::binary);
	List* iterator = this;
	while (iterator != nullptr)
	{
		iterator->obj->bin_write(bin_f);
		iterator = iterator->next;
	}
	bin_f.flush();
}

