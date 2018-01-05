#include "List.h"
#include<conio.h>

int main()
{
	List* L = new List;
	char com[128];
	std::cout << "------List test----------" << std::endl
		<< "help - message with menu " << std::endl;
	std::cin >> com;
	while (strcmp("stop", com) != 0) {
		if (strcmp("help", com) == 0)
		{
			std::cout << "" << std::endl
				<< "1)help -	show this message" << std::endl
				<< "2)show -	show list" << std::endl
				<< "3)push -	push object in the list" << std::endl
				<< "4)edit -	edit object by its position" << std::endl
				<< "5)delete -	delete object by its position" << std::endl
				<< "6)sum -		sum two objects are same class and push result in the list" << std::endl
				<< "7)compare -		compare two objects are same clase" << std::endl
				<< "8)text_read -	read list from text file" << std::endl
				<< "9)text_write -	write the list in text file" << std::endl
				<< "10)bin_read -	read list from binary file" << std::endl
				<< "11)bin_write -	write the list in binary file" << std::endl
				<< "" << std::endl;
		}
		if (strcmp("show", com)==0)
		{
			L->show();
			std::cout << std::endl;
		}
		if (strcmp("push", com) == 0)
		{
			L->push();
			std::cout << std::endl;
		}
		if (strcmp("edit", com) == 0)
		{
			L->edition();
			std::cout << std::endl;
		}
		if (strcmp("delete", com) == 0)
		{
			L = L->deleting();
			std::cout << std::endl;
		}
		if (strcmp("sum", com) == 0)
		{
			L->summation();
			std::cout << std::endl;
		}
		if (strcmp("compare", com) == 0)
		{
			L->comparing();
			std::cout << std::endl;
		}
		if (strcmp("text_read", com) == 0)
		{
			L->text_read();
			std::cout << std::endl;
		}
		if (strcmp("text_write", com) == 0)
		{
			L->text_write();
			std::cout << std::endl;
		}
		if (strcmp("bin_read", com) == 0)
		{
			L->bin_read();
			std::cout << std::endl;
		}
		if (strcmp("bin_write", com) == 0)
		{
			L->bin_write();
			std::cout << std::endl;
		}
		
		std::cin >> com;
	}
	system("pause");
	return 0;
}